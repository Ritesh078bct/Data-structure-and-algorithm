#include <stdio.h>
#include<conio.h>
#include<stdlib.h>

void delete() {
    int value;
   
    while(1){
        system("cls");
        printf("1.delete at front\n2.delete at last\n3.delete anywhere\n");
    scanf("%d",&value);
         switch (value) {

        case 1:
            printf("one\n");
            break;
        case 2:
            printf("two\n");
            break;
        case 3:printf("three\n");
                break;
        default:
            printf("Returning to main function\n");
            getchar(); // Consume the newline character
            return;
    }
    getch();

    }
   
    // Additional code here, if needed

    // The rest of your function logic goes here
}

int main() {

int choice;
    // delete();
while (1)
    {
        system("cls");
        printf("1.Insert\n2.Delete\n3.display\n4.exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            // insert();
            break;
        case 2:
            delete ();
            break;
        case 3:
            // display();
            break;
        case 4:
            exit(0);
            break;
        }
        getch();
    }

    return 0;
}
