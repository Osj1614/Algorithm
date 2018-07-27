#include <iostream>

using namespace std;

int prime[200];
bool isprime[1000001];
int pc = 0;

class Num
{
    public:
        int factor[200];
        Num(Num l, Num r)
        {
            for(int i = 0; i < pc; i++)
            {
                if(l.factor[i] > r.factor[i])
                    factor[i] = l.factor[i];
                else
                    factor[i] = r.factor[i];
            }
        }

        Num(int number)
        {
            for(int i = 0; i < pc; i++)
            {
                factor[i] = 0;
                int f = prime[i];
                if(f <= number)
                {
                    while(number % f == 0)
                    {
                        number /= f;
                        factor[i]++;
                    }
                }
            }
        }

};


int main()
{
    for(int i = 1; i <= 1000000; i++)
        isprime[i] = true;
    isprime[1] = false;
    for(int i = 1; i <= 1000; i++)
    {
        if(isprime[i])
        {
            prime[pc++] = i;
            for(int j = i * 2; j <= 1000000; j += i)
                isprime[j] = false;
        }
    }

    cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{

		Answer = 0;
		int N, M;
		cin >> N >> M;

		int b, l, r;
		cin >> b >> l >> r;
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
		   Implement your algorithm here.
		   The answer to the case will be stored in variable Answer.
		 */
		/////////////////////////////////////////////////////////////////////////////////////////////

		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}
