#include <iostream>
#include <algorithm>

using namespace std;

int Answer;
int N, M;
int pos[501];

int dp[500][501];
int table[500][500];

int main(int argc, char** argv)
{
	int T, test_case;

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
		Answer = 0;
		cin >> N >> M;
		for(int i = 0; i < N; i++)
        {
            cin >> pos[i];
        }
		sort(pos, pos + N);
		for(int k = 0; k < N; k++)
        {
            for(int i = 0; i < N - k; i++)
            {
                table[i][i + k] = pos[i + k] - pos[i];
                if(k > 1)
                    table[i][i + k] += table[i + 1][i + k - 1];
            }
            dp[k][1] = table[0][k];
        }

		for(int m = 2; m <= M; m++)
        {
            for(int k = m - 1; k < N; k++)
            {
                int smallest = 1000000000;
                for(int mid = 0; mid < k; mid++)
                {
                    int val = dp[mid][m - 1] + table[mid + 1][k];
                    if(val < smallest)
                        smallest = val;
                }
                dp[k][m] = smallest;
            }
        }


		cout << "Case #" << test_case+1 << endl;
		cout << dp[N - 1][M] << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}
