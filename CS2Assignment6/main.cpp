#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

void wordSearch(extern char** e);
vector<string> lines;
vector<string> words;
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
    cout<<"K: "<<k<<endl;

    wordSearch (environ);

    int pause;
    cin>>pause;
    return 0;
}
void wordSearch(char** e)//create an array of words to work with
{
    //VARIABLES
   string str=" ";//,line;
   int len= strlen(*e);

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
                /*for(vector<string>::const_iterator k = words.begin(); k != words.end(); ++k)
                {
                    cout << *k <<" " ;
                }*/
            }
            else
            {
                word.clear();
            }
        }                 
    }
   cout<<"TOTAL WORDS: "<<(int) words.size()<<endl;
   int jen=0, levi=0;

   for(jen=0; j<words.size(); jen++)
    {
        for(levi=0; levi<words.size()-1; levi++)
        {

        }
    }

}
