#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

int main()
{
    blaze;
    int a[] = {-3, 0, 1, 2, -1, 1, -2};
    int n = sizeof(a) / sizeof(a[0]);
    sort(a, a + n);
    for (int i = 0; i < n - 2; ++i)
    {
        int low = i + 1, high = n - 1;
        while (low < high)
        {
            int ans = a[i] + a[low] + a[high];
            if (ans == 0)
            {
                cout << a[i] << " " << a[low] << " " << a[high] << endl;
                low++;
                high--;
            }
            else if (ans < 0)
            {
                low++;
            }
            else
                high--;
        }
    }
    return 0;
}