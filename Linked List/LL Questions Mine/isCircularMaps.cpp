#include<iostream>
#include<bits/stdc++.h> //Use this one for all structures
using namespace std;

//see his map APPROACH IN FILE DETECT CYCLE ONE its simpler 

//Time Complexity O(n)
//Space Complexity O(n)

class Node{
    public:
        map <int, bool> mapp; // for key val pairs
        Node * next;

        //Using initilization list for const map here
        
        //this is for non-circular list
        Node(const map <int, bool > & data) : mapp(data), next(nullptr){}

        //for circular list
        // Node(const map <int, bool > & data) : mapp(data), next(this){}
};



void print(Node * head){
    Node * temp = head;

    while(temp){//Null is treated as 0
        cout<<"{ ";
        for(auto & pair : temp -> mapp){ // put the & for address or it won't be saved outside the block
            cout<<"Value: "<< pair.first <<" Visited status: "<<pair.second <<" | ";
        }
        cout<<" }"<<endl;
        temp = temp -> next;
    }
}


//see his map APPROACH IN FILE DETECT CYCLE ONE its simpler 
//use this for circular list ok 
void printCirc(Node *& tail){

    Node * temp = tail;

    if(tail == NULL){
        cout<<"List is Empty."<<endl;
    }
    else{
        do{

            for(auto pair : temp -> mapp){  // put the & for address or it won't be saved outside the block
                string res = pair.second == 1 ? "Yes" :  "No" ;
                cout<<"Value: "<< pair.first <<" Visited status: "<<res<<" | "<<endl;
            }

            temp = temp -> next ;
        }while(tail != temp);
        cout<<"Repeats..."<<endl;
    }
}

//see his map APPROACH IN FILE DETECT CYCLE ONE its simpler 
//This was HARD
bool isCircular(Node * head){

    // Node * curr = head ->next ;

    while(head){ //NULL is treated as 0.
        
        for(auto &pair: head -> mapp){ 

            if (pair.second == 1){
                return true;
            }
            pair.second = 1;

        }

        head = head -> next;
    }


}

//see his map APPROACH IN FILE DETECT CYCLE ONE its simpler 
// for simple linked list
void addAtEnd(Node * &head, const map<int ,bool> & data){

//for circular linked list
// void addAtEnd(Node * &head, const map<int ,bool> & data,int ele){
    Node * n1 = new Node (data);

    if(!head){//NULL is treated as 0.
        head = n1;

        //this is for circular list comment it for normal one
        // n1 -> next = head;        
    }else{
        Node * h = head;

        // for simple linked list
        while(h -> next){
            h = h -> next;
        }

        //for circular linked list
        // bool chk = 0;
        // while(h -> next){
        //     for(auto &pair : h -> mapp ){ // put the & for address or it won't be saved outside the block
                
        //         if(pair.first == ele){
        //             chk = 1;
        //         }
        //         // pair.second = 1;

        //     }
        //     if(chk){
        //         break;
        //     }
        //     h = h -> next;
        // }
        //this is for circular list comment it for normal one
        // n1 -> next = h -> next;

// -------------------------------------------------------------------------
        h -> next = n1; // THIS LINE is for both circular and simple LL
// --------------------------------------------------------------------------
        
        // head = n1;
        
        
    }

    // printCirc(head);
}



//see his map APPROACH IN FILE DETECT CYCLE ONE its simpler 
int main(){

    Node * head = nullptr;
    // //we're putting double brackets while passing arguments cause'
    // // assume I'm making a list of nodes basically which are also 
    // // pointing towards each other so 1st one is for nodes and 
    // // 2nd one is for list of map's elements which are nodes in this case okay
    addAtEnd(head,{{10,0}});
    addAtEnd(head,{{20,0}});
    addAtEnd(head,{{30,0}});
    addAtEnd(head,{{40,0}});
    addAtEnd(head,{{50,0}});

    // for circular linked list
    // addAtEnd(head,{{10,0}},10);
    // addAtEnd(head,{{20,0}},10);
    // addAtEnd(head,{{30,0}},20);
    // addAtEnd(head,{{40,0}},30);
    // addAtEnd(head,{{50,0}},40);


    //as we're learning here you can also do it in pairs just pass the nodes'
    //  values in pairs in add function like: -
    // addAtEnd(head,{{50,0},{60,0}}); and you can do as many as you want too 

    // printCirc(head);
    print (head);
    cout<<isCircular(head);

}

// #include <iostream>
// #include <functional>

// using namespace std;

// class LinkedList {
// public:
//     int value;
//     LinkedList* next;

//     // Constructor for a single node
//     LinkedList(int val) : value(val), next(nullptr) {}

//     // Method to add a new node at the end of the list
//     void add(int val, function<int(int)> mapFn) {
//         LinkedList* newNode = new LinkedList(mapFn(val));

//         // Traverse to the end of the list and add the new node
//         LinkedList* current = this;
//         while (current->next) {
//             current = current->next;
//         }
//         current->next = newNode;
//     }

//     // Print the linked list
//     void print() const {
//         const LinkedList* current = this;
//         while (current) {
//             cout << current->value << " ";
//             current = current->next;
//         }
//         cout << endl;
//     }

//     // Destructor to clean up memory
//     ~LinkedList() {
//         LinkedList* current = next;
//         while (current) {
//             LinkedList* nextNode = current->next;
//             delete current;
//             current = nextNode;
//         }
//     }
// };

// int main() {
//     // Create the first node manually
//     LinkedList list(1);  // Starting with a value of 1

//     // Add more nodes dynamically with a map function
//     list.add(2, [](int x) { return x * 2; });
//     list.add(3, [](int x) { return x * 2; });
//     list.add(4, [](int x) { return x * 2; });

//     // Print the linked list
//     list.print();  // Expected Output: 1 4 6 8

//     return 0;
// }
