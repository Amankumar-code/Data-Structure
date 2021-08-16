#include<iostream>
#include<string>

using namespace std;

string toLowerCase(string str)
{
    for(int i=0;str[i]!='\0';i++)
    {
        if(str[i]>= 65 && str[i]<=90) //converting only capital alphabats which is between 65-90
        {
            str[i]=str[i]+32; //converting them to lower case because lower case alphabats start from 97 and end at 122.
                              //So The difference between them is 32.
        }
    }

    return str;
};

int main()
{
    string str="MY NAME IS AMAN.";

    cout<<toLowerCase(str);
}
