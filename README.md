# json_util
Utility program for c++ file i/o in a json format

-This program is designed to simplify the process of file saving and loading
of aggregate objects, by storing them in a json format.
-Most of the time I imagine this will be stored to a file however, given the json
is readable as a string at various points it could easily be manipulated at the users
will, such as streamed to a nodejs server.

<b>Install</b>
Install for the project should be fairly straight forward, depending on your setup.  
The simplest is one that mirrors that of a unix based system, which is how I myself
designed the library to be used and implemented.  My directories are for example:
	bin/				-> Any binary or executables generated
	build/			   -> All of the build and compile files, navigate to this and run "cmake .."
	docs/			   -> Where the documentation is stored
	include/		 -> Global include for your src too, and cmake will copy the required headers into a folder named json
	lib/				  -> Where the library is outputed, and any other libraries used would be placed
	src/				 -> Your source code for the project
		json/		    -> The source code for the json library
		...
	...

The idea is you copy the src/json/ directory into your src/, then just make sure you set the 
CMAKE_ARCHIVE_OUTPUT_DIRECTORY to lib/, and add_subdirectory for json/ in your src/.
An example can be this project.

Explantions out of the way, to directly copy this project and see an example in action:
git clone ...							  // Clone the project to a chosen directory
cd project								// Navigate into the project
mkdir build && cd build/	// make and navigate into the build directory
cmake ..								 // After confirming that the cmake settings are what you want run the cmake script
make									  // Compile the library, which will go into lib, and the executable which will go
												// into bin
make test							   // If you wish to run the tests

Now you have a fully functional example to work off of, and could feasibly copy the src/json/ folder into your
project