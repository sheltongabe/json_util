/**
 * @file 		json_util_test.cpp
 * @brief	  serve as the entry point of the program
 * 
 * 
 * 
 * @author		Gabriel Shelton		sheltongabe
 * @date 		  07-29-2018
 * @version		0.5
 */

#include <iostream>
#include <utility>
#include <random>
#include <string>
#include <sys/stat.h>

// Include JSON headers
#include "json_util/json_file.h"

#include "test_object.h"

int main(int argc, char **argv) {
	// Setup for random
	std::mt19937 rng;
	rng.seed(std::random_device()());

	int testNum = (argc != 2)? 0 : std::stoi(std::string(argv[1]));

	// ----- Tests -----
	// Test TestObject
	TestObject object1(rng);
	json::JSONFile::writeJSON(std::move("object.json"), object1);

	TestObject object2(json::JSONFile::readJSON(std::move("object.json")));

	std::cout << "object1 == object2: " << (object1 == object2) << std::endl;

	if(object1 != object2) {
		// Create the fail directory
		std::string dirName = std::move("fail_");
		dirName += std::to_string(testNum);
		if(mkdir(dirName.c_str(), 
				S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH) == -1) {
			std::cout << "Failed to create dir" << std::endl;
		}

		// write fails
		json::JSONFile::writeJSON((dirName + "/in.json").c_str(), object1);
		json::JSONFile::writeJSON((dirName + "/out.json").c_str(), object2);
		return 1;
	}

	return 0;
}