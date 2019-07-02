#include <iostream>
#include<algorithm>
using namespace std;

int main()
{
    int ncase;
    int c;
    cin >> ncase;
    while (ncase--)
    {
        int dataNum, data[3];
        cin  >> dataNum >> data[0] >>data[1];
        cout << data[0] << " " ;

        dataNum = dataNum - 2;
        while (dataNum--)
        {
            cin >> data[2];
            c=data[2];

            sort(data,data+3);

            cout << data[1] << " " ;

            data[0]=data[1];data[1]=c;
        }
        cout << c << endl;
    }
    return 0;
}
