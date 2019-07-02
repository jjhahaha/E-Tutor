#include<iostream>
using namespace std;

int arr[1000][1000];

int main()
{
    int ncase,M;
    int i,j,k;
    cin >> ncase;
    while (ncase--)
    {
        cin >> M;

        for(i = 0 ; i < M ; i++)
            for(j = 0 ; j < M ; j++)
            {
                cin >> arr[i][j];

                if (arr[i][j] != 1)
                    arr[i][j] = 9999;
            }


        for(i = 0; i < M; i++)
            for(j = 0; j < M; j++)
                for(k = 0; k < M; k++)
                    if (arr[i][j] > arr[i][k] + arr[k][j])
                        arr[i][j] = arr[i][k] + arr[k][j];

        cout << arr[0][M - 1]<<endl;
    }
    return 0;
}
