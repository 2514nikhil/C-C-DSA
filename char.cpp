#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string str = "Arijit Singh";

    int n = str.length();
    vector<char> arr(n);

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
