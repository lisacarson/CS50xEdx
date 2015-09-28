/**
* caesar.c
*
* Lisa Carson
*
* User enters a positive integer 
* User then enters plain text to be encrypted
* Encrypts messages
*/


#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    
  
    
    // determines if argc = 2
    if (argc != 2)
    {
        printf("Error\n");
        return 1;   
    }
    
    int k = atoi(argv[1]);
    string plaintext = GetString();
    
    for(int i = 0, n = strlen(plaintext); i < n; i++) 
    {  
        // converts lowercase letters to cipher
        if (islower(plaintext[i]))
        {
            int alpha = plaintext[i] - 97;
            int newalpha = (alpha + k) % 26;
            int cipher = newalpha + 97;
            printf("%c", cipher);
    
        }
        
        // coverts uppercase letters to cipher
        if (isupper(plaintext[i]))
        {
            int alpha = plaintext[i] - 65;
            int newalpha = (alpha + k) % 26;
            int cipher = newalpha + 65;
            printf("%c", cipher);
    
        }
        
        // puts blank space in cipher
        if (isblank(plaintext[i]))
        {
            printf(" ");
        }
        
        // puts digits in cipher
        if (isdigit(plaintext[i]))
        {
            printf("%c", plaintext[i]);
        }
        
        // puts punctuation in cipher
        if (ispunct(plaintext[i]))
        {
            printf("%c", plaintext[i]);
        }
    }
 
    printf("\n"); 
 
    return 0;
}   
