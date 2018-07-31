/**
 *  @file		json_text_parser.h
 *  @brief	  Serve as a static class to convert between string and json::JSON 	
 *  
 * 	Store static methods that convert between a string in json format, and
 * 	json::JSON which can be used to construct JSONAble objects
 *  
 *  @author		Gabriel Shelton	sheltongabe
 *  @date		  07-31-2018
 *  @version	0.3
 */

#ifndef JSON_TEXT_PARSER_H
#define JSON_TEXT_PARSER_H

#include <sstream>
#include <algorithm>

#include "json_exception.h"
#include "jsonable.h"

// Define function pointers for the RecursiveFunctions
typedef json::JSONValue (*RecursiveFunction) (std::stringstream);

namespace json {

	/**
	 * 	@class		JSONTextParser
	 * 	@brief		A Pure static class that will handle conversions for json
	 * 
	 * 	Have a public interface that calls protected, recursive functions that will parse
	 * 	a json string to JSON (std::map<std::string, JSONValue>)
	 * 
	 */
	class JSONTextParser {
		 public:
			JSONTextParser();

			/**
			 * 	@brief	Copy Constructor
			 * 
			 * 	Details
			 * 
			 * 	@version	0.1
			 */
			JSONTextParser(JSONTextParser& copy);

			/**
			 * 	@brief 	Convert valid json text to a JSON object that JSONAble objects can be built from
			 * 
			 * 	-Call protected method recursiveObjectParser in order to handle the work horse
			 * 	of the conversion
			 * 	-This method just stands as a public interface
			 * 
			 * 	@param		std::string	 			   jsonText 
			 * 	@return 	  JSON 						  Object the text represented
			 * 	@throw		  JSONException		  If there is an error in the parsing of the JSON
			 * 
			 *	@version 0.3
			 */
			static JSON parse(std::string jsonText);

			/**
			 * 	@brief 	Destructor
			 * 
			 * 	Details
			 * 
			 * 	@version 0.1
			 */
			~JSONTextParser();

		protected:
			/// Characters that mark the beginning or termination of a string
			static std::vector<char> STRING_MARKERS;

			/// Characters that mark that string reading should be terminated
			static std::vector<char> STRING_TERMINATERS;

			/// The strings that are valid boolean
			static std::vector<std::string> BOOLEAN_STRINGS;

			/// The characters that mark that a recurssive call is needed, and which call, passing std::stringstream
			static std::map<char, JSONValue(*) (std::stringstream&)> RECURSIVE_CHARACTERS;

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
			 * 	@version 0.3
			 */
			static JSONValue recursiveObjectParser(std::stringstream& s);

			/**
			 * @brief		Read in a string object or read till a STRING_TERMINATOR character
			 * 
			 * @param 	std::stringstream	stream to read from
			 * @return    std::string 				string read in
			 * 
			 * 	@version 0.1
			 */
			static JSONValue getString(std::stringstream& s);

			/**
			 * 	@brief	Check to see if the passed value is in the passed vector
			 * 
			 * 	uses count in std::algorithm to see if the value is in the vector
			 * 
			 * 	@param		T			Value
			 * 	@param		T			Vector containting type T
			 * 	@return		  bool	   If value is in the vector
			 * 
			 * 	@version 0.1
			 */
			template <typename T>
			static bool isIn(T value, std::vector<T>);

		private:

	};
}
#endif