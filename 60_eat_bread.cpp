#include <iostream>
using namespace std;

int main()
{
    //Add from the xth number to the yth number
    int ncase,i,n, m;
    int x,y;
    int sum = 0;

    cin >> ncase;
    while (ncase--)
    {
        cin >> n >> m;

        int w[n];

        for(i = 1 ; i <= n ; i++)
            cin >> w[i];
        while (m--)
        {
            cin >> x >> y;
            for(i = x ; i <= y ; i++)
            {
                sum = sum + w[i];
            }
            cout << sum << endl;
            sum = 0;
        }
    }
    return 0;
}
