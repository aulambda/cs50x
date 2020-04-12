#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    // Initialize 'main' variables
    float change_due;
    int cents;
    int coins = 0;
    

    // Get a positive float from the user and 
    // convert to an integer representing # of pennies
    do
    {
        change_due = get_float("How much do I owe you?:\n");
        cents = round(change_due * 100);
    }
    while (change_due <= 0);

    // Run through each of the denominations until 'cents' - zero
    do
    {
        while (cents >= 25)
        {
            cents = cents - 25;
            coins++;
        }
       
        while (cents >= 10)
        {
            cents = cents - 10;
            coins++;
        }
        
        while (cents >= 5) 
        {
            cents = cents - 5;
            coins++;
        }
        
        while (cents >= 1)
        {
            cents = cents - 1;
            coins++;
        } 
        
    }
    while (cents > 0);

    // Print the final number of separate coins used 
    printf("%i\n", coins);

   

}