#include<iostream>
#include<string>

using namespace std;

int main()
{
    string str;
    getline(cin, str);

    int vow=0,co=0;

    for(int i=0;str[i]!='\0';i++)
    {
        if(str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u' || str[i]=='A' || str[i]=='E' || str[i]=='I' || str[i]=='O' || str[i]=='U')
        {
            vow++;
        }else if(str[i]>=65 && str[i]<=90 || str[i]>=90 && str[i]<=122){
            co++;
        }else{
            continue;
        }
    }

    cout<<"Vowels : "<<vow<<endl;
    cout<<"Consonants : "<<co<<endl;
    return 0;
}
