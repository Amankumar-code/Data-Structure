#include<iostream>
using namespace std;

//structure
struct node
{
    int data;
    struct node* next;
};


//function to insert node at end
struct node *insert(struct node* head,int data){
    struct node *curr;
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    curr=head;

    temp->data=data;
    temp->next=NULL;

    if(head==NULL){
        head=temp;
    }else{
        while(curr->next!=NULL){
            curr=curr->next;
        }
        curr->next=temp;
    }

    return head;
}

//function to print linked list elements
void print(struct node *head){
    struct node *curr=head;

    if(head==NULL){
        cout<<"Linked list is empty!!"<<endl;
        return;
    }
    while(curr){
        cout<<curr->data<<" ";
        curr=curr->next;
    }
}

//function to delete last element of linked list
void delAtEnd(struct node *head)
{
    struct node *curr=head;
    struct node *temp;

    if(head==NULL)
    {
        cout<<"LinkedList is already empty!"<<endl;
        return;
    }else{
        while(curr->next!=NULL){
            temp=curr;
            curr=curr->next;
        }
        temp->next=NULL;
        free(temp);
    }

}

//function to insert node at given position

struct node *insertAtPos(struct node *head,int pos,int data){
    struct node *curr=head;
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    struct node *prev;

    temp->data=data;
    temp->next=NULL;

    if(pos==1){
        temp->next=head;
        return temp;
    }

    if(head==NULL)
    {
        cout<<"Linked list is empty!"<<endl;
    }else{
        while(--pos){
            prev=curr;
            curr=curr->next;
        }
        temp->next=prev->next;
        prev->next=temp;

    }

    return head;
}

struct node *delAtBeg(struct node *head)
{

    if(head==NULL){
        cout<<"Linked list is empty"<<endl;
        return NULL;
    }

    struct node *temp=head;
    head=head->next;

    free(temp);

    return head;
}

struct node *delAtPos(struct node *head, int pos)
{
    struct node *prev=head;
    struct node *curr=head;

    if(head==NULL)
    {
        cout<<"Linked list is empty!"<<endl;
        return NULL;
    }else{
        while(--pos)
        {
            prev=curr;
            curr=curr->next;
        }
        prev->next=curr->next;
        free(curr);
    }

    return head;
}

int main()
{
    int len;
    int data;
    int choice=100;
    int pos;
    struct node *head=NULL;

    while(choice!=0)
    {

        cout<<"Enter your choice : \n1. Insert element in Linked List.\n2. Print Linked List.\n3. Insert at given position\n4. Delete First Node.\n5. Delete Last Node.\n6. Delete Node at Given Position."<<endl;
        cout<<"Enter 0 to exit."<<endl;
        cin>>choice;

        switch(choice)
    {
        case 1:
            cout<<"How many elements you want to insert : ";
            cin>>len;
            while(len!=0){
                cout<<"Enter data : "<<endl;
            cin>>data;

            head=insert(head,data);
            len--;
            }
            break;
        
        case 2:
            cout<<"Linked list : ";
            print(head);
            cout<<endl;
            break;

        case 3:
            cout<<"Enter position you want to enter data : ";
            cin>>pos;
            cout<<"Enter data : ";
            cin>>data;
            head=insertAtPos(head,pos,data);
            break;
        
        case 4:
            head=delAtBeg(head);
            break;
        
        case 5:
            delAtEnd(head);
            break;
        
        case 6:
            cout<<"Enter position which you want to remove : ";
            cin>>pos;
            head=delAtPos(head,pos);
            break;
        
        case 0:
            cout<<"Quitting...."<<endl;
            break;
            
        default:
            cout<<"Invalid choice!!"<<endl;
    }
    }

    return 0;
}
