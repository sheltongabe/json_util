/**
 *  @file		json_exception.h
 *  @brief	  Define an exception interface for the client code and user to see json is misinterpreted	
 *  
 * 	The Exception that is thrown when an error happens interpretting json w/in the
 * 	json library
 *  
 *  @author		Gabriel Shelton	sheltongabe
 *  @date		  07-15-2018
 *  @version	0.1
 */

#ifndef JSON_EXCEPTION_H
#define JSON_EXCEPTION_H

#include <exception>
#include <string>
#include <ostream>

namespace json {
	/**
	 * 	@class		JSONException
	 * 	@brief		Store what went wrong within the exception, to be printed later
	 * 
	 * 	Using a string variable store a message when the exception is thrown,
	 * 	then later extract it with a stream extraction operator
	 * 
	 */
	class JSONException : public std::exception {
		public:
			/**
			 * 	@brief	Default Constructor
			 * 
			 * 	Initializing with a blank errorMessage
			 * 
			 * 	@version	0.1
			 */
			JSONException();

			/**
			 * 	@brief	Initializing Constructor
			 * 
			 * 	Initialize errorMessage to the passed string
			 * 
			 * 	@version	0.1
			 */
			JSONException(std::string error);

			/**
			 * 	@brief	Copy Constructor
			 * 
			 * 	Copy the Exception, and message
			 * 
			 * 	@version	0.1
			 */
			JSONException(JSONException& copy);

			/**
			 * 	@brief	Move Constructor
			 * 
			 * 	Move the errorMessage in
			 * 
			 * 	@version	0.1
			 */
			JSONException(JSONException&& copy);

			/**
			 * 	@brief	Get the value of errorMessage
			 * 
			 * 	@return	std::string		The errorMessage at this moment
			 * 
			 * 	@version 0.1
			 */
			inline std::string getErrorMessage() const;

			/**
			 * 	@brief	Destructor
			 * 
			 * 
			 * 
			 * 	@version 0.1
			 */
			~JSONException();

		protected:
			/// Default Error Message
			static std::string DEFAULT_ERROR_MESSAGE;

			/// Error message that is represented by this error
			std::string errorMessage;
	};

	/**
	 * 	@brief 	Overload the insertion operator to output errorMessage
	 * 
	 * 	Makes it so the insertion operator outputs the errorMessage
	 * 	to the ostream that is passed in
	 * 
	 * 	@param	std::ostream&		ostream to insert into
	 * 	@param	JSONException&	 exception being outputed
	 * 
	 * 	@return	 std::ostream&
	 * 
	 * 	@version 0.1
	 */
	std::ostream& operator<<(std::ostream& stream, const JSONException& rhs);
}
#endif