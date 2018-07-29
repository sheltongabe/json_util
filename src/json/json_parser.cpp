/**
 *  @file		json_parser.cpp
 *  @brief	  Parse jsonText into a JSON map	
 *  
 * 	Details
 *  
 *  @author		Gabriel Shelton	sheltongabe
 *  @date		  07-28-2018
 *  @version	0.1
 */

#include "json_parser.h"

namespace json {
	// ----- Initialize static variables used by the methods -----

	// Characters that mark the beginning or termination of a string
	std::vector<char> JSONParser::STRING_MARKERS = {'\'', '\"'};

	// Mark that string reading should be terminated in getString
	std::vector<char> JSONParser::STRING_TERMINATERS = { ',', '}' };

	// Valid boolean strings ordered so if you mod 2 their index you get the 1 or 0 bool value
	std::vector<std::string> JSONParser::BOOLEAN_STRINGS = {
		"false", "true", "False", "True"
	};	

	// A map between characters that should indicate a recursive call and will perform that call
	std::map<char, JSONValue(*) (std::stringstream&)> JSONParser::RECURSIVE_CHARACTERS = {
		{ '\'', JSONParser::getString },
		{ '\"', JSONParser::getString }
	};
	// JSONParser::RECURSIVE_CHARACTERS['\"'] = JSONParser::getString;

	//
	// Default Constructor
	//
	JSONParser::JSONParser() {

	}

	//
	// Copy Constructor
	//
	JSONParser::JSONParser(JSONParser& copy) {

	}

	//
	// parse (std::string) -> JSON
	//
	JSON JSONParser::parse(std::string jsonText) {
		// Build a stream for the jsonText
		std::stringstream s(jsonText);

		// Call the recursiveJSONParser and return the built JSON project
		JSON j = JSONParser::recursiveJSONParser(s);
		return std::move(j);
	}
	//
	// recursiveJSONParser (std::stringstream) -> JSON
	//
	JSON JSONParser::recursiveJSONParser(std::stringstream& s) {
		// Construct the JSON map for this round in the recursive function
		JSON j;
		// clear { that signifies the begining of an object
		s.get();

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
			if(JSONParser::RECURSIVE_CHARACTERS.count(starter)) {
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
	JSONValue JSONParser::getString(std::stringstream& s) {
		// Input helper variables
		std::string input;

		// If we are reading a string
		if(JSONParser::isIn(static_cast<char>(s.peek()), JSONParser::STRING_MARKERS)) {
			// Read until the next char is the flag again
			char flag = s.get(), tmp;
			while( (tmp = s.get()) != flag) {
				input += tmp;
			}
		}
		// If we are reading until a string terminator (reading non-string values)
		else {
			char tmp;
			while(!JSONParser::isIn( (tmp = s.get() ), JSONParser::STRING_TERMINATERS)) {
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
	bool JSONParser::isIn(T value, std::vector<T> container) {
		// Set iterators to the begining and end of the vector
		auto begin = container.begin(), end = container.end();
		return std::count(begin, end, value) > 0;
	}

	//
	// Destructor
	//
	JSONParser::~JSONParser() {

	}
}