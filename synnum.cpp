/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/

#include <iostream>

using namespace std;

int Answer;

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
	int cn[200];
	int cc = 0;
    for(int i = 1; i < 10000; i++)
    {
        int nums[4];
        int n = 0;
        int num = i;
        while(num != 0)
        {
            nums[n] = num % 10;
            num /= 10;
            n++;
        }
        bool flag = true;
        for(int j = 0; j < n / 2; j++)
        {
            if(nums[j] != nums[n - j - 1])
            {
                flag = false;
            }
        }
        if(flag)
        {
            cn[cc] = i;
            cc++;
        }
    }
    cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{

		Answer = 4;
		/////////////////////////////////////////////////////////////////////////////////////////////
		int N;
		cin >> N;
		int M;
		int Ans[3];
		for(M = 0; M < cc; M++)
		{
		    if(N < cn[M])
		        break;
		}
		for(int i = 0; i < M; i++)
		{
		    if(cn[i] == N)
		    {
		        Answer = 1;
		        Ans[0] = i;
		        break;
		    }
		    if(Answer > 2)
		    {
		        for(int j = i; j < M; j++)
		        {
		            if(cn[i] + cn[j] == N)
		            {
		                Answer = 2;
		                Ans[0] = i;
		                Ans[1] = j;
		                break;
		            }
		            if(Answer > 3)
		            {
		                for(int k = j; k < M; k++)
		                {
        		            if(cn[i] + cn[j] + cn[k] == N)
	            	        {
		                        Answer = 3;
		                        Ans[0] = i;
		                        Ans[1] = j;
		                        Ans[2] = k;
		                        break;
		                    }
		                }
		            }
		        }
		    }
		}
		if(Answer == 4)
		    Answer = 0;
		/////////////////////////////////////////////////////////////////////////////////////////////

		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << endl;
		cout << Answer;
		for(int i = Answer - 1; i >= 0; i--)
		    cout << " " << cn[Ans[i]];
		cout << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}
