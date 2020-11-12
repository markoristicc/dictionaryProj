#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "hash24.h"
#include "Dictionary.h"

using namespace std;
Dictionary::Dictionary(string fname, int tsize)
{
    vector<vector<string>> allocation; //to keep track of primary hash
    Hash24 h1;
    n = tsize;
    int t;                           //used for inner table size
    string line = "";                //line to read from File
    int index;                       //index to be returned from hash(line)
    int *primarySlots = new int[21]; //primarySlots and max index keep track of primary table data
    int maxIndex = 0;
    int reHashes[21]; //rehashes used to keep track of amount of rehashes
    ifstream myfile(fname);
    if (myfile.is_open()){
        while (getline(myfile, line)){
            index = h1.hash(line) % n;
            allocation[index].push_back(line);
            count++;
        }
        myfile.close();
    }
    table.resize(count);
    for (int i = 0; i < count; i++)
    {
        t = allocation[i].size(); //amount of elements to be hashed in subtable
        table[i] = new string[t * t];
        hashes[i] = new Hash24();
        for (int j = 0; j < t; j++)
        {
            int *indeces = new int[t]; // for wiping the table if there is a collision
            index = (hashes[i]->hash(allocation[i][j])) % (t * t);
            indeces[j] = index;
            if (table[i][index] != "")
                table[i][index] = allocation[i][j];
            else
            {
                while (j >= 0)
                {
                    table[i][indeces[j]] = "";
                    j--;
                }
                reHashes[0]++;
                Hash24 *tmp = hashes[i];
                hashes[i] = new Hash24();
                delete tmp;
            }
        }
        if (reHashes[0] > 0 && reHashes[0] < 21)
        {
            reHashes[reHashes[0]]++;
        }
        if (t < 21)
            primarySlots[t]++;
        if (t > maxIndex)
            maxIndex = i;
    }
    h1.dump();
    cout << "Number of words = " << count << endl;
    cout << "Table size = " << n << endl;
    cout << "Max collisions = " << allocation[maxIndex].size() << endl;
    for (int k = 0; k < 21; k++)
    {
        cout << "# of primary slots with " << k << " words = " << primarySlots[k];
    }
    cout << "*** Words in the slot with the most collisions ***" << endl;
    for (int k = 0; k < allocation[maxIndex].size(); k++)
    {
        cout << allocation[maxIndex][k] << endl;
    }
    double sum = 0;   //used for average # of rehashes
    double randy = 9; //^^
    for (int k = 1; k < 21; k++)
    {
        cout << "# of secondary hash tables trying " << k << " hash functions = " << reHashes[k] << endl;
        sum += reHashes[k] * k;
        randy += reHashes[k];
    }
    cout << "Average # of hash functions tried = " << (sum / randy) << endl;
};
bool Dictionary::find(string word)
{
    return true;
};
void Dictionary::writeToFile(string fname){

};
void Dictionary::readFromFile(string fname){};