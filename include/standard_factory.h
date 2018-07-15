/**
 *  @file		standard_factory.h
 *  @brief	  Implement how to build standard JSON types, and store its defaults	
 *  
 * 	Store the default values for json types and create them on demand
 *  
 *  @author		Gabriel Shelton	sheltongabe
 *  @date		  07-15-2018
 *  @version	0.1
 */

#ifndef STANDARD_FACTORY_H
#define STANDARD_FACTORY_H

#include "json_abstract_factory.h"

namespace json {
	/**
	 * 	@class		StandardFactory
	 * 	@brief		Extend and implement JSONAbstractFactory to create standard Json types
	 * 
	 * 	Overrides all of the methods in JSONAbstractFactory and returns the default value stored
	 * 	and modified in the source file
	 * 
	 */
	class StandardFactory : public JSONAbstractFactory {
		protected:
			/// stores default values for the different types
			static std::map<std::string, JSONValue> DEFAULT_VALUES;

		public:
			/**
			 * 	@brief	Default Constructor
			 * 
			 * 	Initialize the base version of the class
			 * 
			 * 	@version	0.1
			 */
			StandardFactory();

			/**
			 * 	@brief	Copy Constructor
			 * 
			 * 	Copy another version of a StandardFactory
			 * 
			 * 	@version	0.1
			 */
			StandardFactory(StandardFactory& copy);

			/**
			 * @brief 	Return the default value for an integer
			 * 
			 * 	
			 * 
			 * 	@version 0.1
			 */
			virtual int createInt();

			/**
			 * @brief	Destructor
			 * 
			 * 
			 * 
			 * 	@version 0.1
			 */
			~StandardFactory();

		private:

	};
}
#endif