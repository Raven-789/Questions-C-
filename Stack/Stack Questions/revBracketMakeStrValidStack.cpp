#include<iostream>
#include<stack>
using namespace std;


template <typename T>
void printStack(stack<T> s) {
    bool chk =s.empty();
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << "ok" << endl;
}


void pushStackStr(stack <char> &s, string str){ // we made it void as we've used reference variable

    for(int i = 0; i < str.length(); i++){

        char ch = str[i];
        s.push(ch);

    }
}


//My Approach -------------------------------------------------------------------------------------------------------
//Time Complexity O()
//Space Complexity O()

int revBracketMakeStrValid(string str){
    stack <char> st;
    int cnt = 0;
    //impossible string
    if((str.length()) & 1){
        return -1;
    }

    for(int i = 0; i < str.length(); i++){
    // while(!st.empty()){
        char ch = str[i];

        if(ch == '{'){
            st.push(ch);
        }
        else{
            if(ch == '}'){

                while(1){
                    
                    if(st.empty()){
                        st.push(ch);
                        break;
                    }
                    char top = st.top();
                    if(top == '{' && ch == '}' ){//get the ch condition
                        st.pop();
                        break;
                    }
                    else{//when there is a closing bracket in ch only unpaired, we might 
                        st.push(ch);//to push the unbalanced brackets 
                        break;
                    }

                }

            }
        }
    }

    cnt = st.size();
    
    //he gave me the idea to do this block here and the formula
    int a = 0, b = 0;
    while(!st.empty()){
        if(st.top() == '{'){
            a++;
        }else if(st.top() == '}'){
            b++;
        }
        st.pop();
    }
    int ans = ((a+1)/2) + ((b+1)/2);

    // -----------------------------------------------------------------------------------------------------------------
    // return cnt/2; // This was wrong you made a mistake thining the ans is just cnt/2 you were close but not there ok
    //------------------------------------------------------------------------------------------------------------------
    return ans;
}


//His approach ------------------------------------------------------------------------------------------------------------------------
//Time Complexity O()
//Space Complexity O(n)

int findMinCost(string str){

    //odd condition
    stack <char> st;
    int cnt = 0;
    //impossible string
    if((str.length()) & 1){
        return -1;
    }

    for(int i = 0; i < str.length(); i++){
        char ch = str[i];

        if(ch == '{'){
            st.push(ch);
        }else{

            if(!st.empty() && st.top() == '{'){
                st.pop();
            }
            else{
                st.push(ch);
            }

        }
    }

    //counting the unbalaced braces and calculating the least no. of reversals

    int a = 0, b = 0;
    while(!st.empty()){

        if(st.top() == '{'){
            a++;
        }else if(st.top() == '}'){
            b++;
        }
        st.pop();
    }

    int ans = ((a+1)/2) + ((b+1)/2);
    return ans;

}



int main(){

    // string str = "{{{}";//1
    // string str = "{}}{}}";//1
    // string str = "{{{}}{}}}}";   // it works yessss!!!!!!!!!! 
    // string str = "}}}{{{";   // it also works yessss!!!!!!!!!! 
    string str = "{{{{";// 2 
    // string str = "{{{}}";//impossible -1

    cout<<revBracketMakeStrValid(str);
    cout<<endl;
    cout<<findMinCost(str);


}