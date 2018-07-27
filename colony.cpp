#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int ftree[400004];
int treesize = 0;

void updateTree(int val, int index)
{
    if(index == 0)
        return;
    for(int i = index; i <= treesize; i+= i & (-i))
        ftree[i] += val;
}

int getTree(int right)
{
    int i = right;
    int sum = 0;
    while(i > 0)
    {
        sum += ftree[i];
        i -= i & -i;
    }
    return sum;
}

class simpley
{
    public:
    int y;
    bool two;
    int index;

    simpley(int _y, bool _two, int _index)
    {
        y = _y;
        two = _two;
        index = _index;
    }

    bool operator <(const simpley& right) const
    {
        return y < right.y;
    }
};

class PS
{
    public:
    long long x, y, y2;
    int type;
    PS(long long _x, long long _y, long long _y2, int _type)
    {
        x = _x;
        y = _y;
        y2 = _y2;
        type = _type;
    }

    PS(long long _x, long long _y)
    {
        x = _x;
        y = _y;
        y2 = 0;
        type = 0;
    }
    bool operator <(const PS& right) const
    {
        if(x == right.x)
            return type > right.type;
        return x < right.x;
    }
};

class Point
{
    public:
    long long x, y;
    Point()
    {
        x = 0;
        y = 0;
    }
    Point(int _x, int _y)
    {
        x = _x;
        y = _y;
    }
};

Point p1[100000];
Point p2[100000];
vector<PS> vec;
vector<simpley> sy;
int N;

void setvec(int ti)
{
    vec.clear();
    for(int i = 0; i <= ti; i++)
    {
        vec.push_back(PS(p1[i].x + p1[i].y, p1[i].x - p1[i].y));
        long long len = ti - i;
        vec.push_back(PS(p2[i].x + p2[i].y - len, p2[i].x - p2[i].y - len, p2[i].x - p2[i].y + len, 1));
        vec.push_back(PS(p2[i].x + p2[i].y + len, p2[i].x - p2[i].y - len, p2[i].x - p2[i].y + len, -1));
    }
    sort(vec.begin(), vec.end());

    sy.clear();
    for(int i = 0; i < vec.size(); i++)
    {
        sy.push_back(simpley(vec[i].y, false, i));
        if(vec[i].type != 0)
            sy.push_back(simpley(vec[i].y2, true, i));
    }
    sort(sy.begin(), sy.end());
    int num = 0;
    int prev = 2147000001;
    for(auto y : sy)
    {
        if(prev != y.y)
        {
            num++;
            prev = y.y;
        }
        if(y.two)
            vec[y.index].y2 = num;
        else
            vec[y.index].y = num;
    }
    treesize = 1;
    while(treesize < num)
        treesize *= 2;
}

void input()
{
    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> p2[i].x >> p2[i].y >> p1[i].x >> p1[i].y;
}

void reset()
{
    for(int i = 0; i <= treesize; i++)
        ftree[i] = 0;
}

bool isPossible(int ti)
{
    setvec(ti);
    reset();
    for(int i = 0; i < vec.size(); i++)
    {
        if(vec[i].type == 0)
        {
            if(getTree(vec[i].y) > 0)
            {
                return true;
            }
        }
        else
        {
            updateTree(vec[i].type, vec[i].y);
            updateTree(-vec[i].type, vec[i].y2 + 1);
        }
    }
    return false;
}

int calc()
{
    int left = 0, right = N - 1;
    while(left < right)
    {
        int mid = (left + right) / 2;
        if(isPossible(mid))
            right = mid;
        else
            left = mid + 1;
    }

    if(left == N - 1)
    {
        if(isPossible(N - 1))
        {
            return N;
        }
        else
            return -1;
    }
    return left + 1;
}

int main(int argc, char** argv)
{
	int T, test_case;


	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
        input();
		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << endl;
		cout << calc() << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}
