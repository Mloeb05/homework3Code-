#include <iostream>
#include <fstream>
#include <iomanip>
#include <program3functions.h>


using namespace std;

int main(int argc, char *argv[])
{
	ifstream fileIn;
	char c;
	int count[26] = { 0 };
	int max = 0;
	int min = 0;
	string maxString;
	string minString;
	
	fileIn.open(argv[1]);
	
	// Read characters from file and count the frequency of each character
	while (fileIn >> c)
	{
		if (isalpha(c))
		{
			c = tolower(c);
			count[c - 'a']++;
		}
	}
	
	// Find the max and min character frequencies
	max = findMax(count);
	min = findMin(count);
	
	// Check for all characters with the max frequency
	for (int i = 0; i < 26; i++)
	{
		if (count[i] == max)
		{
			maxString += char(i + 'a') + ", ";
		}
	}
	
	// Check for all characters with the min frequency
	for (int i = 0; i < 26; i++)
	{
		if (count[i] == min)
		{
			minString += char(i + 'a');
		}
	}
	
	// Print the results
	cout << "The input file reads as follows:" << endl << endl;
	while (fileIn >> c)
	{
		cout << c;
	}
	cout << endl << endl;
	
	cout << "Highest frequency character (appeared " << max << " times in the file): " << maxString << endl;
	cout << "Lowest frequency characters (appeared " << min << " time in the file): " << minString << endl << endl;
	
	
    // Print the character frequency list
    for (int i = 0; i < 26; i++)
    {
        if (count[i] > 0)
        {
            cout << char(i + 'a') << ": " << count[i] << endl;
        }
    }

    // Print the histogram
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

    return 0;
}