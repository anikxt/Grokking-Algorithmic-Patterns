#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

int main()
{
    blaze;
    int a[] = {1, 2, 3, 4, 6};
    int n = sizeof(a) / sizeof(a[0]);
    int target = 6;
    // int low = 0, high = n - 1;
    // while (low < high)
    // {
    //     if (a[low] + a[high] == target)
    //     {
    //         cout << low << " " << high << endl;
    //         break;
    //     }
    //     else if (a[low] + a[high] > target)
    //         high--;
    //     else
    //         low++;
    // }

    unordered_map<int, int> m;
    for (int i = 0; i < n; ++i)
    {
        if (m.find(target - a[i]) != m.end())
        {
            cout << m[target - a[i]] << " " << i << endl;
            break;
        }
        else
        {
            m[a[i]] = i;
        }
    }

    return 0;
}