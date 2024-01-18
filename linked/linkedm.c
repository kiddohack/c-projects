#include <stdio.h>
#include <stdlib.h>
  
//linked list
struct node {
  int data;
  struct node *next;
} *head;
 

void initialize(){
    head = NULL;
}
 
//Inserts a node in front of linked list. 
void insertAtFront(int num) 
{
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data  = num;

    newNode->next = head;

    head = newNode;
}
 

//Inserts a node after last node of linked list 
void insertAtEnd(struct node* head, int num)
{
    if (head == NULL) { 
       printf("Error : Invalid node pointer !!!\n");       
       return;  
    }

    struct node* newNode =(struct node*) malloc(sizeof(struct node));
    newNode->data  = num;
    newNode->next = NULL;

    while(head->next != NULL)
       head = head->next;
     

    head->next = newNode;
}
 

//Prints a linked list from head node till tail node 

void printLinkedList(struct node *nodePtr) {
    printf("\nLinked List\n");
  while (nodePtr != NULL) 
  {
     printf("%d", nodePtr->data);
     nodePtr = nodePtr->next;
     if(nodePtr != NULL)
         printf("-->");
  }
}


//Sorts the link in asceding way
void sortList(struct node *head)
{
    struct node *temp, *ptr, *sciot;
    int sw;


        ptr = head;
        while(ptr->next != NULL)
        {
            temp = ptr->next;
            if(ptr->data > temp->data)
            {
                sw = temp->data;
                temp->data = ptr->data;
                ptr->data = sw;
            }
            ptr = ptr->next;
        }
}

//Finds the number required from input
int findIt(struct node *head, int f)
{
    struct node * current = head;
    while(current->next != NULL)
    {
        if (current->data == f)
            return 1;
        current = current->next;
    }
    return 0;
}

  
int main() 
{
    initialize();
    system("cls");
    int count = 1;
    //menu
    int k;
    do
    {
        printf("Press enter to continue! ");
        getchar(); getchar();
        system("cls");
        int f;
        printf("Menu. Select what you want to do\n"
                "1. Insert at front\n"
                "2. Insert at end\n"
                "3. Print the list\n"
                "4. Sort the list\n"
                "5. Find the number\n"
                "0. Exit\n");
        scanf("%d", &k);
        switch(k)
        {
            case 1:
                printf("Insert the number: ");
                scanf("%d", &f);
                insertAtFront(f);
                count++;
                break;
            case 2:
                printf("Insert the number: ");
                scanf("%d", &f);
                insertAtEnd(head, f);
                count++;
                break;
            case 3:
                printf("This is the list\n");
                printLinkedList(head);
                printf("\n");
                break;
            case 4:
                for(int i = 0; i < count; i++)
                    sortList(head);
                printf("\n");
                break;
            case 5:
                printf("What number to search? ");
                scanf("%d", &f);
                findIt(head, f) ? printf("Found it!\n") : printf("Didn't found!\n");
                break;
            default:
                break;
        }
    } while (k!= 0);
    

    return 0;
}