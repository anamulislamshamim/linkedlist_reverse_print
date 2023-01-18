#include<bits/stdc++.h>

using namespace std;

// create Node object constructor
class Node
{
public:
    int data;
    Node* next;
};
// create linked list constructor
class LinkedList
{
public:
    // create head node
    Node* head;
    // create LinkedList constructor to initialize a default value as soon as
    // the linked list initialized
    LinkedList()
    {
        head=NULL;
    };
    Node* CreateNewNode(int value)
    {
        // allocate heap memory for newNode
        Node* newNode = new Node();
        newNode->data=value;
        newNode->next=NULL;
        return newNode;
    };
    // create a InsertAtHead function to add a new node at Head
    void InsertAtHead(int value)
    {
        Node* myHeadNode = CreateNewNode(value);
        // check if the head is NULL then head=myHeadNode;
        if(head==NULL)
        {
            head=myHeadNode;
            return;
        };
        myHeadNode->next=head;
        head=myHeadNode;
    };
    void InsertAfterSpecificValue(int value, int data)
    {
       Node* a=head;
       while(a!=NULL)
       {
           if(a->data == value)
            break;
           a=a->next;
       };
       if(a==NULL)
       {
           cout << value << " does not exist in the Linked List!" << "\n";
           return;
       };
       Node* newNode = CreateNewNode(data);
       newNode->next=a->next;
       a->next= newNode;
    };
    void Traverse()
    {
        Node* traverseNode = head;
        while(traverseNode!=NULL)
        {
            cout << traverseNode->data << " ";
            traverseNode=traverseNode->next;
        }
    };
    void Reverse(Node* r)
    {
        if(r!=NULL)
        {
            Reverse(r->next);
            cout << r->data << " ";
        }
    };
    void ReverseTraverse()
    {
        Reverse(head);
    };
};


int main()
{
    // create a linked list
    LinkedList l;
    l.InsertAtHead(10);
    l.InsertAtHead(20);
    l.InsertAtHead(30);
    l.InsertAtHead(40);
    l.InsertAtHead(50);
    l.Traverse();
    cout << "\n";
    l.ReverseTraverse();
    cout << "\n";
    l.InsertAfterSpecificValue(30, 117);
    l.ReverseTraverse();
    cout << "\n";
    l.Traverse();
    return 0;
}
