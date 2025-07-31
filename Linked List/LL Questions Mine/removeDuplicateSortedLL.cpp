#include<iostream>
#include<map>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
        // Node *prev;

        //constructor
        Node(int d){
            this -> next = NULL;
            
            this -> data = d;
        }


        // These might not work as we're calling destructor in mid program that could be resulting in an error
        //Destructor Read his code could be useful 
        ////will only be called explicitly as its dynamic allocation use delete "keyword"
    ~Node() {
        int value = this -> data;
        //memory free
        if(this->next != NULL) {
            this->next = NULL;
            // delete this;// don't use this line as this deletes all of the list
        }
        cout << " memory is free for node with data " << value << endl;
    }

        // ~Node() {
        // if (next != nullptr) {
        //     // delete next;  // recursively deletes the rest of the list
        //     next = nullptr;
        // }
        //     cout << "Memory is free for node with data " << data << endl;
        // }
};

//My approach-------------------------------------------------------------------------------------------------------------------------------------
//for sorted list
//I'm not freeing space tho okay
//Time Complexity O(n)
//Space Complexity O(1)

void removeDuplicatesSorted(Node * head){
    Node * st = nullptr;
    Node * prev = nullptr;

    bool chk = true;
    
    while(head){
        
        // if(head){
            if(chk && head -> data == head -> next ->data ){
                
                chk = false;
                st = head;
            
            }
            // 1st conditon is for last node and 2nd condition is there so all the ones which couldn't 
            // be in prev. if also be included and then we don't have to use "else"
            else if(!(head -> next )|| head -> data != head -> next ->data){
                if(prev -> data == head -> data){
                    st -> next = head -> next;//for connecting the 1st node to another unique node
                }else{
                    st = head;
                    st -> next = head -> next;//for connecting the 1st node to another unique node
                }

                chk = true;
            }
        // }
            

        prev = head;
        head = head -> next;

    }
}


//His Approach---------------------------------------------------------------------------------------------------------------------------------
//Better one
//for sorted list
//Time Complexity O(n)
//Space Complexity O(1)

// For sorted LL
Node * uniqueListSorted(Node * head){
    
    if(!head){
        return nullptr;
    }

    Node* curr = head;

    while(curr){

        if((curr -> next) && curr -> data == curr -> next -> data){

            Node * nextt = curr -> next -> next;
            Node * nodeToDelete = curr -> next;
            delete(nodeToDelete);
            curr -> next = nextt;

        }else{
            curr = curr -> next;
        }

    }
    return head;
}


//Unsorted list
//Time Complexity O(n²)
//Space Complexity O(1)
void removeDuplicateUnsorted(Node * head){

    Node * curr = head -> next;
    Node * prev = head;

    while(head){
        while(curr){
            
            if(head -> data == curr -> data){
                curr = curr -> next;

            }
            else{
                prev -> next = curr;
                prev = curr;
                curr = curr -> next;
            }
            if(curr && prev){
            cout<<prev-> data<<" "<< curr -> data<<endl;}else{ cout<< "Null"<<endl;}
        }
        if(head){
            head = head ->next;
        }
        else{
            return ;
        }
        if((head) && (head -> next) ){
            curr = head -> next ;
        }
        prev = head;

    }

}



void print(Node * head){
    Node* temp = head;

    while(temp != NULL){
        cout<<temp -> data<<" -> ";
        temp = temp -> next;
    }
    cout<<"Null"<<endl;
}



//Used in 2nd Approach of Rmove Duplicates from a LL see in int main you'll get it--------------------------------------------------------------------

//This is yours tho you did saw if swap() works with nodes too turns out swap can just switches the value
//but can switch the address so technically address' are same and pointers are too but just value inside those
//addresses chages ok

//This Function's Time Complexity is O(n²)
//Space Complexity O(1)
void sort(Node * head){

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

//Remove Duplicates 3rd Approach yours----------------------------------------------------------------------------------------

void removeDuplicatesMap(Node * head){

    // it does initialize to false when accessed with operator[].
    // If you use .at(key) instead of operator[], and the key is missing, it will throw an exception.
    map <int, bool> present;
    Node * temp = nullptr;
    Node *prev = nullptr;
    bool chk = false;

    while(head){
        if(present[head -> data] == false){
            if(chk){
                temp -> next = head;
                chk = false;
            }
            temp = head;
            present[head -> data] = true;
        }
        else{
            chk = true;

        }
        head = head -> next;
    }

}

int main(){

    Node * n = new Node(1);

    Node * head =n;
    // Node * head =nullptr;


    //For ordered list

    // head -> next = new Node(1);
    // head -> next -> next = new Node(1);
    // head -> next -> next -> next = new Node(2);
    // head -> next -> next -> next -> next = new Node(2);
    // head -> next -> next -> next -> next -> next = new Node(2);
    // head -> next -> next -> next -> next -> next -> next = new Node(3);
    // head -> next -> next -> next -> next -> next -> next -> next = new Node(7);
    // head -> next -> next -> next -> next -> next -> next -> next -> next = new Node(4);
    // head -> next -> next -> next -> next -> next -> next -> next -> next -> next = new Node(4);


    // print(head);
    // // removeDuplicatesSorted(head);// My function
    // uniqueListSorted(head);
    // print(head);

    //For Un-Ordered List
    head -> next = new Node(4);
    head -> next -> next = new Node(2);
    head -> next -> next -> next = new Node(1);
    head -> next -> next -> next -> next = new Node(1);
    head -> next -> next -> next -> next -> next = new Node(2);
    head -> next -> next -> next -> next -> next -> next = new Node(4);
    head -> next -> next -> next -> next -> next -> next -> next = new Node(1);
    head -> next -> next -> next -> next -> next -> next -> next -> next = new Node(4);
    head -> next -> next -> next -> next -> next -> next -> next -> next -> next = new Node(3);

    // print(head);
    // removeDuplicateUnsorted(head);
    // print(head);

    // //2nd Approach to Remove Duplicates from a LL make a sort function and then pass it to old removeDuplicatesSorted (mine) or uniqueList (his)
    print(head);
    sort(head);
    print (head);
    // removeDuplicatesSorted(head);
    // uniqueListSorted(head);// this function itself has time Complexity O(logn) but as
    //  we've used my sort function so it becomes O(n²) in total 
    print(head);

    //3rd Appraoch of Removing Duplicates (Map) yours
    // print(head);
    // removeDuplicatesMap(head);
    // print(head);
}