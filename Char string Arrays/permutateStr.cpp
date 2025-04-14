// Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

// In other words, return true if one of s1's permutations is the substring of s2.

 

// Example 1:

// Input: s1 = "ab", s2 = "eidbaooo"
// Output: true
// Explanation: s2 contains one permutation of s1 ("ba").


#include<iostream>
using namespace std;

bool chkEqual(int a[26], int b[26]){
    for (int i = 0; i < 26; i++)
    {
        //this condition works cause' there are only 2 indexes which are updated and other
        //  indexes are 0 and if its 0 in all array then we've found a match yessss
        
        //AND as we're comparing character wise it checks all the permutations of the string 
        // itself like ab and ba are both compared with this one char at a time type of 
        // comparision way
        if (a[i]!=b[i])
            return 0;
        
    }
    return 1;
}

bool chkInclusion(string s1, string s2){
    //character count array
    int count1[26]={0};

    for (int i = 0; i < s1.length(); i++)
    {
        int index=s1[i]-'a';
        count1[index]++;
    }
    
    //traverse s2 string in window of size s1 length and compare

    int i=0;
    int windowSize=s1.length();
    int count2[26]={0};

    //running for 1st window
    while (i< windowSize && i<s2.length())// this s2.length is for the condition when length of s1 is greater than s2  
    {
        int index=s2[i]-'a';
        count2[index]++;
        i++;
    }
    
    if (chkEqual(count1,count2))
    {
        return 1;
    }
    
    //further processing of window
    //only 2 indexes of the count1 and count 2 are updated so only s1's size is compared that's
    //how window size is maintained by only updating 2 indexes at a time
    
    while (i<s2.length())//the same i is used so it continues from the prev. window's index
    {
        char newChar=s2[i];
        int index=newChar-'a';
        count2[index]++;

        char oldChar=s2[i-windowSize];
        index=oldChar-'a';
        count2[index]--;

        i++;

        if (chkEqual(count1, count2))
            return 1;
        
    }
    return 0;

}

int main(){
    string s1="ab",s2="eidbaooo";
    cout<<chkInclusion(s1,s2);
}