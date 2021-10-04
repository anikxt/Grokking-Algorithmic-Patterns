#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

int main()
{
    blaze;
    int a[] = {-2, -1, 0, 2, 3};
    int n = sizeof(a) / sizeof(a[0]);
    vector<int> res(n);
    int low = 0, high = n - 1, highIdx = n - 1;
    while (low < high)
    {
        if (a[low] * a[low] > a[high] * a[high])
        {
            res[highIdx--] = a[low] * a[low];
            low++;
        }
        else
        {
            res[highIdx--] = a[high] * a[high];
            high--;
        }
    }

    for (int i = 0; i < n; ++i)
    {
        cout << res[i] << " ";
    }

    return 0;
}