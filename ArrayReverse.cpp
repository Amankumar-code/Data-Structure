#include<iostream>
using namespace std;

int main()
{
    int arr[]={1,2,3,4,5,6,7,8,9,10};
    int len=sizeof(arr)/sizeof(arr[0]);
    int front,back;

    int a;

    cout<<"Orignal array : ";
    for(int i=0;i<len;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    

    //reverse array
    int i=0,j=len-1;
    while(i<j)
    {
        front=arr[i];
        back=arr[j];

        arr[i]=back;
        arr[j]=front;

        i++;
        j--;
    }


    cout<<"Reversed array : ";
    for(int i=0;i<len;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}
