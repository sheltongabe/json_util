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
#include <utility>

#include "json/json_file.h"
#include "json/json_parser.h"
#include "json/json_text_builder.h"
#include "car.h"

int main() {

	std::string FILE_NAME = "test.json";

	Car c(json::JSONFile::readJSON(FILE_NAME));
	std::cout << c.toString();

	Car c1;
	json::JSONFile::writeJSON(std::move("test_out1"), c1.getJSON());
	json::JSONFile::writeJSON(std::move("test_out2.json"), c1);

	return 0;
}