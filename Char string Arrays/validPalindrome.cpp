// A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

// Given a string s, return true if it is a palindrome, or false otherwise.

 

// Example 1:

// Input: s = "A man, a plan, a canal: Panama"
// Output: true
// Explanation: "amanaplanacanalpanama" is a palindrome.
// Example 2:

// Input: s = "race a car"
// Output: false
// Explanation: "raceacar" is not a palindrome.

//Above question is valid plaindrome question

#include<iostream>
using namespace std;

bool isvalid(char ch){
    if ((ch>='a' && ch<='z')||(ch>='A' && ch<='Z')||(ch>='0' && ch<='9'))
    {
        return 1;
    }else{
        return 0;
    }
    
}

char toLowerCase(char ch){
    if ((ch>='a' && ch<='z')||(ch>='0' && ch<='9'))
    {
        return ch;
    }else{
        char temp=ch-'A'+'a';
        return temp;
    }
    
}

bool isPalindromeChar(string word){
    int s=0,e=word.length()-1;

    while (s<e)
    {
        if (word[s]!= word[e])//everything is in lower case already 
        {
            return 0;
        }else{
            s++;
            e--;
        }
    }
    return 1;
} 

bool validPalindrome(string s){
    string temp="";

    // removing all useless characters
    for (int i = 0; i < s.length(); i++)
    {
        if (isvalid(s[i]))
        {
            temp.push_back(s[i]);
            
        }   

    }
    
    //Converting it to lower case
    for (int j = 0; j < s.length(); j++)
    {
        temp[j]=toLowerCase(temp[j]);
    }
    
    //checking if its a plaindrome
    return isPalindromeChar(temp);

}



int main(){
    cout<<validPalindrome("A man, a plan, a canal: Panama");
    cout<<validPalindrome(" , ");
    cout<<validPalindrome(" ");
    cout<<validPalindrome("a");
}