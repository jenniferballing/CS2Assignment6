#include <iostream>
#include <sstream>
using namespace std;

void wordSearch(extern char**);
int main()
{
    extern char **environ; // needed to access your execution environment
    int k = 0;
   
    /*while (environ[k] != NULL)
    {
        cout << environ[k] << endl;
        k++;
    }*/

    wordSearch (environ);

    return 0;
}
void wordSearch(extern char** e)
{
    char arr[10];
    for(int i=0; i<1; i++)
    {
        arr[i]=*e[i];
        cout<<arr[i];
    }
    string str(arr);

    string word;
    stringstream ss(str);
    ss>> word;
    //cout<<word;  
    
}