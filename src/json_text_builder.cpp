/**
 *  @file		json_text_builder.cpp
 *  @brief	  Implementation of conversion from a JSON object to string
 *  
 * 	Details
 *  
 *  @author		Gabriel Shelton	sheltongabe
 *  @date		  07-23-2018
 *  @version	0.1
 */

#include <iomanip>

#include "json_text_builder.h"

namespace json {

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

		// convert from object to string
		std::string jsonText = JSONTextBuilder::parseObject(
				j, s, JSONTextBuilder::INITIAL_NUM_TABS);

		// return the contents of the string
		return std::move(jsonText);		
	}

	//
	// parseObject (JSON&, std::stringstream&, numTabs) -> void
	//
	void parseObject(JSON& j, std::stringstream& s, int numTabs) {
		// Determine the type of each variable in the json moving key, by key, 
		// and behave appropriately
		auto begin = j.begin(), end = j.end();
	}

	// 
	// Destructor
	//
	JSONTextBuilder::~JSONTextBuilder() {

	}

}