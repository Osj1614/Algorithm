/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class seq
{
    public:
    int val = 0;
    int i = 0;
    bool operator <(const seq& right) const
    {
        return val < right.val;
    }
};

int Answer;
int data[10000];
int pattern[300];
int patinv[300];
seq temp[300];
int tempp[300];
int N, M, K;

int bigger(int a, int b)
{
    if(a > b)
        return a;
    return b;
}
/*
int getlcs()
{
    int table[301][301];
    for(int i = 0; i <= M; i++)
        table[i][0] = table[0][i] = 0;
    for(int i = 1; i <= M; i++)
        for(int j = 1; j <= M; j++)
        {
            if(pattern[i - 1] == tempp[j - 1])
                table[i][j] = table[i - 1][j - 1] + 1;
            else
                table[i][j] = bigger(table[i - 1][j], table[i][j - 1]);
        }
    return table[M][M];
}
*/
int getlis()
{
    int lis = 1;
    vector<int> lisvec;
    lisvec.push_back(tempp[0]);
    for(int i = 1; i < M; i++)
    {
        if(lisvec.back() < tempp[i])
        {
            lisvec.push_back(tempp[i]);
            lis++;
        }
        else
        {
            vector<int>::iterator pos = lower_bound(lisvec.begin(), lisvec.end(), tempp[i]);
            *pos = tempp[i];
        }
    }
    return lis;
}

int main(int argc, char** argv)
{
	int T, test_case;
	/*
	   The freopen function below opens input.txt file in read only mode, and afterward,
	   the program will read from input.txt file instead of standard(keyboard) input.
	   To test your program, you may save input data in input.txt file,
	   and use freopen function to read from the file when using cin function.
	   You may remove the comment symbols(//) in the below statement and use it.
	   Use #include<cstdio> or #include <stdio.h> to use the function in your program.
	   But before submission, you must remove the freopen function or rewrite comment symbols(//).
	 */

	// freopen("input.txt", "r", stdin);

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{

		Answer = 0;
		cin >> N >> M >> K;
		/////////////////////////////////////////////////////////////////////////////////////////////
		for(int i = 0; i < N; i++)
            cin >> data[i];

        for(int i = 0; i < M; i++)
        {
            cin >> temp[i].val;
            temp[i].i = i;
        }
        sort(temp, temp + M);

        for(int i = 0; i < M; i++)
            pattern[i] = temp[i].i;

        for(int i = 0; i < M; i++)
            patinv[pattern[i]] = i;

        for(int i = 0; i <= N - M; i++)
        {
            for(int j = 0; j < M; j++)
            {
                temp[j].val = data[i + j];
                temp[j].i = j;
            }
            sort(temp, temp + M);
            for(int k = 0; k < M; k++)
                tempp[k] = patinv[temp[k].i];
            int lis = getlis();
            if(lis >= M - K)
                Answer++;
        }
        /////////////////////////////////////////////////////////////////////////////////////////////

		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}
