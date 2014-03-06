#include <iostream>
#include <sstream>
#include <string>
using namespace std;

void wordSearch(extern char** e);
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

    int pause;
    cin>>pause;
    return 0;
}
void wordSearch(extern char** e)//create an array of words to work with
{
    //VARIABLES
   int i=0, count=0;
   string str=" ",line;
   int len= strlen(*e);

   //PUT ARGUMENT INTO STRING FORM
   for(i=0; i<45; i++)
   {
       str+= *(e+i);
   }
   stringstream ss (str);   

   //CHECK FOR POSSIBLE WORDS- ELIMINATE ILLEGAL CHARACTERS     
   getline(ss, line);
   int len2= line.length();
   string PossWordArr[2000];
   for(int i=0; i<len2; i++)
   {           
        if(isalnum(line[i])||line[i]=='_')
        {
            PossWordArr[i]=line[i];
        }
        else
        {
            PossWordArr[i]=' ';
        }
   }

   //CHECKING FOR REAL WORDS
   string RealWordArr[100];
   string word=" ";
   int k=0, K=0, m=0, alpha;

   //PUT REAL WORDS INTO CHAR** ARRAY
   while(K<1187)//)
    {  
        word=PossWordArr[K-1];
        alpha=0;
        while (PossWordArr[K]!=" ")
        {
            word+=PossWordArr[K];
            K++;
            if(PossWordArr[K]>"A" &&PossWordArr[K]<"z")
            {
                alpha ++;
            }
        }
        
        if(PossWordArr[K]==" ")
        {
            int len = strlen(word.c_str());
            if(len>=3 && alpha>0)
            {
                RealWordArr[k]=word;
                cout<<"k: "<<k<<" "<<RealWordArr[k]<<endl;
                k++;                   
            }K++; 
        }    
    }

}
