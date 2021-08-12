#include<iostream>
#include<string>

using namespace std;

int main()
{
    int f=0;
    int len=0;
    char temp;

    string str="Hello Aman";

    cout<<"Orignal string : "<<str<<endl;

    //finding length of string
    for(int i=0;str[i]!='\0';i++)
    {
        len++;
    }

    len=len-1;

    for(int i=0;i<=len;i++)
    {
        temp=str[i];
        str[i]=str[len];
        str[len]=temp;
        len=len-1;
    }

    cout<<"Reverse String : "<<str<<endl;

    return 0;
}
