/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/

#include <iostream>
#include <algorithm>

using namespace std;

int points[100];

class path
{
    public:
        int a, b;

    int dist()
    {
        if(points[a] > points[b])
            return points[a] - points[b];
        return points[b] - points[a];
    }
};
bool compare(const path &a, const path &b)
{
    if(a.a == b.a)
        return a.b < b.b;
    return a.a < b.a;
}

int Answer;
int N, M;
int ans[100];
bool check[100];
path p[2000];
int pc[100];
int pi[101];

void setans()
{
    for(int i = 0; i < N; i++)
        ans[points[i]] = i;
}

int calc()
{
    int val = 0;
    for(int i = 0; i < M * 2; i++)
        val += p[i].dist();
    return val / 2;
}

void findroute(int v, int n)
{
    if(n == N)
    {
        int val = calc();
        if(val < Answer)
        {
            setans();
            Answer = val;
        }
        return;
    }
    points[n] = v;
    for(int i = pi[v]; i < pi[v + 1]; i++)
    {
        if(!check[p[i].b])
        {
            check[p[i].b] = true;
            findroute(p[i].b, n + 1);
            check[p[i].b] = false;
        }
    }
}

void depthfirst(int n)
{
    if(n == N)
    {
        int val = calc();
        if(val < Answer)
        {
            setans();
            Answer = val;
        }
        return;
    }
    for(int i = 0; i < N; i++)
    {
        if(!check[i])
        {
            check[i] = true;
            points[n] = i;
            depthfirst(n + 1);
            check[i] = false;
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

		Answer = 1000000000;
		cin >> N >> M;


        for(int i = 0; i < N; i++)
        {
            check[i] = false;
            pc[i] = 0;
        }
		for(int i = 0; i < M; i++)
        {
            cin >> p[i * 2].a >> p[i * 2].b;
            pc[p[i*2].a]++;
            pc[p[i*2].b]++;
            p[i * 2 + 1].b = p[i * 2].a;
            p[i * 2 + 1].a = p[i * 2].b;
        }
        sort(p, p + M * 2, compare);

        pi[0] = 0;
		for(int i = 1; i <= N; i++)
            pi[i] = pi[i-1] + pc[i-1];
        /////////////////////////
        ////////////////////////////////////////////////////////////////////
		if(N < 9)
        {
            depthfirst(0);
        }
        else
        {
            for(int i = 0; i < N; i++)
            {
                check[i] = true;
                findroute(i, 0);
                check[i] = false;
                if(Answer < 1000000000)
                    break;
            }
        }
		/////////////////////////////////////////////////////////////////////////////////////////////

		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
		for(int i = 0; i < N; i++)
            cout << ans[i] << " ";
        cout << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}
