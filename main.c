#include<stdio.h>
#include<stdlib.h>

struct stack
{
    int size;
    int top;
    char *arr;
};

int empty(struct stack *ptr)
{
    if(ptr->top==-1)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

int full(struct stack *ptr)
{
    if(ptr->top==ptr->size-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(struct stack *ptr , char value)
{
    if(full(ptr))
    {
        printf("the stack is full\n");
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top]=value;
    }
}

char pop(struct stack *ptr)
{

    if(empty(ptr))
    {
        printf("the stack is empty\n");
        return -1;
    }
    else
    {
        char value=ptr->arr[ptr->top];
        ptr->top--;
        return value;
    }



}


char top(struct stack *sp)
{
    return sp->arr[sp->top];
}




int match( char a,char b)
{
    if(a=='{'&&b=='}')
    {
        return 1;
    }
    if(a=='('&&b==')')
    {
        return 1;
    }
    if(a=='['&&b==']')
    {
        return 1;
    }
    return 0;
}



int paranthesis_match(char *exp)
{
    struct stack * sp;
    sp->size=100;
    sp->top=-1;
    sp->arr=(char *)malloc(sp->size*sizeof(char));

    char popout;

    for(int i=0;exp[i]!='\0';i++)
    {
        if(exp[i]=='('||exp[i]=='{'||exp[i]=='[')
        {
            push(sp,exp[i]);
        }
        else if(exp[i]==')'||exp[i]=='}'||exp[i]==']')
        {
            if(empty(sp))
            {
                return 0;
            }
            popout=pop(sp);
            if(!match(popout,exp[i]))
            {
                return 0;
            }
        }
    }

    if(empty(sp))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


int main()
{
    char *exp="[({9}-[5])]";

    if(paranthesis_match(exp))
    {
        printf("Valid paranthasis\n");
    }
    else
    {
        printf("Not valid paranthesis\n");
    }



}