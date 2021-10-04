#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

int main()
{
    blaze;
    int a[] = {2, 1, 5, 1, 3, 2};
    int k = 3;
    int n = sizeof(a) / sizeof(a[0]);
    int sum = 0, maxSum = INT_MIN, sliderBegin = 0;
    for (int i = 0; i < n; ++i)
    {
        sum += a[i]; // add the next element
        // slide the window, we don't need to slide if we've not hit the required window size of 'k'
        if (i >= k - 1)
        {
            maxSum = max(maxSum, sum);
            sum -= a[sliderBegin]; // subtract the element going out
            sliderBegin++;         // slide the window ahead
        }
    }
    cout << maxSum << endl;
    return 0;
}