//Deletion on doubly linked list

#include<iostream>
using namespace std;


struct node
{
    struct node *prev;
    int data;
    struct node *next;
};

struct node *insert(struct node *head,int data)
{
    struct node *curr=head;
    struct node *temp=(struct node*)malloc(sizeof(struct node));

    temp->prev=NULL;
    temp->data=data;
    temp->next=NULL;

    if(head==NULL)
    {
        head=temp;
        return head;
    }else{
        while(curr->next!=NULL)
        {
            curr=curr->next;
        }
        temp->prev=curr;
        curr->next=temp;
    }
    return head;
}

void print(struct node *head)
{
    struct node *curr=head;

    if(head==NULL)
    {
        cout<<"Linked list is empty!"<<endl;
        return;
    }else{
        while(curr)
        {
            cout<<curr->data<<" ";
            curr=curr->next;
        }
    }
}

struct node *delAtEnd(struct node *head){
    struct node *curr=head;
    struct node *p=head;

    if(head==NULL)
    {
        cout<<"Linked list is empty!"<<endl;
        return head;
    }
    if(head->next==NULL)
    {
        free(head);
        return NULL;
    }else{
        while(curr->next!=NULL)
        {
            curr=curr->next;
        }
        p=curr->prev;
        p->next=curr->next;
        free(curr);
    }

    return head;
}

struct node *delAtBeg(struct node *head)
{
    struct node *curr=head;

    if(head==NULL )
    {
        cout<<"Linked list is empty!"<<endl;
        return head;
    }

    if(head->next==NULL)
    {
        free(head);
        return NULL;
    }

    head=head->next;
    head->prev=NULL;
    free(curr);

    return head;
}

struct node *delAtPos(struct node *head,int pos)
{
    struct node *curr=head;
    struct node *p=head;

    if(head==NULL)
    {
        cout<<"Linked list is empty"<<endl;
        return head;
    }
    if(pos==1){
        head=head->next;
        free(head);
        return head;
    }else{
        while(--pos){
            curr=curr->next;
        }
        p=curr->prev;
        p->next=curr->next;
        if(curr->next){
            curr->next->prev=p;
        }
        free(curr);
    }
    
    return head;
}

int main()
{
    struct node *head=NULL;
    int data,choice=0,run,pos;

    while(choice!=6)
    {
        cout<<"Enter your choice: "<<endl;
        cout<<"1. Insert\n2. Delete last node\n3. Delete first node\n4. Delete Particular Node\n5. Traverse\n6. To Exit"<<endl;
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
                    head=insert(head,data);
                }
                cout<<endl;
                break;
            
            case 2:
                head=delAtEnd(head);
                break;

            case 3:
                head=delAtBeg(head);
                break;
            
            case 4:
                cout<<"Which node you want to delete : "<<endl;
                cin>>pos;
                head=delAtPos(head,pos);
                break;
            
            case 5:
                print(head);
                cout<<endl;
                break;
            
            case 6:
                cout<<"Quitting..."<<endl;
                break;
            
            default:
                cout<<"Enter a valid choice!!"<<endl;
                break;
        }
    }
    return 0;
}
