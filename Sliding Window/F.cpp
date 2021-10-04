#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

int main()
{
    blaze;
    string s = "aabc";
    int k = 2;
    int sliderBegin = 0, maxSize = INT_MIN, maxRepeatLetterCount = 0;
    unordered_map<char, int> umap;
    // try to extend the range [windowStart, windowEnd]
    for (int sliderEnd = 0; sliderEnd < s.size(); ++sliderEnd)
    {
        umap[s[sliderEnd]]++;
        maxRepeatLetterCount = max(maxRepeatLetterCount, umap[s[sliderEnd]]);
        // current window size is from windowStart to windowEnd, overall we have a letter which is
        // repeating 'maxRepeatLetterCount' times, this means we can have a window which has one
        // letter repeating 'maxRepeatLetterCount' times and the remaining letters we should replace.
        // if the remaining letters are more than 'k', it is the time to shrink the window as we
        // are not allowed to replace more than 'k' letters
        while (sliderEnd - sliderBegin + 1 - maxRepeatLetterCount > k)
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