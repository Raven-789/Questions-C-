#include<iostream>
#include<utility>
using namespace std;

//Time Complexity O(n)
//Space Complexity O(1)

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


void print(Node * head){
    Node* temp = head;

    while(temp != NULL){
        cout<<temp -> data<<" -> ";
        temp = temp -> next;
    }
    cout<<"Null"<<endl;
}


//My appraoch 1st---------------------------------------------------------------------------------------------------------------------------------------------------------------------
//I think there's replacement
//My approach wasn't in his list soo maybe I'm GOD??


void sort1s2s0s(Node * head){

    Node * curr = head -> next;
    Node * prev = nullptr;

    while(head){
        while(curr){

            if(head -> data > curr -> data ){

                swap(head -> data, curr -> data);
                // cout<< head ->data<< " "<<curr -> data<<endl;
                // print(head);
                // print(curr);
                // curr = curr -> next;

            }
            // else {          //(curr -> data == head -> data)
            //     curr = curr -> next;
            // }
            curr = curr-> next;
        }
        // head = head -> next;
        if(head){
            head = head ->next;
        }
        else{
            return ;
        }

        // curr = head -> next;
        if((head) && (head -> next) ){
            curr = head -> next ;
        }
        // prev = head;
    }

}


//His Approach 1st---------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Time Complexity O(n)
//Space Complexity O(1)
//I also figured it a bit
//this one  replaces the data so it doesn't chages the links' position

Node * sort1s2s0sHis(Node * head){

    int cnt0 = 0, cnt1 = 0, cnt2 = 0;

    Node * temp = head;

    while(temp){

        if(temp -> data == 0){
            cnt0++;
        }else if (temp -> data == 1){
            cnt1++;
        }else if(temp -> data == 2){
            cnt2++;
        }
        temp = temp -> next;

    }

    temp = head;

    while(temp){

        if(cnt0){
            temp -> data = 0;
            cnt0--;
        }else if(cnt1){
            temp -> data = 1;
            cnt1--;
        }else if(cnt2){
            temp -> data = 2;
            cnt2--;
        }

        temp = temp -> next;


    }
    return head;
}

//His Approach 2nd ----------------------------------------------------------------------------------------------------------------------------------
//Without data replacement we made 3 different lists
//Time Complexity O(n)
//Space Complexity O(1)

void populate(Node * &tail, Node * temp){

    tail -> next = temp;
    tail = temp;        

}

Node * sort1s2s0sHis2nd(Node * head){

    Node * zeroHead = new Node (-1);
    Node * zeroTail = zeroHead;
    Node * oneHead = new Node (-1);
    Node * oneTail = oneHead;
    Node * twoHead = new Node (-1);
    Node * twoTail = twoHead;

    Node * temp = head;


    //creating seperate lists for 0s, 1s, 2s
    while(temp){

        int val = temp -> data;

        if(val == 0){
            populate(zeroTail,temp);
        }
        else if(val == 1){
            populate(oneTail,temp);
        }
        else if(val == 2){
            populate(twoTail,temp);
        }
        temp = temp -> next;
    }

    //merging all 3 lists into one
    if(oneHead){
        zeroTail -> next = oneHead -> next;
    }else{
        zeroTail -> next = twoHead -> next;
    }
    
    oneTail -> next = twoHead -> next;
    twoTail -> next = nullptr;

    //setup head node
    head = zeroHead -> next;

    //delete dummy nodes
    delete zeroHead;
    delete twoHead;
    delete oneHead;

    return head;

}



int main(){

    Node * n = new Node(1);

    Node * head =n;
    // Node * head =nullptr;

    head -> next = new Node(1);
    head -> next -> next = new Node(0);
    head -> next -> next -> next = new Node(2);
    head -> next -> next -> next -> next = new Node(1);
    head -> next -> next -> next -> next -> next = new Node(2);
    head -> next -> next -> next -> next -> next -> next = new Node(0);
    head -> next -> next -> next -> next -> next -> next -> next = new Node(2);
    head -> next -> next -> next -> next -> next -> next -> next -> next = new Node(1);
    head -> next -> next -> next -> next -> next -> next -> next -> next -> next = new Node(0);

    print (head);
    // sort1s2s0s(head);
    print(head);
    print(sort1s2s0sHis(head));
    // print(sort1s2s0sHis2nd(head));

}