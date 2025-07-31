#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
        Node * rand;

        Node(int val){
            data =val;
            next=nullptr;
            rand = nullptr;
        }
};



void print(Node * head){
    while(head != nullptr){
            cout<<head->data<<" -> ";
        head=head->next;
    }
    cout<<"Null\n";
}


void printRand(Node * head){

        while(head){
        if((head -> rand)){
            cout<<"[ "<<head -> data << ", "<<head -> rand -> data<<" ]"<<endl;
        }else{
            cout<<"[ "<<head -> data << ", "<<"NUll ]"<<endl;    
        }
        head = head -> next;
    }
    // cout<< "ok" << endl;

}


//My Approach ---------------------------------------------------------------------------------------------------------------------------------------------------------------------
// is wrong as I'm pointing the clone's list's pointers to original list's nodes which doesn't satisfies the constraints but it does solves the problem see his 3rd approach for this
//Time Complexity O(n)
//Space Complexity O(1) but this approach is wrong okay as it doesn't follows the constraints but it does solves the problem okay see his 3rd approach for this
//Lecture 52

Node * cloneLLWithRandomPtr(Node * head){

    Node * h1 = head, *h2 = head;
    Node * ans = new Node (-111111);
    Node * anss = ans;
    Node * ansss = ans;
    Node * final_Answer = ans;

    //Coping the node's elements
    while(h1){

        ans -> next = new Node(h1 -> data);

        h1 = h1-> next;
        ans = ans -> next;//to move forward the ans to the new node which was just created 

    }
    print (anss -> next);

    cout<<"nodes next pointer print successful!"<<endl;

    //now coping the node's random pointers
    anss = anss -> next;
    while(h2){

        anss -> rand = h2 -> rand;
// ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        h2 = h2 -> next;// THIS LINE CONNECTS CLONE NODE'S RAND TO ORIGINAL NODE'S RAND WHICH MAKES YOUR APPROACH WRONG OKAY
// ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        
    anss = anss -> next;

    }

    print(ansss -> next);

    cout<< "LL is still intact after rand pointers "<<endl;

    // ansss = ansss -> next;
    // while(ansss){
    //     if((ansss -> rand)){
    //         cout<<"[ "<<ansss -> data << ", "<<ansss -> rand -> data<<" ]"<<endl;
    //     }else{
    //         cout<<"[ "<<ansss -> data << ", "<<"NUll ]"<<endl;    
    //     }
    //     ansss = ansss -> next;
    // }
    // cout<< "ok" << endl;
    // printRand(ansss);

    return final_Answer -> next;
}


//His Approach-----------------------------------------------------------------------------------------------------------------------------------------
//Time Complexity O(n²)
//Space Complexity O(n)

// Node * cloneLLWithRandomPtrHis1st(Node * head){
// }
// he uses nested loop to clone in this one which is honestly soo bad he himself even didn't clone it

// His 2nd Approach-----------------------------------------------------------------------------------------------------------------------------------------
//Time Complexity O(n)
//Space Complexity O(n)


void insertAtTail (Node * &head, Node * &tail, int d){

    Node * newNode = new Node (d);
    if(!head){//if head IS null
        head = newNode;
        tail = newNode;
        return;
    }else{
        tail -> next = newNode;
        tail = newNode;
    }

}

Node * cloneLLWithRandomPtrHis2nd(Node * head){

    //step 1 create cloned list
    Node * cloneHead = nullptr;
    Node * cloneTail = nullptr;

    Node * temp = head;

    while (temp){
        insertAtTail(cloneHead, cloneTail, temp -> data);
        temp = temp -> next;
    }

    //step 2 create a map
    unordered_map <Node *, Node* > oldToNew; //you've to include unordered_map before to use this

    // temp = head;
    Node * originalNode = head;
    Node * cloneNode = cloneHead;

    while(originalNode){

        oldToNew[originalNode] = cloneNode;
        originalNode = originalNode -> next;
        cloneNode = cloneNode -> next;
    }

    // step 3 ordering the random pointers 

    originalNode = head;
    cloneNode = cloneHead;

    while(originalNode){

        cloneNode -> rand = oldToNew[originalNode -> rand];
        originalNode = originalNode -> next;
        cloneNode = cloneNode -> next;

    }

    return cloneHead;

}

//His 3rd Approach BESSTTT---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Time Complexity O(n)
//Space Complexity O(1)
//lecture 52 if you don't get the visualization but I believe in youu you'll do it without it

Node * cloneLLWithRandomPtrHis3rd(Node * head){

    //step 1 create a clone list

    Node * cloneHead = nullptr;
    Node * cloneTail = nullptr;

    Node * temp = head;

    while (temp){
        insertAtTail(cloneHead, cloneTail, temp -> data);//fucntion's created in "his approach 2nd" we're using that one ok 
        temp = temp -> next;
    }

    // step 2 add cloneNodes in b/w Original List

    Node * originalNode = head;
    Node * cloneNode = cloneHead;

    while(originalNode && cloneNode){

        //For original node
        Node * nextt = originalNode -> next;
        originalNode -> next = cloneNode;
        originalNode = nextt;

        //For clone node
        nextt = cloneNode -> next;
        cloneNode -> next = originalNode;
        cloneNode = nextt;
    }

    // step 3 random pointer copy

    temp = head;
    while(temp){

        if((temp -> next)){

            temp -> next -> rand = temp -> rand ? temp -> rand -> next : temp -> rand;

            //we've used teranary operator for this if else condition
            // if((temp -> rand)){
            //     temp -> next -> rand = temp -> rand -> next;
            // }else{
            //     temp -> next = temp -> rand;
            // }
        }

        temp = temp -> next -> next; //we've moved it 2 times as we've mapped the original list to cloned list

    }

    // step 4 revert the changes done in step 2

    originalNode = head;
    cloneNode = cloneHead;

    while(originalNode && cloneNode){

        //for original list
        originalNode -> next = cloneNode -> next;
        originalNode = originalNode -> next;

        // for clone list
        if(originalNode){
            cloneNode -> next = originalNode -> next;
        }
        cloneNode = cloneNode -> next;

    }

    // step 5 return ans
    return cloneHead;
}




int main(){

    Node * n = new Node(1);

    Node * head =n;
    // Node * head =nullptr;
    
    
    head -> next = new Node(3);
    head -> next -> next = new Node(5);
    head -> next -> next -> next = new Node(9);
    
    
    //Rand pointers of the nodes
    head -> rand = head -> next -> next;// 1st element pointing to 3rd element 5
    head -> next -> rand = head -> next -> next;// 2nd element also pointing to 3rd element 5
    head -> next -> next -> rand = nullptr; // 3rd element pointing to NULL
    head -> next -> next -> next -> rand = head -> next -> next;// 4th element also pointing to 3rd element 5



    // head -> next -> next -> next -> next = new Node(2);
    // head -> next -> next -> next -> next -> next = new Node(2);
    // head -> next -> next -> next -> next -> next -> next = new Node(3);
    // head -> next -> next -> next -> next -> next -> next -> next = new Node(7);
    // head -> next -> next -> next -> next -> next -> next -> next -> next = new Node(4);
    // head -> next -> next -> next -> next -> next -> next -> next -> next -> next = new Node(4);

    print(head);

    //// mine doesn't follows the constraint that clone list can't point to original list but it does the job 
    ////its just... mine doesn't follows the problem's constraints which makes it wrong BUT not useless ok
    // Node * ans = cloneLLWithRandomPtr(head);
    // print(ans);
    // printRand(ans);

    // Node * ansHis = cloneLLWithRandomPtrHis2nd(head);
    // print(ansHis);
    // printRand(ansHis);

    //this 3rd approach of his is best as it has O(n) time and O(1) space and 
    // also follows the constraint that clone list can't point to original list
    Node * ansHiss = cloneLLWithRandomPtrHis2nd(head);
    print(ansHiss);
    printRand(ansHiss);

}