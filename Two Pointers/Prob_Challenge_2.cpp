#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

int getValidCharIdx(const string &str, int idx)
{
    int backSpaceCount = 0;
    while (idx >= 0)
    {
        if (str[idx] == '#') // found a backspace character
        {
            backSpaceCount++;
        }
        else if (backSpaceCount > 0) // a non backspace character
        {
            backSpaceCount--;
        }
        else
            break;

        idx--; // skip a backspace or valid character
    }

    return idx;
}

int main()
{
    blaze;
    string s = "xywrrmp", t = "xywrrmu#p";
    // use two pointers to compare the strings
    int idx1 = s.size() - 1, idx2 = t.size() - 1, flag = 1;
    while (idx1 >= 0 or idx2 >= 0)
    {
        int i1 = getValidCharIdx(s, idx1);
        int i2 = getValidCharIdx(t, idx2);

        if (i1 < 0 and i2 < 0) // reached the end of both the strings
        {
            flag = 1;
            break;
        }

        if (i1 < 0 or i2 < 0) // reached the end of one of the strings
        {
            flag = 0;
            break;
        }

        if (s[i1] != t[i2])
        {
            flag = 0;
            break;
        }

        idx1 = i1 - 1;
        idx2 = i2 - 1;
    }
    cout << (flag ? "Yes" : "No") << endl;

    return 0;
}