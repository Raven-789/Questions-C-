//Decimal to Binary +ve Numbers

// #include<iostream>
// #include<math.h>
// using namespace std;
// int main(){
//     int n;
//     cin>>n;
//     float ans=0; // use float as beacuse of precision issues the no. maybe different okay for pow funciton
//     int i=0;
//     while (n!=0)
//     {
//         // float bit =n%10;
//         float bit =n&1;
//         // bit= ;
//         float p=pow(10,i);
//         // cout<<pow(10,i)<<endl;
//         ans=(bit * p)+ans; //This is used to reverse a DIGIT NOT A NUMBER in order for number you can mod and use ans=(mod*10)+ans
        
//         cout<<ans<<endl;
//         n=n >> 1;   
//         i++;
//     }
//     cout<<"Answer is "<<ans<<endl;

// }

// ⸻⸻⸻⸻⸻⸻⸻⸻Binary to Decimal Numbers⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻
//
// #include<iostream>
// #include<math.h>
// using namespace std;
// int main(){
//     int num,i=0;
//     cin>>num;
//     float dec;
//     while (num!=0)
//     {
//         int dig=num%10;
//         if (dig==1)
//         {
//             dec=dec+pow(2,i);
//         }
//         i++;
//         num=num/10;
//     }
//     cout<<dec;
    
// }


// ⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻1's complement⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻
//
// #include<iostream>
// #include<math.h>
// using namespace std;
// int main(){

// 1st Attempt of 1's complement

    // int n,i=0,m=0;
    // float ans=0;
    // cin>>n;
    // int num=n,n1=n;
    // while(n!=0){
    //     int bit=n&1;
    //     ans=(pow(10,i)*bit)+ans;
    //     n=n>>1;
    //     i++;
    // }
    // // int ansi=ans;
    // cout<<ans<<endl;
    // cout<<n<<num<<n1<<endl;
    // // cout<<ansi;

    // if (num==0)
    // {
    //     return 1;
    // }
    
    // while (num!=0)
    // {
    //     m=((m << 1)|1);
    //     num=num>>1;
    // }
    // float ans1= ((~n1) & m);
    // cout<<ans1;
    
// --------------------------------------------------------Shorter way of 1's complement---------------------------------------------------------------------------------------
//

    // int n;
    // cin>>n;
    // int m=n,mask=0;
    // while (n!=0)
    // {
    //     mask=(mask<<1)|1;
    //     n=n>>1;
    // }
    // int ans=(~m)&mask;
    // cout<<ans;  
// }

// ⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻ Negative no. to Binary⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻
//

#include<iostream>
#include<math.h>
using namespace std;
int main(){
//     // int num,i=0,mask;
//     // float bin;
//     // cin>>num;
//     // num=num*-1;
//     // while(num!=0){
//     //     int bit=(num&1);
//     //     if (bit==1)
//     //     {
//     //         bin=(pow(10,i)*0)+bin;
//     //     }
//     //     else
//     //         bin=(pow(10,i)*1)+bin;
        
//     //     // bin=(pow(10,i)*bit)+bin;
//     //     num=num>>1;
//     //     i++;
//     // }
//     // cout<<bin;

    int num;
    cin >> num;
    unsigned int bin = static_cast<unsigned int>(num); //this is to simplify -ve no. storage as unsigned it makes it easier

    cout << "Binary representation: ";
    for (int i = 31; i >= 0; i--) {
        cout << ((bin >> i) & 1);     // here as we stored the no. in unsigned int its easier 
            //so we just use 31 as its storage and use & operator to get the stored bits AI is crwwaaazzyy
    }
    cout << endl;
}