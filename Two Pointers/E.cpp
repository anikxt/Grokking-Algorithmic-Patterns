#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

int main()
{
    blaze;
    int a[] = {1, 0, -1, 1}, target = -1;
    int n = sizeof(a) / sizeof(a[0]);
    sort(a, a + n);
    int closestTarget = INT_MAX, x, y, z, flag = 0;
    for (int i = 0; i < n - 2; ++i)
    {
        int low = i + 1, high = n - 1;
        while (low < high)
        {
            int res = a[i] + a[low] + a[high];
            if (abs(target - res) == 0)
            {
                cout << res << endl;
                flag = 1;
                break;
            }
            if (abs(target - res) < closestTarget)
            {
                closestTarget = target - res;
            }

            if (target - res > 0)
            {
                low++;
            }
            else
            {
                high--;
            }
        }
    }

    if (!flag)
        cout << target - closestTarget << endl;
    return 0;
}