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

void append(struct Node** head_ref, struct Node **tail_ref, int new_data)
{
    struct Node* new_node = new Node(new_data);
    if (*head_ref == NULL)
        *head_ref = new_node;
    else
        (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}

int getNthFromLast(struct Node* head, int n);

int main()
{
    int T,i,n,l,k;
    cin>>T;
    while(T--) {
        struct Node *head = NULL,  *tail = NULL;
        cin>>n>>k;
        for(i=1; i<=n; i++)
        {
            cin>>l;
            append(&head, &tail, l);
        }
        printf("%d", getNthFromLast(head, k));
        cout << endl;
    }
    return 0;
}

int getNthFromLast(Node *head, int n)
{
    int c=0;
    Node *ptr=head;
    while(ptr) {
        c++;
        ptr=ptr->next;
    }
    if(n>c)
        return -1;
    ptr=head;
    int i=0;
    while(i<(c-n)) {
        ptr=ptr->next;
        i++;
    }
    return ptr->data;
}
