/*
* mario.c
*
* Lisa Carson
*
* Creates a half-pyramid
*
*/
#include <stdio.h>
#include <cs50.h>
int main(void)
{
    int height;
    
    // Prompts user to enter height
    do
    {
        printf("Enter a number between 0 and 23\n ");
        height = GetInt();
    }
    while (height < 0 || height > 23);
    
    // Prints half-pyramid
    for (int row = 0; row < height; row++)
    {
        for (int column = 0; column < height - (row + 1); column++)
        {
            printf(" ");
        }
        for (int column = 0; column < row + 2; column++)
        {
            printf("#");
        }
        printf("\n");
    }
    return 0;
}
