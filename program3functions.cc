#include "program3functions.h"

// Find the max frequency of a character in the file
int findMax(int count[])
{
    int max = 0;
    for (int i = 0; i < 26; i++)
    {
        if (count[i] > max)
        {
            max = count[i];
        }
    }
    return max;
}

int findMin(int count[])
{
    int min = 0;
    for (int i = 0; i < 26; i++)
    {
        if (count[i] < count[min])
        {
            min = i;
        }
    }
    return count[min];
}
