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

Node *findMiddle(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    while (fast != NULL and fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

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

bool palindromeCheck(Node *head)
{
    if (head == NULL or head->next == NULL)
        return true;
    Node *slow = head;
    Node *fast = head;
    Node *ptr2 = slow->next;
    while (fast != NULL and fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node *headSecondHalf = reverse(slow);      // reverse the second half
    Node *copyHeadSecondHalf = headSecondHalf; // store the head of reverse part to revert back later

    // compare the first and the second half
    while (head != NULL and headSecondHalf != NULL)
    {
        if (head->data != headSecondHalf->data)
        {
            break; // not a palindrome
        }
        head = head->next;
        headSecondHalf = headSecondHalf->next;
    }

    reverse(copyHeadSecondHalf);
    if (head == NULL or headSecondHalf == NULL)
    {
        return true;
    }
    return false;
}

int main()
{
    blaze;
    Node *head = new Node(2);
    head->next = new Node(4);
    head->next->next = new Node(6);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(2);
    cout << "isPalindrome: " << (palindromeCheck(head) ? "Yes" : "No") << endl;

    head->next->next->next->next->next = new Node(2);
    cout << "isPalindrome: " << (palindromeCheck(head) ? "Yes" : "No") << endl;
    return 0;
}