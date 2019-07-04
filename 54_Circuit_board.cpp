#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
    int ncase;
    cin >> ncase;
    while (ncase--)
    {
        double Ti,T;
        char d; // ,
        int i;
        cin >> Ti >> d >> i;  //input : 94.87,9
        //T i = T i-1 + 2.71828 * i
        T = Ti + 2.71828 * (1 + i) * i / 2 ;
        cout << fixed << setprecision(4) << T << endl;
    }
}
