#include <iostream>
#define MAX 100000000

using namespace std;

int table[100][100][20];
int bulb[100];
int N, K;

int main()
{
    cin >> N >> K;
    for(int i = 0; i < N; i++)
    {
        cin >> bulb[i];
        bulb[i]--;
    }

    for(int i = 0; i < N; i++)
        for(int j = i; j < N; j++)
            for(int k = 0; k < K; k++)
            {
                if(i == j)
                {
                    if(bulb[i] == k)
                        table[i][j][k] = 0;
                    else
                        table[i][j][k] = 1;
                }
                else
                    table[i][j][k] = MAX;
            }

    for(int i = N-1; i >= 0; i--)
        for(int j = i; j < N; j++)
            for(int k = 0; k < K; k++)
            {
                int smallest = table[i][j][k];
                for(int m = i; m < j; m++)
                {
                    int val = table[i][m][k] + table[m+1][j][k];
                    if(val < smallest)
                        smallest = val;
                }
                for(int c = 0; c < k; c++)
                {
                    int val = table[i][j][c] + 1;
                    if(val < smallest)
                        smallest = val;
                }
                table[i][j][k] = smallest;
                cout << i << "," << j << "," << k << ":" << table[i][j][k] << endl;
            }
    int smallest = table[0][N-1][0];

    for(int c = 1; c < K; c++)
    {
        int val = table[0][N-1][c];
            if(val < smallest)
                smallest = val;
    }
    cout << smallest;
    return 0;
}
