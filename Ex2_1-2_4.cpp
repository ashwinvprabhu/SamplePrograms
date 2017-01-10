//
//  main.cpp
//  CodingInterview
//
//  Created by Ashwin V Prabhu on 1/4/17.
//  Copyright © 2017 Ashwin Venkatesh Prabhu. All rights reserved.
//

// Chapter 2: Linked list. Class Node implements a linked list.
// AppendToTail method will append a node to the tail of the list
// DeleteNode method will delete a node. Parameters passed are the head node and data of the node to be deleted

// Exercise2.1: Write a code to remove duplicates from an unsorted linked list
// Solution: This can be done by iterating through the linked list once while keeping a hash table. Running time is O(N) where N is # elements in the list
// Exercise2.1 FOLLOW UP: How to solve the problem if a temporary buffer is not allowed?
// Solution: iterate with two pointers - current and runner which checks for all subsequent duplicate nodes
// This solution runs in O(1) space but O(N^2) running time

// Exercise2.2: Implement an algorithm to find the kth to last element of a singly linked list

// Exercise2.3: Delete middle node with access only to that node and no access to first and last node

// Exercise2.4: Code to partition linked list around value x such that the value below x comes on the left side and rest on the right side

// Exercise2.5: Code to sum two lists. Each node stores a digit and the digits are stored in reverse order.
// FOLLOW UP - If the digits are stored in the forward order, how to solve this problem?

#include <iostream>
#include <unordered_set>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    
    Node()
    {
        next = NULL;
        data = -1;
    }
    
    Node(int d)
    {
        next = NULL;
        data = d;
    }
    
    void AppendToTail(int d)
    {
        Node *end = new Node(d);
        Node *n = this;
        
        while (n->next != NULL)
        {
            n = n->next;
        }
        n->next = end;
    }
    
    Node * DeleteNode(Node *head, int d)
    {
        Node *n = head;
        
        if (n->data == d)
        {
            return head->next;
        }
        
        while (n->next != NULL)
        {
            if (n->next->data == d)
            {
                n->next = n->next->next;
                return head;
            }
            n = n->next;
        }
        return head;
    }
    
    void DisplayAllNodes()
    {
        Node *head = this;
        while (head != NULL)
        {
            cout << "Current node is: " << head->data << endl;
            head = head->next;
        }
    }
};

// Exercise 2.1: Solution #1
void DeleteDuplicates(Node *n)
{
    unordered_set<int> *hashset = new unordered_set<int>();
    Node *previous = NULL;
    
    while (n != NULL)
    {
        // Checks if the element has already been found once
        // If yes, then prints the element and deletes it from the list
        // Else, enters the element into the hash table
        if (hashset->count(n->data) > 0)
        {
            cout << "Deleted duplicate value: " << n->data << endl;
            previous->next = n->next;
        }
        else
        {
            hashset->insert(n->data);
            previous = n;
        }
        n = n->next;
    }
}

// Exercise 2.1: Solution #2
// Current node is set to the head node which is passed as a parameter. Runner node runs through the current node till the end
// deleting all the duplicates it find the way of the current node
void DeleteDuplicatesWithoutBuffer(Node *n)
{
    Node *current = n;
    while (current != NULL)
    {
        Node *runner = current;
        while (runner->next != NULL)
        {
            if (runner->next->data == current->data)
            {
                cout << "Deleted duplicate value: " << runner->next->data << endl;
                runner->next = runner->next->next;
            }
            else
            {
                runner = runner->next;
            }
        }
        current = current->next;
    }
}

// Exercise2.2: Recursive approach. Takes O(n) time and O(1) space
int PrintKthtoLastElement(Node *head, int k)
{
    if (head == NULL)
    {
        return 0;
    }
    int index = PrintKthtoLastElement(head->next, k) + 1;
    if (index == k)
    {
        cout << k << "th to last node is " << head->data << endl;
    }
    return index;
}

// Exercise2.2: Iterative approach. Two pointers.
Node* NthToLast(Node *head, int k)
{
    Node *p1 = head;
    Node *p2 = head;
    
    for (int i = 0; i < k; i++)
    {
        if (p1 == NULL)
        {
            return 0;
        }
        p1 = p1->next;
    }
    
    while (p1 != NULL)
    {
        p1 = p1->next;
        p2 = p2->next;
    }
    return p2;
}

// Exercise2.3: Solution
bool DeleteMiddleNode(Node *n)
{
    if (n == NULL || n->next == NULL) return false;
    Node *next = NULL;
    next = n->next;
    n->data = next->data;
    n->next = next->next;
    return true;
}

// Exercise2.4: Solution
Node* Partition(Node *node, int x)
{
    Node *head = node;
    Node *tail = node;
    
    while (node != NULL)
    {
        Node *next = node->next;
        if (node->data < x)
        {
            node->next = head;
            head = node;
        }
        else
        {
            tail->next = node;
            tail = node;
        }
        node = next;
    }
    return head;
}

// Exercise2.5: Solution
Node* AddTwoLists(Node *l1, Node *l2, int carry)
{
    if (l1 == NULL && l2 == NULL && carry == 0) return NULL;
    
    Node *result = new Node();
    int value = carry;
    if (l1 != NULL)
    {
        value += l1->data;
    }
    
    if (l2 != NULL)
    {
        value += l2->data;
    }
    
    result->data = value % 10;
    
    if (l1 != NULL || l2 != NULL)
    {
        Node *more = AddTwoLists(l1 == NULL ? NULL : l1->next, l2 == NULL ? NULL : l2->next, value > 10 ? 1 : 0);
        result->next = more;
    }
    return result;
}

int main(int argc, const char * argv[])
{
    Node *n = new Node(1);
    n->AppendToTail(12);
    n->AppendToTail(1);
    n->AppendToTail(10);
    n->AppendToTail(3);
    n->AppendToTail(17);
    n->AppendToTail(8);
    n->AppendToTail(2);
    n->AppendToTail(17);
    n->AppendToTail(17);
    n->AppendToTail(9);
    n->AppendToTail(100);
    n->AppendToTail(2);
    n->AppendToTail(15);
    n->AppendToTail(18);
    n->AppendToTail(22);
    n->AppendToTail(35);
    n->AppendToTail(10);
    n->AppendToTail(17);
    
    //DeleteDuplicatesWithoutBuffer(n);
    
    //cout << "6th last node is: " << NthToLast(n, 6)->data << endl;
    
    //PrintKthtoLastElement(n, 6);
    
    //DeleteMiddleNode(n->next->next->next);
    
    //n = Partition(n, 8);
    
    //n->DisplayAllNodes();
    
    //Node *l1 = new Node(7);
    //l1->AppendToTail(1);
    //l1->AppendToTail(6);
    
    //Node *l2 = new Node(5);
    //l2->AppendToTail(9);
    //l2->AppendToTail(2);
    
    //Node *final_result = AddTwoLists(l1, l2, 0);
    //final_result->DisplayAllNodes();
    
    return 0;
}
