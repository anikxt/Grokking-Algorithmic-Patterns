#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

int main()
{
    blaze;
    string s = "odicf", pattern = "dc";
    int sliderBegin = 0, matched = 0;
    unordered_map<char, int> charFrequencyMap;
    for (auto &it : pattern)
    {
        charFrequencyMap[it]++;
    }
    // our goal is to match all the characters from the 'charFrequencyMap' with the current window
    // try to extend the range [windowStart, windowEnd]
    for (int sliderEnd = 0; sliderEnd < s.size(); ++sliderEnd)
    {
        if (charFrequencyMap.find(s[sliderEnd]) != charFrequencyMap.end())
        {
            // decrement the frequency of the matched character
            charFrequencyMap[s[sliderEnd]]--;
            if (charFrequencyMap[s[sliderEnd]] == 0)
            {
                matched++;
            }
        }

        if (matched == charFrequencyMap.size())
        {
            cout << "true" << endl;
            return true;
        }

        if (sliderEnd >= pattern.size() - 1) // shrink the window
        {
            if (charFrequencyMap.find(s[sliderBegin]) != charFrequencyMap.end())
            {
                if (charFrequencyMap[s[sliderBegin]] == 0)
                {
                    matched--; // before putting the character back, decrement the matched count
                }
            }
            // put the character back for matching
            charFrequencyMap[s[sliderBegin]]++;
            sliderBegin++;
        }
    }
    cout << "false" << endl;
    return false;
}