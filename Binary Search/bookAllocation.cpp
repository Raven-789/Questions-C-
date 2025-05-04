#include<iostream>
#include<vector>
using namespace std;

bool isPossible(vector <int> arr,int m ,int n, int mid){
    int studenCount=1;
    int pageSum=0;

    //cout << "checking for mid "<< mid <<endl;
    for (int i = 0; i < n; i++)
    {

        if (pageSum+arr[i]<=mid)//this assigns books for 1st student till its less than mid (a possible sol)
        {
            pageSum+=arr[i];
        }
        
        else{ // if the mid is greater then we'll go to the next student . Then check constraints 
            //(in if condition check them if you want) then we reset the pagesum to next element of arr 
            //of books (another pg no.)for the next student
            studenCount++;
            
             if ((studenCount>m)||(arr[i]>mid)) 
            {
                return false;
            }
            pageSum=arr[i];//Increasing the pagesum for next iteration with another book and NEXT STUDENT
        }

        //this is if control doesn't go in else condition and comes here we need to still check no. of students
        if (studenCount>m)
        {
            return false;
        }
        //cout << " for i " << i << " Student "<< studentCount << " pageSum " << pageSum << endl;
    }
    return true;
    
}

// m is no of students
// n is no. of books
//
int bookAllocator(vector <int> arr,int n, int m){
    int s=0,sum=0;

    for (int i = 0; i < n; i++)
    {
        sum=sum+arr[i];
    }

    int e=sum;
    int ans=-1;
    int mid=s+(e-s)/2;

    while (s<=e)
    {
        if (isPossible(arr,m,n,mid))
        {
            ans=mid;
            e=mid-1;
        }
        else{
            s=mid+1;
        }
        mid=s+(e-s)/2;
    }
    return ans;

}



int main(){
    // Conditions for no allocation:-
    // The first condition when the book allocation isn't possbile is when the no. of students is more than no. 
    // books just return -1 then its simple and wasn't asked in the question that's why I didn't put it there you can 
    //if you want to now okay

    // If it's impossible to distribute the books to students without exceeding the mid constraint, allocation isn't possible.


    // m is no of students
    // n is no. of books
    vector <int> arr={10,20,30,40};
    cout<<bookAllocator(arr,4,2);

    // vector <int> arr={15,17,20};//with this it gives -1
    // cout<<bookAllocator(arr,3,2);// This gives -1 yaaayyyyyy

    // vector <int> arr={2,1,3,4};
    // cout<<bookAllocator(arr,4,2);
}