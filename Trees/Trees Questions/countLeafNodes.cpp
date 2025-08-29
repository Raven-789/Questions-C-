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

    cout<<"Enter data for inserting in the left of " <<root -> data <<endl;
    root -> left = buildTree(root -> left);
    cout<<"Enter data for inserting in the right: " <<root -> data <<endl;
    root -> right = buildTree(root -> right);

    return root;

}


//My Appproach ----------------------------------------------------------------------------------------------------------------------------------
//Time Complexity O(n)
//Space Compexity O(n)

void preOrderTraversal(node * root, vector <node*> & v){

    //base case
    if(root == nullptr){
        
        return;
    }

    cout<<root -> data<<" ";
    v.push_back(root);
    preOrderTraversal(root -> left,v);
    preOrderTraversal(root -> right,v);
}

int countLeafNodes(node * root){

    vector <node *> v;
    preOrderTraversal(root,v);
    int cnt = 0;

    for(auto ele : v){
        if(ele -> left == nullptr && ele -> right == nullptr){
            cnt++;
        }
    }
    return cnt;

}

//his Appproach easier and efficient----------------------------------------------------------------------------------------------------------------------------------
//Time Complexity O(n)
//Space Compexity O(1)

void Traversal(node * root,int &cnt){

    //base case
    if(root == nullptr){
        
        return;
    }

    cout<<root -> data<<" ";
    Traversal(root -> left,cnt);

    //leaf node
    if(root -> left == nullptr && root -> right == nullptr){
        cnt++;
    }

    Traversal(root -> right,cnt);
    
}

int countLeafNodesHis(node * root){

    int cnt = 0;
    Traversal(root,cnt);
    return cnt;

}



int main(){

    node * root = nullptr;
    root = buildTree(root);
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    
    cout<<"Preorder Traversal: "<<endl;
    // preOrderTraversal(root);
    cout<<"No. of leaf node are : "<< countLeafNodes(root);
    // cout<<"No. of leaf node are (His) : "<< countLeafNodesHis(root);
}
