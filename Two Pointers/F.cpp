#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

int main()
{
    blaze;
    int a[] = {-1, 4, 2, 1, 3}, target = 5;
    int n = sizeof(a) / sizeof(a[0]);
    sort(a, a + n);
    for (int i = 0; i < n - 2; ++i)
    {
        int low = i + 1, high = n - 1;
        while (low < high)
        {
            int res = a[i] + a[low] + a[high];
            if (res >= target)
            {
                high--;
            }
            else
            {
                for (int x = low + 1; x <= high; ++x)
                {
                    cout << a[i] << " " << a[low] << " " << a[x] << endl;
                }
                low++;
            }
        }
    }
    return 0;
}