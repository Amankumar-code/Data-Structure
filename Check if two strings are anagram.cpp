#include<iostream>
#include<string>

using namespace std;

int main()
{
    string str1="o evil you";
    string str2="i love you";

    bool res=false;

    for(int i=0;str1[i]!='\0';i++) // NOTE : '\0' denote end of String
    {
        res=false;

        for(int j=0;str2[j]!='\0';j++)
        {

            if(str1[i] == str2[j])
            {
                str2[j]='0'; //if match found then replace that char with 0 to mark them visited
                res=true;    //if match found mark true
                break;       //break the loop
            }
        }
        if(res==false){  // after running second loop if res is still false that means match not found and strings is not anagram
            break;
        }
    }
    

    if(res==false){
        cout<<"String is not anagram"<<endl;
    }else{
        cout<<"String is anagram"<<endl;
    }
    return 0;
}
