#include<iostream>
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

Node* sortedMerge(struct Node* a, struct Node* b);

void printList(struct Node *n)
{
    while (n!=NULL)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        int data;
        cin>>data;
        struct Node *head1 = new Node(data);
        struct Node *tail1 = head1;
        for (int i = 1; i < n; ++i)
        {
            cin>>data;
            tail1->next = new Node(data);
            tail1 = tail1->next;
        }
        cin>>data;
        struct Node *head2 = new Node(data);
        struct Node *tail2 = head2;
        for(int i=1; i<m; i++)
        {
            cin>>data;
            tail2->next = new Node(data);
            tail2 = tail2->next;
        }
        Node *head = sortedMerge(head1, head2);
        printList(head);
    }
    return 0;
}

Node* sortedMerge(Node* head_A, Node* head_B)
{
    Node *f, *s, *t, *p;
    f=head_A;
    s=head_B;
    t=NULL;
    if(f->data<s->data) {
        t=f;
        f=f->next;
        t->next=NULL;
    }
    else {
        t=s;
        s=s->next;
        t->next=NULL;
    }
    p=t;
    while(f && s) {
        if(f->data<s->data) {
            p->next=f;
            p=f;
            f=f->next;
            p->next=NULL;
        }
        else {
            p->next=s;
            p=s;
            s=s->next;
            p->next=NULL;
        }
    }
    if(f)
        p->next=f;
    else
        p->next=s;
    return t;
}
