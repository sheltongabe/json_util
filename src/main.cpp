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

#include "json/json_file.h"
#include "json/json_parser.h"
#include "json/json_text_builder.h"
#include "car.h"

int main() {

	std::string FILE_NAME = "test.json";
	std::string testJson = json::JSONFile::read(FILE_NAME);

	json::JSON j = json::JSONParser::parse(testJson);

	Car c;
	std::string defaultJSONText = json::JSONTextBuilder::parse(c.getJSON());
	json::JSONFile::write(std::move("test_out.json"), defaultJSONText);

	return 0;
}