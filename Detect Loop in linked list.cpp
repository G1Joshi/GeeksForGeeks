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

void push(struct Node **head_ref, int new_data)
{
    struct Node *new_Node = new Node(new_data);
    new_Node->next = (*head_ref);
    (*head_ref) = new_Node;
}
int detectloop(struct Node *list);

int main()
{
    int t, n, c, x, i;
    cin >> t;
    while (t--)
    {
        cin >> n;
        struct Node *head = NULL;
        struct Node *temp;
        struct Node *s;
        cin >> x;
        push(&head, x);
        s = head;
        for (i = 1; i < n; i++)
        {
            cin >> x;
            push(&head, x);
        }
        cin >> c;
        if (c > 0)
        {
            c = c - 1;
            temp = head;
            while (c--)
                temp = temp->next;
            s->next = temp;
        }
        int g = detectloop(head);
        if (g)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}

int detectloop(Node *head)
{

    Node *f = head;
    Node *s = head;
    while (f && s && f->next)
    {
        s = s->next;
        f = f->next->next;
        if (s == f)
        {
            return 1;
        }
    }
    return 0;
}