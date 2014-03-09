#ifndef WORDOBJ_H
#define WORDOBJ_H
#include<iostream>
#include<string>
#include <vector>

using namespace std;

class WordObj
{
    string name;
    vector<string> line;
    int count;
public:
    WordObj(void);
    WordObj(string, int);
    void addLine(string);
    void setName(string);
    void setCount(int);
    vector<string> getLine();
    string getName();
    int getCount();
    ~WordObj(void);
};
#endif
