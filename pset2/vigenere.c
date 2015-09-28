/**
* vigenere.c
*
* Lisa Carson
* User types in a keyword
* User types in text encrypted
*/


#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    
  
    
    // checks that there is only one keyword   
    if (argc != 2)
    {
        printf("Error\n");
        return 1;   
    }
    
    // sets k as argv 
    string k = argv[1];
    
    
    for (int j = 0; j < strlen(argv[1]); j++)
    {
        // checks if the keyword is alpha
        if (!isalpha(argv[1][j]))
        {
            printf("Error \n");
            return 1;
        }

    }    
    // gets plaintext from user
    string plaintext = GetString();
     
    for(int i = 0, j = 0, n = strlen(plaintext), klen = strlen(k) ; i < n; i++) 
    {  
        // check if plain text is alpha
        if (isalpha(plaintext[i]))
        { 
            // outputs cipher
            if (islower(plaintext[i]) && islower(k[j % klen]))
            {
                int kalpha = k[j % klen] - 97;
                int alpha = plaintext[i] - 97;
                int newalpha = (alpha + kalpha) % 26;
                int cipher = newalpha + 97;
                printf("%c", cipher);
                j++;
            
            }
            // outputs cipher
            else if (islower(plaintext[i]) && isupper(k[j % klen]))
            {
                int kalpha = k[j % klen] - 65;
                int alpha = plaintext[i] - 97;
                int newalpha = (alpha + kalpha) % 26;
                int cipher = newalpha + 97;
                printf("%c", cipher);
                j++;
           
            }
            // outputs cipher
            else if (isupper(plaintext[i]) && isupper(k[j % klen]))
            {
                int kalpha = k[j % klen] - 65;
                int alpha = plaintext[i] - 65;
                int newalpha = (alpha + kalpha) % 26;
                int cipher = newalpha + 65;
                printf("%c", cipher);
                j++;
            
            }
            // outputs cipher
            else if (isupper(plaintext[i]) && islower(k[j % klen]))
            {
                int kalpha = k[j % klen] - 97;
                int alpha = plaintext[i] - 65;
                int newalpha = (alpha + kalpha) % 26;
                int cipher = newalpha + 65;
                printf("%c", cipher);
                j++;
            }   
       }
       // prints non alpha characters
       else if (!isalpha(plaintext[i]))
        { 
            printf("%c", plaintext[i]);
            
       }  
             
    }
 
       
        
   
 
    printf("\n"); 
 
    return 0;
}   
