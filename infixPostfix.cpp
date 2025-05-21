#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

//Check if character is operator
bool isOperator(char c){
    return (c=='+'|| c=='-'|| c=='/'|| c=='^'|| c=='*' );
}

//Return precedence of operators
int precedence(char c){
    if(c=='^')
        return 3;
    if(c=='*'|| c=='/' )
        return 2;
    if(c=='+'|| c=='-' )
        return 1;
    return -1;
}

//Infix to Postfix concersion
string infixToPostfix(string s){
    stack <char> st;
    string result;

    for(char c : s){
        //if operand, add to result
        if(isalnum(c)){
            result +=c;
        }
        //if '(' is pushed into stack
        else if(c== '('){
            st.push(c);
        }
        ///if '(' is to be popped till '(' is encountered
        else if(c==')'){
            while(!st.empty() && st.top()!='(' ){
                result += st.top();
                st.pop();
            }
            if(!st.empty()) st.pop(); //remove '(' 
        }
        //Operator 
        else if(isOperator(c)){
            while(!st.empty() && precedence(st.top()) >= precedence(c)){
                result += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    //Pop any remaining operators
    while (!st.empty()){
        result += st.top();
        st.pop();
    }

    return result;
}

//Infix to prefix conversion
string infixToPrefix(string s){
    //Reverse the infix string
    reverse(s.begin(),s.end());

    //Swap '(' with ')' and vie versa
    for (int i = 0 ; i < s.length() ; i++){
        if(s[i]== '(' ) s[i]=')';
        else if( s[i]==')') s[i]='(';
    }

    //Convert reversed expression to postfix
    string postfix=infixToPostfix(s);

    //Reverse postfix to get prefix
    reverse(postfix.begin(), postfix.end());

    return postfix;
}

int main(){
    string infix ="(A-B/C)*(A/K-L)";

    cout<<"Infix: "<< infix<<endl;
    cout<<"Postfix: "<<infixToPostfix(infix)<<endl;
    cout<<"Prefix: "<<infixToPrefix(infix)<<endl;
}
