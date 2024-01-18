#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <unistd.h>

#define width 29
#define height 30
#define left 3
#define mid 12
#define right 21
#define speed 400000
#define lower 100000

int x, enemypose;
int carpos, score;

void gameover()
{
    system("cls");
    printf("\t\tHAHAHA, you Lost with score = %d!\n", score);
    exit(2);
}

//takes input and moves the car
int move()
{
    char a;
    if(kbhit())
    {
        a = getch();
        if(a == 'd' || a == 'D')
            return 9;
        else if (a == 'a' || a == 'A')
            return -9;
        else if (a == 'X' || a == 'x')
        {
            printf("Bye bye Bitch!\n");
            exit(1);
        }
    }
    return 0;
}

int randomiser()
{
    srand(time(NULL));

    static int s;
    if (s == 0)
    {
        s = rand() % 11 + 5;
        return s;
    }
    if (s > (height - 1))
    {
        s = 0;
    }
}

//prints everything on the screen
void print(int carpos, int s1, int s2, int s3, int enemypos, int enemypos2, int enemypos3)
{
    

    for (int i = 0; i < height; i++) 
    {
        for (int j = 0; j < width; j++) 
        {
            if(i == 0 || i == (height - 1) || j == 0 || j == (width - 1))
                printf("#");
            else if (j == 9 || j == 19)
                printf("|");
            else if (j == carpos && i == (height - 4))
                printf("X");
            else if (j == (carpos + 1) && i == (height - 4))
                printf("x");
            else if (j == (carpos + 2) && i == (height - 4))
                printf("x");
            else if (j == (carpos + 3) && i == (height - 4))
                printf("X");
            else if (j == (carpos + 1) && i == (height - 3))
                printf("x");
            else if (j == (carpos + 2) && i == (height - 3))
                printf("x");
            else if (j == (carpos) && i == (height - 2))
                printf("X");
            else if (j == (carpos + 1) && i == (height - 2))
                printf("x");
            else if (j == (carpos + 2) && i == (height - 2))
                printf("x");
            else if (j == (carpos + 3) && i == (height - 2))
                printf("X");   
            else if (j == left && i == enemypos - s1)
                printf("*");
            else if (j == (left + 1) && i == enemypos - s1)
                printf("*");
            else if (j == (left + 2) && i == enemypos - s1)
                printf("*");
            else if (j == (left + 3) && i == enemypos - s1)
                printf("*");
            else if (j == mid && i == enemypos2 - s2)
                printf("*");
            else if (j == (mid + 1) && i == enemypos2 - s2)
                printf("*");
            else if (j == (mid + 2) && i == enemypos2 - s2)
                printf("*");
            else if (j == (mid + 3) && i == enemypos2 - s2)
                printf("*");
            else if (j == right && i == enemypos3 - s3)
                printf("*");
            else if (j == (right + 1) && i == enemypos3 - s3)
                printf("*");
            else if (j == (right + 2) && i == enemypos3 - s3)
                printf("*");  
            else if (j == (right + 3) && i == enemypos3 - s3)
                printf("*"); 
            else if (j == carpos && carpos == left && (enemypos - s1) == 26)
                gameover();  
            else if (j == carpos && carpos == mid && (enemypos2 - s2) == 26)
                gameover();  
            else if (j == carpos && carpos == right && (enemypos3 - s3) == 26)
                gameover();  
            else
                printf(" ");
        }
        printf("\n");
    }
}

    int s1, s2, s3;
    int enemy1, enemy2, enemy3;
//main draw
void drawborder(int carpos)
{
    srand(time(NULL));

    s1 = randomiser();

    if (s2 == 0)
    {
        s2 = rand() % 15 + 6;
    }
    if (s2 > (height - 1))
    {
        s2 = 0;
    }

    s3 = 5;

    system("cls");

    if (enemy1 > (height + s1 - 1))
    {
        enemy1 = 1;
        score += 1;
    }
    
    if (enemy2 > (height + s2 - 1))
    {
        enemy2 = 1;
        score += 1;
    }

    if (enemy3 > (height + s3 - 1))
    {
        enemy3 = 1;
        score += 1;
    }
    print(carpos, s1, s2, s3, enemy1, enemy2, enemy3);

    printf("Score = %d\n", score);
    printf("A for <- and D for ->\n");
    printf("Press X to exit the game\n");
    enemy1 += 1;
    enemy2 += 1;
    enemy3 += 1;

}

//main function
int main()
{
    carpos = 12;
    int s;
    printf("\t\tPress 1 if you wanna start the game\n\t\tPress 0 to exit right now and be a pussy\n");
    s = getch();
    switch(s)
    {
        case 49:
            drawborder(carpos);

            while(1)
            {
                if (score < 5)
                    usleep(speed);
                else if (score == 5 || score < 9)
                    usleep(speed - lower);
                else if (score == 10 || score < 14)
                    usleep(speed - (2 * lower));
                else if (score == 15 || score < 19)
                    usleep(speed - (3 * lower));
                else if (score == 20 || score < 25)
                    usleep(speed - (4 * lower));
                carpos += move();
                if(carpos > 21)
                    carpos = 21;
                if(carpos < 3)
                    carpos = 3;
                drawborder(carpos);
            }
            break;
        case 48:
            return 1;
        default:
            printf("\t\tDebiloid, 1 sau 0, cacova huia apesi altceva, freaco!\n");
            break;
    }

    return 0;

}