#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// FAT file system block size is 512 bytes
const int BLOCK_SIZE = 512;

int main(int argc, char *argv[])
{
    // Accept a single command-line argument
    if (argc != 2)
    {
        printf("Usage: ./recover FILE\n");
        return 1;
    }

    // Open memory card
    FILE *card = fopen(argv[1], "r");
    if (card == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    uint8_t buffer[BLOCK_SIZE];

    // Image counter
    int img_no = 0;

    // Repeat until end of card
    while (fread(buffer, BLOCK_SIZE, 1, card) == 1)
    {

        // If found JPEG header
        // Detect JPEG signature patterns which is 0xff 0xd8 0xff
        // fourth byte is 0xe0 - 0xef which is 224 -> 239 and first four bits are 1110
        // Bitwise operator to check for the fourth byte first four bits
        if (buffer[0] == 255 && buffer[1] == 216 && buffer[2] == 255 && (buffer[3] & 240) == 224)
        {
            // Create a new JPEG file
            char file_name[8];
            sprintf(file_name, "%03i.jpg", img_no);
            FILE *img = fopen(file_name, "w");
            img_no++;

            // Write file header
            fwrite(buffer, BLOCK_SIZE, 1, img);

            while (fread(buffer, BLOCK_SIZE, 1, card))
            {
                // If found next jpeg file
                if (buffer[0] == 255 && buffer[1] == 216 && buffer[2] == 255 &&
                    (buffer[3] & 240) == 224)
                {
                    // Close current file
                    fclose(img);

                    // Create next jpeg file
                    sprintf(file_name, "%03i.jpg", img_no);
                    img = fopen(file_name, "w");
                    img_no++;

                    // Write next img header
                    fwrite(buffer, BLOCK_SIZE, 1, img);
                }
                // Write current file
                else
                {
                    fwrite(buffer, BLOCK_SIZE, 1, img);
                }
            }
            fclose(img);
        }
    }
    fclose(card);
}
