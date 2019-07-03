#include <iostream>

using namespace std;

int main()
{
    int ncase, N;
    cin >> ncase;
    while (ncase--)
    {
        cin >> N;
        N = N / 3;
        cout << N * (N + 1) * 3 / 2 << endl; //Multiplier of 3 by trapezoidal area formula
    }
}
