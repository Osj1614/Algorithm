#include <iostream>

using namespace std;

int hmap[100][100];
int emap[100][100];
bool check[100][100];
int mx[100];
int my[100];
bool ecs[100][100];
int mcc[100];
int ecc[100];
int ec = 0;
int mc = 0;
int stacx[100000];
int stacy[100000];
int stacd[100000];
int sr = 0;
int sc = 0;
int width[100];
int r, d;

int ab(int a)
{
    if(a < 0)
        return -a;
    return a;
}
void push(int x, int y, int dis)
{
    if(!check[y][x])
    {
        stacx[sc] = x;
        stacy[sc] = y;
        stacd[sc] = dis;
        sc++;
        check[y][x] = true;
    }
}

void flood(int x, int y, int m, int dis)
{
    sr++;
    if(emap[y][x] > -1)
        ecs[m][emap[y][x]] = true;
    if(dis++ < d)
    {
        bool up = y > 0, down = y < 2*r - 2;
    int lux = x;
    int ldx = x;

    if(y <= r - 1)
        lux -= 1;
    if(y >= r - 1)
        ldx -= 1;

    if(up)
    {
        if(lux >= 0)
            if(hmap[y][x] >= hmap[y - 1][lux])
                push(lux, y - 1, dis);

        if(lux + 1 < width[y-1])
            if(hmap[y][x] >= hmap[y - 1][lux + 1])
                push(lux + 1, y - 1, dis);
    }

    if(x > 0)
    {
        if(hmap[y][x] >= hmap[y][x - 1])
            push(x - 1, y, dis);
    }
    if(x + 1 < width[y])
    {
        if(hmap[y][x] >= hmap[y][x + 1])
            push(x + 1, y, dis);
    }

    if(down)
    {
        if(ldx >= 0)
            if(hmap[y][x] >= hmap[y + 1][ldx])
                push(ldx, y + 1, dis);

        if(ldx + 1 < width[y + 1])
            if(hmap[y][x] >= hmap[y + 1][ldx + 1])
                push(ldx + 1, y + 1, dis);
    }
    }
    if(sr < sc)
        flood(stacx[sr], stacy[sr], m, stacd[sr]);
}

int main()
{
    int tc;
    cin >> tc;
    for(int t = 0; t < tc; t++)
    {
        cin >> r >> d;
        mc = 0;
        ec = 0;
        for(int y = 0; y < 2 * r - 1; y++)
        {
            width[y] = r * 2 - ab(y + 1 - r) - 1;
            for(int x = 0; x < width[y]; x++)
                cin >> hmap[y][x];
        }
        for(int y = 0; y < 2 * r - 1; y++)
            for(int x = 0; x < width[y]; x++)
            {
                emap[y][x] = -1;
                char c;
                cin >> c;
                if(c == 'E')
                    emap[y][x] = ec++;
                else if(c == 'M')
                {
                    mx[mc] = x;
                    my[mc++] = y;
                }
            }
        for(int m = 0; m < mc; m++)
        {
            for(int y = 0; y < 2 * r - 1; y++)
                for(int x = 0; x < width[y]; x++)
                {
                    check[y][x] = false;
                }
            mcc[m] = 0;
            for(int e = 0; e < ec; e++)
                ecs[m][e] = false;
            sr = -1;
            sc = 0;
            check[my[m]][mx[m]] = true;
            flood(mx[m], my[m], m, 0);
        }

        for(int e = 0; e < ec; e++)
            ecc[e] = 0;
        for(int m = 0; m < mc; m++)
        {
            for(int e = 0; e < ec; e++)
                if(ecs[m][e])
                {
                    mcc[m]++;
                    ecc[e]++;
                }
        }
        int ans = 0;
        while(true)
        {
            int smallest = 101;
            int index = -1;
            int m, e;
            for(m = 0; m < mc; m++)
                if(smallest > mcc[m] && mcc[m] > 0)
                {
                    smallest = mcc[m];
                    index = m;
                }
            if(index == -1)
                break;
            m = index;
            index = -1;
            smallest = 101;
            for(e = 0; e < ec; e++)
            {
                if(ecs[m][e] && smallest > ecc[e])
                {
                    smallest = ecc[e];
                    index = e;
                }
            }
            e = index;
            mcc[m] = 0;
            ecc[e] = 0;
            ans++;
            for(m = 0; m < mc; m++)
            {
                if(ecs[m][e])
                {
                    ecs[m][e] = false;
                    mcc[m]--;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
