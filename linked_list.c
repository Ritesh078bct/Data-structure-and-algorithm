#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct node
{
    int info;
    struct node *next;
};
struct node *head = NULL, *ptr, *newptr, *prevptr;
struct node *getnode()
{
    struct node *np;
    np = (struct node *)malloc(sizeof(struct node));
    printf("enter the data:");
    scanf("%d", &np->info);
    np->next = NULL;
    return np;
}
void create()
{
    struct node *last;

    char ch;
    do
    {
        newptr = getnode();
        if (head == NULL)
            head = newptr;
        else
            last->next = newptr;
        last = newptr;
        printf("Do you want to add more..(y/n)");
        scanf(" %c", &ch);
    } while (ch == 'y' || ch == 'Y');
}
void display()
{
    ptr = head;
    printf("The entered elements are:\n");
    if (ptr == NULL)
    {
        printf("linked list is empty");
    }
    while (ptr != NULL)
    {
        printf("%d\t", ptr->info);
        ptr = ptr->next;
    }
}
void insertAtFront()
{
    newptr = getnode();
    newptr->next = head;
    head = newptr;
    printf("%d added", head->info);
}
void insertAtLast()
{
    newptr = getnode();
    if (head != NULL)
    {

        ptr = head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = newptr;
        printf("%d is added", newptr->info);
    }
    else
    {
        head = newptr;
        printf("%d is added", head->info);
    }
}
void insertAnywhere()
{
    int key;
    if(head!=NULL){
    printf("enter key");
    scanf("%d", &key);
    ptr = head;
    while (ptr != NULL && ptr->info != key)
    {
        ptr = ptr->next;
    }
    if (ptr == NULL)
    {
        printf("node with key does not exist");
    }
    else
    {
        newptr = getnode();
        newptr->next = ptr->next;
        ptr->next = newptr;
    }
    printf("%d added!", newptr->info);

    }else{
        printf("list is empty");
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
void deleteFromFront()
{
    if (head == NULL)
    {
        printf("linked list is empty!");
    }
    else
    {
        ptr = head;
        printf("%d is deleted", head->info);
        head = head->next;
        free(ptr);
    }
}
void deleteFromLast()
{
    prevptr = NULL;
    if (head == NULL)
    {
        printf("linked list is empty");
    }
    else
    {
        ptr = head;
        while (ptr->next != NULL)
        {
            prevptr = ptr;
            ptr = ptr->next;
        }
        printf("%d is deleted", ptr->info);
        if (!prevptr)
        {
            head = NULL;
        }
        else
        {

            prevptr->next = NULL;
        }
        free(ptr);
    }
}
void deleteFromAnywhere()
{
    int key;
    if (head == NULL)
    {
        printf("linked list is empty");
    }
    else
    {
        printf("enter key\n");
        scanf("%d", &key);
        ptr = head;
        while (ptr != NULL && ptr->info != key)
        {
            prevptr = ptr;
            ptr = ptr->next;
        }
        if (ptr == NULL)
        {
            printf("node does not exist");
        }
        else
        {
            printf("%d is deleted:", ptr->info);
            if (prevptr)
                prevptr->next = ptr->next;
            else
                head = ptr->next;
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