/**
* greedy.c
*
* Lisa Carson
*
* Outputs the amount of coins used.
*
*/
#include <stdio.h>
#include <math.h>
#include <cs50.h>

int main(void)
{
    float inputchange;
    int change;
    do
    {
        // Gets the amount of change from user.
        printf("How much change is owed?\n");
        inputchange = GetFloat();
    }
    while (inputchange < 0);
    
    // Converts from dollars and cents to cents, changes from float to integer. 
    inputchange = inputchange * 100;
    change = roundf(inputchange);
    
    int num_counter = 0;
    
    // Calculates how many quarters are to be used and adds to counter.
    while (change >= 25)
    { 
        num_counter = num_counter + 1;
        change = change - 25;      
    }
    
    // Calculates how many dimes are to be used and adds to counter.
    while (change >= 10)
    { 
        num_counter = num_counter + 1;
        change = change - 10;      
    }
    
    // Calculates how many nickels to be used and adds to counter.
    while (change >= 5)
    { 
        num_counter = num_counter + 1;
        change = change - 5;      
    }

    // Calculates how many nickels to be used and adds to counter.
    while (change >= 1)
    { 
        num_counter = num_counter + 1;
        change = change - 1;      
    }

    // Prints the total amount of coins.
    printf("%i\n", num_counter);
    
    return 0;
    
 }
    
















