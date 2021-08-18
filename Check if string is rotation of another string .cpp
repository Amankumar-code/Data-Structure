#include<iostream>
#include<string>

using namespace std;

bool check(string str,string rot)
{
    //finding length of both strings
    int len1=str.length();
    int len2=rot.length();

    char temp;

    //comparing both strings length
    if(len1!=len2)
    {
        return false;
    }

    //rotating string
    while(len1-1)
    {
        temp=str[len1-1];
        str.erase(len1-1);
        str=temp+str;

        //comparing both strings after rotation
        if(str==rot){
            return true;
        }else{
            continue;
        }
    }

    return false;
}

int main()
{
    string str="abcd";
    string rot="bcda";

    if(check(str,rot)){
        cout<<"True";
    }else{
        cout<<"False";
    }
    return 0;
}
