#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

/* 
Time Complexity - O(N * M * Len)
where ‘N’ is the number of characters in the given string, ‘M’ is the total number of words, and ‘Len’ is the length of a word.

Space Complexity - O(M)
since at most, we will be storing all the words in the two HashMaps. In the worst case, we also need O(N) space for the resulting list. 
So, the overall space complexity of the algorithm will be O(M+N).
*/

int main()
{
    blaze;
    string s = "catfoxcat";
    string words[] = {"cat", "fox"};
    int n = sizeof(words) / sizeof(words[0]);

    unordered_map<string, int> wordFrequencyMap;
    for (auto word : words)
    {
        wordFrequencyMap[word]++;
    }

    vector<int> resultIndices;
    int wordsCount = n, wordLength = words[0].size();
    for (int i = 0; i <= s.size() - wordsCount * wordLength; ++i)
    {
        unordered_map<string, int> wordsSeen;
        for (int j = 0; j < wordsCount; j++)
        {
            int nextWordIndex = i + j * wordLength;

            // get the next word from the string
            string word = s.substr(nextWordIndex, wordLength);

            if (wordFrequencyMap.find(word) == wordFrequencyMap.end()) // break if we don't need this word
            {
                break;
            }

            wordsSeen[word]++; // add the word to the 'wordsSeen' map

            // no need to process further if the word has higher frequency than required
            if (wordsSeen[word] > wordFrequencyMap[word])
            {
                break;
            }

            if (j + 1 == wordsCount) // store index if we have found all the words
            {
                resultIndices.push_back(i);
            }
        }
    }

    for (int i = 0; i < resultIndices.size(); ++i)
    {
        cout << resultIndices[i] << " ";
    }
    cout << endl;
    return 0;
}