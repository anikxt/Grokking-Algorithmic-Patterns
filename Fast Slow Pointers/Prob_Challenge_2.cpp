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

Node *reverse(Node *head)
{
    Node *prev = NULL;
    while (head != NULL)
    {
        Node *next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}

void rearrange(Node *head)
{
    Node *slow = head;
    Node *fast = head;

    while (fast != NULL and fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    Node *headSecondHalf = reverse(slow);
    Node *headFirstHalf = head;

    // rearrange
    while (head != NULL and headSecondHalf != NULL)
    {
        Node *temp = headFirstHalf->next;
        headFirstHalf->next = headSecondHalf;
        headFirstHalf = temp;

        temp = headSecondHalf->next;
        headSecondHalf->next = headFirstHalf;
        headSecondHalf = temp;
    }

    // set the next of the last node to 'NULL'
    if (headFirstHalf != NULL)
    {
        headFirstHalf->next = NULL;
    }
    return;
}

int main()
{
    blaze;
    Node *head = new Node(2);
    head->next = new Node(4);
    head->next->next = new Node(6);
    head->next->next->next = new Node(8);
    head->next->next->next->next = new Node(10);
    head->next->next->next->next->next = new Node(12);

    rearrange(head);

    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
    return 0;
}