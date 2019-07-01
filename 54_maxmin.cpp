#include <iostream>
#include<iomanip>
using namespace std;

int main()
{
    int i, ncase;
    double num[10];
    double mmax,mmin;

    cin >> ncase;
    while (ncase--)
    {
        for(int i = 0; i < 10; i++)
        {
            cin >> num[i];
            if(i == 0)
            {
                mmax = num[i];
                mmin = num[i];
            }
            else
            {
                if(num[i] > mmax)
                    mmax = num[i];

                if(num[i] < mmin)
                    mmin = num[i];
            }
        }
        cout << fixed << setprecision(2) << "maximum:" << mmax << endl;
        cout << fixed << setprecision(2) << "minimum:" << mmin << endl;
    }
    return 0;
}
