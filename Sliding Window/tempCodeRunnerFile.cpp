using namespace std;

#include <iostream>
#include <string>
#include <unordered_map>

class MinimumWindowsubstring
{
public:
    static string findsubstring(const string &str, const string &pattern)
    {
        int windowStart = 0, matched = 0, minLength = str.length() + 1, substrstart = 0;
        unordered_map<char, int> charFrequencyMap;
        for (auto chr : pattern)
        {
            charFrequencyMap[chr]++;
        }
        // try to extend the range [windowstart, windowEnd]
        for (int windowEnd = 0; windowEnd < str.length(); windowEnd++)
        {
            char rightchar = str[windowEnd];
            if (charFrequencyMap.find(rightchar) != charFrequencyMap.end())
            {
                charFrequencyMap[rightchar]--;
                if (charFrequencyMap[rightchar] >= 0)
                { // count every matching of a character
                    matched++;
                }
            }
            // shrink the window if we can, finish as soon as we remove a matched character
            while (matched == pattern.length())
            {
                if (minLength > windowEnd - windowStart + 1)
                {
                    minLength = windowEnd - windowStart + 1;
                    substrstart = windowStart;
                }

                char leftchar = str[windowStart++];
                if (charFrequencyMap.find(leftchar) != charFrequencyMap.end())
                {
                    // note that we could have redundant matching characters, therefore we'll decrement the
                    // matched count only when a useful occurrence of a matched character is going out of the
                    // window
                    if (charFrequencyMap[leftchar] == 0)
                    {
                        matched--;
                    }
                    charFrequencyMap[leftchar]++;
                }
            }
        }
        return minLength > str.length() ? "" : str.substr(substrstart, minLength);
    }
};

int main(int argc, char *argv[])
{
    cout << MinimumWindowsubstring::findsubstring("aabdec", "abc") << endl;
    cout << MinimumWindowsubstring::findsubstring("abdabca", "abc") << endl;
    cout << MinimumWindowsubstring::findsubstring("adcad", "abc") << endl;
}
