/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/

#include <iostream>
#include <algorithm>
#define MAX 1000000001

using namespace std;

class memo
{
    public:
    int py;
    int h;
    bool operator <(const memo& right) const
    {
        return py < right.py;
    }
};

int bigger(int a, int b)
{
    if(a > b)
        return a;
    return b;
}

int Answer;
int N;
memo memos[10000];
int mh[10010];

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
	mh[0] = -MAX;
	for(test_case = 0; test_case  < T; test_case++)
	{
		Answer = 1;
		int dummy;
		cin >> N;
		for(int i = 0; i < N; i++)
        {
            cin >> dummy >> memos[i].py >> memos[i].h;
            mh[i + 1] = MAX;
        }
        sort(memos, memos + N);
        /////////////////////////////////////////////////////////////////////////////////////////////
		for(int i = 0; i < N; i++)
        {
            for(int j = Answer; j > 0; j--)
            {
                if(mh[j] <= memos[i].py)
                {
                    int h = bigger(memos[i].py, mh[j] + memos[i].h);
                    if(mh[j + 1] > h)
                        mh[j + 1] = h;
                    if(j == Answer)
                        Answer++;
                }
                if(mh[j] + memos[i].h < memos[i].py)
                {
                    mh[j] += memos[i].h;
                }
                else if(mh[j] <= memos[i].py)
                {
                    mh[j] = memos[i].py + memos[i].h + 1;
                }
                else
                {
                    mh[j] += memos[i].h;
                }
            }
            mh[1] = memos[i].py;
        }
		/////////////////////////////////////////////////////////////////////////////////////////////

		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << endl;
		cout << N - Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}
