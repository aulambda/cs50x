#include <cs50.h>
#include <stdio.h>

bool valid_triangle(float a, float b, float c);

int main(void)
{
    float triA = get_float("Side a:\n");
    float triB = get_float("Side b:\n");
    float triC = get_float("Side c:\n");

    if (valid_triangle(triA, triB, triC) == true)
    {
        printf("That\'s a valid triangle!");
    }
    else
    {
 printf("What a failure!");
    }
}

bool valid_triangle (float a, float b, float c)
{
    if (a <= 0 || b <= 0 || c <= 0)
    {
        return false;
    }
    if ( a + b <= c || a + c <= b || b + c <= a)
    {
        return false;
    }

    return true;
}