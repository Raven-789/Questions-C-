#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *next;

        Node(int val){
            data =val;
            next=nullptr;
        }
};

void print(Node * head){
    while(head != nullptr){
            cout<<head->data<<" -> ";
        head=head->next;
    }
    cout<<"Null\n";
}


//HW why you prefere merge sort in Linked List and Quick Sort in Arrays??
//Also see the link which he told about int the end of the lecture 53


//His Approach --------------------------------------------------------------------------------------------------------------------------------------
//Time Complexity O(nlogn)
//Space Complexity O(logn)

Node * getMid(Node * head){

    Node *slw = head;
    Node *fst = head -> next;

    while((fst) && (fst -> next)){
        slw = slw -> next;
        fst = fst -> next -> next;
    }
    return slw;

}

Node * merge(Node * left, Node * right){

    //if one of the lists is Null
    if(!left){//if left is null
        return right;
    }
    if(!right){//if right is null 
        return left;
    }

    Node * ans = new Node(-1111);
    Node * temp = ans;

    while(right && left){

        if(left -> data < right -> data){

            temp -> next = left;
            temp = left;//to bring the temp to left's address it same thing as temp = temp -> next as we've connected left's element to it
            left = left -> next;

        }else{

            temp -> next = right;
            temp = right;//to bring the temp to rgiht's address it same thing as temp = temp -> next as we've connected right's element to it
            right = right -> next;

        }

    }

    //test it

    while(left){
        temp -> next = left;
        temp = left;//to bring the temp to left's address it same thing as temp = temp -> next as we've connected left's element to it
        left = left -> next;
    }
    while(right){
        temp -> next = right;
        temp = right;//to bring the temp to right's address it same thing as temp = temp -> next as we've connected right's element to it
        right = right -> next;
    }

    ans = ans -> next;// to exclude the dummy node we first made 
    return ans;

}

Node * mergeSortLL(Node * head){

    //Base case
    if(!head || !(head -> next)){// use "OR" here ok
        return head;
    }

    //divide list in 2 halves
    Node * mid = getMid(head);
    Node * left = head;
    Node * right = mid -> next;
    mid -> next = nullptr; // this so that the 1st list has a end and doesn't merges with the 2nd list

    //recursive calls to mergeSort for left and then right
    left = mergeSortLL(left);
    right = mergeSortLL(right);

    //merge the divided parts of the list in the end
    Node * result = merge(left,right);

    return result;
}


int main(){

    Node * n = new Node(5);

    Node * head =n;
    // Node * head =nullptr;

    head -> next = new Node(2);
    head -> next -> next = new Node(6);
    head -> next -> next -> next = new Node(3);
    head -> next -> next -> next -> next = new Node(1);
    head -> next -> next -> next -> next -> next = new Node(1);
    head -> next -> next -> next -> next -> next -> next = new Node(0);
    head -> next -> next -> next -> next -> next -> next -> next = new Node(2);
    head -> next -> next -> next -> next -> next -> next -> next -> next = new Node(1);
    head -> next -> next -> next -> next -> next -> next -> next -> next -> next = new Node(0);

    print(head);
    print(mergeSortLL(head));

}