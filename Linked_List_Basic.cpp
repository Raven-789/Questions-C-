#include<iostream>
using namespace std;

struct node
{
    int data;
   node* next;
};

void printlist(node*t){
    while (t!=nullptr)
    {
        cout<<t->data<<"->";
        t=t->next;
    }
    
}

int main (){
    node* head =new node();
    node* second =new node();
    node* third=new node();

    head->data=1;
    head->next=second;

    second->data=2;
    second->next=third;

    third->data=3;
    third->next=nullptr;

    printlist(head);

    cout<<"NULL";
    return 0;

}