#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

// INCOMPLETE

int main()
{
    blaze;
    string s = "catfoxcat";
    string words[] = {"cat", "fox"};
    int n = sizeof(words) / sizeof(words[0]);
    string f;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < words[i].size(); ++j)
        {
            f.push_back(words[i][j]);
        }
    }
    unordered_map<char, int> umap;
    for (auto &it : f)
    {
        umap[it]++;
    }

    int sliderBegin = 0, matched = 0;
    vector<int> v;
    for (int sliderEnd = 0; sliderEnd < s.size(); ++sliderEnd)
    {
        if (umap.find(s[sliderEnd]) != umap.end())
        {
            umap[s[sliderEnd]]--;
            if (umap[s[sliderEnd]] >= 0)
            {
                matched++;
            }
        }

        while (matched == umap.size())
        {
            v.push_back(sliderBegin);
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

    for (int i = 0; i < v.size(); ++i)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}