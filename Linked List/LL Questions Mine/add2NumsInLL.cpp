#include<iostream>
#include<algorithm>//my appraoch
#include<string>//my approach
#include<vector>
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


// My Approach his is more optimized-----------------------------------------------------------------------------------------------------------------------------------------
//Brute force probably not that good ok
//Time Complexity O(n)
//Space Complexity O(n)

Node * add2ElementsOfLL(Node * h1, Node * h2){

    Node * prev = nullptr;
    Node * nextt = nullptr;
    Node * curr = h1;

    while(curr){
        nextt = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = nextt;
    }
    print(prev);

    Node * prev2 = nullptr;
    Node * nextt2 = nullptr;
    Node * curr2 = h2;

    while(curr2){
        nextt2 = curr2 -> next;
        curr2 -> next = prev2;
        prev2 = curr2;
        curr2 = nextt2;
    }
    print(prev2);

    Node * add = new Node(-11111), * val = new Node(0), *carry = new Node(0);
    Node * ans = add;
    bool chk = true;

    while(prev && prev2){// && so that I can deal if one list has ended and other still has elements outside this loop
        
        if((prev -> data + prev2 -> data) < 10 ){
            
            if(carry){// if carry is not 0 then check if the val + carry is above 9 if it is then just put 0 in node and add prev carry will be handled in the outer else (you've to find that else ok)
                val -> data = (prev -> data + prev2 -> data) + carry -> data; // add both val and carry for comparision 
                if(val -> data >= 10){// to check if val + carry is less than 10 AND... YOU'VE TO USE "">="" SO THAT IF ITS 10, 10 IS INCLUDED 
                    val -> data = ((prev -> data + prev2 -> data) + carry -> data) - 10;
                    carry -> data = ((prev -> data + prev2 -> data) + carry -> data) / 10;
                    add -> next = new Node(0);// if the carry is more than 10 in the next carry too just put 0 in the new node and move next
                    chk = false;// this chk is to keep track IF the CARRY MAKES THE VALUE GREATER THAN 10 then we don't have to make carry 0 you know
                }
            }else{
                val -> data = prev -> data + prev2 -> data;// add the 2 LL's data and putting it in new node for less redundancy
            }
            
            add -> next = new Node(val -> data);// creating a new node for new value from the addition and pointing the prev node to the new node
            add = add -> next;// proceeding to the newly created node
            if(chk){
                carry -> data = 0;// condition to reset carry to 0 as its been canceled out or it was 0 beforehand soo it won't matter if we again set it to 0 
            }
        }
        else if((prev -> data + prev2 -> data) >= 10 ){
            if(carry -> data != 0){ // condtion for consecutive carries DO THIS ONE
                //if there're multiple carries you've 1st add the carry to val for new node and then divide it with 10 to get the tens value of val to put in the carry variable
                val -> data = carry -> data +( (prev -> data + prev2 -> data) - 10);
                carry -> data = carry -> data +( (prev -> data + prev2 -> data) / 10);
            }else{
                val -> data = (prev -> data + prev2 -> data) - 10;// else just add excess which is more than nine
                carry -> data = (prev -> data + prev2 -> data) / 10;// this will give out the tens place digit which we'll put int carry as its done in mathematics and you did it and we took the ones digit bitch
            }
            add -> next = new Node(val -> data);// we've to put val which is in ones place for the addition
            add = add -> next;
        }
        chk = true;// in the next iteration we need to handle the carry variable normally as not all times the condition will be when carry + val > 10 (find that condition to get this comment)
        prev = prev -> next;
        prev2 = prev2 -> next;
    }


    //to add the remaining elements of the list which is longer 
    if(prev){
        add-> next = prev;
    }else if(prev2){
        add -> next = prev2;
    }

    // as we've reversed the lists the add list is in reversed we'll reverse it once again

    ans = ans -> next;
    Node * prev3 = nullptr;
    Node * nextt3 = nullptr;
    Node * curr3 = ans ;

    cout<<"normal list for checking (the above 2 lists were added ok)"<<endl;
    print(ans);

    while(curr3){

        nextt3 = curr3 -> next;
        curr3 -> next = prev3;
        prev3 = curr3;
        curr3 = nextt3;

    }

    cout<<"reversed list"<< endl;
    print(prev3);
    cout<< "ok"<<endl;

    return prev3;
}


//His Approach ---------------------------------------------------------------------------------------------------------------------
//Time Complexity O()
//Space Complexity O()

//he's using reverse function which we made in 
Node * reverse(Node * head){

    Node * curr = head;
    Node * prev = nullptr;
    Node * next = nullptr;

    while(curr){

        //this for pointing the next nodes in other direction
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;

    }
    return prev;
}

//inserting at tail fucntion too??!?! damn yarr
void insertAtTail(Node * &head, Node * &tail, int val){

    Node * temp = new Node(val);

    if(!head){// if head is Null
        head = temp;
        tail = temp;
        return;
    }else{
        tail -> next = temp;
        tail = temp;
    }

}

// he's using add function too !!!

Node * add(Node * first, Node * second){

    int carry = 0;
    Node * ansHead = nullptr;
    Node * ansTail = nullptr;

    while(first || second || carry){

        int val1 = 0;
        
        if(first){
            val1 = first -> data;
        }

        int val2 = 0;

        if(second){
            val2 = second -> data;
        }

        int sum = carry + val1 + val2;

        int digit = sum % 10;

        // Node * temp = new Node (digit);// no need to do this as we can directly pass digit into the function

        insertAtTail(ansHead, ansTail, digit);

        carry = sum / 10;
        if(first)
            first = first -> next;

        if(second)
            second = second -> next;

        
    }

    return ansHead;
}

// his main function for adding 2 no.s of the linked list
Node * addTwoLists(Node * first, Node * second){

    //step 1 reverse lists
    first = reverse(first);
    second = reverse(second);

    // step 2 add the elements of the 2 linked lists
    Node * ans = add(first, second);

    //step 3 reverse the ans again
    ans = reverse(ans);

    return ans;

}



int main(){

    //This works in every combination of nodes but try different ones so that we can be sure ok if you want to
    //damnn you know it also works in his condition which is 45 + 345 yayyyyyyyyyyyyy
    Node * n = new Node(4);
    Node * h1 = n;
    h1 -> next = new Node(5);
    // h1 -> next -> next = new Node(5);

    Node * n2 = new Node(3);
    Node * h2 = n2;
    h2 -> next = new Node(4);
    h2 -> next -> next = new Node(5);
    // h2 -> next -> next -> next = new Node(7);

    print(h1);
    print(h2);

    // print(add2ElementsOfLL(h1, h2));//My approach
    print(addTwoLists(h1,h2));//His Approach

}