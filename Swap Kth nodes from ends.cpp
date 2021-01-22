#include <iostream>

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

Node *swapkthnode(Node *head, int num, int K);

void addressstore(Node **arr, Node *head)
{
    Node *temp = head;
    int i = 0;
    while (temp)
    {
        arr[i] = temp;
        i++;
        temp = temp->next;
    }
}

bool check(Node **before, Node **after, int num, int K)
{
    if (K > num)
        return 1;
    return (before[K - 1] == after[num - K]) && (before[num - K] == after[K - 1]);
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int num, K, firstdata;
        cin >> num >> K;
        int temp;
        cin >> firstdata;
        Node *head = new Node(firstdata);
        Node *tail = head;
        for (int i = 0; i < num - 1; i++)
        {
            cin >> temp;
            tail->next = new Node(temp);
            tail = tail->next;
        }

        Node *before[num];
        addressstore(before, head);

        head = swapkthnode(head, num, K);

        Node *after[num];
        addressstore(after, head);

        if (check(before, after, num, K))
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }
}

void swap(Node **p, Node **q)
{
    Node *t = *p;
    *p = *q;
    *q = t;
}

Node *swapkthnode(Node *head, int num, int K)
{
    if (!head || K > num || K == num + 1 - K)
        return head;
    Node *a, *b, *c, *x, *y, *z;
    a = c = x = z = NULL;
    b = y = head;
    int i = 1;
    while (i < K)
    {
        a = b;
        b = b->next;
        ++i;
    }
    c = b->next;
    i = 0;
    while (i < num - K)
    {
        x = y;
        y = y->next;
        ++i;
    }
    z = y->next;
    if (K > num / 2)
    {
        swap(&a, &x);
        swap(&b, &y);
        swap(&c, &z);
    }
    if (abs(K - (num + 1 - K)) == 1)
    {
        a->next = c;
        c->next = b;
        b->next = z;
        return head;
    }
    b->next = y->next = NULL;
    if (!a)
    {
        x->next = b;
        y->next = c;
        return y;
    }
    else if (!x)
    {
        a->next = y;
        b->next = z;
        return b;
    }
    a->next = y;
    y->next = c;
    x->next = b;
    b->next = z;
    return head;
}
