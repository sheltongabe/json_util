/**
 * @file 		main.cpp
 * @brief	  serve as the entry point of the program
 * 
 * 
 * 
 * @author		Gabriel Shelton		sheltongabe
 * @date 		  07-19-2018
 * @version		0.1
 */

#include <iostream>

#include "json_file.h"

int main() {

	std::string FILE_NAME = "test.json";
	std::cout << json::JSONFile::read(FILE_NAME) << std::endl;

	return 0;
}