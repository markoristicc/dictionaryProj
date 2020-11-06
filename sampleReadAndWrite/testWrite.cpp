#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "test.h"

using namespace std;



// Driver code for write to file
int main(int argc, char* argv[])
{
	// Creating object of the class
	Test object;
	cout<<"Initializing Test class object..."<<endl;
    object.initialize();
    object.print();
	object.writeOutput();


	return 0;
}
