/**
 *  @file		json_parser.cpp
 *  @brief	  Implementation of conversion from a JSON object to string
 *  
 * 	Details
 *  
 *  @author		Gabriel Shelton	sheltongabe
 *  @date		  07-31-2018
 *  @version	0.4
 */

#include <iomanip>

#include "json_parser.h"

namespace json {

	// Initialize static variables
	int JSONParser::INITIAL_NUM_TABS = 0;

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
	// parse (JSON j) -> std::string
	//
	std::string JSONParser::parse(JSON j) {
		// Build the stringstream that will hold the text during the conversion
		std::stringstream s;

		// convert from object to stringstream
		int numTabs = JSONParser::INITIAL_NUM_TABS;
		JSONParser::parseObject(j, s, numTabs);

		// return the contents of the string
		std::string jsonText = s.str();
		return std::move(jsonText);		
	}

	//
	// parseObject (JSON&, std::stringstream&, numTabs) -> void
	//
	void JSONParser::parseObject(JSON& j, std::stringstream& s, int& numTabs) {
		// Place Object marker '{' and a new line into the stream and adjust numTabs
		s << "{" << std::endl;
		++numTabs;

		// Get iterators to the begining and end of the map
		auto begin = j.begin(), end = j.end();

		// Move through the current layer of JSON (j) and call visit on each doing
		// the appropriate thing for each type
		for(auto current = begin; current != end; ) {
			// Insert the appropriate number of tabs
			for(int i = 0; i < numTabs; ++i)
				s << "\t";

			// Insert key and colon
			s << "\"" << (current->first) << "\"" << " : ";

			// Insert the appropriate JSON text
			std::visit(JSONTextVisitor{s, numTabs}, current->second);

			// If there is another key next then place a comma and a newline
			if(++current != end)
				s << "," << std::endl;
			else
				s << std::endl;
		}

		// End object
		--numTabs;
		for(int i = 0; i < numTabs; ++i)
			s << "\t";
		s << "}" << std::flush;
	}

	//
	// parseArray (JSONArray&, std::stringstream&, numTabs&) -> void
	//
	void JSONParser::parseArray(
			JSONArray& array, std::stringstream& s, int& numTabs) {
		// Insert array marker
		s << "[" << std::endl;
		++numTabs;

		// Move the appropriate number of tabs and begin visiting along the array
		// adding commas between elements, but not at the end
		for(int i = 0; i < numTabs; ++i)
			s << "\t";
		
		// Iterator to the end of the array
		auto end = array.end();

		// Loop through the array, visiting as needed, and adding formatting
		// Do nothing in the 3 term of the for loop, because current will be advanced in the loop
		for(auto current = array.begin(); current < end; ) {
			// Insert the current item into the stringstream
			for(int i = 0; i < numTabs; ++i)
				s << "\t";
			std::visit(JSONTextVisitor{s, numTabs}, *current);

			// advance current and check if a comma is needed
			if(++current != end)
				s << "," << std::endl;
			else
				s << std::endl;
		}
		
		// decrement numTabs and output array end
		--numTabs;
		for(int i = 0; i < numTabs; ++i)
			s << "\t";
		s << "]";

	}

	// 
	// Destructor
	//
	JSONParser::~JSONParser() {

	}

}