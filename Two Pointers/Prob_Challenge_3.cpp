#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

int main()
{
    blaze;
    int a[] = {1, 2, 5, 3, 7, 10, 9, 12};
    int n = sizeof(a) / sizeof(a[0]);
    int low = 0, high = n - 1;
    // find the first number out of sorting order from the beginning
    while (low < n - 1 and a[low] <= a[low + 1])
    {
        low++;
    }

    if (low == n - 1) // if the array is sorted
    {
        cout << 0 << endl;
        return 0;
    }

    // find the first number out of sorting order from the end
    while (high > 0 and a[high] >= a[high - 1])
    {
        high--;
    }

    // find the maximum and minimum of the subarray
    int subarrayMax = INT_MIN, subarrayMin = INT_MAX;
    for (int i = low; i <= high; ++i)
    {
        subarrayMax = max(subarrayMax, a[i]);
        subarrayMin = min(subarrayMin, a[i]);
    }

    // extend the subarray to include any number which is bigger than the minimum of the subarray
    while (low > 0 and a[low - 1] > subarrayMin)
    {
        low--;
    }

    // extend the subarray to include any number which is bigger than the maximum of the subarray
    while (high < n - 1 and a[high + 1] < subarrayMax)
    {
        high++;
    }
    cout << high - low + 1 << endl;
    return 0;
}