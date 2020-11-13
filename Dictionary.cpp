#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "hash24.h"
#include "Dictionary.h"

using namespace std;
Dictionary::Dictionary(string fname, int tsize)
{
    n = tsize;
    vector<vector<string>> allocation; //to keep track of primary hash
    allocation.resize(n);
    hashes.resize(n);
    int t;                           //used for inner table size
    string line = "";                //line to read from File
    int index;                       //index to be returned from hash(line)
    int *primarySlots = new int[21]; //primarySlots and max index keep track of primary table data
    int maxIndex = 0;
    int reHashes[21]; //rehashes used to keep track of amount of rehashes
    fill_n(reHashes,21,0);
    ifstream myfile(fname);
    if (myfile.is_open()){ // first loop assigns initial hashes 
        while (getline(myfile, line)){
            index = (h1.hash(line)) % n;
            allocation[index].push_back(line);
            count++;
        }
        myfile.close();
    }
    table.resize(n);
    for (int i = 0; i < count; i++)
    {
        t = allocation[i].size(); //amount of elements to be hashed in subtable
        table[i].resize(t*t);
        hashes[i] = new Hash24();
        int *indeces = new int[t]; // for wiping the table if there is a collision
        for (int j = 0; j < t; j++)
        {
            index = (hashes[i]->hash(allocation[i][j])) % (t * t);
            indeces[j] = index;
            if (table[i][index] == "") //if empty, go ahead
                table[i][index] = allocation[i][j];
            else //else use indeces to wipe table[i] efficiently
            {
                while (j >= 0)
                {
                    table[i][indeces[j]] = "";
                    j--;
                }
                reHashes[0]++; //because we aren't outputting if a func rehashes 0 times, use 0th element to store
                Hash24 *tmp = hashes[i];
                hashes[i] = new Hash24();
            }
        }
        if (reHashes[0] > 0 && reHashes[0] < 21) //if func rehashed between 1 and 20 times, increment rehashes index
        {
            reHashes[reHashes[0]]++;
            reHashes[0] = 0;
        }
        if (t < 21)
            primarySlots[t]++;
        if (t > maxIndex)
            maxIndex = i;
        delete[] indeces;
    } //end of 2nd loop
    //below is just output
    h1.dump();
    cout << "Number of words = " << count << endl;
    cout << "Table size = " << n << endl;
    cout << "Max collisions = " << allocation[maxIndex].size() << endl;
    for (int k = 0; k < 21; k++)
    {
        cout << "# of primary slots with " << k << " words = " << primarySlots[k] << endl;
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
    int index = h1.hash(word)%n;
    if(!(table[index].empty())){
        int tmp = index;
        index = hashes[index]->hash(word) % (table[index].size());
        if(table[tmp][index] == word)
            return true;
    }
    else return false;
    return false;
};
void Dictionary::writeToFile(string fname){
    ofstream myFile(fname);
    for(int i = 0; i < n; i++){
        if(!(table[i].empty())){
            for(int j = 0; j < table[i].size(); j++){
                if(table[i][j] != ""){
                    myFile.write(&(table[i][j][0]), table[i][j].length());
                    myFile<<endl;
                }
            }
        }
    }
};
Dictionary Dictionary::readFromFile(string fname){
    ifstream input(fname);
    int c = 0;
    ofstream toWrite("nice.txt");
    string line = "";
    while(getline(input, line)){
        c++;
        toWrite<<line<<endl;
    }
    return Dictionary("nice.txt", c);
};