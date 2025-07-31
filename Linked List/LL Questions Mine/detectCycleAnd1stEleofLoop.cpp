#include<iostream>
#include<bits/stdc++.h> //Use this one for all structures
#include <unordered_set>
using namespace std;

//SEE all the approaches of detect and remove cycle HW Lec 47

//Both is given with the functions as all are different
// TIME Complexity 
// Space Complexity 

//Floyd Cycle detection Algo is used in this


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

        //Destructor
        //will only be called explicitly as its dynamic allocation use delete "keyword"
        ~Node() {
        int val = this -> data;
        if(next != NULL) {
            // delete next;// don't use this line as this deletes all of the list
            next = NULL;
        }
        cout << "memory free for node with data "<< val << endl;
    }
};


//Detection of LOOP ----------------------------------------------------------------------------------------------------------------------------------------
//  MY APPROACH----------------------------------------------------------------------------------------------------------------------------------------
//Floyd's Cycle Detection method
//this also gives the meeting point so his is better

//Time Complexity O(n)
//Space Complexity O(1)


Node * detectCycle(Node * head){
    Node * fst = head, *slw = head;

    while (fst && fst -> next){

        //Alternative---------------------------------------------------------------
        //  fast = fast -> next;
        // if(fast != NULL){// this condition is also NEW READ THIS ONE TOOO 
        //     fast = fast -> next;
        // }
//-----------------------------------------------------------------------------------

        fst = fst -> next -> next;
        slw = slw -> next;
        if(fst == slw){
            // cout<< fst -> data <<"  "<<slw -> data<<endl;
            return slw; //or you can return fst too doesn't matter as they both are in same place
        }
    }
    return NULL;


}


//His Approach-----------------------------------------------------------
//his includes MAPS??!?!?! this also gives the meeting point so his is better

//Time Complexity O(n)
//Space Complexity O(n)

bool detectLoop(Node * head){

    if(head == NULL){
        return false;
    }

    // it does initialize to false when accessed with operator[].
    // If you use .at(key) instead of operator[], and the key is missing, it will throw an exception.
    map <Node *, bool> visit;
    Node * temp = head;
    while(temp){//Null is treated as 0

        //cycle is present
        if(visit [temp] == true){
            cout<<"Loop is present at "<<temp -> data<< endl;
            return true;
        }
        visit [temp] = true;
        temp = temp -> next;
    }
    return false;
}

// 3rd Approach
//Using a Hash Set (visited nodes tracking)
// Uses extra space to store visited nodes.
//it puts the visited node into the set and if the node is already present in the set this means cycle detected

bool hasCycleHash(Node* head) {
    std::unordered_set<Node*> visited;
    while (head) {
        if (visited.count(head)) return true;
        visited.insert(head);
        head = head->next;
    }
    return false;
}




// 1st Element of Loop----------------------------------------------------------------------------------------------------------------------------------------
//Time Complexity O(n)
//Space Complexity O(1)  better than Map's approach
// to see WHY this works Go to Lec : 47 
//His approach to this function was even better no... GODLYYY as his time complexity would be better as he cut it off most of it
//by calling the floyd Cycle Detection method


Node* firstEleOfLoop(Node * head){
    Node * fst = head, *slw = head;
    bool chk = false;
    while (fst && fst -> next){

        //Alternative---------------------------------------------------------------
        //  fast = fast -> next;
        // if(fast != NULL){// this condition is also NEW READ THIS ONE TOOO 
        //     fast = fast -> next;
        // }
//-----------------------------------------------------------------------------------

        fst = fst -> next -> next;
        slw = slw -> next;
        if(fst == slw){
            // cout<< fst -> data <<"  "<<slw -> data<<endl;
            if(chk){
                return fst -> next;
            }
            chk = true;
        }
    }


}

//1st element of loop his approach which is GODLYYY--------------------------------------------
//Time Complexity O(n)
//Space Complexity O(1)



Node* getStartingNode(Node * head){

    if(!head){ //NULL is treated as 0.
        return NULL;
    }

    //And for this to work this function has to be below detect cycle function or else its outside the scope okay
    Node *intersection = detectCycle(head);// this line why this one is GODLYYYY!!!!!!!!
    Node* slw = head;

    while(slw != intersection){
        slw = slw -> next;
        intersection = intersection -> next;
    }
    return slw;
}


//Remove loop ----------------------------------------------------------------------------------------------------------------------------------------

//My Approach with using his technique of calling prev fucntions 
//THIS'LL run in all condtions 1 node (loop of node pointing to itself) , no node etc

//Time Complexity O(n)
//Space Complexity O(1)
void removeCycle(Node *head){
    Node * start = getStartingNode(head);
    // Node * temp = head -> next;//Original (Mine, his is better)
    Node * temp = head ;// his addition 
    while(start != temp -> next){
        temp = temp -> next;
    }
    temp -> next = nullptr;

}


// 2nd Approach
// Modifying Pointers Temporarily
// Temporarily mark visited nodes by setting their next pointer to a dummy node.
// If you encounter a node whose next already points to dummy → cycle exists
//after this function all nodes are pointing to dummy you can't print the list after this

// ⚠️ The dummy-node trick is best used only for cycle detection + immediate 
// removal, not for preserving or printing the list afterward.

void removeCycleDummy(Node* head) {
    Node dummy(0);  // Dummy node to mark visited nodes
    Node* prev = nullptr;
    
    while (head) {
        // If current node's next already points to dummy → cycle found
        if (head->next == &dummy) {
            // Break the cycle
            if (prev) prev->next = nullptr;
            cout << "Cycle detected and removed at node with value " << head->data << "\n";
            return;
        }
        // Save next node before modifying
        Node* nextNode = head->next;
        // Mark current node as visited by pointing next to dummy
        head->next = &dummy;
        prev = head;
        head = nextNode;
    }
    cout << "No cycle detected\n";
}


//3rd Approach
// Hashing (Using unordered_set)
// Traverse the list.
// Add each node to a set. then if the node is already present in set point it's prev to NULL or nullptr (safer)


void removeCycleHashing(Node* head) {
    std::unordered_set<Node*> seen;
    Node* prev = nullptr;
    while (head) {
        if (seen.count(head)) {
            if (prev) prev->next = nullptr;
            return;
        }
        seen.insert(head);
        prev = head;
        head = head->next;
    }
}

// 4th Approach
// Brute Force with Nested Loop
//The key here is that ptr2 stops at ptr1, so it never loops infinitely even if there's a cycle.
// so this successfully just compares every node if that node has any other pointing back to it in a nested 
// while loop okay

void removeCycleBrute(Node* head) {
    Node* ptr1 = head;
    while (ptr1) {
        Node* ptr2 = head;
        while (ptr2 != ptr1) {
            if (ptr2->next == ptr1) {
                ptr2->next = nullptr;
                return;
            }
            ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
}


//5th Approach
// Floyd’s Cycle Detection Algorithm
//You're putting slow at head when the fast and slow 1st time adn when they meet 2nd time it'll be 
// the starting node of cycle by maths (you can see that in Lec 47)

void removeCycleFloyd(Node* head) {
    Node *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next; fast = fast->next->next;
        if (slow == fast) break;
    }
    if (!fast || !fast->next) return;
    slow = head;
    while (slow != fast) {
        slow = slow->next; fast = fast->next;
    }
    while (fast->next != slow) fast = fast->next;
    fast->next = nullptr;
}


// -------------------------------------------------------------------------------------------------------------------------


void print(Node *head){

    Node *temp = head;

    if(!temp){
        cout<<"List is empty";
    }else{
        while(temp){
            cout<<temp -> data<<" -> ";
            temp = temp -> next;
        }
        cout<<"Null"<<endl;
    }
}

int main(){
    Node *head = new Node(10);
    head -> next = new Node(20);
    head -> next  -> next = new Node(30);
    head -> next  -> next  -> next = new Node(40);
    head -> next  -> next  -> next  -> next = new Node(50);
    head -> next  -> next  -> next  -> next  -> next = head -> next ; //Creating a cycle

    cout<<detectCycle(head)<<endl;
    cout<<detectLoop(head)<<endl;
    
    //you can also use maps like in detecLoop too but it takes O(n) in Space Complexity soo.. better than Map's Approach

    //My function
    cout<<"1st element of loop "<<firstEleOfLoop(head) -> data<<endl;// to see WHY this works Go to Lec : 47 

    //his function
    cout<<"1st element of loop "<<getStartingNode(head) -> data<<endl;// the GODLY ONEE!!

    removeCycle(head);
    print(head);


}