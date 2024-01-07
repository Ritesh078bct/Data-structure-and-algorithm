#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define size 5
struct queue{
    int data[size];
    int rear,front;
};
void enqueue(struct queue *q)
{
        if(q->rear==size-1)
        {
            printf("Queue is Full");

        }  
        else{
            q->rear++;
            printf("Enter the element\n");
            scanf("%d",&q->data[q->rear]);
            printf("%d is added\n",q->data[q->rear]);
        }
}
void display(struct queue q)
{
    int i;
    if(q.rear==-1)
        printf("queue is empty");
    else{
        printf("The entered elements are:");
        for(i=q.rear;i>=q.front;i--){
            printf("\n%d",q.data[i]);
        }
    }
}
//DEQUEUING ELEMENTS FROM THE QUEUE WITHOUT SHIFTING ELEMENTS.....
// void dequeue(struct queue *q){
//     if(q->rear<q->front)
//     {
//         printf("queue is empty");
//     }
//     else{
//         printf("%d is dequeueped out",q->data[q->front]);
//         q->front++;
//     }
// }
//DEQUEUING ELEMENTS BY SHIFTING THE ELEMENTS FROM FRONT+1 TO FRONT UPTO REAR POSITION TOWARDS FRONT....
void dequeue(struct  queue *q)
{
    int i;
    if(q->rear<q->front)
    {
        printf("Queue is Empty!!");
    }
    else{
        printf("\n%d is dequeued",q->data[q->front]);
        for(i=q->front;i<q->rear;i++)
        {
            q->data[i]=q->data[i+1];
        }
        
        q->rear--;


    }
}

int main()
    {
        int choice;
        struct queue q;
        q.rear=-1;
        q.front=0;
        while(1){
            system("cls");
            printf("1.enqueue\n2.dequeue\n3.display\n4.exit\n");
            scanf("%d",&choice);
            switch(choice){
                case 1:enqueue(&q);
                         break;
                case 2:dequeue(&q);
                    break;
                case 3:display(q);
                         break;
                case 4:exit(0);
                      break;
                
            }
            getch();
        }
        
        return 0;
    }