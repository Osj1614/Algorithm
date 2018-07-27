#include <iostream>

using namespace std;

// 0: 1 2 3 4
int code[26][82]; //code: 0:ºóÄ­ 1:Ã¼Å© 2:Áö³ª°¨
int dirs; // 0:1234  1:2  2:12321 3:1233 4:2124 5:12123 6:121234 7:12 8:123414 9:12334
int curdir;
int sum = 0;
bool jumped;
void flood(int x, int y)
{
    code[y][x] = 2;
    bool jump = false;
    if(code[y][x+1] == 1)
    {
        if(curdir != 1)
            dirs = dirs*10 + 1;
        curdir = 1;
        flood(x + 1, y);
        jump = true;
    }
    if(code[y+1][x] == 1)
    {
        if(jump)
            jumped = true;
        if(curdir != 2)
            dirs = dirs*10 + 2;
        curdir = 2;
        flood(x, y+1);
        jump = true;
    }
    if(code[y][x-1] == 1)
    {
        if(jump)
            jumped = true;
        if(curdir != 3)
            dirs = dirs*10 + 3;
        curdir = 3;
        flood(x - 1, y);
        jump = true;
    }
    if(code[y-1][x] == 1)
    {
        if(jump)
            jumped = true;
        if(curdir != 4)
            dirs = dirs*10 + 4;
        curdir = 4;
        flood(x, y - 1);
    }
}

int main()
{
    int tc;
    cin >> tc;
    for(int t = 0; t < tc; t++)
    {
        int r, c;
        cin >> r >> c;
        for(int x = 0; x < 82; x++)
            for(int y = 0; y < 27; y++)
                code[y][x] = 0;
        for(int y = 1; y <= r; y++)
        {
            for(int x = 1; x <= c; x++)
            {
                char m;
                cin >> m;
                if(m == '*')
                    code[y][x] = 1;
            }
        }

        for(int y = 1; y <= r; y++)
        {
            for(int x = 1; x <= c; x++)
            {
                if(code[y][x] == 1)
                {
                    curdir = 0;
                    dirs = 0;
                    jumped = false;
                    flood(x, y);
                    switch(dirs)
                    {
                        case 1234:
                            if(jumped)
                                sum += 9;
                            else
                                sum += 0;
                            break;
                        case 0:
                        case 2: sum += 1;
                            break;
                        case 12321: sum += 2;
                            break;
                        case 123: sum += 3;
                            break;
                        case 234:
                        case 2124: sum += 4;
                            break;
                        case 12123: sum += 5;
                            break;
                        case 121234: sum += 6;
                            break;
                        case 12: sum += 7;
                            break;
                        case 123414: sum += 8;
                            break;
                    }
                }
            }
        }
        cout << sum << endl;
        sum = 0;
    }
    return 0;
}
