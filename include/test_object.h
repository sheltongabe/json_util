/**
 *  @file		test_object.h
 *  @brief	  Stress test the json library	
 *  
 * 	-Define a class and enumeration of types that used in combination,
 * 	will stress test the json library 
 * 
 *  @author		Gabriel Shelton	sheltongabe
 *  @date		  07-28-2018
 *  @version	0.1
 */

#ifndef TEST_OBJECT_H
#define TEST_OBJECT_H

#include <random>
#include <utility>

#include "json/jsonable.h"

/**
 * 	@class		TestObject
 * 	@brief		Stress test the json library with random generation
 * 
 * 	Extend the JSONAble object and randomly construct lists of members
 * 
 */
class TestObject : public json::JSONAble {
	protected:
		/// The prefix for the member name / key
		static std::string MEMBER_PREFIX;

		/// Range for integers
		static constexpr std::pair<int, int> INTEGER_RANGE = {-32000, 32000};

		/// Range for chars
		static constexpr std::pair<int, int> CHAR_RANGE = {97, 122};

		/// Number of types
		static const int NUM_TYPES = 3;

		/// Precision of doubles generated
		static const int PRECISION = 6;

		/// Used by the random number generator to select the value stored
		enum Type {
			INTEGER = 0,
			DOUBLE = 1,
			STRING = 2
		};

		/// Members being stored
		std::map<std::string, json::JSONValue> members;

	public:
		/**
		 * 	@brief	Default Constructor
		 * 
		 * 	Details
		 * 
		 * 	@version	0.1
		 */
		TestObject();

		/**
		 * 	@brief	Initializing constructor
		 * 
		 * 	Initialize the members of the object with the random items
		 * 
		 * 	@version	0.1
		 */
		TestObject(std::mt19937& rng);

		/**
		 * 	@brief	Copy Constructor
		 * 
		 * 	Details
		 * 
		 * 	@version	0.1
		 */
		TestObject(TestObject& copy);

		/**
		 * 	@brief	Construct from a JSON map
		 *
		 *	Details
		 * 
		 * 	@version 0.1
		 */
		TestObject(json::JSON json);

		/**
		 * @brief	get the object in json form
		 *
		 * 	Convert the object members to a JSON map and return
		 *
		 * 	@version 0.1
		 */
		virtual json::JSON getJSON();

		/**
		 * 	@brief	Compare and return if the two objects are equal
		 * 
		 * 	Compare and see if all objects in the members map are equal
		 * 
		 * 	@param		TestObject& 	other
		 * 	@return 	  bool					If the object is equal
		 * 
		 * 	@version 0.1
		 */
		bool  operator==(const TestObject& other) const;

		/**
		 * 	@brief	Compare and return if the two objects are not equal
		 * 
		 * 	Use the equal operator and invert it
		 * 
		 * 	@param		TestObject& 	Object being compared to
		 * 	@return 	  bool					If the object is not-equal
		 * 
		 * 	@version 0.1
		 */
		bool  operator!=(const TestObject& other) const;

		/**
		 * 	@brief	Destructor 
		 * 
		 * 	Details
		 * 
		 * 	@version	0.1
		 */
		~TestObject();

	private:

};

#endif