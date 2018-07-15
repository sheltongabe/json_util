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
			 * 	@brief	Read in a file (filename) and return its text in a single string to be parsed
			 * 
			 * 	-If the filename doesn't have an .json extension, add it and then read in the file
			 * 	-From there read the file into a string and return the string w/ std::move
			 * 
			 * 	@param	std::string		Name of file that is being read in w/ or w/out .json
			 * 
			 * 	@return   std::string	  The JSON read from the file
			 * 	@return	  std::string	  Blank string if error
			 * 
			 * 	@version 0.1
			 */
			static std::string read(std::string filename);

			/**
			 * 	@brief	Write the text that is in a json form to the file (filename)
			 * 
			 * 	-If the filename is missing .json extension add it, then write to the file
			 * 	
			 * 	@param	std::string		Name of the file to write to w/ or w/out file extension
			 * 	@param	std::string		The data getting written to the file in a json format
			 * 
			 * 	@return	  bool				Did the data get written correctly
			 *  
			 * 	@version 0.1
			 */
			static bool write(std::string filename, std::string text);

		private:
	};
}
#endif