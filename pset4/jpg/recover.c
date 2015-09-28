/**
 * recover.c
 * Lisa Carson
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 */
#include <stdio.h>
#include <stdint.h>
int main(int argc, char* argv[])
{
 
 
    FILE* inptr = fopen("card.raw", "r");
    if (inptr == NULL)
    {
        printf("Could not open");
        return 2;
    }
 
    uint8_t buffer[512];
    int filenumber = 0;
    char title[8];
    FILE* img = NULL;
 
 

    while(fread(&buffer, sizeof(buffer), 1, inptr) == 1) 
    { 
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] == 0xe0 || buffer[3] == 0xe1))
        {
            if (filenumber > 0)
                fclose(img);
                
            sprintf(title, "%03d.jpg", filenumber);
            img = fopen(title, "a");
            filenumber++;
            fwrite(&buffer, sizeof(buffer), 1, img);
            
         }
        
        else if(filenumber > 0)
        {
            fwrite(&buffer, sizeof(buffer), 1, img);
        }
    }
 
 
    fclose(inptr);
    fclose(img);
    return 0;
 }
 
