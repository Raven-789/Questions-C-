#include<iostream>
#include<bits/stdc++.h> //Use this one for all structures
using namespace std;


void printFunction(vector <int> s){

    for(auto a : s ){
        cout<<a<<" ";
    }

}

template <typename T>
void printStack(stack<T> s) {
    bool chk =s.empty();
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << "ok" << endl;
}

//If you do it with vectors the Time Complexity would be O(n²) which we can optimize with using stack 

vector <int> nextSmallerElement(vector <int> s, int n){

    stack <int> st;
    vector <int> ans(n);//You initilize like this ... When you know how many elements you'll need up front  
    int top;
    st.push(-1);
    // ans.push_back()
    for(int i = s.size()-1; i >= 0; i--){

        int ele = s[i];
        

        if(ele > st.top()){
            // ans.push_back(st.top);// this line gives reverse answer ok
            ans[i] = st.top();
            st.push(ele);
            top = st.top();

        }else {
            while(ele < st.top()){
                st.pop();
                top = st.top();
            }
            ans[i] = st.top();
            st.push(ele);
        }

        // ans.push_back(st.top());
    }

    
    return ans;
}


//His appraoch-----------------------------------------------------------------------------------------------------------
//Time Complexity O(n)
//Space Complexity O(1)

vector <int> nextSmallerElementHis(vector <int> s, int n){
    stack <int> st;
    vector <int> ans(n);
    st.push(-1);

    for(int i = n-1; i >= 0; i--){

        int curr = s[i];
        while(st.top() >= curr){
            st.pop();
        }

        //ans is that top of stack
        ans[i] = st.top();
        st.push(curr);

    }
    return ans;
}


int main(){

    // when you're revising do this question 
    //previous smaller element its easy try it I've not given the hint but if you ever need it its in Lec56 1question's ending ok

    vector <int> s = {2,1,4,3};
    printFunction(nextSmallerElement(s,s.size()));
    // printFunction(nextSmallerElementHis(s,s.size()));

}























































//don't use the vid damn it!!!!