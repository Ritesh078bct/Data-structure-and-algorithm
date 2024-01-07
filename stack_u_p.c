#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define size 5
struct stack
{
    int data[size];
    int top;
};
void push(struct stack *s)
{
    if(s->top==size-1)
    {
        printf("Stack OVerflow!!!\n");
    }
    else{
        s->top++;
        printf("Enter the data\n");
        scanf("%d",&s->data[s->top]);
        printf("data is added\n");
    }
}

void display(struct stack *s)
{
    int i;
    if(s->top==-1)
    {
        printf("Oops!! STACK IS EMPTY..");
    }
    else{
        printf("The data are:\n");
        for(i=s->top;i>=0;i--)
        {
            printf("%d\n",s->data[i]);
        }
    }
}
void pop(struct stack *s)
{
    if((*s).top==-1)
    {
        printf("Stack is Empty!!");
    }
    else
    {
        printf("%d is popped out\n",(*s).data[(*s).top]);
        (*s).top--;
    }
}
void At_top(struct stack *s)
{
    printf("Top of the stack is:%d",s->data[s->top]);
}
int main()
    {
        int choice;
        struct stack s;
        s.top=-1;
        while(1){
            system("cls");
            printf("1.push\n2.pop\n3.display\n4.At_top\n5.exit\n");
            scanf("%d",&choice);
            switch(choice)
            {
                case 1:push(&s);
                        break;
                case 2:pop(&s);
                        break;
                case 3:display(&s);
                        break;
                case 4:At_top(&s);
                        break;    
                case 5:exit(0);
                        break;                            
            }
            getch();
        }
        
        return 0;
    }