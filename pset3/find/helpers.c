/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>

#include "helpers.h"

#include <stdio.h>

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // implement a searching algorithm
    int lower = 0;
    int upper = n-1;
    
    while (lower <= upper)
    {
        int middle = (upper + lower) / 2;
        if (values[middle] == value)
        {
            return true;
        }
        else if (values[middle] < value)
        {
            lower = middle + 1;
        }
        else if (values[middle] > value)
        {
            upper = middle - 1;
        }
    }
    return false;
    
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement an O(n^2) sorting algorithm
    
    for(int i = 0; i < n-1; i++)
    {   
      int swaps = 0;  
        
        for(int j = 0; j < n-1-i; j++)
        {
            if (values[j] > values[j + 1])
            {
                int temp = values[j + 1];
                values[j + 1] = values[j];
                values[j] = temp;
                swaps++;
            }
         }
       if (!swaps)
        break;
      }   
 
}

