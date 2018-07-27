/**
 *  @file		car.h
 *  @brief	  For initial testing	
 *  
 * 	Serve as an object to create for initial testing, not stress testing
 *  
 *  @author		Gabriel Shelton	sheltongabe
 *  @date		  07-19-2018
 *  @version	0.1
 */

#ifndef CAR_H
#define CAR_H

#include "json/jsonable.h"

/**
 * 	@class		Car
 * 	@brief		Defines the data and properties for a Car
 * 
 * 	Implements JSONAble so the data can easily be saved
 * 
 */
class Car : public json::JSONAble{
	public:
		/**
		 * 	@brief	Default Constructor
		 * 
		 * 	Details
		 * 
		 * 	@version	0.1
		 */
		Car();

		/**
		 * 	@brief	Initializing Constructor
		 * 
		 * 	Initialize the properties to the passed values
		 * 
		 * 	@version	0.1
		 */
		Car(int num_wheels, std::string model);

		/**
		 * 	@brief	Copy Constructor
		 * 
		 * 	Details
		 * 
		 * 	@version	0.1
		 */
		Car(Car& copy);

		/**
		 * 	@brief	Construct from a JSON map
		 *
		 * 	Take in a json::JSON map and build the car w/ properties
		 *
		 * 	@version 0.1
		 */
		Car(json::JSON json);

		/**
		 * 	@brief	Convert the cars properties to a string and return it
		 * 
		 * 	Take the properties of the car and convert them to a formatted string and return it
		 * 
		 * 	@return 	std::string		formatted string that shows the properties for the car
		 * 
		 * 	@version 0.1
		 */
		std::string toString();


		/**
		 * @brief	get the object in json form
		 * 
		 * 	Convert the object members to a JSON map and return
		 * 
		 * 	@version 0.1
		 */
		virtual json::JSON getJSON();


		/**
		 * 	@brief 	Destructor
		 * 
		 * 	Details
		 * 
		 * 	@version 0.1
		 */
		~Car();

	protected:
		/// number of wheels on the car
		int num_wheels;

		/// Model of the car
		std::string model;

	private:

};

#endif