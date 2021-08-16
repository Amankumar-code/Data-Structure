#include<iostream>
#include<string>

using namespace std;

string toLowerCase(string str)
{
    for(int i=0;str[i]!='\0';i++)
    {
        if(str[i]>= 97 && str[i]<=122) //converting only lower case alphabats which is between 97-122
        {
            str[i]=str[i]-32; //converting them to captial letter because capital letters start from 65 and end at 90.
                              //So The difference between them is 32.
        }
    }

    return str;
};

int main()
{
    string str="my name is aman.";

    cout<<toLowerCase(str);
}
