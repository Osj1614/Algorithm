/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 1000000000

using namespace std;

int Answer;

class path
{
    public:
    int cost;
    int to;
    path(int c, int t)
    {
        cost = c;
        to = t;
    }
};

class vertex
{
    public:
    vector<path> paths;
    vector<int> visited;
    int cost = MAX;
};

class visit
{
public:
    int ver;
    int prevc;
    int from;
    int cost;

    bool operator <(const visit& right) const
    {
        return cost > right.cost;
    }

    visit(int v, int pc, int f, int c)
    {
        ver = v;
        prevc = pc;
        from = f;
        cost = c;
    }
};

vertex v[100001];
priority_queue<visit> visits;
int N, M;
bool backward = false;

void flood(int ver, int prevc, int from, int cost)
{
    if(backward && v[ver].cost + cost < Answer)
        Answer = v[ver].cost + cost;

    v[ver].visited.push_back(from);

    if(v[ver].cost >= cost && !backward)
        v[ver].cost = cost;

    for(auto p : v[ver].paths)
    {
        if(p.cost >= prevc && find(v[p.to].visited.begin(), v[p.to].visited.end(), ver) == v[p.to].visited.end() && p.to != from)
        {
            visits.push(visit(p.to, p.cost, ver, cost + p.cost));
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
		Answer = MAX;
        cin >> N >> M;
        if(N <= 1000 && M <= 1000)
        {
        for(int i = 0; i < N; i++)
        {
            v[i].cost = MAX;
            v[i].paths.clear();
            v[i].visited.clear();
        }
		for(int i = 0; i < M; i++)
        {
            int f, t, c;
            cin >> f >> t >> c;
            v[f - 1].paths.push_back(path(c, t - 1));
            v[t - 1].paths.push_back(path(c, f - 1));
        }
		/////////////////////////////////////////////////////////////////////////////////////////////
		backward = false;
        for(auto p : v[0].paths)
            visits.push(visit(p.to, p.cost, 0, p.cost));
        while(!visits.empty())
        {
            visit vis = visits.top();
            visits.pop();
            flood(vis.ver, vis.prevc, vis.from, vis.cost);
        }

        for(auto p : v[N - 1].paths)
            visits.push(visit(p.to, p.cost, N - 1, p.cost));
        backward = true;
        while(!visits.empty())
        {
            visit vis = visits.top();
            visits.pop();
            flood(vis.ver, vis.prevc, vis.from, vis.cost);
        }
		/////////////////////////////////////////////////////////////////////////////////////////////
        }
		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << endl;
		if(Answer == MAX)
            Answer = -1;

        cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}
