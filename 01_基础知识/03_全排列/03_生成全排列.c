#include <iostream>
#include <algorithm>
#include <string>
 
using namespace std;
 
int main()
{
    string str;
    cin >> str;
    sort(str.begin(), str.end());
    cout << str << endl;
    while (next_permutation(str.begin(), str.end()))
    {
        cout << str << endl;
    }
    return 0;
}