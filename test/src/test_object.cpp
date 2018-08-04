/**
 *  @file		test_object.cpp
 *  @brief	  Provide a test-bed to stress test the library	
 *  
 * 	Has stood up to 100,000 tests in a single run so far
 *  
 *  @author		Gabriel Shelton	sheltongabe
 *  @date		  08-02-2018
 *  @version	0.4
 */

#include <sstream>
#include <variant>
#include <algorithm>

// For abs value during double checks
#include <cstdlib>

#include "test_object.h"

std::string TestObject::MEMBER_PREFIX = "member_";

//
// Default Constructor
//
TestObject::TestObject() : JSONAble() {

}

//
// Copy Constructor
//
TestObject::TestObject(TestObject& copy) :
		members(copy.members),
		JSONAble(copy) {

}

//
// Initializing Constructor
//
TestObject::TestObject(std::mt19937& rng) {
	// find out the number of members to generate
	std::uniform_int_distribution<> numMembersGenerator(1, 100);
	int numMembers = numMembersGenerator(rng);

	// Generate the members
	for(int i = 0; i < numMembers; ++i) {
		// Determine the key
		std::string key = TestObject::MEMBER_PREFIX + std::to_string(i);

		// Generate value to be stored and store it
		json::JSONValue value = this->generateValue(rng);
		this->members[key] = value;
	}
	
}

//
// JSON Constructor
//
TestObject::TestObject(json::JSON j) {
	// Go through each key and push the value to the members list
	for(auto current = j.begin(); current != j.end(); ++current) {
		this->members[current->first] = current->second;
	}
}

// 
// generateValue (std::mt19937&) -> json::JSONValue
//
json::JSONValue TestObject::generateValue(std::mt19937& rng) {
	// For deciding if an object, array, or base-type should be generated
	std::uniform_real_distribution<double> percentGenerator(0.0, 1.0);

	// Decide which type should be generated
	json::JSONValue value;

	// Should an object be generated
	if(percentGenerator(rng) < TestObject::CHANCE_FOR_OBJECT) {
		TestObject obj(rng);
		value = std::move(obj.getJSON());
	}
	// Should an array be generated
	else if(percentGenerator(rng) < TestObject::CHANCE_FOR_ARRAY) {
		// Array
		json::JSONArray array;

		// length of array
		std::uniform_int_distribution<> intGenerator(0, 50);
		int arrayLen = intGenerator(rng);

		// loop and generate contents of array
		for(int i = 0; i < arrayLen; ++i)
			array.push_back(std::move(this->generateValue(rng)));

		value = std::move(array);
	}
	// Generate a base type
	else
		value = std::move(this->generateBaseValue(rng));

	return std::move(value);
}

// 
// generateBaseValue (std::mt19937&) -> json::JSONValue
//
json::JSONValue TestObject::generateBaseValue(std::mt19937& rng) {
	// Build generators
	std::uniform_int_distribution<> int_generator(
			TestObject::INTEGER_RANGE.first, 
			TestObject::INTEGER_RANGE.second);
	std::uniform_int_distribution<> typeGenerator(
			0, TestObject::NUM_TYPES - 1);

	// Place to store the value generated
	json::JSONValue value;

	// Type to generate
	int type = typeGenerator(rng);
	switch(type) {
		case INTEGER:
		{
			value = int_generator(rng);
		}
		break;

		case DOUBLE:
		{
			// Generate 2 integers cast as doubles
			double v = static_cast<double>(
					static_cast<double>(int_generator(rng)) / 
					static_cast<double>(int_generator(rng)));
			value = v;
		}
		break;

		case STRING:
		{
			std::uniform_int_distribution<> char_generator(
					TestObject::CHAR_RANGE.first, 
					TestObject::CHAR_RANGE.second);
			std::uniform_int_distribution<> strlenGenerator(1, 50);

			// Determine the length of the string
			int strlen = strlenGenerator(rng);

			// Generate the string
			value = static_cast<std::string>(std::move(""));
			for(int j = 0; j < strlen; ++j) {
				char c = char_generator(rng);
				std::get<std::string>(value) += c;
			}
		}
		break;

		case BOOLEAN:
		{
			std::uniform_int_distribution<> bool_generator(0, 1);
			value = (bool_generator(rng) == 0) ? false : true;
		}
		break;

		case NULL_TYPE:
		{
			value = std::monostate();
		}
		break;
	}

	return std::move(value);
}

//
// getJSON () -> json::JSON
//
json::JSON TestObject::getJSON() const {
	// Build the JSON object to store the data to
	json::JSON j;

	// Add members to the json
	for(auto current = this->members.begin(); 
			current != this->members.end(); 
			++current) {
		j[current->first] = current->second;
	}

	// return the json
	return std::move(j);
}

//
// operator== (const TestObject&) -> bool
//
bool TestObject::operator==(const TestObject& other) const {
	// check for self comparison
	if(this == &other)
		return true;

	// use json::JSONCompare to compare the JSON generated by each
	json::JSONValue leftJSON = this->getJSON(), rightJSON = other.getJSON();
	return std::visit(json::JSONCompare{leftJSON}, rightJSON);
}

//
// operator!= (const TestObject&) -> bool
//
bool TestObject::operator!=(const TestObject& other) const {
	return !(*this == other);
}

//
// Destructor
//
TestObject::~TestObject() {

}