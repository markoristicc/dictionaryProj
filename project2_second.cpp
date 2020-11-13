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
    Dictionary h = h.readFromFile(argv[1]); //lol wtf
    string delimiter = ", ";
    size_t pos = 0;
    string tmp;
    string s = argv[2];
    while ((pos = s.find(delimiter)) != string::npos) {
        tmp = s.substr(0, pos);
        if(h.find(tmp))
            cout<<tmp<<" found"<<endl;
        else cout<<tmp<<" not found"<<endl;
        s.erase(0, pos + delimiter.length());
    }
    if(h.find(s))
        cout<<s<<" found"<<endl;
    else cout<<s<<" not found"<<endl;
        return 1;
}