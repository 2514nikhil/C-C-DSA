#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str = "Arijit Singh";

    int n = str.length();
    char arr[n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = str[i];
    }

    cout << '[';
    for (int i = 0; i < n; i++)
        cout << arr[i] << ",";
    cout << ']';
    return 0;
}
