#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

#include "wav.h"

int check_format(WAVHEADER header);
int get_block_size(WAVHEADER header);

int main(int argc, char *argv[])
{
    // Ensure proper usage
    // Checking if user inputs correctly or not
    if (argc != 3)
    {
        printf("Usage: ./reverse input.wav output.wav\n");
    }

    // Open input file for reading
    // creating a File variable for opening initial file
    FILE *initial_file = fopen(argv[1], "r");
    if (initial_file == NULL)
    {
        printf("file is not available, please try again once more\n");
        return 1;
    }

    // Read header
    // reading the initial file
    WAVHEADER header;
    fread(&header, sizeof(WAVHEADER), 1, initial_file);


    // Use check_format to ensure WAV format
    // checking if the initial file format is corrcectly entered or not
    int isCorrect = check_format(header);
    if (isCorrect == 1)
    {
        printf("file is correct\n");
    }
    else if (isCorrect == 0)
    {
        printf("file is inorrect\n");
        return 1;
    }


    // Open output file for writing
    // opening the final file
    FILE *final_file = fopen(argv[2], "w");

    // Write header to file
    fwrite(&header, sizeof(WAVHEADER), 1, final_file);

    // Use get_block_size to calculate size of block
    int eachBlockSice = get_block_size(header);

    // Write reversed audio to file
    // making the main initial file into reversed and put it into the final file
    BYTE reversed[eachBlockSice];
    fseek(initial_file, 0, SEEK_END);

    // counting the music size here
    long size;
    size = ftell(initial_file) - sizeof(WAVHEADER);

    // counting the number of blocks in music size below
    int block;
    block = (int)size / eachBlockSice;

    for (int p = block - 1; p >= 0; p--)
    {
        fseek(initial_file, sizeof(WAVHEADER) + p * eachBlockSice, SEEK_SET);
        fread(reversed, eachBlockSice, 1, initial_file);
        fwrite(reversed, eachBlockSice, 1, final_file);
    }

    fclose(initial_file);
    fclose(final_file);
}

int check_format(WAVHEADER header)
{
    BYTE isFormatCorrect[] = {'W', 'A', 'V', 'E'};
    for (int p = 0; p < 4; p++)
    {
        if (isFormatCorrect[p] != header.format[p])
        {
            char str[] = "incorrect";
            return 0;
        }
    }
    return 1;
}

int get_block_size(WAVHEADER header)
{
    WORD numberInEachFile;
    numberInEachFile = header.bitsPerSample / 8;
    int shouldBeReturned =  header.numChannels * numberInEachFile;
    return shouldBeReturned;
}