#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

// Declare my function prototypes
int letterCount(string str);
int wordCount(string str);
int sentenceCount(string str);
int colemanLiau(float letters, float words, float sentences);

int main(void)
{
    // Get user input text 
    string usrTxt = get_string("Text: ");

    // Calculate stats of text
    int letters = letterCount(usrTxt);
    int words = wordCount(usrTxt);
    int sentences = sentenceCount(usrTxt);
    int index = colemanLiau(letters, words, sentences);

    // Print colemanLiau index as a string, simplifying ouliers
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 1 && index < 16)
    {
        printf("Grade %i\n", index);
    }
    else
    {
        printf("Grade 16+\n");
    }
}

int letterCount(string str)
{
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (isalpha(str[i]))
        {
            count++;
        }
    }
    return count;
}

int wordCount(string str)
{
    int count = 1;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (!isgraph(str[i]))
        {
            count++;
        }
    }
    return count;
}

int sentenceCount(string str)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '.' || str[i] == '!' || str[i] == '?')
        {
            count++;
        }
    }
    return count;
}

int colemanLiau(float letters, float words, float sentences)
{
    float l = (letters / words) * 100;
    float s = (sentences / words) * 100;
    int index = round(0.0588 * l - 0.296 * s - 15.8);

    return index;
}