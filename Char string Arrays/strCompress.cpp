// Given an array of characters chars, compress it using the following algorithm:

// Begin with an empty string s. For each group of consecutive repeating characters in chars:

// If the group's length is 1, append the character to s.
// Otherwise, append the character followed by the group's length.
// The compressed string s should not be returned separately, but instead, be stored in the input character array chars. Note that group lengths that are 10 or longer will be split into multiple characters in chars.

// After you are done modifying the input array, return the new length of the array.

// You must write an algorithm that uses only constant extra space.

 

// Example 1:

// Input: chars = ["a","a","b","b","c","c","c"]
// Output: Return 6, and the first 6 characters of the input array should be: ["a","2","b","2","c","3"]
// Explanation: The groups are "aa", "bb", and "ccc". This compresses to "a2b2c3".


#include<iostream>
#include<vector>
using namespace std;

int compress(vector <string> &chars){
    int i=0;
    int ansIndex=0;
    int n=chars.size();

    while (i<n)
    {
        // MISTAKE was you put "j" instead of "i"
        int j=i+1;//first character of the chars vector 
        // comparing that jth index chars vector with all other character when it doesn't
        //  matches it means new char has been encountered
        while (j<n && chars[i]==chars[j])
        {
            j++;
        }
        
        //storing that jth char in the same vector
        chars[ansIndex++]=chars[i];

        int count =j-i;// this gives the no. of occ. of that jth char

        if (count>1)
        {
            string cnt=to_string(count);
            for (char ch : cnt)
            {
                chars[ansIndex++]=ch;
            }
            
        }

        //going to new char
        i=j;

    }
    for (int i = 0; i < n; i++)
    {
        cout<<chars[i]<<" ";
    }
    return ansIndex;
    
    
}
// int compress(vector<string> &chars) {
//     int i = 0;
//     int ansIndex = 0;
//     int n = chars.size();

//     while (i < n) {
//         int j = i + 1;

//         while (j < n && chars[i] == chars[j]) {
//             j++;
//         }

//         // Store current character
//         chars[ansIndex++] = chars[i];

//         int count = j - i;

//         if (count > 1) {
//             string cnt = to_string(count);
//             for (char ch : cnt) {
//                 chars[ansIndex++] = string(1, ch);  // Since vector<string>, wrap ch in string
//             }
//         }

//         i = j;
//     }

//     chars.resize(ansIndex); // Optional: remove leftovers
//     for (int i = 0; i < n; i++)
//     {
//         cout << chars[i] << " ";
//     }

//     return ansIndex;
// }


int main(){
    vector <string> x={"a","a","b","b","c","c","c"};

    compress(x);
}