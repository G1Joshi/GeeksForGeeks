#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node *rotate(struct Node *head, int k);

void printList(Node *n)
{
    while (n != NULL)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, val, k;
        cin>>n;
        cin>> val;
        Node *head = new Node(val);
        Node *tail = head;
        for(int i=0; i<n-1; i++)
        {
            cin>> val;
            tail->next = new Node(val);
            tail = tail->next;
        }
        cin>> k;
        head = rotate(head,k);
        printList(head);
    }
    return 1;
}

Node* rotate(Node* head, int k)
{
    if(!head || !head->next) return head;
    Node *ptr=head, *temp=head;
    int n=0;
    while(ptr) {
        n++;
        ptr=ptr->next;
    }
    if(!k || k==n) return head;
    k=k%n;
    ptr=head;
    while(k>1) {
        k--;
        ptr=ptr->next;
    }
    if(!ptr) return head;
    head=ptr->next;
    ptr->next=NULL;
    ptr=head;
    while(ptr->next)
        ptr=ptr->next;
    ptr->next=temp;
    return head;
}
