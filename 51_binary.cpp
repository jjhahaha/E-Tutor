#include <iostream>
using namespace std;

void binary(int val)
{
	for(int i = 7; i >= 0; i--)
	{
		if(val & (1 << i))
			cout << "1";
		else
			cout << "0";
	}
	cout << endl;
}
int main()
{
    int ncase;
    cin >> ncase;
    while (ncase--)
    {
        int N;
        cin >> N;
        binary(N);
    }
    return 0;
}
