//Pattern 1 First way 

// 1
// 23
// 345
// 4567
// 56789
// 67891011
// 78910111213

// #include<iostream>
// using namespace std;
// int main(){
//     int n;
//     cout <<"Enter a no. ";
//     cin>>n;
    
//     int row=1;
//     while (row<=n)
//     {
//         int col =1;
//         // int val=row;
//         int c=0;
//         while (col<=row)
//         {
            
//             cout<<row+c;
//             c=c+1;
//             // cout<<val;
//             // val=val+1;
//             col=col+1;
//             // row=row+1;
//         }
//         cout<<endl;
//         row=row+1;
//     }
//     cout<<"ok";
// }

//Pattern 1 2ND Way⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻

// 1
// 23
// 345
// 4567
// 56789
// 67891011
// 78910111213
// #include<iostream>
// using namespace std;
// int main(){
//     int n , row =1;
//     cout<<"Enter number :";
//     cin>>n;

//     while (row<=n)
//     {
//         int col=1;
//         while (col<=row)
//         {
//             cout<<(col+row)-1;
//             col=col+1;
//         }
        
//         cout<<endl;
//         row=row+1;
//     }
    
//     cout<<"ok";
// }


// Pattern 2⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻
// 0 3 5 7 9 11 13 15 
// #include<iostream.h>
// using namespace std;
// int main(){
//     for(int i =0;i<=15;i+=2){
//         cout<<i<<" ";
//         // int x;
//         if (i&1){
//             // x=i&1;
//             // cout<<x;
//             continue;
//         }
//         i++;
//     }
// }

//Pattern 3 You have to predict the output⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻

// #include<iostream>
// using namespace std;
// int main(){

//     for(int i=0;i<5;i++){
//         for(int j=i;j<=5;j++){
//             if(i+j==10){
//                 break;
//             }
//             cout<<i<<" "<<j<<endl;
//         }
//     }

// }
// 0 0
// 0 1
// 0 2
// 0 3


//Pattern 4 ⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻

// ask

// ABC
// ABC
// ABC
// comentted line's pattern
// ABC
// DEF
// GHI
// #include<iostream>
// using namespace std;
// int main(){
//    char alpha=65;
//    int num=0;      
//     for (int j = 1; j <= 3; j++){
//         for (int i = 1; i <= 3; i++){
//             cout<<static_cast<char>(alpha+i-1);
//         //  cout<<static_cast<char>(alpha+num); //ask this one
//         //  num=num+1;
//         }
//         cout<<endl;
//     }
// }

// Pattern 5 ⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻

// ABC
// BCD
// CDE

// #include<iostream>
// using namespace std;
// int main(){
//     char alpha='A';
//     for (int i = 1; i <= 3; i++){
//         for (int j = 1; j <=3; j++){
//             cout<<static_cast<char>(alpha+i+j-2);
//         }
//         cout<<endl;
//     }
// }


// Pattern 6 ⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻

// ask
// A activated output
// BC
// CDE
// A
// BC
// DEF
// #include<iostream>
// using namespace std;
// int main(){
//     char alpha='A';
//     int num=0;
//     for (int i = 0; i <= 4; i++){
//         for (int j = 0; j <= i; j++){
//             // cout<<static_cast<char>(alpha+num);
//             cout<<static_cast<char>(alpha+i+j);
//             num++;
//         }
//         cout<<endl;
//     }
// }


//Pattern 7⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻

// D
// CD
// BCD
// ABCD

// #include<iostream>
// using namespace std;
// int main(){
//     char alpha=64;
//     int num=4;
//     int row=1; //for, for loop
//     for (int i = 1; i <=4; i++){
//         char start='A'+4 -i;
//         for (int j = i; j >=1; j--)
//         {
//             // cout<<static_cast<char>(alpha+num-j+1); // My version which was better this time yeessssssss
//             cout<<start; //vid version
//             start++; // vid version
//         }
//         cout<<endl;
//     } 
// }


//Pattern 8⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻

//     *
//    **
//   ***
//  ****
// #include<iostream>
// using namespace std;
// int main(){
//     for (int i = 1; i <=4; i++){
//         for (int j = 1; j <= 4-i; j++){
//             cout<<" ";
//         }
//         for (int k = 1; k<=i; k++){
//             cout<<"*";
//         }
//         cout<<endl;
//     }
// }

//Pattern 9⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻

//Current activated output
// ****
// ***
// **
// *
//Output if space K loop is activated
// ****
//  ***
//   **
//    *

// #include<iostream>
// using namespace std;
// int main(){
//     for (int i = 4; i >=1; i--){
//         // for (int k = 0; k <4-i;k++){
//         //     cout<<" ";
//         // }
//         for (int j = 1; j <= i; j++){
//             cout<<"*";
//         }
//         cout<<endl;
//     }
// }

//Pattern 10⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻

// you can also do this with variable but we didn't as it was easier & also we wanted to improve
// 1111
//  222
//   33
//    4

// #include<iostream>
// using namespace std;
// int main(){
//     for (int i =4; i >= 1; i--){
//         for (int k = 0; k<4-i; k++){
//             cout<<" ";
//         }
//         for (int j = 1; j <=i; j++){
//             cout<<4-i+1;
//         }
//         cout<<endl;
//     }
// }

//Pattern 11⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻

//    1
//   22
//  333
// 4444

// #include<iostream>
// using namespace std;
// int main(){
//     for (int i =1; i <= 4 ; i++){
//         for (int k = 1; k<4-i+1; k++){
//             cout<<" ";
//         }
//         for (int j = 1; j <=i; j++){
//             cout<<i;
//         }
//         cout<<endl;
//     }
// }

//Pattern 12⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻

// 1234
//  234
//   34
//    4

// #include<iostream>
// using namespace std;
// int main(){
//     for (int i = 0; i < 4; i++){
//         for (int k = 1; k <=i; k++){
//             cout<<" ";
//         }
        
//         for (int j = i+1; j <=4; j++){
//             cout<<j;
//         }
//         cout<<endl;        
//     }
// }

//Pattern 13⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻

//   1
//  23
// 456

// #include<iostream>
//   using namespace std;
//   int main (){
//     int num=1;
//     for (int i = 1; i <= 3; i++){
//         for (int k = 1; k <= 3-i; k++){
//             cout<<" ";
//         }
        
//         for (int j = 1; j <=i ; j++){
//             cout<<num;
//             num++;
//             // cout<<i+j-1;
//         }
//         cout<<endl;
//     }
//   }


//Pattern 14⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻

//yaaayyyyy!!! yeah but check the placements of loops and 3 things you print here
//    1
//   121
//  12321
// 1234321

// #include<iostream>
// using namespace std;
// int main(){
//     for (int i = 4; i >= 1; i--){
//         for (int k = 1; k < i; k++){
//             cout<<" ";
//         }
        
//         for (int j = 1; j <= 4-i+1; j++){
//             cout<<j;
//         }
//         for (int l = 1; l <= 4-i; l++){
//             cout<<4-i-l+1;
//         }
//         cout<<endl;
//     }
// }

//Pattern 15⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻

//     *
//    ***
//   *****
//  *******
// *********

// New logic for a Pyramid And Reverse the "i" loop to invert the Pyramid 
//The Previous logic was to divide the Pyramid and do it but if its just 1 character
// #include<iostream>
// using namespace std;
// int main(){
//     for (int i = 1; i <=5; i++)
//     {
//         for (int k = 1; k <=5-i; k++)
//         {
//             cout<<" ";
//         }
        
        
//         for (int j = 1; j <=2*i-1; j++)
//         {
//             cout<<"*";
//         }

//         cout<<endl;
//     }
// }

//Pattern 16⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻

// 1234554321
// 1234**4321
// 123****321
// 12******21
// 1********1

// #include<iostream>
// using namespace std;
// int main(){
//     for (int i = 1; i <= 5; i++)
//     {
//         for (int j = 1; j <= 5-i+1; j++)
//         {
//             cout<<j;
//         }
//         // I would've used k loop first as in all other questions of vid patterns 
//         // but here Placement was required to put k loop after i see it you'll get it
//         for (int k = 1; k <= (i-1)*2; k++)
//         {
//             cout<<"*";
//         }

//         for (int l = 5-i+1; l >= 1; l--)
//         {
//             cout<<l;
//         }
//         cout<<endl;
//     }
    
// }



