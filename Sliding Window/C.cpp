#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

int main()
{
    blaze;
    string s = "araaci";
    int k = 2;
    int sliderBegin = 0, distinctCount = 0, maxSize = INT_MIN;
    unordered_map<char, int> umap;
    // in the following loop we'll try to extend the range [windowStart, windowEnd]
    for (int sliderEnd = 0; sliderEnd < s.size(); ++sliderEnd)
    {
        umap[s[sliderEnd]]++;
        // shrink the sliding window, until we are left with 'k' distinct characters in the frequency map
        while (umap.size() > k)
        {
            umap[s[sliderBegin]]--;
            if (umap[s[sliderBegin]] == 0)
            {
                umap.erase(s[sliderBegin]);
            }
            sliderBegin++; // shrink the window
        }
        maxSize = max(maxSize, sliderEnd - sliderBegin + 1); // remember the maximum length so far
    }
    cout << maxSize << endl;
    return 0;
}