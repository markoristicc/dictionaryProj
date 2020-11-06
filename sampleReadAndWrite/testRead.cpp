#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "test.h"

using namespace std;

// Driver code for read from file
int main(int argc, char* argv[])
{
    cout<<"Reading from file..."<<endl;
    Test newObj = Test::readInput();
    cout<<"Printing Test object..."<<endl;
    newObj.print();

	return 0;
}
