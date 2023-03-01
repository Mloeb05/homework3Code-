#include <iostream>
#include <fstream>
#include <iomanip>
#include "program3functions.h"

using namespace std;

int main(int argc, char *argv[])
{
    ifstream fileIn;
    char c;
    int count[26] = { 0 };
    string maxString;
    string minString;

    fileIn.open(argv[1]);

    // Read characters from file and count the frequency of each character
    while (fileIn >> c)
    {
        // checks if the code is uppercase and sets it to lower case
        if (isalpha(c))
        {
            c = tolower(c);
            count[c - 'a']++;
        }
    }

    // Close input file
    fileIn.close();

    // Find the highest and lowest frequency characters
    int max = findMax(count);
    int min = findMin(count);

    // Output highest frequency characters
    cout << "Highest frequency character is " << max << endl;
    int lastMaxIndex = -1;
    for (int i = 0; i < 26; i++)
    {
        if (count[i] == max)
        {
            lastMaxIndex = i;
        }
    }
    for (int i = 0; i < 26; i++)
    {
        if (count[i] == max)
        {
            if (i == lastMaxIndex && i != 0)
            {
                cout << "and ";
            }
            cout << (char)(i + 'a');
            if (i != lastMaxIndex)
            {
                cout << ", ";
            }
        }
    }
    cout << endl;

    // Output lowest frequency characters
    cout << "Lowest frequency characters (appeared " << min << " time(s) in the file): ";
    int lastMinIndex = -1;
    for (int i = 0; i < 26; i++)
    {
        if (count[i] == min)
        {
            lastMinIndex = i;
        }
    }
    for (int i = 0; i < 26; i++)
    {
        if (count[i] == min)
        {
            if (i == lastMinIndex && i != 0)
            {
                cout << "and ";
            }
            cout << (char)(i + 'a');
            if (i != lastMinIndex)
            {
                cout << ", ";
            }
        }
    }
    cout << endl;

    // Output frequency of each character
    for (int i = 0; i < 26; i++)
    {
        cout << (char)(i + 'a') << ": " << count[i] << endl;
    }

    // Print the histogram so that there are stars over the letters
    cout << endl;
    for (int i = max; i > 0; i--)
    {
        cout << setw(2) << i << " ";
        for (int j = 0; j < 26; j++)
        {
            if (count[j] >= i)
            {
                cout << "* ";
            }
            else
            {
                cout << "  ";
            }
        }
        cout << endl;
    }
    cout << "   ";
    for (int i = 0; i < 26; i++)
    {
        cout << char(i + 'a') << " ";
    }
    cout << endl;

    fileIn.close();
	// Close the file and then return 0
    return 0;
}

