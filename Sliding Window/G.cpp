#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

int main()
{
    blaze;
    int a[] = {0, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1};
    int k = 3;
    int n = sizeof(a) / sizeof(a[0]);
    int sliderBegin = 0, maxSize = INT_MIN;
    unordered_map<int, int> umap;
    for (int sliderEnd = 0; sliderEnd < n; ++sliderEnd)
    {
        umap[a[sliderEnd]]++;
        while (umap[0] > k)
        {
            umap[a[sliderBegin]]--;
            if (umap[a[sliderBegin]] == 0)
            {
                umap.erase(a[sliderBegin]);
            }
            sliderBegin++;
        }
        maxSize = max(maxSize, sliderEnd - sliderBegin + 1);
    }
    cout << maxSize << endl;
    return 0;
}