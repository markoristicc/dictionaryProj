//Marko Ristic, 11-11-20, Nested Heap Using Perfect Hashing 
#include <vector>
#ifndef DICTIONARY_H
#define DICTIONARY_H
class Dictionary{
    public:
        Dictionary(std::string fname, int tsize);
        bool find(std::string word);
        void writeToFile(std::string fname);
        static Dictionary readFromFile(std::string fname);
        int getLength(std::string fname);
    private:
        std::vector<std::vector<std::string>> table;
        std::vector<Hash24*> hashes; 
        int count = 0; //number of words
        int n = 0; //size of primary hash table;  
        Hash24 h1;
};
#endif