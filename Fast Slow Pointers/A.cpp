#include <bits/stdc++.h>
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//=======================
using namespace std;
//=======================

struct Node
{
    int data;
    Node *next;
};

bool hasCycle(Node *head)
{
    Node *slow = head;
    Node *fast = head;

    while (fast != NULL and fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (slow == fast)
        {
            return true; // found the cycle
        }
    }
    return false;
}

int main()
{
    blaze;
    Node *head = new Node;
    Node *temp = head;
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; ++i)
    {
        int x;
        cin >> x;
        temp->data = x;
        temp->next = new Node;
        temp = temp->next;
    }
    int x;
    cin >> x;
    temp->data = x;
    temp->next = NULL;

    temp = head;

    // Case 1

    return 0;
}