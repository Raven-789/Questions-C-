#include<iostream>
using namespace std;

//Time Complexity O(n)
//Space Complexity O(n)


class Node{
    public:
        int data;
        Node *next;

        //constructor
        Node(int d){
            this -> next = NULL;
            this -> data = d;
        }
};
// you can also have destructors which should be called explicitly because
// we're dealing in dynamic memeory and only for static memeory destructors are called implicitly

int getlen(Node * head){

    Node * h = head;
    int cnt = 0;

    while(h != NULL){
        cnt++;
        h = h -> next;
    }
    return cnt;
}

// ---------------------------------------------------------------------------------------------------

//My Approach

Node * getMidOfLL(Node * &head){
    int len = getlen(head), cnt = 1;
    Node * h = head;
    if(len & 1){
        //for odd no. of nodes

        while(cnt != ((len-1)/2)+1 ){
            h = h -> next;
            cnt++;
        }
        return h;

    }else{
        //for even no. of nodes
        while(cnt != (len/2)+1 ){
            h = h -> next;
            cnt++;
        }
        return h;

    }
}



//His appraoch which betterr again!!!!?!?
//this code is giving +1 index as it starts from 0 and "<" operator is
//  used that's what you didn't used

Node * findMidOfLL(Node * head){
    int len = getlen(head);
    int ans = len/2;

    Node* temp = head;
    int cnt = 0;
    while(cnt < ans){
        temp = temp -> next;
        cnt++;
    }
    return temp;
}


//3rd approach MY take

Node * getMidOfLL2nd(Node * head){

    Node * fst = head, *slw = head;

//this while condition only works in && as fst -> next gives segementation fault and && avoids that
//as if 1st condition is false it won't check 2nd condition but if you use || operator if 1st 
//condtion is true then || HAS to check fst -> next which guess what results in segementation fault
//it like property of && and || read this one carefully okay!


    while(fst != NULL && fst -> next != NULL ){// another way to write the conditon but see his as it was used in in Divide LL in two file his is better see in this file's his approach
        
//we don't need these but for imp of while codition as its too good to pass on read that and its 
// comments for how  it only works with && and avoids segmentation fault

        // if (fst ->next != NULL){
            //     fst = fst -> next -> next;
        // }else{
            //     fst = NULL;
            // }
//--------------------------------------------------------------------------------------------------------

        fst = fst -> next -> next;
        slw = slw -> next;
    }

    return slw;

}


//his approach I think mine is better yayyyyyyyyy but its not see in Divide LL in two file

Node * findMidOfLL2nd(Node* head){

    if(head == NULL || head -> next == NULL){
        return head;
    }

    if(head -> next -> next ==NULL){
        return head -> next;
    }

    Node * slow = head;
    Node * fast = head -> next; // this is NEW HERE READ THIS ONE 

    while(fast != NULL ){
        fast = fast -> next;
        if(fast != NULL){// this condition is also NEW READ THIS ONE TOOO 
            fast = fast -> next;
        }
        slow = slow -> next;
    }

    return slow;

}

// -----------------------------------------------------------------------------------------------------------------------


void print(Node * h){
    Node * temp = h;
    while(temp != NULL){
        cout<<temp -> data<<" -> ";
        temp = temp -> next;
    }
    cout<<"NULL"<<endl;
}

void insertAtHead(Node *& h, int data){

    Node *n = new Node(data);
    n -> next = h;
    h = n;
    
}


int main(){
    Node *n1 = new Node(1);
    Node *head = n1;
    // Node *head = NULL;// for testing of empty list 
    insertAtHead(head, 10);
    insertAtHead(head, 20);
    insertAtHead(head, 30);
    insertAtHead(head, 40);  
    print(head);
    print(getMidOfLL(head));
    // cout<<findMidOfLL(head) -> data<<endl;
    print(getMidOfLL2nd(head));// my call on 2nd type of approach of from his vid

    print(findMidOfLL2nd(head));
    // cout<< getlen(head)<<endl;
}