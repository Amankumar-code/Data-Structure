#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node* next;
};

struct node *insert(struct node *head,int data){
    struct node *curr;

    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->next=NULL;

    curr=head;

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

void printList(struct node *head){

    struct node *curr=head;
    if(head==NULL){
        cout<<"Linked list is empty!!"<<endl;
    }else{
        while(curr){
            cout<<curr->data<<" ";
            curr=curr->next;
        }
    }
}

struct node *del(struct node *head){
    struct node *curr=head;
    struct node *temp;

    if(head==NULL){
        cout<<"Linked list is already empty!!";
    }else if(head->next==NULL){
        head=NULL;
        free(head);
    }else{
        while(curr->next!=NULL){
            temp=curr;
            curr=curr->next;
        }
        temp->next=NULL;
        free(temp);
    }
    return head;
}


int main()
{
    struct node *head=NULL;

    head=insert(head,10);
    head=insert(head,20);
    head=insert(head,30);
    head=insert(head,40);
    head=insert(head,50);
    head=insert(head,60);

    printList(head);
    del(head);
    printList(head);

    return 0;
}
