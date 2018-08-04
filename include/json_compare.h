/**
 *  @file		json_compare.h
 *  @brief	  Define a visitor for comparing JSONValues	
 *  
 * 	Compare two JSONValues using the std::visit pattern
 * 	the left-hand-side is passed during construction, and the right w/ visit
 *  
 *  @author		Gabriel Shelton	sheltongabe
 *  @date		  08-02-2018
 *  @version	0.4
 */

#ifndef JSON_COMPARE_H
#define JSON_COMPARE_H

#include "jsonable.h"

namespace json {

	/**
	 * 	@struct		JSONCompare
	 * 	@brief		 Define how to compare two JSONValues
	 * 
	 * 	Left-hand-side is passed by reference in the constructor,
	 * 	default constructor is deleted
	 * 	Right hand side is called by std::visit
	 * 
	 */
	struct JSONCompare {
		/// Left hand side of the comparison
		JSONValue& left;

		/// Used for comparing doubles, if they are that close they are considered equal
		static constexpr double EPSILON = 0.000001;

		/**
		 * 	@brief	Default Constructor
		 * 
		 * 	Details
		 * 
		 * 	@version	0.0
		 */
		JSONCompare() = delete;

		/**
		 * 	@brief	Initializing Constructor
		 * 
		 * 	Initialize left-hand-side
		 * 
		 * 	@version	0.4
		 */
		JSONCompare(JSONValue& left) : left(left) { }

		/**
		 * 	@brief 	Compare for a double
		 * 
		 * 	@param double	  	    Right hand side of the comparison
		 * 	@return bool				Result of the comparison 
		 */
		bool operator()(double& right);

		// ----- Comparisons -----
		/**
		 * 	@brief 	Compare for a JSONObject
		 * 
		 * 	@param JSONObject 	Right hand side of the comparison
		 * 	@return bool				Result of the comparison 
		 */
		bool operator()(JSONObject& right);

		/**
		 * 	@brief 	Compare for a JSONArray
		 * 
		 * 	@param JSONArray 	 Right hand side of the comparison
		 * 	@return bool				Result of the comparison 
		 */
		bool operator()(JSONArray& right);

		/**
		 * 	@brief 	Compare for std::monostate
		 * 
		 * 	@param std::monostate 	 Right hand side of the comparison
		 * 	@return bool						Result of the comparison 
		 */
		bool operator()(std::monostate& right);

		/**
		 * 	@brief 	Compare for a generic auto determined type
		 * 
		 * 	@param T				 	 Right hand side of the comparison
		 * 	@return bool				Result of the comparison 
		 */
		template<typename T>
		bool operator()(T& right);

		/**
		 * 	@brief	Destructor
		 * 
		 * 	Details
		 * 
		 * 	@version	0.4
		 */
		~JSONCompare() { }
	};

};
#endif