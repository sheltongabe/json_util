/**
 * @file 		main.cpp
 * @brief	  serve as the entry point of the program
 * 
 * 
 * 
 * @author		Gabriel Shelton		sheltongabe
 * @date 		  07-28-2018
 * @version		0.1
 */

#include <iostream>
#include <utility>
#include <random>

// Include JSON headers
#include "json/json_file.h"

#include "test_object.h"

int main(int argc, char **argv) {
	// Setup for random
	std::mt19937 rng;
	rng.seed(std::random_device()());

	int testNum = (argc == 1)? 0 : std::stoi(std::string(argv[1]));

	// Test TestObject
	TestObject object1(rng);
	json::JSONFile::writeJSON(std::move("object.json"), object1);

	TestObject object2(json::JSONFile::readJSON(std::move("object.json")));

	if(object1 != object2)
		return 1;

	return 0;
}