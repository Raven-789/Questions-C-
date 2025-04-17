#include<iostream>
#include<vector>
using namespace std;
//Segmented Sieve
//Time complexity of thsi function is
//O(n*log(log n))
//Harmonic Progession 1/2+1/3+1/5+1/7... (2,3,5,7 are prime no.s)

int countPrimes(int n){
  int cnt=0;
  vector <bool> prime(n+1,true);
  prime[0]=prime[1]=false;

  for (int i = 2; i < n; i++)
  {
    if (prime[i])
    {
      cnt++;
      for (int j = 2*i; j < n; j=j+i)
      {
        prime[j]=0;
      }
      
    }
    
  }
  return cnt;
}

int main(){
int num;
cout<<"Enter number: ";
cin>>num;
int num2;
cout<<"Enter another number: ";
cin>>num2;


    for (int j = num; j <= num2; j++)
    {
        int f=0;
        for (int i = 2; i <j; i++)
        {
            if (j%i==0)
            {
                f++;
                break;
            }
            // cout<<"hw";
        }
      if (f==0)
      {
        cout<<j<<endl;
        // f=0;
      }
    //   f=0;
    }

}