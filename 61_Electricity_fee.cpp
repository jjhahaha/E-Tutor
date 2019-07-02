#include <iostream>
#include<iomanip>

using namespace std;

int main()
{
    int ncase;
    cin >> ncase;
    double ele_fee;
    while (ncase--)
    {
        double sum = 0, nsum = 0;
        cin >> ele_fee;
        if(ele_fee <= 120)
        {
            sum = ele_fee*2.1;
            nsum = ele_fee*2.1;
        }
        else if(120 < ele_fee && ele_fee <= 330)
        {
            sum = 120*2.1 + (ele_fee-120)*3.02;
            nsum = 120*2.1 + (ele_fee-120)*2.68;
        }
        else if(330 < ele_fee && ele_fee <= 500)
        {
            sum = 120*2.1 + 210*3.02 + (ele_fee-330)*4.39;
            nsum = 120*2.1 + 210*2.68 + (ele_fee-330)*3.61;
        }
        else if(500 < ele_fee && ele_fee <= 700)
        {
            sum = 120*2.1 + 210*3.02 + 170*4.39 + (ele_fee-500)*4.97;
            nsum = 120*2.1 + 210*2.68 + 170*3.61 + (ele_fee-500)*4.01;
        }
        else if(ele_fee > 700)
        {
            sum = 120*2.1 + 210*3.02 + 170*4.39 + 200*4.97 + (ele_fee-700)*5.63;
            nsum = 120*2.1 + 210*2.68 + 170*3.61 + 200*4.01 + (ele_fee-700)*4.5;
        }
        cout << "Summer months:" << fixed << setprecision(2) << sum << endl;
        cout << "Non-Summer months:" << fixed << setprecision(2) << nsum << endl;
    }
    return 0;
}
