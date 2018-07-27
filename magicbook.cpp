#include <iostream>
#include <string>

using namespace std;

int toint(char c)
{
    if(c == 'a')
        return 0;
    if(c == 'e')
        return 1;
    if(c == 'i')
        return 2;
    if(c == 'o')
        return 3;
    if(c == 'u')
        return 4;
    return -1;
}
int main()
{
    int T, test_case;

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
        int first = -2, last = 1001;
		/////////////////////////////////////////////////////////////////////////////////////////////

        string str;
        int len;
        int as[1000];
        int ac = 0;
        int counter[1000];
        cin >> len >> str;
        for(int i = 0; i < len; i++)
        {
            int val = toint(str[i]);
            if(val == 0)
            {
                as[ac] = i;
                counter[ac] = 1;
                ac++;
            }
            else if(val != -1)
            {
                for(int j = 0; j < ac; j++)
                {
                    if(counter[j] == val)
                    {
                        counter[j]++;
                        if(counter[j] == 5 && last - first > i - as[j])
                        {
                            first = as[j];
                            last = i;
                        }
                    }
                }
            }
        }
        if(first == -2)
            last = -2;
		/////////////////////////////////////////////////////////////////////////////////////////////

		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << endl;
		cout << first+1 << " " << last+1 << endl;
	}
    return 0;
}
