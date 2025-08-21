#include<iostream>
#include<bits/stdc++.h> //Use this one for all structures
using namespace std;


void printFunction(vector <int> s){

    for(auto a : s ){
        cout<<a<<" ";
    }cout<<endl;

}


//my Approach ----------------------------------------------------------------------------------------------------------------------------
//Time Complexity O(n²) his algo was O(n)
//Space Complexity O(n)

int largestRectangleArea(vector<int>& h) {
    
    int sz = h.size();
    vector <int> width(sz);
    vector <int> area;
    int fwd , bck, ans = 0;
    int cnt = 1; //we're setting it 1 as it shows the width of rectangles which is by default 1 by general logic
    for(int i = 0; i < sz; i++){

        int ele = h[i];
        bck = i-1;
        fwd = i+1;

        //we're comparing the current element with its prev and next element both at one time and if rectangle is not smaller than the prev or next rectagle we put the such val in it which makes the while loop's condtion false whihc helps us get out of while loop ok
        while(bck != -1 || fwd != sz){ // use || here as we need both conditions to be false for while to not work okay
            
            if(ele > h[bck] && bck != -1){//if current rectangle is longer than previous one then its width has to be same (for prev rectangles)
                bck = -1;// if the previous element is smaller than current one then we've to get out of loop for that we'll put bck = -1 as then we'll be statisfying the conditon and also we won't have to traverse whole vector... simple right
            }
            else if(ele <= h[bck] && bck != -1){
                cnt++;
                bck--;
            }
            

            if(ele > h[fwd] && fwd != sz){//if current rectangle is longer than next one then its width has to be same (for next rectangles)
                fwd = sz;// if the next element is smaller than current one then we've to get out of loop for that we'll put fwd = sz as then we'll be statisfying the conditon and also we won't have to traverse whole vector... simple right
            }
            else if(ele <= h[fwd] && fwd != sz){
                cnt++;
                fwd++;
            }
            
        }
        width[i] = cnt;
        cnt = 1;//resetting the width for next rectangle 

    }
    printFunction(width);
    // you can use max fucntion too okay-------------------------------------------------------------------------------
    for(int i = 0; i < sz; i++){
        if( (width[i] * h[i]) > ans){
            ans = width[i] * h[i];
        }
    }

    return ans;
    
}

// His Approach--------------------------------------------------------------------------------------------------------------------------------------------
//Time Complexity O(n)
//Space Compelxity O(n)

vector <int> nextSmallerElementHis(vector <int> s, int n){
    stack <int> st;
    vector <int> ans(n);
    st.push(-1);

    for(int i = n-1; i >= 0; i--){

        int curr = s[i];
        //to hande s[-1] we've put this st.top() != -1 condition so that we directly put it in ans[i] okay
        while(st.top() != -1 && s[st.top()] >= curr){//as now st.top has only indexes to access the values inside it we need to use s[st.top()] okay
            st.pop();
        }

        //ans is that top of stack
        ans[i] = st.top();
        st.push(i);// we've made it index based now  with this line

    }
    cout<<"Next Function : ";
    printFunction(ans);
    return ans;
}


vector <int> prevSmallerElementHis(vector <int> s, int n){
    stack <int> st;
    vector <int> ans(n);
    st.push(-1);

    //by reversing the loop from n to 0, to 0 to n we've made it prevSmallerElement ok
    for(int i = 0; i <= n-1; i++){

        int curr = s[i];

        //to hande s[-1] we've put this st.top() != -1 condition so that we directly put it in ans[i] okay
        while(st.top() != -1 && s[st.top()] >= curr){//as now st.top has only indexes to access the values inside it we need to use s[st.top()] okay
            st.pop();
        }

        //ans is that top of stack
        ans[i] = st.top();
        st.push(i);// we've made it index based now  with this line

    }
    cout<<"Previous:  ";
    printFunction(ans);
    return ans;
}

int largestRectangleAreaHis(vector<int>& h) {

    int ans = 0;
    int sz = h.size();
    vector <int> next(sz);
    next = nextSmallerElementHis(h,sz);

    vector <int> prev(sz);
    prev = prevSmallerElementHis(h,sz);
    int area = INT_MIN;
    for(int i = 0; i < sz; i++){

        if(next[i] == -1){
            next[i] = sz;
        }

        int temp = next[i];
        int tem = prev[i];
        int l = h[i];
        int b = next[i] - prev[i] - 1;//formula to get the no. of indexes of the rectangles which are shorter than the current one
        int newArea = l*b;

        area = max(area,newArea);
    }

    return area;

}



int main(){

    // vector <int> v = {2,1,5,6,2,3};
    vector <int> v = {2,1,5,6,2,3};
    // vector <int> v = {2,2,2,2};
    printFunction(v);

    // cout<<largestRectangleArea(v)<<endl;
    cout<<largestRectangleAreaHis(v)<<endl;


}