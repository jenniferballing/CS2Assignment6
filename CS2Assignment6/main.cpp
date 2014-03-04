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
        cout << environ[k] << endl;
        k++;
    }
    cout<<endl;

    wordSearch (environ);

    return 0;
}
void wordSearch(extern char** e)
{
   char* temp[45]={0, 0};
   int i=0;
   char* word="jen";
   
   for(i=0; i<45; i++)
   {
       temp[i]=e[i];
       string str;
       str+= temp[i];
       cout<<str<<endl;
       if(strcmp(word, temp[i])!=0)
        {
            cout<<"Found a match!"<<endl;
        }
   }
   

}