/**
 *  @file		json_file.h
 *  @brief	  Handle the reading and writing of files in json
 *  
 * 	-Files are read in as and returned as std::strings
 * 	-Files are taken in as a std::map and written out as valid json
 *  
 *  @author		Gabriel Shelton	sheltongabe
 *  @date		  07-15-2018
 *  @version	0.1
 */

#ifndef JSON_FILE_H
#define JSON_FILE_H

#include <string>
#include <utility>
#include <fstream>

#include "json_exception.h"
#include "json_parser.h"
#include "json_text_builder.h"

namespace json {
	/**
	 * 	@class		JSONFile
	 * 	@brief		Purely static class that reads / writes json files
	 * 
	 * 	-read: filename (std::string) -> jsonString (std::string)
	 * 	-write: filename (std::string), jsonString (std::string) -> bool
	 * 
	 */
	class JSONFile {
		public:
			/// File extension for a json file
			static std::string FILE_EXTENSION;

			/**
			 * 	@brief	Default Constructor
			 * 
			 * 	(Does nothing purely static class)
			 * 
			 * 	@version	0.1
			 */
			JSONFile();

			/**
			 * 	@brief	Copy Constructor
			 * 
			 * 	(Does Nothing, purley static class)
			 * 
			 * 	@version	0.1
			 */
			JSONFile(JSONFile& copy);

			/**
			 * 	@brief 	Read the contents of the file, parse the JSON, and return
			 * 
			 * 	Use the internal read to read the contents of the file, and JSONParser to parse the json
			 * 
			 * 	@param 	std::string				filename 
			 * 	@return   JSON 						JSON representation
			 * 	@throw	  JSONException	   If there is an error reading the file or parsing it
			 * 
			 * 	@version 0.1
			 */
			static JSON readJSON(std::string filename);

			/**
			 * 	@brief 	Write the json-text for the JSON object passed into a file
			 * 
			 * 	Construct the json-text from the JSON object and write it to a file
			 * 	using the internal write method
			 * 
			 * 	@param 	std::string						filename 
			 * 	@param	JSON							  The JSON being written
			 * 	@return   bool								 Whether or not the write suceeded
			 * 	@throw	  JSONException			   If there was an error during writing
			 * 
			 * 	@version 0.1
			 */
			static bool writeJSON(std::string filename, JSON j);

			/**
			 * 	@brief 	Write the json-text for the JSONAble object passed into a file
			 * 
			 * 	Construct the json-text from the JSONAble object and write it to a file
			 * 	using the internal write method
			 * 
			 * 	@param 	std::string						filename 
			 * 	@param	JSONAble					  The JSONAble object being written
			 * 	@return   bool								 Whether or not the write suceeded
			 * 	@throw	  JSONException			   If there was an error during writing
			 * 
			 * 	@version 0.1
			 */
			static bool writeJSON(std::string filename, JSONAble& object);

			/**
			 * 	@brief	Read in a file (filename) and return its text in a single string to be parsed
			 * 
			 * 	-If the filename doesn't have an .json extension, add it and then read in the file
			 * 	-From there read the file into a string and return the string w/ std::move
			 * 
			 * 	@param	std::string			  Name of file that is being read in w/ or w/out .json
			 * 
			 * 	@return   std::string	  		The JSON read from the file
			 * 	@throw	  JSONException	  if there is an error reading the file
			 * 
			 * 	@version 0.1
			 */
			static std::string read(std::string filename);

			/**
			 * 	@brief	Write the text that is in a json form to the file (filename)
			 * 
			 * 	-If the filename is missing .json extension add it, then write to the file
			 * 	
			 * 	@param	std::string				Name of the file to write to w/ or w/out file extension
			 * 	@param	std::string				The data getting written to the file in a json format
			 * 
			 * 	@return	  bool						Did the data get written correctly
			 * 	@throw	  JSONException		If there was an error writing the data
			 *  
			 * 	@version 0.1
			 */
			static bool write(std::string filename, std::string text);

			/**
			 * 	@brief	Destructor
			 * 
			 * 	Details
			 * 
			 * 	@version 0.1
			 */
			~JSONFile();

		private:
			/**
			 * 	@brief	Check if the given filename has the file extension
			 * 
			 * 	Details
			 * 
			 * 	@param	std::string			Name of the file
			 * 
			 * 	@return	  bool					If the file has the correct FILE_EXTENSION at the end
			 * 
			 * 	@version 0.1
			 */
			static bool checkExtension(std::string filename);
	};
}
#endif