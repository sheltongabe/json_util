/**
 *  @file		json_file.cpp
 *  @brief	  Provide implementations for how to read and write files, from one string
 *  
 * 	-Handles adding the file extension and how to write to the files as well as read to them
 * 	-Purely static class, not meant to be instansiated
 *  
 *  @author		Gabriel Shelton	sheltongabe
 *  @date		  07-15-2018
 *  @version	0.1
 */

#include "json_file.h"

#include <sstream>
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
	std::string JSONFile::read(std::string filename) {
		// Check the file extension and correct if needed
		if(!checkExtension(filename))
			filename += JSONFile::FILE_EXTENSION;

		// Variable to store the final output
		std::string output = "";

		// Open and read the JSON string
		try {
			// Variables to read in the data
			std::stringstream s;
			std::string line;
			std::ifstream jsonFile(filename);
			
			// Read the file, until you run out of file to read
			while(!jsonFile.eof()) {
				jsonFile >> line;
				s << line;
			}

			// close the stream and set the output
			jsonFile.close();
			output = s.str();
		}
		// If there is an error, throw an JSONException telling that there was an
		// error reading the file
		catch(std::exception e) {
			throw JSONException("Error reading data in json file: " + filename);
		}

		// if the input had no errors, return the contents of the file in output
		return std::move(output);
	}

	// 
	// write (std::string, std::string) -> bool
	//
	bool JSONFile::write(std::string filename, std::string jsonData) {
		// Check the file extension and correct if needed
		if(!checkExtension(filename))
			filename += JSONFile::FILE_EXTENSION;

		// Open and write the json text to the file
		try {
			// Output file
			std::ofstream jsonFile(filename);
			jsonFile << jsonData;
			jsonFile.close();
		}
		// If there is an error throw a JSONException
		catch(std::exception e) {
			throw JSONException("Error writing data to the file: " + filename);
		}

		// Will only ever return true or throw an exception
		return true;
	}

	// 
	// checkExtension (std::string) -> bool
	//
	bool JSONFile::checkExtension(std::string filename) {
		// use a reverse find to try and see if the FILE_EXTENSION is in the string, 
		// or the index it starts
		const size_t lastFind = filename.rfind(JSONFile::FILE_EXTENSION);
		if(lastFind == std::string::npos)
			return false;

		// If the File Extension is present ensure it is at the end of the file name
		else
			return (filename.length() - JSONFile::FILE_EXTENSION.length()) == lastFind;
	}

	// 
	// Destructor
	//
	JSONFile::~JSONFile() {

	}
}