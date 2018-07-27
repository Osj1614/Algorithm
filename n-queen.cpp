#include <iostream>

using namespace std;

bool column[200];
bool daegak[200];
bool daegak2[200];
int n;

int nqueen(int row)
{
    if(row == n)
        return 1;
    int count = 0;
    for(int i = 0; i < n; i++)
    {
        if(!column[i])
        {
            int dae = row + i;
            int dae2 = row - i + n;
            if(!daegak[dae] && !daegak2[dae2])
            {
                column[i] = true;
                daegak[dae] = true;
                daegak2[dae2] = true;
                count += nqueen(row + 1);
                column[i] = false;
                daegak[dae] = false;
                daegak2[dae2] = false;
            }
        }
    }
    return count;
}

int main()
{
    cin >> n;
    for(int i = 0; i < n * 2; i++)
    {
        column[i] = daegak[i] = daegak2[i] = false;
    }
    cout << nqueen(0);
    return 0;
}
