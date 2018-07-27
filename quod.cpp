#include <iostream>

using namespace std;


int m[11][11];

int test()
{
    for(int i = 1; i < 11; i++)
        for(int j = 0; j < 11; j++)
        {
            for(int k = i; k < 11 - j; k++)
                for(int l = 0; l < 11 - i - j; l++)
                    if(m[k][l] == m[k - i][l + j] && m[k][l] == m[k - i + j][l + j + i] && m[k][l] == m[k + j][l + i])
                    {
                        if(m[k][l] != 0)
                            return m[k][l];
                    }
        }
    return 0;
}

int main()
{
    int tests;
    cin >> tests;
    for(int t = 0; t < tests; t++)
    {
        for(int i = 0; i < 11; i++)
            for(int j = 0; j < 11; j++)
            {
                char c;
                cin >> c;
                if(c == 'R')
                    m[i][j] = 1;
                else if(c == 'B')
                    m[i][j] = 2;
                else
                    m[i][j] = 0;
            }
        switch(test())
        {
            case 0: cout << "No squares" << endl;
                break;
            case 1: cout << "Red" << endl;
                break;
            case 2: cout << "Blue" << endl;
                break;
        }
    }
    return 0;
}
