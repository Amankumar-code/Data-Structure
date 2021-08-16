//naive approach
//Traverse every element and return index of first occuring character.
//Time Complexity : O(n^2)

#include<iostream>
#include<string>

using namespace std;

int leftMost(string str)
{
    for(int i=0;str[i]!='\0';i++)
    {
        for(int j=i+1;str[j]!='\0';j++)
        {
            if(str[i]!=' ') //ignore the empty space.
            {
                if(str[i]==str[j])
                {
                    return i;
                }
            }
        }
    }
    return -1;
};

int main()
{
    string str="a b b";

    cout<<leftMost(str)<<endl;

    return 0;
}
