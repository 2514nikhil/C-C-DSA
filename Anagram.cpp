#include <iostream>
#include <string>

using namespace std;

int main()
{
    string S1 = "Arijit";
    string S2 = "rijitA";

    if (S1.length() != S2.length())
    {
        cout << "Not an Anagram" << endl;
    }
    else
    {
        int count[256] = {0};

        for (char c : S1)
        {
            count[c]++;
        }

        for (char c : S2)
        {
            count[c]--;
        }

        bool isAnagram = true;
        for (int i = 0; i < 256; i++)
        {
            if (count[i] != 0)
            {
                isAnagram = false;
                break;
            }
        }

        if (isAnagram)
        {
            cout << "Anagram" << endl;
        }
        else
        {
            cout << "Not an Anagram" << endl;
        }
    }
}