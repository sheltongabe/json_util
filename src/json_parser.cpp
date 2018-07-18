/**
 *  @file	json_parser.cpp
 *  @brief	
 *  
 * 	Details
 *  
 *  @author	First_Last_Name	username
 *  @date	07-17-2018
 *  @version	0.0
 */

#include "json_parser.h"

namespace json {
	// ----- Initialize static variables used by the methods -----
	// Characters that should be ignored like spaces, tabs, and newlines
	std::vector<char> JSONParser::IGNORE_CHARACTERS = {};

	// Characters that mark the beginning or termination of a string
	std::vector<char> JSONParser::STRING_MARKERS = {'\'', '\"'};

	// Mark that string reading should be terminated in getString
	std::vector<char> JSONParser::STRING_TERMINATERS = { ',', '}' };

	// Valid boolean strings ordered so if you mod 2 their index you get the 1 or 0 bool value
	std::vector<std::string> JSONParser::BOOLEAN_STRINGS = {
		"false", "true", "False", "True"
	};	

	// A map between characters that should indicate a recursive call and will perform that call
	std::map<char, void*> JSONParser::RECURSIVE_CHARACTERS = {
		// Not necessarily recursive calls but can take advantage of the framework to build strings
		{ '\"', JSONParser::getString },
		{ '\'', JSONParser::getString }
	};

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
	JSON recursiveJSONParser(std::stringstream s) {

	}

	// 
	// clearIgnoreCharacters (std::stringstream) -> char
	//
	char clearIgnoreCharacters(std::stringstream s) {
		// character to hold the char being pulled out of the stream
		char tmp;
		while(std::count(
				JSONParser::IGNORE_CHARACTERS.begin(), 
				JSONParser::IGNORE_CHARACTERS.end(), 
				(tmp = s.get())) != 0) {
			
		}
		s.unget();
	}

	//
	// getString (std::stringstream) -> std::string
	//
	std::string getString(std::stringstream) {

	}

	//
	// Destructor
	//
	JSONParser::~JSONParser() {

	}
}