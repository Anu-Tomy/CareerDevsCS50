#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
    // program should accept one command-line argument - name of  file to recover
    if (argc != 2)
    {
        fprintf(stderr, "Usage: recover card.raw\n");
        return 1;
    }
    // assign filename to char*
    char *infile = argv[1];

    // open the card.raw file and check for NULL
    FILE *card_ptr = fopen(infile, "r");
    if (card_ptr == NULL)
    {
        fprintf(stderr, "File not found!");
        return 2;
    }

    // struct to contain bytes from fread
    uint8_t buffer[512];
    // initialize jpg variables
    bool found_first_jpg = false;
    FILE *new_jpg_ptr = NULL;
    int file_counter = 0;
    char filename[8];
    //read in 512 bytes from card.raw until you reach EOF(end byte is 0)
    while (fread(buffer, 1, 512, card_ptr) != 0x00) //fread(data, size, number,inptr)
    {
        //if we find the header pattern of bytes
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            //if we have not found the first jpg
            if (!found_first_jpg)
            {
                //change the boolean value
                found_first_jpg = true;
                //write in the bytes into a separate file
                // 1)open the file
                sprintf(filename, "%03i.jpg", file_counter++);
                new_jpg_ptr = fopen(filename, "w");
                if (new_jpg_ptr == NULL)
                {
                    return 2;
                }
                // 2) write from buffer into new_jpg_ptr
                fwrite(buffer, 1, 512, new_jpg_ptr);
            }
            else
            {
                //close the prevoius file
                fclose(new_jpg_ptr);
                // write in the bytes into a new file
                // 1)open the file
                sprintf(filename, "%03i.jpg", file_counter++);
                new_jpg_ptr = fopen(filename, "w");
                if (new_jpg_ptr == NULL)
                {
                    return 2;
                }
                //2) write from buffer into new_jpg_ptr
                fwrite(buffer, 1, 512, new_jpg_ptr);
            }
        }
        else
        {
            //if we have found the first jpg
            if (found_first_jpg)
            {
              //continue to write the bytes
              fwrite(buffer, 1, 512, new_jpg_ptr);
            }
        }
    }

    //Close all files and free the memory used
    fclose(new_jpg_ptr);
    fclose(card_ptr);

    return 0;
}