#include "WordObj.h"


WordObj::WordObj(void)
{
    name=" ";
    count = 0;
}
WordObj::WordObj(string n, int c)
{
    name=n;
    count=c;
}
void WordObj::setName(string n)
{
    name = n;
}
void WordObj::setCount(int c)
{
    count = c;
}
void WordObj::addLine(string l)
{
    line.insert(line.end(), l);
}
vector<string> WordObj::getLine()
{
    return line;
}
string WordObj::getName()
{
    return name;
}
int WordObj::getCount()
{
    return count;
}
WordObj::~WordObj(void)
{
}
