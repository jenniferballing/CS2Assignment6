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
   //cout<<e[0]<<endl<<endl;
   //cout<<*(e+40)<<endl<<endl;
   //cout<<*(*e)<<endl<<endl;
   int i=0, count=0;
   string str=" ",line;//, line2, line3, line4;
   //char *tr=e;
   int len= strlen(*e);
   //cout<<"LEN: "<<len<<endl;

   int counter=0;
   //cout<<"LEN: "<<endl;
   for(i=0; i<44; i++)
   {
       str+= *(e+i);
       cout<<str<<endl<<endl;
       counter++;
   }
  // cout<<"Counter: "<<counter<<endl;
   //cout<<"Before SS: "<<str<<endl;
   stringstream ss (str);
   //cout<<endl<<endl<<"After SS: "<<str<<endl;//doesn't have all of the file
   

   //CHECKING FOR POSSIBLE WORDS
         
   getline(ss, line);//possibly reading whole file without error
   int len2= line.length();
   string arr[3000];
   cout<<"LEN2: "<<len2<<endl;
   
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
           // cout<<arr[i];
            
            count++;
       }
     //  cout<<endl<<"COUNT:"<<count<<endl;
}