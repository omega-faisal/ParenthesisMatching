#include <stdio.h>
#include <stdlib.h>
struct stack
{
    int size;
    int top;
    char *arr;
};
int isempty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isfull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void push(struct stack *ptr, char data)
{

    ptr->top++;
    ptr->arr[ptr->top] = data;
}
char pop(struct stack *ptr)
{

    char data;
    data = ptr->arr[ptr->top];
    ptr->top--;
    return data;
}
int stacktop(struct stack *ptr)
{
    return ptr->arr[ptr->top];
}
int match(char a,char b)
{
    if(a=='(' && b==')')
    {
        return 1;
    }
    if(a=='{' && b=='}')
    {
        return 1;
    }
    if(a=='[' && b==']')
    {
        return 1;
    }
    else{
        return 0;
    }

}
int parenCheck(char *exp)
{
    struct stack *sp=(struct stack*)malloc(sizeof(struct stack));
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    for (int i = 0; exp[i] != '\0'; ++i)
    {
        if (exp[i] == '(' || exp[i]=='{' || exp[i]=='[')
        {
            push(sp, exp[i]);
        }
        else if (exp[i] == ')' || exp[i]=='}' || exp[i]==']')
        {
            if (isempty(sp))
            {
                return 0;
            }
            if (match(stacktop(sp),exp[i]))
            {
                pop(sp);
            }
        }
    }
    if(isempty(sp))
    {
        return 1;
    }
    else
    return 0;
}
int main()
{
    char exp[100];
    printf("Enter the expression\n");
    scanf("%s",exp);
    if (parenCheck(exp))
    {
        printf("the parenthesis is matched");
    }
    else

        printf("the parenthesis is not matched");
    return 0;
}