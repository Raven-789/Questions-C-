#include<iostream>
#include<vector>
using namespace std;
void printarr(vector<int> arr,int size){
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

//0 2 2 0 0 0 1 1 2 1 1 1
void sort0s1s2s(vector<int> arr,int size){
    int left=0,right =size-1;
    while (left<right){ //Do not put <= there it goes into infinite loop
        while ((arr[left]==0)&&(left<right))
        {
            left++;
        } //{1,1,2,0,0,0,1,1,2,2,1,0}
        if ((arr[right]==0)&&(arr[left]==1)&&(left<right))//Modify for 0 swaping
        {
            swap(arr[left],arr[right]);
            left++;
            right--;
        }
        // cout<<left;
        //that OR condition makes skip right pointer towards the left (that is the other end) skipping 
        //1s or 2s to sort them later
        while ((arr[right]==2)||(arr[right]==1)&&(left<right))
        {
            right--;
        }
        //--------------------------------------------------------------------------------------------
        //find out why is this if block results in infinite loop if commented 
        if (left<right)
        {
            swap(arr[left],arr[right]);
            left++;
            right--;
        }
        //--------------------------------------------------------------------------------------------
        //condition for geting desired left val in the same while loop and as condtion of right & left
        //is left<right it'll be equal if it doesn't satisfies as that variable still got incremented the 
        //last time that's why the condtion was unfullfilled and loop stops

        //its a condition for getting the end of 0s side
        if (left==right)
        {       //0 0 0 0 2 1 1 1 2 2 1 1 
            // right==size-1;//fuck this mistake okay
            right=size-1;
            //Left ptr should be increased as the left denotes the position of a 0 so we need to go 1+
            // so that it doesn't gives this 0 0 0 0 2 1 1 1 2 2 1 1  as output
            left=left+1;
            while (left<right)
            {
                // cout<<left<<endl;
                //resetting right pointer to the right end so that we can do the swaping loop like for 2 
                //different elements after finding the end for the first element i.e 0, so its just 1s & 2s now yesss
                
                // cout<<left;
                while ((left<right)&&(arr[left]==1))
                {
                    // cout<<left<<endl;
                    left++;
                }
                
                while ((arr[right]==2)&&(left<right))
                {
                    right--;
                    // cout<<right<<endl;
                }

                if (left<right)
                {
                    swap(arr[left],arr[right]);
                    left++;
                    right--;
                }
                
            }
        }
            
        
    }
    // cout<<left;// I did this to see if the left ptr is at the correct position or not
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
}

int main(){
    vector<int> arr={1,1,2,0,0,0,1,1,2,2,1,0};
    sort0s1s2s(arr,12);
    // printarr(arr,12);//You can't print vectors like array as it in arrays the original memeory
    //  address is edited but this is vector

}