#ifndef TEST_H
#define TEST_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;


class Bucket {
public:
    int hash_a;
    int hash_b;
    int bsize;

    Bucket();
    Bucket(int a, int b, int c);
};

class Test {
public:
	string name;
    size_t str_len;
	int a;
    int b;
    int p;
    int tsize;
    vector<Bucket> buckets;

    Test();
    Test(string name1, int a1, int b1, int p1, int tsize1, vector<Bucket> buckets1);
    void initialize();

	static Test readInput() {
        ifstream file_obj;
        file_obj.open("input.txt", ios::in | ios::binary);
        // file_obj.seekg(0, ios::end);
        // int size = file_obj.tellg();
        // cout<<"Read size: "<<size<<endl;
        // file_obj.seekg(0, ios::beg);
        size_t str_len;
        file_obj.read((char*)&str_len, sizeof(str_len));
        // Read string
        char* strData = new char[str_len];
        file_obj.read(strData, str_len);
        string name(strData);
        // Read int variables
        int a;
        file_obj.read((char*)&a, sizeof(a));
        int b;
        file_obj.read((char*)&b, sizeof(b));
        int p;
        file_obj.read((char*)&p, sizeof(p));
        int tsize;
        file_obj.read((char*)&tsize, sizeof(tsize));
        // cout<<"name: "<<name<<endl;
        // cout<<"str_len: "<<str_len<<endl;
        // cout<<"a: "<<a<<endl;
        // cout<<"b: "<<b<<endl;
        // cout<<"p: "<<p<<endl;
        // cout<<"tsize: "<<tsize<<endl;
        // Read vector
        vector<Bucket> buckets(tsize);
        for (int i = 0; i < tsize; i++)
        {
            Bucket temp;
            file_obj.read((char*)&temp, sizeof(temp));
            // cout<<"Bucket "<<i<<" : "<<temp.hash_a<<" "<<temp.hash_b<<" "<<temp.bsize<<endl;
            buckets[i] = temp;
        }
        file_obj.close();
        Test* temp = new Test(name, a, b, p, tsize, buckets);
        return *temp;
    }

    void writeOutput();
    void print();
};

#endif