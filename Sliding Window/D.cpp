#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

int main()
{
    blaze;
    char a[] = {'A', 'B', 'C', 'B', 'B', 'C'};
    int n = sizeof(a) / sizeof(a[0]);
    int sliderBegin = 0, maxFruit = INT_MIN;
    unordered_map<char, int> umap;
    // try to extend the range [windowStart, windowEnd]
    for (int sliderEnd = 0; sliderEnd < n; ++sliderEnd)
    {
        umap[a[sliderEnd]]++;
        // shrink the sliding window, until we are left with '2' fruits in the frequency map
        while (umap.size() > 2)
        {
            umap[a[sliderBegin]]--;
            if (umap[a[sliderBegin]] == 0)
            {
                umap.erase(a[sliderBegin]);
            }
            sliderBegin++;
        }
        maxFruit = max(maxFruit, sliderEnd - sliderBegin + 1);
    }
    cout << maxFruit << endl;
    return 0;
}