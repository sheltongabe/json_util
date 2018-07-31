/**
 *  @file	jsonable.h
 *  @brief		  Define everything for JSONable and JSON representation
 *
 *	Define JSON representation and how to make an object JSONAble
 *
 *  @author		Gabriel Shelton	sheltongabe
 *  @date		  07-31-2018
 *  @version	0.3
 */

#ifndef JSONABLE_H
#define JSONABLE_H

#include <map>
#include <variant>
#include <vector>

namespace json {
	// Forward declare a class for arrays and objects
	class JSONObject;
	// class JSONArray;  (future feature V_0.4)

	/// Defines JSONValues to be a variant <int, double, string, bool>
	using JSONValue = std::variant<int, double, std::string, bool, JSONObject>;

	/// Define JSON to be a map between string keys and JSONValues
	using JSON = std::map<std::string, JSONValue>;

	/**
	 * 	@class		JSONAble
	 * 	@brief		Overloaded by the client to make the object be reduced
	 * 	to json
	 *
	 * 	Overload the JSON map constructor / getJSON method to build and get a
	 * 	JSON version of the code.
	 */
	class JSONAble {
		public:
			/**
			 * 	@brief	Default Constructor
			 *
			 * 	Initialize members to default values, does nothing (Pure Abstract Class)
			 *
			 * @version	0.1
			 */
			JSONAble();

			/**
			 * 	@brief	Copy Constructor
			 *
			 * 	Copy members from another object, does nothing (Pure Abstract Class)
			 *
			 * @version	0.1
			 */
			JSONAble(JSONAble &copy);

			/**
			 * 	@brief	Move Constructor
			 *
			 * 	Move members from another object, does nothing (Pure Abstract Class)
			 *
			 * @version	0.1
			 */
			JSONAble(JSONAble &&object);

			/**
			 * 	@brief	Construct from a JSON map
			 *
			 * 	Client uses this to construct their object from the passed JSON map
			 *
			 * 	@version 0.1
			 */
			JSONAble(JSON json);

			/**
			 * @brief	get the object in json form
			 * 
			 * 	Convert the object members to a JSON map and return
			 * 
			 * 	@version 0.1
			 */
			virtual JSON getJSON() = 0;

			/**
			 * 	@brief	Destructor
			 *
			 * 	No objects allocated
			 *
			 * @version	0.1
			 */
			~JSONAble();

		private:
	};

	/**
	 * 	@class	JSONObject
	 * 	@brief 	Define a pair of strings and JSONValues
	 * 
	 * 	Uses JSON as the definition of the JSONObject, but it has to be done like this
	 * 	because, when JSONValues is defined the compiler is not yet aware of JSON
	 * 
	 * 	@version 0.3
	 */
	class JSONObject : public JSON { 
		public:
			/// Copy Constructor for JSON
			JSONObject(JSON& j) : JSON(j) { }

			/// Move Constructor for JSON
			JSONObject(JSON&& j) : JSON(j) { }
	};

} // namespace json
#endif