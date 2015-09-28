/**
 * copy.c
 * Lisa Carson
 * Computer Science 50
 * Problem Set 4
 *
 * Copies a BMP piece by piece, just because.
 */
       
#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char* argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        printf("Usage: ./copy infile outfile\n");
        return 1;
    }

    // remember filenames
    char* infile = argv[2];
    char* outfile = argv[3];
    int n = atoi(argv[1]);
    
    if (n < 1 || n >100)
    {
        printf("n must be between 1 and 100");
    }
    // open input file 
    FILE* inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE* outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf, bf_new;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);
    bf_new = bf;
    
    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi, bi_new;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);
    bi_new = bi;
    
    
    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || 
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }
    bi_new.biHeight = bi.biHeight * n;
    bi_new.biWidth = bi.biWidth * n;
    int padding_new = (4-(bi_new.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    bi_new.biSizeImage = abs(bi_new.biHeight) * (bi_new.biWidth *sizeof(RGBTRIPLE) + padding_new);
    bf_new.bfSize = bi_new.biSizeImage + 54;
    
    // write outfile's BITMAPFILEHEADER
    fwrite(&bf_new, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi_new, sizeof(BITMAPINFOHEADER), 1, outptr);

    // determine padding for scanlines
    int padding =  (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    

    // iterate over infile's scanlines
    for (int i = 0;  i < abs(bi.biHeight); i++)
    {
        RGBTRIPLE array[bi.biWidth*n];
             
            
        // iterate over pixels in scanline
        for (int j = 0; j < bi.biWidth; j++)
        {
                
            // temporary storage
            RGBTRIPLE triple;
                
            // read RGB triple from infile
            fread(&triple, sizeof(RGBTRIPLE), 1, inptr);
                
   
                for (int l = 0; l < n; l++)
                    array[(j * n) + l] = triple;
            
        }
        
        for (int l = 0; l < n; l++)
        {
            for(int k = 0; k < bi.biWidth*n; k++)
                fwrite(&array[k], sizeof(RGBTRIPLE), 1, outptr);
                
            for (int k = 0; k < padding_new; k++)
            {
                fputc(0x00, outptr);
            }
        }
            
            // skip over padding, if any
            fseek(inptr, padding, SEEK_CUR);
    }

       
        
    

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // that's all folks
    return 0;
}
