/**
 *  @file		json_abstract_factory.h
 *  @brief	  Provide a basis for the types of for JSON
 *  
 * 	Provide the base Abstract Class for the JSONFactories
 *  
 *  @author		Gabriel Shelton	sheltongabe
 *  @date		  07-15-2018
 *  @version	0.1
 */

#ifndef JSON_ABSTRACT_FACTORY_H
#define JSON_ABSTRACT_FACTORY_H

namespace json {

	/**
	 * 	@class		JSONAbstractFactory
	 * 	@brief		Provide a base for building JSON types
	 * 
	 * 	Be overridden by the Children classes
	 * 
	 */
	class JSONAbstractFactory {
		public:
			/**
			 * 	@brief	Default Constructor
			 * 
			 * 	Build a default instance (Does Nothing)
			 * 
			 * @version	0.1
			 */
			JSONAbstractFactory();

			/**
			 * 	@brief	Copy Constructor
			 * 
			 * 	Copy the data from one instance to another (Does Nothing)
			 * 
			 * @version	0.1
			 */
			JSONAbstractFactory(JSONAbstractFactory& factory);

			/**
			 * @brief 	Return the default value for an integer
			 * 
			 * 	Be overridden by a child class to create and return a default integer
			 * 
			 * 	@version 0.1
			 */
			virtual int createInt() = 0;

			/**
			 * @brief	Destructor
			 * 
			 * 	Details
			 * 
			 * 	@version 0.1
			 */
			~JSONAbstractFactory();

		private:

	};
}
#endif