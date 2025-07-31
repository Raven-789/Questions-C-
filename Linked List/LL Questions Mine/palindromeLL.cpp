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


int getlen(Node * head){

    Node * h = head;
    int cnt = 0;

    while(h != NULL){
        cnt++;
        h = h -> next;
    }
    return cnt;
}

void print(Node * head){
    while(head != nullptr){
            cout<<head->data<<" -> ";
        head=head->next;
    }
    cout<<"Null\n";
}


//My approach I've used fucntions ----------------------------------------------------------------------------------------
//Time Complexity O(n)
//Space Complexity O(n)


bool isPalindrome(Node * head){

    string str = "";

    while(head){
        int temp = head -> data;
        string chr = to_string(temp);
        str +=  chr;
        head = head -> next;
        // cout<< str<<endl;
    }

    string strRev = str;
    reverse(strRev.begin(),strRev.end());
    // cout<<strRev<<"reversed"<<endl;
    // cout<<str<<endl;
    
    if(strRev == str){
        return true;
    }else{
        return false;
    }
}


//His Approach Converted LL into array/ vector-------------------------------------------------------------------------
//Time Complexity O(n)
//Space Complexity O(n)

bool checkPalindrome(vector <int> arr){

    int n = arr.size();
    int s = 0;
    int e = n -1;

    while(s <= e){
        if(arr[s] != arr[e]){
            return false;
        }
        s++;
        e--;

    }
    return true;

}


bool palindromeOrNot(Node * head){

    vector <int> arr;
    Node * temp = head;

    while(temp){
        arr.push_back(temp -> data);
        temp = temp -> next;
    }

    return checkPalindrome(arr);

}


//His 2nd Approach------------------------------------------------------------------------------------------------------

Node * getMid(Node * head){

    Node * fst = head;
    Node * slw = head;

    while((fst -> next) && (fst -> next -> next)){
        fst = fst -> next;
        if(fst){
            fst = fst -> next;
        }
        slw = slw -> next;
    }

    return slw;
}

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

bool his2ndPalindrome(Node  *head){

    if(!(head -> next)){
        return 1;
    }

    Node * mid = getMid(head);

    
    //reverse mid after middle
    Node * temp = mid -> next;
    mid -> next = reverse(temp);

    //Compare both halves
    Node * head1 = head;
    Node * head2 = mid -> next;

    while(head2){

        if(head1 -> data != head2 -> data){
            return false;
        }
        head1 = head1 -> next;
        head2 = head2 -> next;
    }

    //repeat step 2 (Optional as its just for reversing the changes we did to the LL)
     temp = mid -> next;
    mid -> next = reverse(temp);


    return true;

}


int main(){

        Node * n = new Node(1);

    Node * head =n;
    // Node * head =nullptr;

    head -> next = new Node(2);
    head -> next -> next = new Node(2);
    head -> next -> next -> next = new Node(1);
    // head -> next -> next -> next -> next = new Node(2);
    // head -> next -> next -> next -> next -> next = new Node(1);
    // head -> next -> next -> next -> next -> next -> next = new Node(0);
    // head -> next -> next -> next -> next -> next -> next -> next = new Node(2);
    // head -> next -> next -> next -> next -> next -> next -> next -> next = new Node(1);
    // head -> next -> next -> next -> next -> next -> next -> next -> next -> next = new Node(0);
    print(head);

    // if(isPalindrome(head)){//Mine
    //     cout<<"This linked list is a palindrome!!"<<endl;
    // }else{
    //     cout<<"This linked list is NOT a palindrome"<<endl;
    // }


    // if(palindromeOrNot(head)){//his
    //     cout<<"This linked list is a palindrome!!"<<endl;
    // }else{
    //     cout<<"This linked list is NOT a palindrome"<<endl;
    // }


    if(his2ndPalindrome(head)){//His
        cout<<"This linked list is a palindrome!!"<<endl;
    }else{
        cout<<"This linked list is NOT a palindrome"<<endl;
    }
    
}