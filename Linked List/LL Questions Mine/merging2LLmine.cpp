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


//My execution on "HER" Approach -------------------------------------------------------------------------------------------------------
//Time Complexity O(n)
//Space Complexity O(1)

Node * merge2ListsMine(Node * h1, Node * h2){

    Node * lst = new Node(-11111);
    Node * lstHead = lst;

    while((h1) && (h2)){
        
        if(h1 -> data < h2 -> data){
            lst -> next = h1;
            lst = lst -> next;
            h1 = h1-> next;
        }else{
            lst -> next = h2;
            lst = lst -> next;
            h2 = h2 -> next;
        }

    }

    while(h1){
        lst -> next = h1;
        h1 = h1 -> next;
    }

    while(h2){
        lst -> next = h2;
        lst = lst -> next;
        h2 = h2 -> next;
    }

    return lstHead -> next;

}

//His Approach my execution-------------------------------------------------------------------------------------------------------------------------------------
//Time Complexity O(n)
//Space Complexity O(1)
// its lecture 49 if you don't get it ok
//This is the best maybe! but its complicated soo he beat me!!!!!
//list will have atleast one element by constraints of questions 

//His Approach my execution
Node * merge2ListsMyTake(Node * h1, Node * h2){

    Node * prev = h1;
    Node *head2 ;
    Node *head = h1;
    // delete(prev);
    // prev -> data = -1;//I workss!!!!
    
    //if one of them is empty (took this one from him)
    if(h1 == nullptr){
        return h2;
    }
    else if(h2 == nullptr){
        return h1;
    }

    while((h1) || (h2) ){// until we reach both list's ends

        if(prev != h1 ){// to compare if the 1st element of the 2nd list is lesser than 1st element of 1st list then we've to put it behind the current head as this is time when both prev and h1 ptrs are at same element
            
            if(h1){ // if we're at end of 1st list so we now have to append it

                
                if(h2){// if we've reached the end of 2nd list
                    if(h2 -> data >= prev -> data && h2 -> data < h1 -> data){// if the conditions are satisfied to insert element of 2nd list in b/w 1st list's elements

                        prev -> next = h2;

                        head2 = h2 ;
                        h2 = h2 -> next;
                        head2 -> next = h1;
                        prev = prev -> next;// this is so when we add new node in between it connects to that and doesn't skips it this also helps in adding repeated valued nodes
                    }else{// if the elemet of the 2nd list is greater than the element of 1st list
                        prev = h1; //this is if the elements are same I think you can also write "prev = prev -> next;" it'll be same 
                        h1 = h1 -> next;
                    }
                }
                else{//just point to next element of 1st list so that we can insert it in next iteration
                    // h1 = h1 -> next;// don't need to do this it just adds more iterations 
                    return head;// I learned this from him beaten again
                }
            }
            else{// to append the elements of 2nd list (most likely 2nd list's longer that's why)

                prev -> next = h2;
                // prev = prev -> next;
                // head2 = h2;
                // h2 = h2 -> next;
                return head;// this one I took from HIM (HE BEAT ME AGAIN!!!)
                // if(h2){//here we're connecting extra nodes to the 1st list if the 2nd list hasn't reached the end
                //     head2 -> next = prev;
                // }else{//here we've reached the end of 2nd list
                //     head2 -> next =nullptr;
                // }
                // if(h1){
                //     h1 = h1 -> next;
                //     }
                // // if(h2){
                // //     h2 = h2 -> next;
                // // }
            }


        }else if (h2 -> data < h1 -> data){// it if the 2nd list's 1st element is smaller than 1st list's 1st element then we've connect it behind the 1st list's head so it going to be different and handling of ptrs is also different you can see yourself I believe in you
            head2 = h2;// store it so the 2nd list doesn't get haywire
            h2 = h2 -> next;
            head2 -> next = h1;// connecting the 2nd list's node to first's first element
            head = head2;
            prev = head;// it shouldn't move as its 
            // prev = h1;
            // h1 = h1 -> next;
        }else{// as we started prev & h1 at same point to check above condition (edge case) we need to progress h1 for all other cases
            h1 = h1 -> next; 
        }
    }

    return head;

}



//His Approach his execution------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Time Complexity O(n)
//Space Complexity O(1)


Node *  solve(Node * first, Node * second){

    // if there's only 1 element in the list
    if(!(first -> next)){
        first -> next = second;
        return first;
    }


    Node * curr1 = first;
    Node * next1 = curr1 -> next;
    Node * curr2 = second;
    Node * next2 = curr2 -> next;

    while(next1 != nullptr && curr2 != nullptr){
        
        if( (curr2 -> data >= curr1 -> data) && (curr2 -> data <= next1 -> data)){// checking if the element is eligible to be put b/w the 2 elements

            //add nodes b/w the first list
            curr1 -> next = curr2;
            next2 = curr2 -> next;
            curr2 -> next = next1;

            //Updating pointers
            curr1 = curr2;
            curr2 = next2;

        }else{

            //we've to move curr1 & next1 forward as they aren't eligible for the order of the list (Ascending)
            curr1 = next1;
            next1 = next1 -> next;

            if(!next1){// if next1 is Null point the remaining list 
                curr1 -> next = curr2; //if the list1 is complete then last element of finished list is being pointed to rest of the unfinished list
            return first;
            }

        }

    }
    return first;

}


//His Approach his take
Node * merge2ListsHistake(Node * first, Node * second){

    if(!first){
        return second;
    }
    else if(!second){
        return first;
    }

    //this condition is whichever list's 1st element is smallest that list is the 1st in the other fucntion (he beat me!!)
    if(first -> data <= second -> data){
        solve(first,second);
    }
    else{
        solve(second,first);
    }

}


int main(){

    //YOU can probably try different combinations of nodes or ask her to do so to check as its your take on his approach
    Node * n = new Node(2);
    Node * h1 = n;
    h1 -> next = new Node(3);
    // h1 -> next -> next = new Node(5);

    Node * n2 = new Node(1);// your own edge case if the 1st element of 2nd list was smaller than the 1st element of 1st list
    Node * h2 = n2;
    h2 -> next = new Node(1);
    // h2 -> next -> next = new Node(4);
    // h2 -> next -> next -> next = new Node(7);

    print(h1);
    print(h2);

    // print(merge2ListsMine(h1, h2));
    print(merge2ListsMyTake(h1, h2));// his approach's my execution
    // print(merge2ListsHistake(h1,h2));// his apporach his execution
    

}