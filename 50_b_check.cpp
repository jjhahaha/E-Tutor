#include<iostream>
using namespace std;

int main()
{
    char buf[13],ABC;
    int ncase,check,num[14],i;
    unsigned long long n,sum = 0 ;
    cin >> ncase;
    while (ncase--)
    {
        n=0;
        sum = 0;
        for (int i = 0; i < 12; i++)
        {
            cin >> buf[i];
            num[i]=buf[i]-48; // '1'=49
            //cout << num[i] << endl;
            n=n*10+num[i];
        }
        cin >> ABC;
        check = ABC;

        for ( i = 0; i < 12; i += 2)
            sum += num[i] + 3 * num[i + 1];

        sum = 26 - (sum % 26) + '@';


        if (sum == check)
            cout << "valid\n";
        else
            cout << "invalid\n";

    }
    return 0;
}
