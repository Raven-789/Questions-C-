#include<iostream>
#include<deque>
using namespace std;

int main(){
    deque <int> dq;

    dq.push_back(10);
    dq.push_front(20);
    dq.push_back(30);
    dq.pop_front();
    dq.pop_back();

    cout<<"After pops, Front : "<< dq.front()<<endl;
}