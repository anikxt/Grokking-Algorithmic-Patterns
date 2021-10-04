#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

int main()
{
    blaze;
    int a[] = {2, 1, 5, 2, 3, 2};
    int S = 7;
    int n = sizeof(a) / sizeof(a[0]);
    int sliderBegin = 0, windowSum = 0, minSize = INT_MAX;
    for (int sliderEnd = 0; sliderEnd < n; ++sliderEnd)
    {
        windowSum += a[sliderEnd]; // add the next element
        // shrink the window as small as possible until the 'windowSum' is smaller than S
        while (windowSum >= S)
        {
            minSize = min(minSize, sliderEnd - sliderBegin + 1);
            windowSum -= a[sliderBegin]; // subtract the element going out
            sliderBegin++;               // slide the window ahead
        }
    }
    cout << minSize << endl;
    return 0;
}