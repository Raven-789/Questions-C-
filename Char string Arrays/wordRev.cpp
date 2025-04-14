#include<iostream>
using namespace std;

string revChar(string &name){
    int s=0,e=name.length()-1;
    while (s<e)
    {
        // cout<<name[s]<<name[e]<<endl;
        swap(name[s++],name[e--]);
        // cout<<name[s]<<name[e]<<endl;
    }
    cout<<name<<endl;
    return name;
}

string wordRev(string &a){
    string temp="",ch="";
    int len1=a.length();

    for (int i = 0; i <len1 ; i++)
    {
        if(a[i]!=' ')
        {
            // cout<<a[i]<<endl;
            temp.push_back(a[i]);
        }
        // if ((a[i]>='a' && a[i]<='z')||(a[i]>='A' && a[i]<='Z'))
        else if(a[i]==' ')
        {
            revChar(temp);
            cout<<temp<<endl;
            int len=temp.length();
            for (int j = 0; j < len; j++)
            {
                ch.push_back(temp[j]);
                cout<<ch[j];
            }
            ch.push_back(' ');
            temp="";
            cout<<ch<<endl;
        }
        // else if (a[i]!=' ')
        // {
        //     // cout<<a[i]<<endl;
        //     temp.push_back(a[i]);
        // }
    }
    revChar(temp);
    cout<<temp<<endl;
    int len=temp.length();
    for (int j = 0; j < len; j++)
    {
        ch.push_back(temp[j]);
        cout<<ch[j];
    }
    ch.push_back(' ');
    // temp="";
    cout<<ch<<endl;
    return ch;
}

int main(){
    string s="Once upon a time",so="noon si live";
    cout<<"Final answer: "<<endl;
    cout<<endl<<wordRev(s)<<endl;
    cout<<wordRev(so);
   
    
}