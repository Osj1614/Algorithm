/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/

#include <iostream>
#include <algorithm>

using namespace std;


class path
{
public:
    int a;
    int b;
    bool on;
};

bool compare(const path &a, const path &b)
{
    if(a.a == b.a)
        return a.b < b.b;
    return a.a < b.a;
}

int Answer;
path p[800000];
int pc[200000];
int pi[200001];

void off(int b, int s, int e)
{
    int m = (s + e) / 2;
    if(p[m].b == b)
    {
        p[m].on = false;
        return;
    }
    else if(p[m].b < b)
        off(b, m + 1, e);
    else
        off(b, s, m);
}

bool isconnected(int a, int b)
{
    if(pi[a + 1] - pi[a] > pi[b + 1] - pi[b])
        return isconnected(b, a);
    for(int i = pi[a]; i < pi[a + 1]; i ++)
    {
        if(p[i].b == b)
            return true;
    }
    return false;
}

void flood(int i)
{
    if(pc[i] == 2)
    {
        int a, b = -1;
        int ai, bi;
        for(a = pi[i]; a < pi[i + 1]; a++)
        {
            if(p[a].on)
            {
                if(b == -1)
                {
                    b = p[a].b;
                    bi = a;
                }
                else
                {
                    ai = a;
                    a = p[a].b;
                    break;
                }
            }
        }

        if(isconnected(a, b))
        {
            Answer--;
            pc[i] = 0;
            pc[a]--;
            pc[b]--;
            p[ai].on = false;
            p[bi].on = false;
            off(i, pi[a], pi[a + 1] - 1);
            off(i, pi[b], pi[b + 1] - 1);
            flood(a);
            flood(b);
        }
   }
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
		int N, M;
		cin >> N >> M;
		Answer = N;
		for(int i = 0; i < N; i++)
            pc[i] = 0;
		for(int i = 0; i < M; i++)
        {
            cin >> p[i * 2].a >> p[i * 2].b;
            p[i * 2].a -= 1;
            p[i * 2].b -= 1;
            pc[p[i*2].a]++;
            pc[p[i*2].b]++;
            p[i*2].on = true;
            p[i*2+1].on = true;
            p[i * 2 + 1].b = p[i * 2].a;
            p[i * 2 + 1].a = p[i * 2].b;
        }
        sort(p, p + M * 2, compare);
		/////////////////////////////////////////////////////////////////////////////////////////////
		pi[0] = 0;
		for(int i = 1; i <= N; i++)
            pi[i] = pi[i-1] + pc[i-1];

		for(int i = 0; i < N; i++)
        {
            flood(i);
        }
		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}
