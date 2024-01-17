#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head = NULL, *newptr, *ptr;
struct node *getnode()
{
    struct node *np;
    np = (struct node *)malloc(sizeof(struct node));
    printf("enter the data :\n");
    scanf("%d", &np->data);
    np->next = NULL;
    np->prev = NULL;
    return np;
}
void create()
{
    struct node *last = NULL;
    char ch;
    do
    {
        newptr = getnode();
        if (head == NULL)
        {
            head = newptr;
        }
        else
        {
            last->next = newptr;
            newptr->prev = last;
        }
        last = newptr;
        printf("Do you want to add more..(y/n)");
        scanf(" %c", &ch);
    } while (ch == 'y' || ch == 'Y');
}
void display()
{
    ptr = head;
    printf("data are:\n");
    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}
void deleteFromFront()
{
    if(head==NULL)
    {
        printf("linked list is empty!!");
    }
    else{
        ptr=head;
        head=head->next;
        printf("%d is deleted",ptr->data);
        free(ptr);
        head->prev=NULL;
    }
}
void deleteFromLast(){
    if(head==NULL)
    {
        printf("linked list is empty!!");
    }
    else{
        ptr=head;
        while(ptr->next!=NULL){
            ptr=ptr->next;
        }
  printf("%d is deleted",ptr->data);
        ptr->prev->next=NULL;
        
        free(ptr);
    }
}
void deleteFromAnywhere()
{
    int key;
    printf("enter key");
    scanf("%d",&key);
    if(head==NULL){
        printf("linked list is empty");
    }
    else{
        ptr=head;
        while(ptr!=NULL && ptr->data!=key){
            ptr=ptr->next;
        }
        if(ptr==NULL){
            printf("data with %d does not exist",key);
        }else{
            ptr->prev->next=ptr->next;
            ptr->next->prev=ptr->prev;

            printf("%d is deleted",ptr->data);
            free(ptr);
        }
    }
}
void delete()
{
    int ch;
    while (1)
    {
        system("cls");
        printf("1.delete at front\n2.delete at last\n3.delete anywhere\nAny Key to Goback\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            deleteFromFront();
            break;
        case 2:
            deleteFromLast();
            break;
        case 3:
            deleteFromAnywhere();
            break;
        default:
            printf("press Enter..");
            return;
        }
        getch();
    }
}
void insertAtFront()
{
    newptr = getnode();
    newptr->next = head;
    head->prev = newptr;
    head = newptr;
    printf("%d is inserted",newptr->data);
}
void insertAtLast()
{
    newptr = getnode();
    ptr = head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = newptr;
    newptr->prev = ptr;
    printf("%d is inserted",newptr->data);
}
void insertAnywhere()
{
    int key;
    newptr = getnode();
    ptr = head;
    printf("enter key:");
    scanf("%d", &key);
    while (ptr != NULL && ptr->data != key)
    {
        ptr = ptr->next;
    }
    if (ptr == NULL)
    {
        printf("\nnode with key does not exist");
    }else{

    newptr->next = ptr->next;
    ptr->next = newptr;
    ptr->next->prev = newptr;
    newptr->prev = ptr;
    printf("%d is inserted",newptr->data);
    }
        
}
void insert()
{
    int ch;
    while (1)
    {
        system("cls");
        printf("1.Insert at front\n2.Insert at last\n3.Insert anywhere\nAny Key to Goback\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insertAtFront();
            break;
        case 2:
            insertAtLast();
            break;
        case 3:
            insertAnywhere();
            break;
        default:
            printf("press Enter..");
            return;
        }
        getch();
    }
}
int main()
{
    int choice;
    create();

    while (1)
    {
        system("cls");
        printf("1.Insert\n2.Delete\n3.display\n4.exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insert();
            break;
        case 2:
            delete ();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;
        }
        getch();
    }
    return 0;
}