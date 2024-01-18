#include <stdio.h>
#include <stdlib.h>

struct linked
{
    int nr;
    struct linked* next;
}*head;

void null()
{
    head = NULL;
}

//insert at the end
void insertEnd(struct linked *head, int f)
{
    if (head == NULL)
    {
        printf("Head is NULL\n");
        return;
    }

    struct linked *current = (struct linked *) malloc(sizeof(struct linked));


    current -> nr = f;
    current -> next = NULL;

    while (head->next != NULL)
        head = head->next;

    head->next = current;
}


//insert in front
void insertFront(int f)
{
    struct linked * current = (struct linked *) malloc(sizeof(struct linked));

    current->nr = f;
    current -> next = head;

    head = current;
}

//sort the list
void sortLink(struct linked *head)
{
    struct linked *temp, *ptr;
    int sw;

    ptr = head;

    while(ptr->next != NULL)
    {
        temp = ptr->next;
        if(ptr->nr > temp->nr)
        {
            sw = temp->nr;
            temp->nr = ptr->nr;
            ptr->nr = temp->nr;
        }
        ptr = ptr->next;
    }
}

//find it
void findIt(struct linked *head)
{   
    int s;
    printf("What number do you want to search? ");
    scanf("%d", &s);

    do
    {
        if (head->nr == s)
        {
            printf("Found it!!!\n");
            return;
        }
        head = head->next;
    } while (head-> next != NULL);

    printf("Not found it!\n");
}

//print list
void printList(struct linked *head2)
{
    do
    {
        printf("%d --> ", head2->nr);
        head2 = head2->next;
    }while(head2->next != NULL);
    printf("\n");
}

int main()
{
    null();

    
    int k,f;
    //menu
    do
    {   
        printf("Menu:\nSelect what you want to do\n1. Insert at the end\n2. Insert at the beginning\n3. Show the linked list\n4. Sort the list\n5. Find the number\n0. Exit\n");
        scanf("%d", &k);

        switch(k)
        {
            case(1):
                printf("Insert the number ");
                scanf("%d", &f);
                insertEnd(head,f);
                break;
            case(2):
                printf("Insert the number ");
                scanf("%d", &f);
                insertFront(f);
                break;
            case(3):
                printList(head);
                break;
            case(4):
                sortLink(head);
                break;
            case(5):
                findIt(head);
                break;
            default:
                break;
        }
    } while (k != 0);
    
    

}