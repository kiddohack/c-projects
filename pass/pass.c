#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

int len;
int num;
int sym;


void generatepass()
{
    int g;
    srand(time(NULL));
    printf("This is the pass: ");
    for (int i = 0; i < len; i++)
    {
        if((num == 1) && ((i + rand()) % 5 == 1))
        {
            printf("%d", rand() % 9);
        }
        else if(sym == 1 && ((i + rand()) % 7 == 1))
        {
            sym = (sym % 1 == 1) ? 2 : 1;
            if (sym == 1)
                printf("%c", '!' + rand() % 14);
            else if (sym == 0)
                printf("%c", ':' + rand() % 6);
        }
        else if ((i + rand()) % 2 == 0)
        {
            printf("%c", 'A' + (rand() % 25));
        }
        else printf("%c", 'a' + (rand() % 25));
    }
    printf("\n");
}


int main()
{   
    int s;
    len = 0;
    num = 0;
    sym = 0;
    while(1)
    {
        system("cls");
        printf("1. Set the lenght\n"
                "2. Use or not numbers\n"
                "3. Use or not symbols\n"
                "4. Generate\n"
                "5. Exit\n");
        scanf("%d", &s);
        switch(s)
        {
            case 1:
                printf("Give the lenght ");
                scanf("%d", &len);
                printf("Pass will be %d lenght\n", len);
                break;
            case 2:
                num = (num == 0) ? 1 : 0;
                if(num == 1)
                    printf("You will use the numbers!!!\n");
                else printf("You will not use the numbers!!!\n");
                break;
            case 3:
                sym = (sym == 0) ? 1 : 0;
                if(sym == 1)
                    printf("You will use the symbols!!!\n");
                else printf("You will not use the symbols!!!\n");
                break;
            case 4:
                generatepass();
                break;
            case 5:
                return 0;
            default:
                break;
        }
        printf("Press enter to continue!\n");
        getch();
    }
}