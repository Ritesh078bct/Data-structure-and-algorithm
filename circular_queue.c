#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define size 4
struct queue{
    int data[size];
    int rear,front;
};
void enqueue(struct queue *q)
{
        if((q->rear+1)%size==q->front)
        {
            printf("Queue is Full");

        }  
        else{
            q->rear=(q->rear+1)%size;
            printf("Enter the element\n");
            scanf("%d",&q->data[q->rear]);
            printf("%d is added\n",q->data[q->rear]);
        }
}
void display(struct queue *q)
{
    // int i=q->rear;
    int i;
    if(q->rear==q->front)
        printf("queue is empty");
    else{
        printf("The entered elements are:");
        // while(i!=q->front)
        // {
        //     printf("\n%d",q->data[i]);
        //     i=(i-1+size)%size;       // size is added because once the queue is empty and value is added again then rear will be zero 
        // }
        // for(i=q->rear;i!=q->front;i=(i-1+size)%size){
        //     printf("\n%d",q->data[i]);
        // }
        for(i=q->front+1;i!=q->rear;i=(i+1+size)%size){
            printf("%d\n",q->data[i]);
            
        }
        printf("%d\n",q->data[q->rear]);
    }
}
void dequeue(struct queue *q){
    if(q->rear==q->front)
    {
        printf("queue is empty");
    }
    else{
        
        q->front=(q->front+1)%size;
        printf("%d is dequeueped out",q->data[q->front]);
    }
}

int main()
    {
        int choice;
        struct queue q;
        q.rear=-0;
        q.front=0;
        while(1){
            system("cls");
            printf("circular queue....\n\n");
            printf("1.enqueue\n2.dequeue\n3.display\n4.exit\n");
            scanf("%d",&choice);
            switch(choice){
                case 1:enqueue(&q);
                         break;
                case 2:dequeue(&q);
                    break;
                case 3:display(&q);
                         break;
                case 4:exit(0);
                      break;
                
            }
            getch();
        }
        
        return 0;
    }