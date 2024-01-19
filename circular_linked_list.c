#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct node
{
    int data;
    struct node *next;
};
struct node *nodeptr = NULL, *newptr, *ptr, *prevptr;
struct node *getnode()
{
    struct node *np;
    np = (struct node *)malloc(sizeof(struct node));
    printf("enter the data:");
    scanf("%d", &np->data);
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
        if (nodeptr == NULL)
        {
            nodeptr = newptr;
        }
        else
        {
            last->next = newptr;
        }
        newptr->next = nodeptr;
        last = newptr;
        printf("Do you want to enter more :y/n");
        scanf(" %c", &ch);
    } while (ch == 'y' || ch == 'Y');
}
void display()
{

    if (nodeptr != NULL)
    {
        ptr = nodeptr;
        printf("the given data are:\n");
        do
        {
            printf("%d\t", ptr->data);
            ptr = ptr->next;
        } while (ptr != nodeptr);
    }
    else
        printf("display empty");
}
void insert()
{
    int key;
     newptr = getnode();
    if(nodeptr!=NULL)
    {
   
    printf("enter key after which you want to insert:\n");
    scanf("%d", &key);
    ptr = nodeptr;
    do
    {
        ptr = ptr->next;

    } while (ptr->data != key && ptr != nodeptr);
    if (ptr->data != key)
    {
        printf("node with key does not exist");
    }
    else
    {
        printf("%d is inserted.", newptr->data);
        newptr->next = ptr->next;
        ptr->next = newptr;
    }

    }
    else{
        nodeptr=newptr;
        newptr->next = nodeptr;
        printf("%d is inserted",newptr->data);
        
    }
}

void delete()
{
    int key;
    if (nodeptr != NULL)
    {
        printf("enter the data to be deleted\n");
        scanf("%d", &key);
        ptr = nodeptr;
        do
        {
            prevptr = ptr;
            ptr = ptr->next;
        } while (ptr->data != key && ptr != nodeptr);
        if (ptr->data != key)
        {
            printf("node with key does not exist");
        }
        else
        {
            if (ptr == nodeptr)
            {
                if (ptr->next==nodeptr)
                {
                    nodeptr=NULL;
                }else{
                    nodeptr = ptr->next;
                    prevptr->next = ptr->next;
                }
             
            }
            else{
                prevptr->next=ptr->next;
            }
            
            printf("%d is deleted.", ptr->data);
            free(ptr);
        }
    }
    else
    {
        printf("empty");
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