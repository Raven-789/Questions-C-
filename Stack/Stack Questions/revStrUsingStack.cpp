#include<iostream>
#include<stack>
using namespace std;

int main(){

    //Time Complexity O(n)
    //Space Complexity O(n)
    string str = "Kaido";
    cout<<str<<endl;
    stack <char> s;

    for(int i = 0; i < str.length(); i++){

        char ch = str[i];
        s.push(ch);

    }

    string ans ="";

    for(int i = 0; i < str.length(); i++){

        char ch = s.top();
        ans.push_back(ch);
        s.pop();

    }
    cout<<ans<<endl;
}