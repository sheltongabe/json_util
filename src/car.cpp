/**
 *  @file	car.cpp
 *  @brief	
 *  
 * 	Details
 *  
 *  @author	First_Last_Name	username
 *  @date	07-19-2018
 *  @version	0.0
 */

#include <sstream>

#include "car.h"

//
// Default Constructor
//
Car::Car() :
		num_wheels(4),
		model(std::move("Ford")),
		JSONAble() {

}

//
// Initializing Constructor
//
Car::Car(int num_wheels, std::string model) :
		num_wheels(num_wheels),
		model(model),
		JSONAble() {

}

//
// JSON Constructor
//
Car::Car(json::JSON json) :
		num_wheels(std::get<int>(json["num_wheels"])),
		model(std::get<std::string>(json["model"])),
		JSONAble(json) {

}

//
// Copy Constructor
//
Car::Car(Car& copy) :
		num_wheels(copy.num_wheels),
		model(copy.model),
		JSONAble(copy) {

}

// 
// toString () -> std::string
//
std::string Car::toString() {
	// Variables used to output properties
	std::string output;
	std::stringstream s;

	// insert properties into stream for convienence and speed
	s << "num_wheels: " << num_wheels << std::endl;
	s << "Model: " << model << std::endl;

	// return properties after storing to output
	output = s.str();
	return std::move(output);
}

//
// getJSON () -> json::JSON
//
json::JSON Car::getJSON() {
	json::JSON j;
	j["num_wheels"] = this->num_wheels;
	j["model"] = std::string(this->model);
	return j;
}

// 
// Destructor
//
Car::~Car() {

}