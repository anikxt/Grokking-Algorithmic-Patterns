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

// Time Complexity - O(N) Space Complexity - O(N)

int calculateLength(Node *slow)
{
    Node *current = slow;
    int cycleLength = 0;
    do
    {
        current = current->next;
        cycleLength++;
    } while (current != slow);
    return cycleLength;
}

int findCycleLength(Node *head)
{
    Node *slow = head;
    Node *fast = head;

    while (fast != NULL and fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (slow == fast)
        {
            return calculateLength(slow); // found the cycle
        }
    }
    return 0;
}

int main()
{
    blaze;
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);

    // Case 1
    head->next->next->next->next->next->next = head->next->next;
    cout << "Cycle Length: " << findCycleLength(head) << endl;

    // Case 2
    head->next->next->next->next->next->next = head->next->next->next;
    cout << "Cycle Length: " << findCycleLength(head) << endl;

    return 0;
}