#include<iostream>
using namespace std;

// TIME COMPLEXITY OF ALL IS O(n)
// Space Complexity of all is also O(n)


//condtions were like this but he did it another way see the output and and this 
//statement's output you'll get it you can solve it probably by creating a len fucntion 

// Sample Input 1:
// 6
// 5 4 3 7 9 2
// 4 


// Sample Output 1:
// 7 3 4 5 9 2


// Explanation of the Sample Input 1:
// For the given test case, we reverse the nodes in groups of four. 
// But for the last 2 elements, we cannot form a group of four, s
// o leave them as they are. The linked list becomes 7->3->4->5->9->2. Hence the output is 7 3 4 5 9 2

class Node{
    public:
        int data;
        Node *next;

        //constructor
        Node(int d){
            this -> next = NULL;
            this -> data = d;
        }
        
        //Destructor
        ~Node() {
        int value = this -> data;
        //memory free
        if(this->next != NULL) {
            this->next = NULL;
            // delete this;// don't use this line as this deletes all of the list
        }
        cout << " memory is free for node with data " << value << endl;
    }
};


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

void insertAtTail(Node * & t, int data){
    Node *temp = new Node(data);
    t -> next = temp;
    temp -> next =NULL;
    t = temp;
}

Node * kthGroupRev(Node * &head, Node * curr, Node * prev, Node *next, int k){

    // curr = head;

    if(head == NULL){//use head here not curr you made A MISTAKE
        return NULL;
    }

    // you could put these val.s in default too I think

    curr = head;
    prev = NULL;
    next = NULL;
    int cnt = 0;


    //for k group rev
    while(curr != NULL && cnt < k){
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
        cnt++;
    }

    //for next group connecting 
    if(next != NULL){
        //its basically this 2 -> 4 -> (remaining part)
        //or this 2 -> 4 -> 8-> (remaining part)
        head -> next = kthGroupRev(next,NULL, NULL,NULL,2);
    }

    return prev;
}


int main(){
    Node * n1 = new Node(2);
    Node * head = n1;
    Node * tail = n1;
    insertAtTail(tail, 4);
    insertAtTail(tail, 8);
    insertAtTail(tail, 3);
    insertAtTail(tail, 1);
    insertAtTail(tail, 9);
    print(head);

    print(kthGroupRev(head,head,NULL,NULL,4));


    
}