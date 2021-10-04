#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

int main()
{
    blaze;
    int a[] = {2, 3, 3, 3, 6, 9, 9};
    int n = sizeof(a) / sizeof(a[0]);
    int nextDistinct = 1;
    for (int i = 0; i < n; ++i)
    {
        if (a[nextDistinct - 1] != a[i])
        {
            a[nextDistinct] = a[i];
            nextDistinct++;
        }
    }
    cout << nextDistinct << endl;
    for (int i = 0; i < nextDistinct; ++i)
    {
        cout << a[i] << " ";
    }
    return 0;
}