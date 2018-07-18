/**
 *  @file		json_parser.h
 *  @brief	  Serve as a static class to convert between string and json::JSON 	
 *  
 * 	Store static methods that convert between a string in json format, and
 * 	json::JSON which can be used to construct JSONAble objects
 *  
 *  @author		Gabriel Shelton	sheltongabe
 *  @date		  07-17-2018
 *  @version	0.1
 */

#ifndef JSON_PARSER_H
#define JSON_PARSER_H

#include <sstream>
#include <algorithm>

#include "json_exception.h"
#include "jsonable.h"

namespace json {

	/**
	 * 	@class		JSONParser
	 * 	@brief		A Pure static class that will handle conversions for json
	 * 
	 * 	Have a public interface that calls protected, recursive functions that will parse
	 * 	a json string to JSON (std::map<std::string, JSONValue>)
	 * 
	 */
	class JSONParser {
		public:
			/**
			 * 	@brief	Default Constructor
			 * 
			 * 	Details
			 * 
			 * 	@version	0.1
			 */
			JSONParser();

			/**
			 * 	@brief	Copy Constructor
			 * 
			 * 	Details
			 * 
			 * 	@version	0.1
			 */
			JSONParser(JSONParser& copy);

			/**
			 * 	@brief 	Convert valid json text to a JSON object that JSONAble objects can be built from
			 * 
			 * 	-Call protected method recursiveJSONParser in order to handle the work horse
			 * 	of the conversion
			 * 	-This method just stands as a public interface
			 * 
			 * 	@param		std::string	 			   jsonText 
			 * 	@return 	  JSON 						  Object the text represented
			 * 	@throw		  JSONException		  If there is an error in the parsing of the JSON
			 * 
			 *	@version 0.1
			 */
			static JSON parse(std::string jsonText);

			/**
			 * 	@brief 	Destructor
			 * 
			 * 	Details
			 * 
			 * 	@version 0.1
			 */
			~JSONParser();

		protected:
			/// The Characters that should be ignored in the JSON file
			static std::vector<char> IGNORE_CHARACTERS;

			/// Characters that mark the beginning or termination of a string
			static std::vector<char> STRING_MARKERS;

			/// Characters that mark that string reading should be terminated
			static std::vector<char> STRING_TERMINATERS;

			/// The strings that are valid boolean
			static std::vector<std::string> BOOLEAN_STRINGS;

			/// The characters that mark that a recurssive call is needed, and which call, passing std::stringstream
			static std::map<char, void*> RECURSIVE_CHARACTERS;

			/**
			 * 	@brief 	The workhorse of parsing JSON from a stringstream that is made
			 * 
			 * 	Parses the JSON potentially calling itself recursively, and provides the majority
			 * 	of the work for the parsing returning eventually a moved JSON object
			 * 
			 * 	@param		std::stringstream	JSON being parsed
			 * 	@return		  JSON						 The object representation of the JSON
			 * 	@throw		 JSONException		  If there is an error in the parsing of the JSON
			 * 
			 * 	@version 0.1
			 */
			static JSON recursiveJSONParser(std::stringstream s);

			/**
			 * 	@brief 	Clear out any characters from the stringstream marked in IGNORE_CHARACTERS
			 * 
			 * 	Removes characters from the stream until a character is encountered that is not
			 * 	in IGNORE_CHARACTERS, at which point it puts the character back and ends
			 * 
			 * 	@param 	std::stringstream	stream to clear 
			 * 	@return   char 						  Last character removed and reinserted
			 * 
			 * 	@version 0.1
			 */
			static char clearIgnoreCharacters(std::stringstream s);

			/**
			 * @brief		Read in a string object or read till a STRING_TERMINATOR character
			 * 
			 * @param 	std::stringstream	stream to read from
			 * @return    std::string 				string read in
			 * 
			 * 	@version 0.1
			 */
			static std::string getString(std::stringstream s);

		private:

	};
}
#endif