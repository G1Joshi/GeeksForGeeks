#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

void append(struct Node** head_ref, struct Node **tail_ref,
            int new_data)
{
    struct Node* new_node = new Node(new_data);
    if (*head_ref == NULL)
        *head_ref = new_node;
    else
        (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}

struct Node *reverseList(struct Node *head);

void printList(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp  = temp->next;
    }
}

int main()
{
    int T,n,l;
    cin>>T;
    while(T--)
    {
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        for (int i=1; i<=n; i++)
        {
            cin>>l;
            append(&head, &tail, l);
        }
        head = reverseList(head);
        printList(head);
        cout << endl;
    }
    return 0;
}

Node* reverseList(Node *head)
{
    Node *pre, *cur, *nex;
    pre=NULL;
    cur=head;
    while(cur) {
        nex=cur->next;
        cur->next=pre;
        pre=cur;
        cur=nex;
    }
    return pre;
}
