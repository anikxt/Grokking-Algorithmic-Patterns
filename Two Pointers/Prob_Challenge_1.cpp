#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

int main()
{
    blaze;
    int a[] = {4, 1, 2, -1, 1, -3}, target = 1; // -3 -1 1 2 4
    int n = sizeof(a) / sizeof(a[0]);
    sort(a, a + n);
    int lowOuter = 0, highOuter = n - 1;
    while (lowOuter < highOuter)
    {
        int lowInner = lowOuter + 1, highInner = highOuter - 1;
        while (lowInner < highInner)
        {
            int res = a[lowOuter] + a[lowInner] + a[highInner] + a[highOuter];
            if (res == target)
            {
                cout << a[lowOuter] << " " << a[lowInner++] << " " << a[highInner--] << " " << a[highOuter] << endl;
            }
            else if (res > target)
            {
                highInner--;
            }
            else
                lowInner++;
        }
        highOuter--;
    }
    return 0;
}