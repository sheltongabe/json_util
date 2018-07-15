/**
 *  @file	json_file.cpp
 *  @brief	
 *  
 * 	Details
 *  
 *  @author	First_Last_Name	username
 *  @date	07-15-2018
 *  @version	0.0
 */

#include "json_file.h"

namespace json {
	// Set Default File Extension
	std::string JSONFile::FILE_EXTENSION = std::move(".json");

	//
	// Default Constructor
	//
	JSONFile::JSONFile() {

	}

	//
	// Copy Constructor
	//
	JSONFile::JSONFile(JSONFile& copy) {

	}

	// 
	// read (std::string) -> std::string
	//
	std::string read(std::string filename) {

	}

	// 
	// write (std::string, std::string) -> bool
	//
	bool write(std::string filename, std::string jsonData);
}