/**
 *  @file		json_text_builder.cpp
 *  @brief	  Implementation of conversion from a JSON object to string
 *  
 * 	Details
 *  
 *  @author		Gabriel Shelton	sheltongabe
 *  @date		  07-26-2018
 *  @version	0.1
 */

#include <iomanip>

#include "json_text_builder.h"

namespace json {

	// Initialize static variables
	int JSONTextBuilder::INITIAL_NUM_TABS = 0;

	//
	// Default Constructor
	//
	JSONTextBuilder::JSONTextBuilder() {

	}

	//
	// Copy Constructor
	//
	JSONTextBuilder::JSONTextBuilder(JSONTextBuilder& copy) {

	}

	// 
	// parse (JSON j) -> std::string
	//
	std::string JSONTextBuilder::parse(JSON j) {
		// Build the stringstream that will hold the text during the conversion
		std::stringstream s;

		// convert from object to stringstream
		JSONTextBuilder::parseObject(j, s, JSONTextBuilder::INITIAL_NUM_TABS);

		// return the contents of the string
		std::string jsonText = s.str();
		return std::move(jsonText);		
	}

	//
	// parseObject (JSON&, std::stringstream&, numTabs) -> void
	//
	void JSONTextBuilder::parseObject(JSON& j, std::stringstream& s, int& numTabs) {
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
		}

		// End object
		s << "\n}" << std::flush;
	}

	// 
	// Destructor
	//
	JSONTextBuilder::~JSONTextBuilder() {

	}

}