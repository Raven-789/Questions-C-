#include <iostream>
using namespace std;

struct node{
    int data ;
    node *next;

//constructor
node(int value){
    data=value;
    next=nullptr;
    }
};

void insertatend(node* & head, int value){
    node* newnode = new node(value);
    if (head == NULL)
    {
        head = newnode;
        return;
    }
    node* temp = head;
    while (temp -> next != NULL)
    {
        temp = temp -> next;
    }
    temp ->  next = newnode;
    
    
}

void createcycle(node* head, int pos){
    node* temp = head;
    node* startnode = NULL;
    int count = 1;
    while (temp -> next != NULL)
    {
        if (count == pos)
        {
            startnode = temp;

        }
        temp = temp -> next;
        count ++;
        
    }
    temp -> next = startnode;
    
}

bool detectcycle(node* head){
    node* slow = head;
    node* fast = head;

    while (fast != NULL && fast -> next != NULL)
    {
        slow = slow -> next;
        fast = fast -> next -> next;

    }

    if (slow == fast)
    {
        return true;
    }
    
    
    
}