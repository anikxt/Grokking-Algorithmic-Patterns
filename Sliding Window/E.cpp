#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

int main()
{
    blaze;
    string s = "aabccbb";
    int sliderBegin = 0, maxSize = INT_MIN;
    unordered_map<char, int> umap;
    for (int sliderEnd = 0; sliderEnd < s.size(); ++sliderEnd)
    {
        umap[s[sliderEnd]]++;
        while (umap[s[sliderEnd]] > 1)
        {
            umap[s[sliderBegin]]--;
            if (umap[s[sliderBegin]] == 0)
            {
                umap.erase(s[sliderBegin]);
            }
            sliderBegin++;
        }
        maxSize = max(maxSize, sliderEnd - sliderBegin + 1);
    }
    cout << maxSize << endl;
    return 0;
}