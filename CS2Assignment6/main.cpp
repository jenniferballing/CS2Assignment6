#include <iostream>
#include <sstream>
using namespace std;

void wordSearch(extern char**);
int main()
{
    extern char **environ; // needed to access your execution environment
    int k = 0;
   
    while (environ[k] != NULL)
    {
        //cout << environ[k] << endl;
        k++;
    }
    //cout<<"K: "<<k<<endl;

    wordSearch (environ);

    return 0;
}
void wordSearch(extern char** e)//create an array of words to work with
{
   int i=0, count=0;
   string str=" ",line;
   int len= strlen(*e);

   int counter=0;
   for(i=0; i<45; i++)
   {
       str+= *(e+i);
       counter++;
   }
  
   stringstream ss (str);   

   //CHECKING FOR POSSIBLE WORDS
         
   getline(ss, line);
   int len2= line.length();
   string arr[4000];
   for(int i=0; i<len2; i++)
   {
           
        if(isalnum(line[i])||line[i]=='_')
        {
            arr[i]=line[i];
        }
        else
        {
            arr[i]=' ';
        }
        cout<<arr[i];
    }
}