#include<iostream>
#include<queue>
#include<stack>
using namespace std;


class node{

    public:
        int data;
        node *left;
        node *right;


        node(int d){

            data = d;
            left = nullptr;
            right = nullptr;

        }



};

//1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

node* buildTree(node * root){
    
    int data;
    cout<<"Enter the data: ";
    cin>>data;
    
    root = new node(data);

    if(data == -1){
        return nullptr;
    }
    cout<<"For inserting in the left of " <<root -> data <<endl;
    root -> left = buildTree(root -> left);
    cout<<"For inserting in the right: " <<root -> data <<endl;
    root -> right = buildTree(root -> right);

    return root;

}


void levelAndRevOrderTraversal(node *root){

    deque <node*> q ;
    deque <node*> dq;

    q.push_back(root);
    dq.push_back(root);
    
    q.push_back(nullptr);
    dq.push_back(nullptr);

    cout<<endl<<"Level Order: "<<endl;
    while(!q.empty())
    {
        node *temp = q.front();
        
        q.pop_front();

        
        if(temp == nullptr){//last level has been completed

            cout<<endl;
            if(!q.empty()){//queue still has some child nodes left
                q.push_back(nullptr);
                dq.push_back(nullptr);
            }

        }else{

            cout<< temp -> data <<" ";
            
            if(temp -> left){
                q.push_back(temp -> left);
                dq.push_back(temp -> left);
            }
            if(temp -> right){
                q.push_back(temp -> right);
                dq.push_back(temp -> right);
            }

        }

    }
    cout<<"end"<<endl;

    cout<<"Reverse Level Order: "<<endl;
    dq.pop_back();
    while(!dq.empty()){

        if(dq.back() == nullptr){
            cout<<endl;
        }else{
            cout<<dq.back() ->data<<" ";
        }
        dq.pop_back();
    }

}

int main(){

    node * root = nullptr;
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    root = buildTree(root);
    levelAndRevOrderTraversal(root);

}