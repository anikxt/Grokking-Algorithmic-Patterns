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

/* 
The sequence behavior tells us two things:
1. If the number N is less than or equal to 1000, then we reach the cycle or ‘1’ in at most 1001 steps.
2. For N > 1000, suppose the number has ‘M’ digits and the next number is ‘N1’.
From the Wikipedia, we know that the sum of the squares of the digits of ‘N’ is at most 9^2M, or 81M
(this will happen when all digits of ‘N’ are ‘9’).

This means:
1. N1 < 81M
2. As we know M = log(N + 1)
3. Therefore: N1 < 81 * log(N+1) => N1 = O(logN)

Time Complexity - O(logN) Space Complexity - O(1)
*/

int findSquareSum(int num)
{
    int sum = 0;
    while (num)
    {
        int digit = num % 10;
        sum += digit * digit;
        num /= 10;
    }
    return sum;
}

bool findHappyNumber(int num)
{
    int slow = num, fast = num;
    do
    {
        slow = findSquareSum(slow);                // move one step
        fast = findSquareSum(findSquareSum(fast)); // move two step
    } while (slow != fast);                        // found the cycle

    return slow == 1; // see if the cycle is stuck on the number '1'
}

int main()
{
    blaze;
    cout << findHappyNumber(23) << endl;
    cout << findHappyNumber(12) << endl;
    return 0;
}