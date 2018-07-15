/**
 *  @file		json_exception.cpp
 *  @brief	  Provide Definitions for the exceptions in json and printing them to the user
 *  
 * 	Details 
 * 
 *  @author		Gabriel Shelton	sheltongabe
 *  @date		  07-15-2018
 *  @version	0.1
 */

#include "json_exception.h"

namespace json {
	// Initialize the Default Error Message
	std::string JSONException::DEFAULT_ERROR_MESSAGE = 
			std::move("Error parsing JSON");

	//
	// Default Constructor
	//
	JSONException::JSONException() :
			errorMessage(DEFAULT_ERROR_MESSAGE) {

	}

	//
	// Copy Constructor
	//
	JSONException::JSONException(JSONException& copy) :
			errorMessage(copy.errorMessage) {

	}

	//
	// Move Constructor
	//
	JSONException::JSONException(JSONException&& copy) :
			errorMessage(std::move(copy.errorMessage)) {

	}

	//
	// getErrorMessage () -> std::string
	//
	std::string JSONException::getErrorMessage() const {
		return this->errorMessage;
	}

	//
	// Destructor
	//
	JSONException::~JSONException() {

	}

	//
	// operator<< (std::ostream&, const JSONException&) -> std::ostream
	//
	std::ostream& operator<<(std::ostream& stream, const JSONException& rhs) {
		stream << rhs.getErrorMessage();
		return stream;
	}
}