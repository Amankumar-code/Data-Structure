#include<iostream>
#include<string>

using namespace std;

int main()
{
    string str;
    getline(cin,str);
    int count=0;

    for(int i=0;str[i]!='\0';i++)
    {
        count=0;
        for(int j=i+1;str[j]!='\0';j++)
        {
            
            if(str[i]==str[j] && str[i]!=' ')
            {
                str[j]='0';
                count++;
            }
        }

        if(count>0 && str[i]!='0')
        {
            cout<<str[i]<<" ";
        }
    }

    return 0;
}
