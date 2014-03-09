#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include "WordObj.h"

using namespace std;

void wordSearch(extern char** e);
vector<string> lines;
vector<string> words;
vector<string> tempWords;
vector<WordObj> obVec;
vector<string> foundLines;
int main()
{
    extern char **environ; // needed to access your execution environment
    int k = 0;
    //cout<<"ACTUAL INFORMATION:"<<endl;
    while (environ[k] != NULL)
    {
        
        //cout << environ[k] << endl;
        k++;
    }
    wordSearch (environ);

    int pause;
    cin>>pause;
    return 0;
}
void wordSearch(char** e)
{
    //VARIABLES
   string str=" ";//,line;
   int len= strlen(*e);
   WordObj arr[200];
   WordObj obj;
   string input;

   //PUT ARGUMENT INTO STRING FORM
   while(*e!=NULL)
   {
       lines.insert(lines.end(), *(e));
       str+= *(e++);
   }
   str+=" ";
   string word;
   int j=0;
   int alpha=0;
   int i=0;
   for(i=0; i<str.length(); i++)
   {
        char temp=str[i];
        if(!isalpha (temp) && !isdigit(temp) && temp!='_')//(temp>0&&temp<65) || (temp<90 && temp< 97 ) || (temp >122))//ELIMINATE ILLEGAL CHARS
        {
            temp= ' ';
        }
        if(temp!=' ')
        {
            word+=temp;
        }
        if((temp>64 && temp <91) || (temp>96 && temp<123))//CHECK FOR ENOUGH LETTERS FOR WORD
        {
            alpha ++;
        }            
        if(temp == ' ')
        {
            if(word.length()>1 && alpha>0)//LONG ENOUGH WITH ENOUGH LETTERS
            {
                alpha=0;
                words.insert(words.end(), word);
                word.clear();
            }
            else
            {
                word.clear();
            }
        }                 
    }
   int z;
   int num= words.size();
   cout<<"TOTAL NUMBER OF WORDS: "<<(int) words.size()<<endl<<endl<<endl;
   
   int jen=0, levi=0, iter=0, count=0;
   string sub, n, sub2;
   for(z=0; z<num; z++)//CREATE TEMP VECTOR
    {
        tempWords.insert(tempWords.end(), words[z]);
    }   
   for(jen=0; jen<num; jen++)//SEARCH FOR DUPLICATES
    {
        sub=tempWords[jen];
        for(levi=0; levi<num; levi++)
        {
            if(tempWords[levi]==sub)
            {
                count++;
                if(jen!=levi)
                {
                    tempWords[levi]==" "; 
                }
            }
        }
        obj.setCount(count);
        count=0;
        obj.setName(sub);
        bool exists=false;
        for(i=0; i<obVec.size(); i++)
        {
            if(obVec[i].getName()==sub)
            {
                exists=true;
                break;
            }
        }
        if(exists!=true)
        {
            obVec.insert(obVec.end(), obj);
            cout<<"Name: "<<obj.getName()<<endl;
            cout<<"Number of occurences: "<<obj.getCount()<<endl<<endl;
        }
    }
    for(i=0; i<lines.size(); i++)
    {
        int j=0;
        for(j=0; j<tempWords.size(); j++)
        {
            if(lines[i].find(tempWords[j]))
            {
                //foundLines.insert(foundLines.end(), lines[i]);
                obj.addLine(input);
            }
        }
    }
    for(i=0; i<lines.size(); i++)
    {
        tempWords[i]=lines[i];
    }
    cout<<"PART TWO: USER INFO: "<<endl<<endl;
    int count2=0;
    while (input!="end")
    {
        cout<<"Please enter the search string..."<<endl;
        cin>>input;
            transform(input.begin(), input.end(), input.begin(), ::tolower);
            for(z=0; z<tempWords.size(); z++)
            {
                transform(tempWords[z].begin(), tempWords[z].end(), tempWords[z].begin(), ::tolower);
            }
        cout<<"Your search string was found in the following lines: "<<endl<<endl;
        for(i=0; i<lines.size(); i++)
        {        
            string templine= lines[i];
            transform (templine.begin(), templine.end(), templine.begin(), ::tolower);
            if(templine.find(input)!=string::npos)
            {
                count++;
                cout<<lines[i]<<endl<<endl;
            }
        }cout<<"Your search occurs: "<<count<<" time(s)."<<endl<<endl;
        count=0;
    }
}