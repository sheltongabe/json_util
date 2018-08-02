/**
 *  @file	jsonable.h
 *  @brief		  Define everything for JSONable and JSON representation
 *
 *	Define JSON representation and how to make an object JSONAble
 *
 *  @author		Gabriel Shelton	sheltongabe
 *  @date		  08-02-2018
 *  @version	0.4
 */

#ifndef JSONABLE_H
#define JSONABLE_H

#include <map>
#include <variant>
#include <vector>

namespace json {
	// Forward declare a class for arrays and objects
	class JSONObject;
	class JSONArray;

	/// Defines JSONValues to be a variant
	//	<int, double, string, bool, std::monostate (null), JSONObject>
	using JSONValue = std::variant<
			int, double, std::string, bool, std::monostate, JSONObject, JSONArray>;

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
			virtual JSON getJSON() const = 0;

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
			/// Default Constructor
			JSONObject() : JSON() { }
			/// Copy Constructor for JSON
			JSONObject(JSON& j) : JSON(j) { }

			/// Move Constructor for JSON
			JSONObject(JSON&& j) : JSON(j) { }

			/// overload operator for ==
			bool operator==(const JSONObject& object) {
				return *this == object;
			}

			/// overload operator for !=
			bool operator!=(const JSONObject& object) {
				return !(*this == object);
			}
	};

	/**
	 * 	@class	JSONArray
	 * 	@brief	Extend the vector class of JSONValues and store JSONValues
	 * 
	 * 
	 * 
	 * 	@version 0.4
	 */
	class JSONArray : public std::vector<JSONValue> {
		public:
			/// Default Constructor
			JSONArray() : std::vector<JSONValue>() { }

			/// Copy constructor using vector
			JSONArray(std::vector<JSONValue>& v) : std::vector<JSONValue>(v) { }

			/// Move constructor using vector
			JSONArray(std::vector<JSONValue>&& v) : std::vector<JSONValue>(v) { }

			/// overload operator for ==
			bool operator==(const JSONArray& array) {
				return *this == array;
			}

			/// overload operator for !=
			bool operator!=(const JSONArray& array) {
				return !(*this == array);
			}
	};


} // namespace json

/// Operator overload== for monostate
inline bool operator==(std::monostate const& lhs, 
		std::monostate const& rhs) {
	return true;
}

/// Operator overload!= for monostate
inline bool operator!=(std::monostate const& lhs, 
		std::monostate const& rhs) {
	return false;
}

#endif