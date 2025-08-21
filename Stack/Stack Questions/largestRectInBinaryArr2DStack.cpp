#include<iostream>
#include<bits/stdc++.h> //Use this one for all structures
using namespace std;


void printFunction(vector <int> s){

    for(auto a : s ){
        cout<<a<<" ";
    }cout<<endl;

}



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

//My Approach we've both used perv question's fucntions soo I'm keeping them common ok -------------------------------------------------------------------
//Time Compelxity O(n²)
//Space Complexity O(m) no. of columns calcualte it yar (include the fucntions which are called in it too ok)

int largestRectInBinaryArr(vector< vector <int>>M,int n, int m){
    
    vector <int> v(m);
    int maxx = 0;
    bool chk = true;

    for(int i = 0; i < n; i++){

        for(int j = 0; j < m; j++){

            // cout<<M[i][j];
            if(M[i][j] == 0){
                    v[j] = 0;
                    cout<<v[j];
            }else{
                v[j] += M[i][j];
                cout<<v[j];
            }

        }
        cout<<endl;
        int currMax = largestRectangleAreaHis(v);
        if(currMax > maxx){
            maxx = currMax;
        }

        cout<<"row change"<<endl;
    }
    return maxx;

}



//His Approach--------------------------------------------------------------------------------------------------------------------------------------------
//Time Complexity O(n)
//Space Complexity O(m) no. of col// calculate this one too or use AI

int maxArea(vector< vector <int>>M,int n, int m){

    int area = largestRectangleAreaHis(M[0]);//this line is different

    for(int i = 1; i <  n; i++){

        for(int j = 0; j < m; j++){

            if(M[i][j] !=0){
                M[i][j] = M[i][j] + M[i-1][j];
            }else{
                M[i][j] = 0;
            }

        }
        //entire row is updated now
        area = max(area, largestRectangleAreaHis(M[i]));

    }
    return area;

}


int main(){

    // vector< vector <int>> m =  {{0, 1, 1, 0},
    //                             {1, 1, 1, 1},
    //                             {1, 1, 1, 1},
    //                             {1, 1, 0, 0}};

    // vector< vector <int>> m =  {{1, 1, 1, 1},
    //                             {1, 1, 1, 1},
    //                             {1, 1, 1, 1},
                                // {1, 1, 1, 1}};
    
    // vector< vector <int>> m =  {{0, 1, 1, 1},
    //                             {1, 1, 1, 1},
    //                             {1, 1, 1, 1},
    //                             {1, 1, 1, 1}};

    vector< vector <int>> m =  {{0, 0, 0, 0},
                                {0, 0, 0, 0},
                                {0, 0, 0, 0},
                                {0, 0, 0, 0}};

    cout<<largestRectInBinaryArr(m,4,4)<<endl;
    cout<<maxArea(m,4,4)<<endl;

}