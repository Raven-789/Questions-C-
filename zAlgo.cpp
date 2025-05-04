#include<iostream>
#include<vector>
using namespace std;

//Z Algo function
vector<int> computezarray(string s){
    int n = s.length();
    vector <int> z(n);
    int left = 0, right = 0;

    for (int i = 1; i < n; i++)
    {
        if(i <= right){
            z[i] = min(right - i+1, z[i- left]);
        }

        while (i + z[i] < n && s[z[i]] == s[i +z[i]])
        {
            z[i] ++;
        }

        if(i + z[i] - 1 > right){
            left = i;
            right = i + z[i] - 1;
        }        
    }
    return z;    
}


//Search Function using Z Algo
void Zsearch(string text, string pattern){
    string combined = pattern + "$" + text;
    vector <int> z = computezarray(combined);
    int plen = pattern.length();

    for (int i = 0; i < z.size(); i++)
    {
        if(z[i] == plen){
            cout << "pattern found at index " << i - plen - 1 << endl;
        }
    }
    
}

int main(){
    string text ,pattern;
    cout<<"Enter text: ";
    getline (cin,text);
    cout<<"Enter the pattern: ";
    getline(cin,pattern);

    Zsearch(text,pattern);
}