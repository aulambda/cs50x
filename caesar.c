#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>


char converter(char p, int k, string index);

int main(int argc, string argv[])
{ 

    // Check that we have one comand line arg after prog name
    if (argc == 2)
    {   
        // Check that our command line arg is all numbers
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            if (isdigit(argv[1][i]) == 0)
            {
                printf("Usage: ./caesar key\n");
                return 1;
            } 
        }
    }
    else
    {
        
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Initialize my variables for the function call
    int key = atoi(argv[1]);    // Convert the command-ling arg to int
    string lowIndex = "abcdefghijklmnopqrstuvwxyz";
    string upIndex = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    // Get the plaintext to be converted
    string plaintext = get_string("plaintext: ");

    printf("ciphertext: ");

    /* Iterate over each char in plaintext checking what kind of char it is
    if nonalpha, simply print, if alpha, call function using the appropriate
    alphabet index */
    for (int i = 0, n = strlen(plaintext); i < n; i ++)
    {
        if (!isalpha(plaintext[i]))
        {
            printf("%c", plaintext[i]);
        }
        else if (islower(plaintext[i]))
        {
            printf("%c", converter(plaintext[i], key, lowIndex));

        }
        else
        {
            printf("%c", converter(plaintext[i], key, upIndex));
        }
        
    }
    printf("\n");
    
   
   
 
}

// Applies the cipher by assigning a value to p based on a given key and index
char converter(char p, int k, string index)
{
    int oldP;
    char c;
    for (int i = 0, n = strlen(index); i < n; i ++)
    {
        if (p == index[i]) 
        {
            oldP = i;
        }
    }
    c = index[((oldP + k) % 26)];
    return c;
 
}

