#include<iostream>
#include<queue>
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
    cout<<"For inserting in the right of: " <<root -> data <<endl;
    root -> right = buildTree(root -> right);

    return root; 

}


void levelOrderTraversal(node *root){

    queue <node*> q ;

    q.push(root);
    q.push(nullptr);

    while(!q.empty()){

        node *temp = q.front();
        
        q.pop();

        if(temp == nullptr){//last level has been completed

            cout<<endl;
            if(!q.empty()){//queue still has some child nodes left
                q.push(nullptr);
            }

        }else{

            cout<< temp -> data <<" ";
            if(temp -> left){
                q.push(temp -> left);
            }
            if(temp -> right){
                q.push(temp -> right);
            }

        }

    }
    cout<<"end"<<endl;

}


//LNR
void inorderTraversal(node * root){

    //base case
    if(root == nullptr){
        return;
    }

    inorderTraversal(root -> left);
    cout<<root -> data << " ";
    inorderTraversal(root -> right);

}

//NLR
void preOrderTraversal(node * root){

    //base case
    if(root == nullptr){
        return;
    }

    cout<<root -> data<<" ";
    preOrderTraversal(root -> left);
    preOrderTraversal(root -> right);

}

//LRN
void postOrderTraversal(node * root){

    //base case
    if(root == nullptr){
        return;
    }
    postOrderTraversal(root -> left);
    postOrderTraversal(root -> right);
    cout<<root -> data << " ";

}

void buildFromLevelOrder(node * &root){

    queue <node*> q ;
    cout<<"Enter value for root node"<<endl;
    int data;
    cin>>data;
    root = new node(data);
    q.push(root);

    while(!q.empty()){

        node * temp = q.front();
        q.pop();

        cout<<"Enter data for left of " <<temp -> data <<endl;
        int leftData;
        cin>>leftData;

        if(leftData != -1){
            temp -> left = new node( leftData);
            q.push(temp -> left);
        }

        cout<<"Enter data for right of "<<temp -> data <<endl;
        int rightData;
        cin>>rightData;

        if(rightData != -1){
            temp -> right = new node(rightData);
            q.push(temp -> right);
        }

    }

}


int main(){

    //hw reverse level order do all orders with iteration too Pre,post and in- order traversals
    //this is also how you declare an object
    node * root = nullptr;
    root = buildTree(root);
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    cout<<"Level Order Traversal Output: "<<endl;
    levelOrderTraversal(root);

    // cout<<"Inorder traversal : "<<endl;
    // inorderTraversal(root);
    // cout<<endl;

    // cout<<"Pre-Order Traversal: "<<endl;
    // preOrderTraversal(root);
    // cout<<endl;

    cout<<"Post-Order Traversal "<<endl;
    postOrderTraversal(root);
    cout<<endl;

    // node * root = nullptr;
    // buildFromLevelOrder(root);
    // //1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1
    // levelOrderTraversal(root);// node * root = nullptr;

}