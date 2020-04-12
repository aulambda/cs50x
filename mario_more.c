#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //initialize variables to be used in multiple sections
    int n;
    int height;

    // get user input for height variable, repeat until integer between 0 and 9 is given
    do
    {
        height = get_int("Height:\n");
    }
    while (height < 1 || height > 8);

    // main for loop to repeat internal loops by appropraite number of lines
    for (int line = 1; line <= height; line++)
    {
        // print spaces to right-align hashes
        for (int spaces = height - line; spaces > 0; spaces--)
        { 
            printf(" ");
        }
        
        // print hashes, increasing each time until final amount printed.
        for (int hashes = 1; hashes <= line; hashes++)
        { 
            printf("#");
        }

        printf("  ");

        // print hashes, increasing each time until final amount printed.
        for (int hashes = 1; hashes <= line; hashes++)
        { 
            printf("#");
        }

        // print newline after each loop
        printf("\n");
    }
}