/**
* initials.c
*
* Lisa Carson
*
* User types in name and gets initials
*
*/
#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>
int main(int argc, string argv[])
{

    // Gets name
    string name = GetString();
   
     
    // Gives initials
    for(int i = 0, n = strlen(name); i < n; i++)
    {
        if (i == 0) 
        {
            printf("%c", toupper(name[i]));
        }
        if (isspace(name[i]))
        {
            printf("%c", toupper(name[i + 1]));
        }
        
         
        
     }
    printf("\n");
}
