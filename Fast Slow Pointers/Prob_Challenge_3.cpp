#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

class Node
{
public:
    int data = 0;
    Node *next;

    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

int findNextIdx(const vector<int> &arr, bool isForward, int currentIdx)
{
    bool direction = arr[currentIdx] >= 0;
    if (isForward != direction)
    {
        return -1; // change in direction, return -1
    }

    // wrap around for negative numbers
    int nextIdx = (currentIdx + arr[currentIdx] + arr.size()) % arr.size();

    // one element cycle, return -1
    if (nextIdx == currentIdx)
    {
        nextIdx = -1;
    }

    return nextIdx;
}

bool loopExists(const vector<int> &arr)
{
    for (int i = 0; i < arr.size(); ++i)
    {
        bool isForward = arr[i] >= 0; // if we are moving forward or not
        int slow = i, fast = i;

        // if slow or fast becomes '-1' this means we can't find cycle for this number
        do
        {
            slow = findNextIdx(arr, isForward, slow); //  move one step for slow pointer
            fast = findNextIdx(arr, isForward, fast); // move one step for fast pointer
            if (fast != -1)
            {
                fast = findNextIdx(arr, isForward, fast); //  move another step for fast pointer
            }
        } while (slow != -1 and fast != -1 and slow != fast);

        if (slow != -1 and slow == fast)
        {
            return true;
        }
    }

    return false;
}

int main()
{
    blaze;
    cout << (loopExists(vector<int>{1, 2, -1, 2, 2}) ? "Yes" : "No") << endl;
    cout << (loopExists(vector<int>{2, 2, -1, 2}) ? "Yes" : "No") << endl;
    cout << (loopExists(vector<int>{2, 1, -1, -2}) ? "Yes" : "No") << endl;
    return 0;
}