#include <iostream>
#include <cmath>
#define MAX 2000000001

using namespace std;

int ax[200000], ay[200000], bx[200000], by[200000];
int A, B;
double Answer;

void getData()
{
    cin >> A >> B;
    for(int i = 0; i < A; i++)
        cin >> ax[i] >> ay[i];
    for(int i = 0; i < B; i++)
        cin >> bx[i] >> by[i];
}
inline long long hypot(long long x1, long long y1, long long x2, long long y2)
{
    return (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
}

double getdist(int a, int b)
{
    int b1 = b % B, b2 = (b + 1) % B;
    long long d1 = hypot(ax[a], ay[a], bx[b1], by[b1]);
    long long d2 = hypot(ax[a], ay[a], bx[b2], by[b2]);
    long long d3 = hypot(bx[b1], by[b1], bx[b2], by[b2]);
    if(d1 < d2)
        swap(d1, d2);
    if(d1 > d2 + d3)
    {
        return sqrt(d2);
    }
    else
    {
        return sqrt(d1 - (d3 + d1 - d2) / (double)(4 * d3) * (d3 + d1 - d2));
    }
}

int main()
{
    int T, test_case;
	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
        getData();
		Answer = MAX;
		/////////////////////////////////////////////////////////////////////////////////////////////
		int t = 0;
		while(t < 2)
        {
        if(t == 1)
        {
            swap(A, B);
            swap(ax, bx);
            swap(ay, by);
        }
        int j = 0;
		double smallest = MAX;
		for(int i = 0; i < B; i++)
        {
            double dist = getdist(0, i);
            if(dist < smallest)
            {
                smallest = dist;
                j = i;
            }
        }
        if(smallest < Answer)
            Answer = smallest;
        for(int i = 0; i < A; i++)
        {
            double d1 = getdist(i, j);
            double d2 = getdist(i, j+1);
            double smallest;
            if(d1 < d2)
            {
                while(d1 <= d2)
                {
                    d2 = d1;
                    j--;
                    if(j < 0)
                        j += B;
                    d1 = getdist(i, j);
                }
                smallest = d2;
            }
            else
            {
                j++;
                while(d2 <= d1)
                {
                    d1 = d2;
                    d2 = getdist(i, ++j);
                }
                smallest = d1;
            }
            if(smallest < Answer)
                Answer = smallest;
        }
        t++;
        }
		/////////////////////////////////////////////////////////////////////////////////////////////

		// Print the answer to standard output(screen).
		cout << fixed;
		cout.precision(10);
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}
    return 0;
}
