#include <iostream>
using namespace std;

int main()
{
    int ncase,i;
    cin >> ncase;
    while (ncase--)
    {
        int n, s, e, length = 0, road[10001] = { 0 };

        cin >> n; // n road situation

        while(n--)
        {
            cin >> s >> e;
            for(i = s; i < e; i++)  // Don't count road[e]
                road[i] = 1;
        }

        for(i = 0; i < 10001; i++)
            if(road[i])
                length++;

        cout << length << endl;
    }
    return 0;
}
