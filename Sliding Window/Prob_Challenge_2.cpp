#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

int main()
{
    blaze;
    string s = "abbcabc", pattern = "abc";
    int sliderBegin = 0, matched = 0;
    vector<int> v;
    unordered_map<char, int> umap;
    for (auto &it : pattern)
    {
        umap[it]++;
    }

    for (int sliderEnd = 0; sliderEnd < s.size(); ++sliderEnd)
    {
        if (umap.find(s[sliderEnd]) != umap.end())
        {
            umap[s[sliderEnd]]--;
            if (umap[s[sliderEnd]] == 0)
            {
                matched++;
            }
        }

        if (matched == umap.size())
        {
            v.push_back(sliderBegin);
        }

        if (sliderEnd >= pattern.size() - 1)
        {
            if (umap.find(s[sliderBegin]) != umap.end())
            {
                if (umap[s[sliderBegin]] == 0)
                {
                    matched--;
                }
            }
            umap[s[sliderBegin]]++;
            sliderBegin++;
        }
    }

    for (int i = 0; i < v.size(); ++i)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}