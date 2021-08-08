#include<iostream>

using namespace std;

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};

void print(struct node *head)
{
    struct node *curr=head;

    if(head==NULL)
    {
        cout<<"Linked list is empty"<<endl;
        return;
    }else{
        while(curr){
            cout<<curr->data<<" ";
            curr=curr->next;
        }
    }
}

struct node *insertAtBeg(struct node *head,int data)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));

    temp->prev=NULL;
    temp->data=data;
    temp->next=NULL;

    if(head==NULL)
    {
        head=temp;
        return head;
    }else{
        temp->next=head;
        head->prev=temp;
        head=temp;
    }

    return head;
}

struct node *insertAtEnd(struct node *head,int data)
{
    struct node *curr=head;
    struct node *temp=(struct node*)malloc(sizeof(struct node));

    temp->prev=NULL;
    temp->data=data;
    temp->next=NULL;

    //base condition

    if(head==NULL)
    {
        head=temp;
        return head;
    }else{
        while(curr->next!=NULL){
            curr=curr->next;
        }
        curr->next=temp;
        temp->prev=curr;
    }
    return head;

}

struct node *insertAtPos(struct node *head,int data,int pos)
{
    struct node *curr=head;

    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->prev=NULL;
    temp->data=data;
    temp->next=NULL;

    pos=pos-1;
    //base condition
    if(pos==1)
    {
        head->prev=temp;
        temp->next=head;
        head=temp;
        return head;
    }else{
        while(--pos){
            curr=curr->next;
        }
        temp->next=curr->next;
        temp->prev=curr;
        if(curr->next){
            curr->next->prev=temp;
        }
        curr->next=temp;
    }
    return head;
}

int main()
{
   struct node *head=NULL;
    int data,choice=0,run,pos;

    while(choice!=5)
    {
        cout<<"Enter your choice: "<<endl;
        cout<<"1. Insert at beg\n2. Insert at last\n3. Insert at Pos\n4. Traverse\n5. To Exit"<<endl;
        cin>>choice;

        switch(choice)
        {
            case 1: 
                cout<<"How many data you want to insert: ";
                cin>>run;
                
                while(run--)
                {
                    cout<<"Enter data : ";
                    cin>>data;
                    head=insertAtBeg(head,data);
                }
                cout<<endl;
                break;
            
            case 2:
                cout<<"How many data you want to insert: ";
                cin>>run;
                
                while(run--)
                {
                    cout<<"Enter data : ";
                    cin>>data;
                    head=insertAtEnd(head,data);
                }
                cout<<endl;
                break;

            case 3:
                cout<<"Where you want to insert the element: ";
                cin>>pos;
                
                    cout<<"Enter data : ";
                    cin>>data;
                    head=insertAtPos(head,data,pos);
                cout<<endl;
                break;
            
            case 4:
                print(head);
                cout<<endl;
                break;
            
            case 5:
                cout<<"Quitting..."<<endl;
                break;
            
            default:
                cout<<"Enter a valid choice!!"<<endl;
                break;
        }
    }
    return 0;
}
