#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node* next;
};

struct node *insert(struct node *head,int data)
{
    struct node *curr=head;
    struct node *temp=(struct node*)malloc(sizeof(struct node));

    temp->data=data;
    temp->next=NULL;

    if(head==NULL)
    {
        head=temp;
        return head;
    }else{
        while(curr->next!=NULL){
            curr=curr->next;
        }
        curr->next=temp;
    }

    return head;
}

void fibonacci(struct node *head,int len)
{
    int temp=0;
    int a;

    if(len==0){
        return;
    }
        
    else{

        while(len--)
        {
            cout<<head->data<<" ";
            a=head->data;
            head->data=head->data+temp;
            temp=a;
        }

    }
}

int main()
{
    struct node *head=NULL;

    int len;
    head=insert(head,1);
    
    cout<<"How much pallidrome number you want : ";
    cin>>len;
    
    fibonacci(head,len);
    return 0;
}
