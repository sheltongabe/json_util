/**
 *  @file		json_text_parser.cpp
 *  @brief	  Parse jsonText into a JSON map	
 *  
 * 	Details
 *  
 *  @author		Gabriel Shelton	sheltongabe
 *  @date		  07-29-2018
 *  @version	0.2
 */

#include "json_text_parser.h"
#include "json_exception.h"

namespace json {
	// ----- Initialize static variables used by the methods -----

	// Characters that mark the beginning or termination of a string
	std::vector<char> JSONTextParser::STRING_MARKERS = {'\'', '\"'};

	// Mark that string reading should be terminated in getString
	std::vector<char> JSONTextParser::STRING_TERMINATERS = { ',', '}' };

	// Valid boolean strings ordered so if you mod 2 their index you get the 1 or 0 bool value
	std::vector<std::string> JSONTextParser::BOOLEAN_STRINGS = {
		"false", "true", "False", "True"
	};	

	// A map between characters that should indicate a recursive call and will perform that call
	std::map<char, JSONValue(*) (std::stringstream&)> JSONTextParser::RECURSIVE_CHARACTERS = {
		{ '\'', JSONTextParser::getString },
		{ '\"', JSONTextParser::getString }
	};

	//
	// Default Constructor
	//
	JSONTextParser::JSONTextParser() {

	}

	//
	// Copy Constructor
	//
	JSONTextParser::JSONTextParser(JSONTextParser& copy) {

	}

	//
	// parse (std::string) -> JSON
	//
	JSON JSONTextParser::parse(std::string jsonText) {
		// Build a stream for the jsonText
		std::stringstream s(jsonText);

		// Call the recursiveJSONTextParser and return the built JSON project
		JSON j = JSONTextParser::recursiveObjectParser(s);
		return std::move(j);
	}
	//
	// recursiveObjectParser (std::stringstream) -> JSON
	//
	JSON JSONTextParser::recursiveObjectParser(std::stringstream& s) {
		// Construct the JSON map for this round in the recursive function
		JSON j;

		// clear { that signifies the begining of an object
		if(static_cast<char>(s.peek()) == '{')
			s.get();
		// If not, it is not an object, throw an exception
		else
			throw JSONException("Error parsing object in json text");

		// Loop until you finish this Object
		while(s.peek() != '}') {
			// Get the key for this iteration
			std::string key = std::get<std::string>(getString(s));

			// Skip the colon marking between the key and value
			s.get();

			// The value to pair with the key
			JSONValue value;

			// Peek the next character to see if you need to call a function
			char starter = s.peek();
			if(JSONTextParser::RECURSIVE_CHARACTERS.count(starter)) {
				value = RECURSIVE_CHARACTERS[starter](s);
			}
			// The value is not one that is built by another function
			else {
				// Read everything after the colon into a string and start conversions
				std::string v = std::get<std::string>(getString(s));

				// -----Convert v -> value-----
				// Check for it being a double
				if(v.find('.') != std::string::npos) {
					value = std::stod(v);
				}
				else {
					// Assume the type of integer
					value = std::stoi(v);
				}
			}

			// store value with the key
			j.emplace(key, value);

			// If there is a comma after the value, consume it
			if(s.peek() == ',')
				s.get();
		}

		// Get rid of the '}' marking the end of the object and return the JSON built
		s.get();
		return std::move(j);
	}

	//
	// getString (std::stringstream) -> std::string
	//
	JSONValue JSONTextParser::getString(std::stringstream& s) {
		// Input helper variables
		std::string input;

		// If we are reading a string
		if(JSONTextParser::isIn(static_cast<char>(s.peek()), JSONTextParser::STRING_MARKERS)) {
			// Read until the next char is the flag again
			char flag = s.get(), tmp;
			while( (tmp = s.get()) != flag) {
				input += tmp;
			}
		}
		// If we are reading until a string terminator (reading non-string values)
		else {
			char tmp;
			while(!JSONTextParser::isIn( (tmp = s.get() ), JSONTextParser::STRING_TERMINATERS)) {
				input += tmp;
			}
			s.unget();
		}

		// return the input
		return std::move(input);
	}

	//
	// isIn (T, std::vector<T>) -> bool
	//
	template<typename T>
	bool JSONTextParser::isIn(T value, std::vector<T> container) {
		// Set iterators to the begining and end of the vector
		auto begin = container.begin(), end = container.end();
		return std::count(begin, end, value) > 0;
	}

	//
	// Destructor
	//
	JSONTextParser::~JSONTextParser() {

	}
}