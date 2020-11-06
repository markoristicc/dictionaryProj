#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "test.h"

using namespace std;

Bucket::Bucket() {
    hash_a = 0;
    hash_b = 0;
    bsize = 0;
}

Bucket::Bucket(int a, int b, int c) {
    hash_a = a;
    hash_b = b;
    bsize = c;
}



Test::Test() {

}

Test::Test(string name1, int a1, int b1, int p1, int tsize1, vector<Bucket> buckets1) {
    name = name1;
    str_len = name.length();
    a = a1;
    b = b1;
    p = p1;
    tsize = tsize1;
    buckets = buckets1;
}

void Test::initialize() {
    name = "hello";
    str_len = name.length();
    a = 10;
    b = 5;
    p = 11;
    tsize = 5;
    buckets.resize(tsize);
    for (int i = 0; i < tsize; i++)
    {
        Bucket temp(a, b, i+1);
        buckets[i] = temp;
    }
}

void Test::writeOutput() {
    ofstream file_obj;
    file_obj.open("input.txt", ios::out | ios::trunc);
    file_obj.write((char*)&str_len, sizeof(str_len));
    file_obj.write(name.c_str(), str_len);
    file_obj.write((char*)&a, sizeof(a));
    file_obj.write((char*)&b, sizeof(b));
    file_obj.write((char*)&p, sizeof(p));
    file_obj.write((char*)&tsize, sizeof(tsize));
    for (int i = 0; i < tsize; i++)
    {
        file_obj.write((char*)&buckets[i], sizeof(buckets[i]));
    }

    file_obj.close();
    return;
}

void Test::print() {
    cout<<"name: "<<name<<endl;
    cout<<"str_len: "<<str_len<<endl;
    cout<<"a: "<<a<<endl;
    cout<<"b: "<<b<<endl;
    cout<<"p: "<<p<<endl;
    cout<<"tsize: "<<tsize<<endl;
    for (int i = 0; i < tsize; i++)
    {
        cout<<"Bucket "<<i<<" : "<<buckets[i].hash_a<<" "<<buckets[i].hash_b<<" "<<buckets[i].bsize<<endl;
    }
}
