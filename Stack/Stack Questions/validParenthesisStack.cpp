#include<iostream>
#include<stack>
using namespace std;


//My Approach got beaten again---------------------------------------------------------------------------------------------------------
//Time Complexity O(n)
//Space Complexity O(1)
bool isBalanced(stack <char> s, string str){


    for(int i = 0; i < str.length(); i++){

        //Pushing the expression's charcters one by one in the stack
        char ch = str[i];
        if(ch == '{' || ch == '[' || ch == '(' ){
            s.push(ch);
        }

        if(!(s.empty())){// he made this condtion better... a lot better -----------------------------------------------------------
            if(ch == '}' ){
                if(s.top() == '{'){
                    s.pop();
                }else{
                    return false;
                }
            }if (ch == ']' ){
                if( s.top() == '['){
                    s.pop();
                }else{
                    return false;
                }
            }if(ch == ')'){
                if(s.top() == '('){
                    s.pop();
                }else{
                    return false;
                }
            }
        }else{
            return false;
        }
    }

    if(s.empty()){
        return true;
    }else{
        return false;
    }

}

//His Approach (better one)-------------------------------------------------------------------------------------------------------
//Time Compleixty O(n)
//Space Complexity O(1)

bool validParanthesis(string str){

    stack <char> s;

    for(int i = 0; i < str.length(); i++){

        char ch = str[i];

        //if its a closing bracket
        //if close bracket, stacktop check and pop

        if(ch == '{' || ch == '[' || ch == '('){
            s.push(ch);
        }else{// his conditon is better than mineee!!!--------------------------------------------------------------------------------

            //for closing bracket
            if(!(s.empty())){
                char top = s.top();
                if((ch == ')' && top == '(') || 
                   (ch == '}' && top == '{') || 
                   (ch == ']' && top == '[')){

                    s.pop();
                }
                else{
                    return false;
                }
            }
            else{
                return false;
            }
        }
    }

    if(s.empty()){
        return true;
    }else{
        return false;
    }


}



int main(){
    stack <char> s;
    // string str ="][(){}(({[]}))]";// checking a condition
    string str = "[()]";//checking another condtion
    // string str = "[{()]]";//checking another condtion
    // string str = "[(}{)]";//checking another condtion
    
    
    // if(isBalanced(s, str)){
    //     cout<< "Balanced"<<endl;
    // }else{
    //     cout<<"Un-Balanced"<<endl;
    // }

        if(validParanthesis(str)){
        cout<< "Balanced"<<endl;
    }else{
        cout<<"Un-Balanced"<<endl;
    }
}