#include <iostream>
#include<string>
#include<algorithm>
using namespace std;

int main() {

    int ncase;
    cin >> ncase;
    cin.ignore();   //Prevent getline from reading blanks
    while (ncase--)
    {
        string str;
        getline(cin, str);
        reverse(str.begin(), str.end());
        cout << str << endl;
    }
    return 0;
}
