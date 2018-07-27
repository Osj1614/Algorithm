#include <iostream>

using namespace std;

int roomx[100];
int roomy[100];
bool tree[2049][2049];

int abss(int a)
{
    if(a < 0)
        return -a;
    return a;
}

bool gettree(int tx, int ty, int bx, int by, int nx, int ny, int ntx, int nty, int nbx, int nby)
{
    if(tx > nbx || ty > nby || bx < ntx || by < nty)
    {
        return false;
    }
    else if(tx <= ntx && ty <= nty && bx >= nbx && by >= nby)
    {
        return tree[nx][ny];
    }
    else
    {
        int nmx = (ntx + nbx) / 2;
        int nmy = (nty + nby) / 2;
        return
            gettree(tx, ty, bx, by, nx * 2, ny * 2, ntx, nty, nmx, nmy) ||
            gettree(tx, ty, bx, by, nx * 2 + 1, ny * 2, nmx + 1, nty, nbx, nmy) ||
            gettree(tx, ty, bx, by, nx * 2, ny * 2 + 1, ntx, nmy + 1, nmx, nby) ||
            gettree(tx, ty, bx, by, nx * 2 + 1, ny * 2 + 1, nmx + 1, nmy + 1, nbx, nby);

    }
}

void inserttree(int ix, int iy, int nx, int ny, int ntx, int nty, int nbx, int nby)
{
    tree[nx][ny] = true;
    if(ix + 1023 == nx && iy + 1023 == ny)
        return;
    int nmx = (ntx + nbx) / 2;
    int nmy = (nty + nby) / 2;
    int rtx = ntx, rty = nty, rbx = nbx, rby = nby, rx = nx * 2, ry = ny * 2;
    if(nmx < ix)
    {
        rtx = nmx + 1;
        rx += 1;
    }
    else
        rbx = nmx;
    if(nmy < iy)
    {
        rty = nmy + 1;
        ry += 1;
    }
    else
        rby = nmy;
    inserttree(ix, iy, rx, ry, rtx, rty, rbx, rby);
}

int main()
{
    int tests;
    cin >> tests;
    for(int t = 0; t < tests; t++)
    {
        for(int i = 0; i < 2049; i++)
            for(int j = 0; j < 2049; j++)
                tree[i][j] = false;


        int rc, cc;
        cin >> rc >> cc;
        for(int r = 0; r < rc; r++)
        {
            cin >> roomx[r] >> roomy[r];
        }
        for(int c = 0; c < cc; c++)
        {
            int x, y;
            cin >> x >> y;
            int tx = 1, ty = 1, bx = 1024, by = 1024;
            for(int r = 0; r < rc; r++)
            {
                int dist = max(abss(roomx[r] - x), abss(roomy[r] - y)) - 1;
                tx = max(tx, roomx[r] - dist);
                ty = max(ty, roomy[r] - dist);
                bx = min(bx, roomx[r] + dist);
                by = min(by, roomy[r] + dist);
            }
            if(gettree(tx, ty, bx, by, 1, 1, 1, 1, 1024, 1024))
                cout << "B ";
            else
                cout << "G ";

            inserttree(x, y, 1, 1, 1, 1, 1024, 1024);
        }
        cout << endl;
    }

    return 0;
}
