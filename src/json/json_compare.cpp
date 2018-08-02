/**
 *  @file		json_compare.cpp
 *  @brief	  implement comparisons	
 *  
 * 	Define how these JSONValues are compared
 *  
 *  @author		Gabriel Shelton	sheltongabe
 *  @date		  08-02-2018
 *  @version	0.4
 */

// for std::abs
#include <cmath>

#include "json_compare.h"

namespace json {
	//
	// operator() (double&) -> bool
	//
	bool JSONCompare::operator() (double& right) {
		// get the left value as a double
		double leftValue;
		try {
			leftValue = std::get<double>(this->left);
		}
		catch(std::bad_variant_access& e) {
			return false;
		}

		// compare w/ epsilon
		return std::abs(std::abs(leftValue) - std::abs(right)) <= JSONCompare::EPSILON;
	}

	//
	// operator() (JSONObject&) -> bool
	//
	bool JSONCompare::operator() (JSONObject& right) {
		// Get the left value as a JSONObject
		JSONObject leftValue;
		try {
			leftValue = std::get<JSONObject>(this->left);
		}
		catch(std::bad_variant_access& e) {
			// left does not store JSONObject
			return false;
		}

		// Test for differing size
		if(leftValue.size() != right.size())
			return false;

		// Move through both left and right
		for(auto leftCur = leftValue.begin(), rightCur = right.begin();
				leftCur != leftValue.end();
				++leftCur, ++rightCur) {
			if(!std::visit(JSONCompare{leftCur->second}, rightCur->second))
				return false;
		}

		// if we move through the entire list return true
		return true;
	}

	//
	// operator() (JSONArray const&) -> bool
	//
	bool JSONCompare::operator() (JSONArray& right) {
		// get the left value as a JSONArray
		JSONArray leftValue;
		try {
			leftValue = std::get<JSONArray>(this->left);
		}
		catch(std::bad_variant_access& e) {
			return false;
		}

		// Test for differing size
		if(leftValue.size() != right.size())
			return false;

		// Move through the arrays and test each element with visit
		for(auto leftCur = leftValue.begin(), rightCur = right.begin();
				leftCur != leftValue.end();
				++leftCur, ++rightCur) {
			if(!std::visit(JSONCompare{*leftCur}, *rightCur))
				return false;
		}

		// If we get through all of the elements
		return true;
	}

	//
	// operator() (std::monostate&) -> bool
	//
	bool JSONCompare::operator() (std::monostate& right) {
		if(std::holds_alternative<std::monostate>(this->left))
			return true;
		else
			return false;
	}

	//
	// operator() (T const&) -> bool
	//
	template<typename T>
	bool JSONCompare::operator() (T& right) {
		// Get the value as the same type as T
		T leftValue;
		try {
			leftValue = std::get<T>(this->left);
		}
		catch(std::bad_variant_access& e) {
			// left is not the same type as right
			return false;
		}

		return leftValue == right;
	}
}