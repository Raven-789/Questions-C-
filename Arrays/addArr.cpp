#include<iostream>
#include<vector>
using namespace std;

vector <int> reverse(vector <int>v){
    int s=0;
    int e=v.size()-1;

    while (s<e)
    {
        swap(v[s++],v[e--]);
    }
    return v;
}

vector <int> arrSum(vector <int>& a,int n, vector <int>& b,int m){//that return type and the reverse function is for test okay
    int i=n-1;
    int j=m-1;
    vector <int> ans;
    int carry=0;

    while (i>=0 &&j>=0)
    {
        int val1=a[i];
        int val2=b[i];

        int sum =val1+val2+carry;

        carry=sum/10;
        sum=sum%10;
        ans.push_back(sum);
        i--;j--;
    }

    //first case

    while (i>=0)
    {
        int sum =a[i]+carry;

        carry=sum/10;
        sum=sum%10;
        ans.push_back(sum);
        i--;
    }
    
    //second case

    while (j>=0)
    {
        int sum =b[j]+carry;

        carry=sum/10;
        sum=sum%10;
        ans.push_back(sum);
        j--;
    }

    //third case

    while (carry!=0)
    {
        int sum =carry;

        carry=sum/10;
        sum=sum%10;
        ans.push_back(sum);
    }
    
    //showing the answer
    // return reverse(ans); //this return is for code test okay
    for (int i =  ans.size()-1 ; i>=0 ; i--)
    {
        cout<<ans[i]<<" ";
    }
        
    
    
}

int main(){
    vector <int> arr1={1,2,3,4,5,6};
    vector <int> arr2={1,2,3,4,5,6};
    arrSum(arr1,arr1.size(),arr2,arr2.size());
}