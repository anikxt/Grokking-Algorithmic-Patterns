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

Node *findCycleHead(int cycleLength, Node *head)
{
    Node *ptr1 = head, *ptr2 = head;
    // move ptr2 ahead 'cycleLength' nodes
    while (cycleLength--)
    {
        ptr2 = ptr2->next;
    }

    // increment both pointers until they meet at the start of the cycle
    while (ptr1 != ptr2)
    {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return ptr1;
}

Node *findCycleLength(Node *slow, Node *head)
{
    Node *current = slow;
    int cycleLength = 0;
    do
    {
        current = current->next;
        cycleLength++;
    } while (current != slow);
    return findCycleHead(cycleLength, head);
}

Node *cycleDetection(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    while (fast != NULL and fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (slow == fast)
        {
            return findCycleLength(slow, head);
        }
    }
    return head;
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
    cout << "Cycle Head Data: " << cycleDetection(head)->data << endl;

    // Case 2
    head->next->next->next->next->next->next = head->next->next->next;
    cout << "Cycle Head Data: " << cycleDetection(head)->data << endl;

    // Case 3
    head->next->next->next->next->next->next = head;
    cout << "Cycle Head Data: " << cycleDetection(head)->data << endl;

    return 0;
}