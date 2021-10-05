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

// Time Complexity - O(N) Space Complexity - O(1)

Node *findMiddle(Node *head)
{
    Node *slow = head, *fast = head;
    while (fast != NULL and fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

int main()
{
    blaze;
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    cout << "Middle Node: " << findMiddle(head)->data << endl;

    head->next->next->next->next->next = new Node(6);
    cout << "Middle Node: " << findMiddle(head)->data << endl;

    head->next->next->next->next->next->next = new Node(7);
    cout << "Middle Node: " << findMiddle(head)->data << endl;

    return 0;
}