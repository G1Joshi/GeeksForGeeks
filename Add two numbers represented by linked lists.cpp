#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

struct Node *buildList(int size)
{
    int val;
    cin >> val;

    Node *head = new Node(val);
    Node *tail = head;

    for (int i = 0; i < size - 1; i++)
    {
        cin >> val;
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

void printList(Node *n)
{
    while (n)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

struct Node *addTwoLists(struct Node *first, struct Node *second);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;

        cin >> n;
        Node *first = buildList(n);

        cin >> m;
        Node *second = buildList(m);

        Node *res = addTwoLists(first, second);
        printList(res);
    }
    return 0;
}

Node *reverse(Node *node)
{
    Node *p, *c, *n;
    c = node;
    p = NULL;
    while (c)
    {
        n = c->next;
        c->next = p;
        p = c;
        c = n;
    }
    return p;
}

struct Node *addTwoLists(struct Node *first, struct Node *second)
{
    Node *sum = NULL;
    first = reverse(first);
    second = reverse(second);
    int carry = 0;
    while (first || second || carry)
    {
        int num = carry;
        if (first)
            num += first->data;
        if (second)
            num += second->data;
        carry = num / 10;
        num = num % 10;
        Node *node = new Node(num);
        node->next = sum;
        sum = node;
        if (first)
            first = first->next;
        if (second)
            second = second->next;
    }
    return sum;
}
