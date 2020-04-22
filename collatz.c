#include <stdio.h>

int collatz(int n);

int main(void)
{
    int trial[11] = {1, 2, 3, 4, 5, 6, 7, 8, 15, 27, 50};

    for (int i = 0, num, result; i < 11; i++)
    {
        num = trial[i];
        result = collatz(num);
        printf("collatz of %i is %i\n", num, result);
    }
}

int collatz(int n)
{
    if (n == 1)
    {
        return 0;
    }
    else if ((n % 2) == 0)
    {
        return 1 + collatz(n / 2);
    }
    else
    {
        return 1 + collatz(3 * n + 1);
    }
}