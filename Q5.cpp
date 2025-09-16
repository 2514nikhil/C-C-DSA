#include <iostream>
#include <string.h>

using namespace std;

int check_subString(string str, string sub_str)
{
    int n = str.length();
    int m = sub_str.length();

    for (int i = 0; i <= n - m; i++)
    {
        int j;
        for (j = 0; j < m; j++)
        {
            if (str[i + j] != sub_str[j])
            {
                break;
            }
        }
        if (j == m)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    string str;
    cout << "Enter String:" << endl;
    cin >> str;

    string sub_str;
    cout << "Enter String:" << endl;
    cin >> sub_str;
    int result = check_subString(str, sub_str);
    if (result == -1)
    {
        cout << "Substring not found" << endl;
    }
    else
    {
        cout << "Substring found at index: " << result << endl;
    }
}