#include <stdio.h>
#include <stdlib.h>

char s[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

void show()
{
    printf("\033[0;31m");
    printf("\n\n\t%c\t\033[0;37m|\033[0;31m\t%c\t\033[0;37m|\033[0;31m\t%c\t\n", s[0], s[1], s[2]);
    printf("\033[0m");
    printf("-----------------------------------------------\n");
    printf("\033[0;31m");
    printf("\t%c\t\033[0;37m|\033[0;31m\t%c\t\033[0;37m|\033[0;31m\t%c\t\n", s[3], s[4], s[5]);
    printf("\033[0m");
    printf("-----------------------------------------------\n");
    printf("\033[0;31m");
    printf("\t%c\t\033[0;37m|\033[0;31m\t%c\t\033[0;37m|\033[0;31m\t%c\t\n\n\n", s[6], s[7], s[8]);
    printf("\033[0m");
}


int checkWinner()
{   
    //upper line
    if(s[0] == 'X' && s[1] == 'X' && s[2] == 'X')
    {
        show();
        printf("\t===>> Player 1 Wins! <<===\n");
        return 0;
    } else if(s[0] == 'O' && s[1] == 'O' && s[2] == 'O')
    {
        show();
        printf("\t===>> Player 2 Wins! <<===\n");
        return 0;
    }//main diagonal
    else if(s[0] == 'X' && s[4] == 'X' && s[8] == 'X')
    {
        show();
        printf("\t===>> Player 1 Wins! <<===\n");
        return 0;
    } else if(s[0] == 'O' && s[4] == 'O' && s[8] == 'O')
    {
        show();
        printf("\t===>> Player 2 Wins! <<===\n");
        return 0;
    }//left line
    else if(s[0] == 'X' && s[3] == 'X' && s[6] == 'X')
    {
        show();
        printf("\t===>> Player 1 Wins! <<===\n");
        return 0;
    } else if(s[0] == 'O' && s[3] == 'O' && s[6] == 'O')
    {
        show();
        printf("\t===>> Player 2 Wins! <<===\n");
        return 0;
    }//secondary diagonal
    else if(s[2] == 'X' && s[4] == 'X' && s[6] == 'X')
    {
        show();
        printf("\t===>> Player 1 Wins! <<===\n");
        return 0;
    } else if(s[2] == 'O' && s[4] == 'O' && s[6] == 'O')
    {
        show();
        printf("\t===>> Player 2 Wins! <<===\n");
        return 0;
    }//right line
    else if(s[2] == 'X' && s[5] == 'X' && s[8] == 'X')
    {
        show();
        printf("\t===>> Player 1 Wins! <<===\n");
        return 0;
    } else if(s[2] == 'O' && s[5] == 'O' && s[8] == 'O')
    {
        show();
        printf("\t===>> Player 2 Wins! <<===\n");
        return 0;
    }//down line
    else if(s[6] == 'X' && s[7] == 'X' && s[8] == 'X')
    {
        show();
        printf("\t===>> Player 1 Wins! <<===\n");
        return 0;
    } else if(s[6] == 'O' && s[7] == 'O' && s[8] == 'O')
    {
        show();
        printf("\t===>> Player 2 Wins! <<===\n");
        return 0;
    }//middle vertical line
    else if(s[1] == 'X' && s[4] == 'X' && s[7] == 'X')
    {
        show();
        printf("\t===>> Player 1 Wins! <<===\n");
        return 0;
    } else if(s[1] == 'O' && s[4] == 'O' && s[7] == 'O')
    {
        show();
        printf("\t===>> Player 2 Wins! <<===\n");
        return 0;
    }//middle horizontal line
    if(s[3] == 'X' && s[4] == 'X' && s[5] == 'X')
    {
        show();
        printf("\t===>> Player 1 Wins! <<===\n");
        return 0;
    } else if(s[3] == 'O' && s[4] == 'O' && s[5] == 'O')
    {
        show();
        printf("\t===>> Player 2 Wins! <<===\n");
        return 0;
    }
    return 1;
}

int main()
{
    int player = 2;
    int f;
    int draw = 0;

    do
    {   
        system("cls");
        show();
        player = (player % 2) ? 2 : 1;
        printf("Player %d select the number: ", player);
        scanf("%d", &f);
        if (player == 1)
        {
            if(s[f-1] == 'O')
                printf("You cannot select this, you will miss this move!\n");
            else s[f-1] = 'X';
        }
        else 
        {
            if(s[f-1] == 'X')
                printf("You cannot select this, you will miss this move!\n");
            else s[f-1] = 'O';
        }
        if(draw == 8)
        {
            show();
            printf("\t\t====DRAW====\n");
            break;
        }
        draw++;
    } while (checkWinner() != 0);
    
}
