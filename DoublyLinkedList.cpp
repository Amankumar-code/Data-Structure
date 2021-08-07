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
    
    if(head==NULL){
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

void printBack(struct node *head)
{
    struct node *curr=head;
    
     if(head==NULL)
     {
         cout<<"Linked list is empty!"<<endl;
         return;
     }else{
         while(curr->next!=NULL)
         {
             curr=curr->next;
         }
         
         while(curr)
         {
             cout<<curr->data<<" ";
             curr=curr->prev;
         }
     }
}

int main()
{
    int choice=100;
    int data;
    int run;
    struct node *head=NULL;
    
    while(choice!=4)
    {
        
        cout<<"Enter your choice: "<<endl;
        cout<<"1. Insert element\n2. Traverse\n3. Traverse(Reversed)\n4. To Exit"<<endl;
    
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
                cout<<"Linked list : ";
                print(head);
                cout<<endl;
                break;
            
            case 3:
                cout<<"Reversed Linked list : ";
                printBack(head);
                cout<<endl;
                break;
            
            case 4:
                cout<<"Quitting...."<<endl;
                break;
            
            default:
                cout<<"Enter a valid choice!!"<<endl;
                break;
        }
        
    }
    
    return 0;
}
