/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/

#include <iostream>
#include <string>
#include <queue>

using namespace std;

int Answer;
char str[5000];
int len;
int combo = 0;
bool check[5000];
queue<int> stops;
queue<int> ans;

int main(int argc, char** argv)
{
	int T, test_case;

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{

		Answer = 0;
		ans = queue<int>();
		stops = queue<int>();
		cin >> len >> str;
		fill(check, check + len, false);
		/////////////////////////////////////////////////////////////////////////////////////////////
		int first = 0;
		stops.push(-1);
		ans.push(0);
		while(!stops.empty())
        {
            first = stops.front() + 1;
            Answer = ans.front();
            combo = 0;
            stops.pop();
            ans.pop();
            if(first == len)
                break;

            for(int i = first + 1; i < len; i++)
            {
                if(str[first] == str[i] && !check[i])
                {
                    stops.push(i);
                    ans.push(Answer + 1);
                    combo = 1;
                    check[i] = true;
                }
                else if(str[first + combo] == str[i] && !check[i])
                {
                    stops.push(i);
                    ans.push(Answer + 1);
                    combo++;
                    check[i] = true;
                }
                else
                    combo = 0;
            }
        }
        if(first != len)
            Answer = 0;
		/////////////////////////////////////////////////////////////////////////////////////////////

		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}
