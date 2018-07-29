/**
 *  @file		json_text_builder.h
 *  @brief	  Describes how to build a json string from a JSON object
 *  
 * 	Use Recursive functions, and the visitor pattern,
 *  to go from the JSON object and then to the string
 *  
 *  @author	  Gabriel Shelton	sheltongabe
 *  @date		07-29-2018
 *  @version  0.1
 */

#ifndef JSON_TEXT_BUILDER_H
#define JSON_TEXT_BUILDER_H

#include <sstream>

#include "jsonable.h"


namespace json {

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
		 * 	@brief 	Overload for the general case function call
		 * 
		 * 	Insert the contents of the paramater to the string stream	
		 * 
		 * 	@param	T const&		reference to general object, type is auto determined
		 * 
		 */
		template <typename T>
		void operator()(T const& item) {
			this->s << item;
		}
		
	};

	/**
	 * 	@class		JSONTextBuilder
	 * 	@brief		A pure static class that describes how to convert objects to json strings
	 * 
	 * 	Uses recursive functions to form the json string
	 * 
	 */
	class JSONTextBuilder {
		public:
			/**
			 * 	@brief	Default Constructor
			 * 
			 * 	Details
			 * 
			 * 	@version	0.1
			 */
			JSONTextBuilder();

			/**
			 * 	@brief	Copy Constructor
			 * 
			 * 	Details
			 * 
			 * 	@version	0.1
			 */
			JSONTextBuilder(JSONTextBuilder& copy);

			/**
			 * 	@brief	Destructor
			 * 
			 * 	Details
			 * 
			 * 	@version	0.1
			 */
			~JSONTextBuilder();

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

		protected:
			/// Initial number of tabs that is used when performing conversion
			static int INITIAL_NUM_TABS;

			/// Precision for decimal numbers
			static const int PRECISION = 15;

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
			 * 	@version 0.1
			 */
			static void parseObject(JSON& j, std::stringstream& s, int& numTabs);

		private:

	};
}
#endif