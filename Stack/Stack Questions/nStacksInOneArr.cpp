#include<iostream>
#include<cstring>
#include<bits/stdc++.h> //Use this one for all structures
using namespace std;

// Lec 58th
//hard for me right now but I'm sure for you it'll be easier
//MOST IMP DON'T CHANGE THE INT MAIN COPY IT AND RUN IT IN EXPERIMENT FILE 
// see notebook with chemistry written at its bottom and read comments and debug
//combine both int main's and copy's input's to fully understand the depth of the codee
//read both push pop they're ying and yang here complete opposites 

// read the comments in in main first
//I've combined the approaches --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Time Complexity O(1)
//Space Complexity O(m+n)
class Nstacks{

    public:
        int * arr;
        int * top;// to store the N arrs' starting indexes
        //helps in keeping track of elements just before stack tops 
        //as it helps in tracking whenever we update it. It helps in making a connection or link b/w the different stacks  (see the code for that)
        //in push we use make a link. Linking every same stack element by this and next arr and in pop it helps us backtracking the prev elements as we popped the stack 
        //top you know after that pop we update the next arr with main array's index in where the popped element is and then store that index in freespots for a push just
        //  after the pop or if we're popping consecutively we store that index in another element's place which we popped consecutively and then store "THIS" element's index
        //  in freespots to push (it goes inifinite technically but get the point ok)
        

        int freeSpot;// it shows if there is space for push or if there isn't it shows -1 (it shows both by the value in next arr understand it well)
        int * next;//keeps track of prev empty spaces in pop if you're popping consecutively if its a singular pop then it stores that "index" in freespot for push() 
        //in push function it keeps tracks of elements which come just after stack top 
        int N , S;

        //Constructor
        Nstacks(int N, int S){

            this -> N = N;
            this -> S =S;
            arr = new int [S];
            top = new int [N];
            next = new int [S];
            freeSpot = 0;// as all the arrays are empty at first    

            //Initilize every element with -1
            // fill_n(arr,N,-1);

            // --------------------------------------------------------------------------------------
            memset(top, -1, N * sizeof(int));// its used for ONLY 0 & -1 ONLYYYY  use this function it costs less and (3rd argument is no. of bytes ok)
            // for(int i = 0; i < N; i++){
            //     cout<<top[i];
            // }cout<<"ok"<<endl;
            //---------------------------------------------------------------------------------------

            // fill_n(top,N,-1);// this can fill any no. but costs more okk
            
            
            for(int i = 0; i < S; i++){// we store 1+ in every index so that we can track back the previous freespot
                next[i] = i + 1;// filling the next free spaces in next array
            }
            next[S-1] = -1;// for last element (I thought that I could use memset first and fill it all with -1 and then use loop to update it with next free vals but it costs a lot more as firstly memset has its own time and then loop too soo this )
            // for(int i = 0; i < S; i++){
            //     cout<<next[i];
            // }cout<<"ok"<<endl;

        }

        bool push(int X, int M){// element is X  | arr no. is M
        
            //Overflow condition
            if(freeSpot == -1){
                return false;
            }

            //find index
            int index = freeSpot;

            //update freespot next is storing the free indexes in arr ok (for conceptual purposes)
            freeSpot = next[index];

            //push the value
            arr[index] = X;

            //update next

            // for(int i = 0; i < S; i++){
            //     cout<<next[i];
            // }cout<<"ok"<<endl;
            next[index] =  top[M-1];//this is the null condition for stack ok (for pop function we're just keeping track of it for popping you know)

            // for(int i = 0; i < S; i++){
            //     cout<<next[i];
            // }cout<<"after"<<endl;

            //update top
            top[M -1] = index;//updating the top element of M-1th stack here (storing main arr index here in top)

            return true;
        }

        int pop(int M){

            //underflow condition
            if(top[M-1] == -1){
                return -1;
            }

            int index = top[M -1] ;

            
            

            //Update top
            top[M-1] = next[index];
            
            //update next
            // for(int i = 0; i < S; i++){
            //     cout<<next[i];
            // }cout<<"ok pop"<<endl;

            next[index] = freeSpot;//we're storing freeSpots' indexes (aka main arr indexes) in next arrays when we pop

            // for(int i = 0; i < S; i++){
            //     cout<<next[i];
            // }cout<<"after"<<endl;


            //pop
            freeSpot = index;// we're doing this as index is the element we just popped and index shows the main arr index so we can also return it to the user that we just popped this element... freeSpot = next[index];
            // cout<<arr[index]<<endl;

            return arr[index];

        }

        ~Nstacks() {
        delete[] arr;
        delete[] top;
        delete[] next;
    }

};

int main(){

    //MOST IMP DON'T CHANGE THE INT MAIN COPY IT AND RUN IT IN EXPERIMENT FILE 
    // see notebook with chemistry written at its bottom and read comments and debug
    //combine both int main's and copy's input's to fully understand the depth of the codee
    //

    // we keep track of those places which are conceptually (they're not physically) free by the next array 
    // so the pop and push function push the elements linearly but conceptually they'll traverse just like stacks 
    //which means they'll work like stacks even though they're storing elements linearly ok

    int N = 3;  // number of stacks
    int S = 6; // total size of array

    Nstacks stacks(N, S);
    

    // Push elements
    stacks.push(10, 1);  
    stacks.push(20, 2);  
    stacks.push(30, 1);  
    stacks.push(40, 2);


    // Pop elements
    int val1 = stacks.pop(1);   // pops from stack 1 (should be 15)
    //if we store 4 in freespot and access freespot in push we do it like next[freespot] (aka next[4]... in this case ok which sums up to 5 the next free space in main arr)  
    //BUT!!! if we access freespot in pop we do it to update next[index] so that before we pop the element we store the last freespot which we used to push an element most recent index into next so that next arr can show us the next freespace utilizing the space efficiently okkk

    int val2 = stacks.pop(2);   // pops from stack 2 (should be 45)
    // int val3 = stacks.pop(3);   // pops from stack 3 (should be 30)

    stacks.push(70,1);
    stacks.push(80,2);
    // Check popped values
    std::cout << "Stack 1 popped: " << val1 << std::endl;
    std::cout << "Stack 2 popped: " << val2 << std::endl;
    // std::cout << "Stack 3 popped: " << val3 << std::endl;

}