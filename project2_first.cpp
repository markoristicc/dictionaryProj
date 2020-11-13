#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
#include "hash24.h"
#include "Dictionary.h"

using namespace std;

int main(int argc, char *argv[]){
    if(argc != 3)
        cerr<<"Please enter the correct amout of arguments"<<endl;
    Dictionary h = Dictionary(argv[1], 10000);
    h.writeToFile(argv[2]);
        return 1;
}