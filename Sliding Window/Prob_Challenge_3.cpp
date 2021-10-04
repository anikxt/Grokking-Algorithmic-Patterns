#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

int main()
{
    blaze;
    string s = "aabdec", pattern = "abc";
    int sliderBegin = 0, minSize = s.size() + 1, matched = 0, minSubStr = 0;
    unordered_map<char, int> umap;
    for (auto &it : pattern)
    {
        umap[it]++;
    }
    // try to extend the range [windowStart, windowEnd]
    for (int sliderEnd = 0; sliderEnd < s.size(); ++sliderEnd)
    {
        if (umap.find(s[sliderEnd]) != umap.end())
        {
            umap[s[sliderEnd]]--;
            if (umap[s[sliderEnd]] >= 0) // count every matching of a character
            {
                matched++;
            }
        }
        // shrink the window if we can, finish as soon as we remove a matched character
        while (matched == umap.size())
        {
            if (minSize > sliderEnd - sliderBegin + 1)
            {
                minSize = sliderEnd - sliderBegin + 1;
                minSubStr = sliderBegin;
            }

            // note that we could have redundant matching characters, therefore we'll decrement the
            // matched count only when a useful occurrence of a matched character is going out of the
            // window
            if (umap.find(s[sliderBegin]) != umap.end())
            {
                if (umap[s[sliderBegin]] == 0)
                {
                    matched--;
                }
                umap[s[sliderBegin]]++;
                sliderBegin++;
            }
        }
    }

    cout << s.substr(minSubStr, minSize) << endl;
    return 0;
}