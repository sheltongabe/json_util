/**
 *  @file	test_object.cpp
 *  @brief	
 *  
 * 	Details
 *  
 *  @author	First_Last_Name	username
 *  @date	07-27-2018
 *  @version	0.0
 */

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
	// Build generators
	std::uniform_int_distribution<> int_generator(
			TestObject::INTEGER_RANGE.first, 
			TestObject::INTEGER_RANGE.second);
	std::uniform_int_distribution<> char_generator(
			TestObject::CHAR_RANGE.first, 
			TestObject::CHAR_RANGE.second);
	std::uniform_int_distribution<> strlenGenerator(1, 25);
	std::uniform_int_distribution<> numMembersGenerator(1, 50);
	std::uniform_int_distribution<> typeGenerator(
			0, TestObject::NUM_TYPES - 1);

	// find out the number of members to generate
	int numMembers;
	numMembers = numMembersGenerator(rng);

	// Generate the members
	for(int i = 0; i < numMembers; ++i) {
		// Determine the key
		std::string key = TestObject::MEMBER_PREFIX + std::to_string(i);

		// Determine the type
		uint32_t type = typeGenerator(rng);

		json::JSONValue value;
		switch(type) {
			case INTEGER:
				value = int_generator(rng);
				break;
			
			case STRING:
				// determine the length of the string
				int strlen = strlenGenerator(rng);

				value = "";
				for(int j = 0; j < strlen; ++j) {
					char c = char_generator(rng);
					std::get<std::string>(value) += c;
				}
				break;
		}
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
// getJSON () -> json::JSON
//
json::JSON TestObject::getJSON() {
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

	// Check for different sizes
	if(this->members.size() != other.members.size())
		return false;

	// Check member by member
	for(auto thisCur = this->members.begin(), otherCur = other.members.begin();
			thisCur != this->members.end() && otherCur != other.members.end();
			++thisCur, ++otherCur) {
		if(thisCur->second != otherCur->second)
			return false;
	}

	// If we get here they are equalivalent
	return true;
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