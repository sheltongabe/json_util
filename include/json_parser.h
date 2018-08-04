/**
 *  @file		json_parser.h
 *  @brief	  Describes how to build a json string from a JSON object
 *  
 * 	Use Recursive functions, and the visitor pattern,
 *  to go from the JSON object and then to the string
 *  
 *  @author	  Gabriel Shelton	sheltongabe
 *  @date		07-31-2018
 *  @version  0.4
 */

#ifndef JSON_PARSER_H
#define JSON_PARSER_H

#include <sstream>

#include "jsonable.h"


namespace json {
	// Forward declare the struct JSONTextVisitor for the parser
	struct JSONTextVisitor;

	/**
	 * 	@class		JSONParser
	 * 	@brief		A pure static class that describes how to convert objects to json strings
	 * 
	 * 	Uses recursive functions to form the json string
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
			 * 	@brief	Destructor
			 * 
			 * 	Details
			 * 
			 * 	@version	0.1
			 */
			~JSONParser();

			/**
			 * 	@brief 	Take a JSON and build a string
			 * 
			 * 	Call a recursive method that will start to build the JSON string
			 * 
			 * 	@param	JSON			JSON object to build the text from
			 * 	@return  std::string 	The json string built
			 * 
			 * 	@version 0.1
			 */
			static std::string parse(JSON j);

			/**
			 * 	@brief 	Begin building the text form of an object into a stringstream and visiting as needed
			 * 
			 * 	Use the visitor pattern to visit and get the type of the variant and act based on the type
			 * 	retrieved, inserting it into the stringstream and formatting the json, as needed
			 * 
			 * 	@param	JSON& 				  The object being converted
			 * 	@param	stringstream& 	The stream that the text is being inserted into
			 * 	@param	int						  How many tabs are needed before each line
			 * 
			 * 	@version 0.4
			 */
			static void parseObject(JSON& j, std::stringstream& s, int& numTabs);

			/**
			 * 	@brief 	Begin building the text form of an array into a stringstream and visiting as needed
			 * 
			 * 	Use the visitor pattern to visit and get the type of the variant and act based on the type
			 * 	retrieved, inserting it into the stringstream and formatting the json, as needed
			 * 
			 * 	@param	JSONArray& 		  The array being converted
			 * 	@param	stringstream& 	The stream that the text is being inserted into
			 * 	@param	int						   How many tabs are needed before each line
			 * 
			 * 	@version 0.4
			 */
			static void parseArray(JSONArray& j, std::stringstream& s, int& numTabs);

		protected:
			/// Initial number of tabs that is used when performing conversion
			static int INITIAL_NUM_TABS;

		private:

	};

	/**
	 * 	@struct	JSONTextVisitor
	 * 	@brief 	Define how the JSON object is visited
	 * 
	 * 	Overload the callable operator several times, for each type that is visited,
	 * 	and a general one that takes an auto type for others.
	 * 
	 */
	struct JSONTextVisitor {
		/// The string stream that is being inserted into
		std::stringstream& s;

		/// The number of tabs to place before new lines
		int numTabs;

		/**
		 * 	@brief 	Initializing Constructor
		 * 
		 * 	@param	stringstream	The stream to insert the json text to
		 * 	@param	int						The number of tabs to place before a newline
		 * 
		 * 	@version 0.1
		 */
		JSONTextVisitor(std::stringstream& s, int& numTabs) :
			s(s),
			numTabs(numTabs) { }

		/**
		 * 	@brief 	Operator overload for a string case
		 * 
		 * 	Insert the string paramater to the string stream, w/ quotes
		 * 
		 * 	@param	std::string const&		reference to string object
		 * 
		 */
		void operator()(std::string const& item) {
			this->s << "\"" << item << "\"";
		}

		/**
		 * 	@brief 	Operator overload for a bool case
		 * 
		 * 	Insert the bool paramater to the string stream
		 * 
		 * 	@param	bool const&		reference to bool object
		 * 
		 */
		void operator()(bool const& item) {
			std::string itemStr = (item) ? "true" : "false";
			this->s << itemStr;
		}

		/**
		 * 	@brief 	Operator overload for a JSONObject case
		 * 
		 * 	
		 * 
		 * 	@param	json::JSONObject const&		reference to JSONObject object
		 * 
		 */
		void operator()(JSONObject& item) {
			// Use existing infrastructure to parse the passed object and insert
			// it into the string stream
			json::JSONParser::parseObject(item, this->s, this->numTabs);
		}

		/**
		 * 	@brief 	Operator overload for a JSONArray case
		 * 
		 * 	
		 * 
		 * 	@param	json::JSONArray const&		reference to JSONArray object
		 * 
		 */
		void operator()(JSONArray& item) {
			// Use existing infrastructure to parse the passed array and insert
			// it into the string stream
			json::JSONParser::parseArray(item, this->s, this->numTabs);
		}

		/**
		 * 	@brief 	Operator overload for a std::monostate (null)
		 * 
		 * 	
		 * 
		 * 	@param	std::monostate const&		reference to monostate
		 * 
		 */
		void operator()(std::monostate const& item) {
			std::string nullString = std::move("null");
			this->s << nullString;
		}

		/**
		 * 	@brief 	Overload for the general case function call
		 * 
		 * 	Insert the contents of the paramater to the string stream	
		 * 
		 * 	@param	T const&		reference to general object, type is auto determined
		 * 
		 */
		template <typename T>
		void operator()(T const& item) {
			// String representation for the item
			std::string itemStr = std::to_string(item);
			const char* itemC_Str = itemStr.c_str();

			// Put the item into the stream char-by char
			for(int i = 0; i < itemStr.length(); ++i)
				s.put(itemC_Str[i]);
		}
	};
}
#endif