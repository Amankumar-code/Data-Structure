#include<iostream>
#include<string>

using namespace std;

struct node
{
    char data;
    struct node *next;
};

//global variables
struct node *head=NULL;
bool res;

void push(char brac)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));

    temp->data=brac;

    if(head==NULL)
    {
        head=temp;
        return;
    }else{
        temp->next=head;
        head=temp;
    }
}

void pop()
{
    struct node *curr=head;

    if(head==NULL)
    {
        cout<<"False"<<endl;
        exit(0); //special condition: if there is exta closing bracket
    }else{
        head=head->next;
        free(curr);
    }
}

bool isEmpty()
{
    if(head==NULL)
    {
        return true;
    }else{
        return false;
    }
}

int main()
{
    string brac="(()))";

    for(int i=0;brac[i]!='\0';i++)
    {
        if(brac[i]=='{' || brac[i]=='(' || brac[i]=='[') //inserting all the opening brackets in stack
        {
            push(brac[i]);
        }
    }

    
    for(int i=0;brac[i]!='\0';i++)
    {
        if(brac[i]=='}' || brac[i]==')' || brac[i]==']') //pop all the matching brackets.
        {
            pop();
        }
    }

    if(isEmpty()) //if stack is empty then return true else false
    {
        cout<<"True"<<endl;
    }else{
        cout<<"False"<<endl;
    }

    return 0;
}
