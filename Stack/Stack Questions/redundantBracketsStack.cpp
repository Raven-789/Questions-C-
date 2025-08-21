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

//My Approach (his is better)---------------------------------------------------------------------------------------------------------------------------------------------
//Time Complexity O(n)
//Space Complexity O(n)

//my logic is that I put only opening brackets in stack and whenever I encounter an operator I pop the stack 

bool redundantBracket(string str){

    stack <char> s;
    bool chk = 0, chk1 = 0;

    for(int i = 0; i < str.length(); i++){

        char ch = str[i];

        //to make a bit better you can use else if now so that not everytime EVERY condition needs to be checked
        //you should also make and fucntion which uses another files stored in a variable that also makes it faster like s.top() which you've used multiple times

        if(ch == '{' || ch == '[' || ch == '('){
            s.push(ch);
            // chk = 1;
        }
        if(ch == '+' || ch == '-' || ch == '*' || ch == '/'){
            // chk = 1;
            s.push(ch);
        }
        if(ch == '}' || ch == ']' || ch == ')' ){
            
            while(1){
                if(s.empty()){
                    break;
                }
                char temp = s.top();
                if(temp == '+' || temp == '-' || temp == '*' || temp == '/'){
                    chk = 1;
                    s.pop();
                    continue;//if there are another operators skip the iteration to them
                }if(chk){
                    s.pop();
                    chk = 0;
                }else{
                    if(chk){
                        return true;
                    }
                    else{
                        break;
                    }
                }

            }
            
        }
        
    }

    bool res = s.empty();
    return !res;
}


//His Approach (better one) -------------------------------------------------------------------------------------------------------------------------------------------
//Time Complexity O(n)
//Space Complexity O(n)
bool findRedundantBracket(string & s){

    stack <char> st;
    for(int i = 0; i < s.length(); i++){

        char ch = s[i];

        if(ch == '(' ||ch == '+' || ch == '-' || ch == '*' || ch == '/'){
            st.push(ch);
        }
        else{

            // ch is either ')' or a lowercase character

            if(ch == ')'){
                bool isRedundant = true;

                while(st.top() != '('){

                    char top = st.top();
                    if(top == '+' || top == '-' || top == '*' || top == '/'){
                        isRedundant = false;
                    }
                    st.pop();
                }
                if(isRedundant == true){
                    return true;
                }

                st.pop(); //to remove the ( bracket in the last

            }
        }

    }

    return false;

}




int main(){

    stack <char> s;
    string str = "(((a+b)))";
    // string str = "((a) + b)";
    // string str = "(a*b+(c/d))";
    // string str = "(a+c*b)+(c))";
    // string str = "(((a+b+d+e))) - c";
    // string str = "((a+b)+c)"; 
    // string str = "((a + b) + (c))";
    

//      We both had same approach (I kinda struggled but.. ) but executions are different ok

    redundantBracket(str) == 1 ? cout<<"Redundant String" : cout<<"No redundancy";//mine 
    cout<<endl;
    findRedundantBracket(str) == 1 ? cout<<"Redundant String" : cout<<"No redundancy";// his (better one)

}