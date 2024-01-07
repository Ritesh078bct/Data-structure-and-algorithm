#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define size 5
struct stack{
    int data[size];
    int top;
}s;
void push()
{
    if(s.top==size-1)
        printf("Stack Overflow");
    else{
        s.top++;
        printf("Enter the Data\n");
        scanf("%d",&s.data[s.top]);
        printf("Data is added");

    }    
}
void display()
{
    int i;
    if(s.top==-1)
        printf("stack is empty");
    else{
        printf("The entered elements are:\n");
        for(i=s.top;i>=0;i--){
            printf("%d\n",s.data[i]);
        }
    }
}
void pop(){
    if(s.top==-1)
    {
        printf("stack is empty");
    }
    else{
        printf("%d is popped out",s.data[s.top]);
        s.top--;
    }
}
int main()
    {
        int choice;
       
        s.top=-1;
        while(1){
            system("cls");
            printf("1.push\n2.pop\n3.display\n4.exit\n");
            scanf("%d",&choice);
            switch(choice){
                case 1:push();
                         break;
                case 2:pop();
                    break;
                case 3:display();
                         break;
                case 4:exit(0);
                      break;
                
            }
            getch();
        }
        
        return 0;
    }