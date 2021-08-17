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

char peek()
{
    return head->data;
}

bool check(string brac)
{
    char x;

    for(int i=0;brac[i]!='\0';i++)
    {
        if(brac[i]=='{' || brac[i]=='(' || brac[i]=='[') //inserting all the opening brackets in stack
        {
            push(brac[i]);
            continue;
        }

        if(isEmpty())
        {
            return false;
        }

        switch(brac[i])
        {
            case ']':
                 x=peek();
                pop();
                if(x=='{' || x=='(')
                    return false;
                    break;
            
            case '}':
                 x=peek();
                pop();
                if(x=='[' || x=='(')
                    return false;
                    break;
            
            case ')':
                  x=peek();
                pop();
                if(x=='{' || x=='[')
                    return false;
                    break;
        }
    }

    return isEmpty();


}

int main()
{
    string brac="{}{}()[][]()";
    char x;

    if(check(brac))
    {
        cout<<"true";
    }else{
        cout<<"false";
    }

    return 0;
}
