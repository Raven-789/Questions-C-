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


//--------------------------------------------------------------------------------------------------------------------------------------------

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

//Optimized One------------------------------------------------

void iterativeInOrderTraversal1(node *root) {
    stack<node*> s;
    node* current = root;

    while (current != nullptr || !s.empty()) {
        // Reach the leftmost node of the current node
        while (current != nullptr) {
            s.push(current);
            current = current->left;
        }

        // Current must be NULL at this point
        current = s.top();
        s.pop();

        cout << current->data << " ";  // Visit the node

        // Now, visit the right subtree
        current = current->right;
    }
}

//My One-----------------------------------------------------------------------------------------------------------

void iterativeInorderTraversal(node * root){

    deque <node *> dq;
    stack <node *> s;
    bool chkr = false, chkl = false;
    
    dq.push_back(root);
    s.push(root);
    
    cout<<"Iterative Inorder Traversal: "<<endl;
    
    if(root == nullptr){
        cout<<" "<<endl;
        return;
    }
    while(!s.empty()){
        
        node * temp = s.top();

        while(temp -> left != nullptr){

            chkl = true;
            temp = temp -> left;
            s.push(temp);
            
        }
        
        if(s.top() -> left == nullptr){
            cout<<s.top() -> data << " ";
            s.pop();
        }
        // else if(s.top() -> right != nullptr){//&& temp -> data == s.top() -> data
        //     cout<<s.top() -> data<<" ";
        //     s.pop();
        // }

        if(temp -> right != nullptr){
            temp = temp -> right;
            s.push(temp);
            chkr = true;
        }

        if(chkr){
            // cout<<s.top();
            // s.pop();
        }else if (!s.empty() && s.top() -> left != nullptr){
            // cout<<" -- "<<s.top() -> data<<" -- ";
            s.top() -> left = nullptr;
        }
        // else if (!s.empty() && s.top() -> right != nullptr){
        //     // cout<<" --"<<s.top() -> data<<"-- ";
        //     s.top() -> right = nullptr;
        // }

        
        chkl = chkr = false;
    }

}


// ----------------------------------------------------------------------------------------------------------------------------------------------------------


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

//Optimized One----------------------------------------------------------------------------------------------------------

void iterativePreOrderTraversal1(node *root) {
    if (!root) return; // If root is null, no traversal needed.
    
    stack<node*> s;
    s.push(root);  // Push the root onto the stack.

    while (!s.empty()) {
        node *current = s.top();
        s.pop();
        cout << current->data << " ";  // Visit the node (preorder).

        // Push the right child first so the left child is processed first.
        if (current->right) {
            s.push(current->right);
        }
        if (current->left) {
            s.push(current->left);
        }
    }
}

//My One-----------------------------------------------------------------------------------------------------------

void iterativePreOrderTraversal(node * root){

    deque <node *> dq;
    stack <node *> s;
    bool chkr = false, chkl = false;
    
    cout<<"Iterative Pre-Order Traversal: "<<endl;
    
    if(root == nullptr){
        cout<<" "<<endl;
        return;
    }

    dq.push_back(root);
    s.push(root);
    cout<<s.top() -> data << " ";//printing the current element as in Pre Order parent comes first

    while(!s.empty()){
        
        node * temp = s.top();

        //To print the node
        // if(s.top() -> left == nullptr){
        //     cout<<s.top() -> data << " ";
        //     s.pop();
        // }
        // else if(s.top() -> right != nullptr){//&& temp -> data == s.top() -> data
        //     cout<<s.top() -> data<<" ";
        //     s.pop();
        // }     

        
        //to go into left node
        while(temp -> left != nullptr){

            chkl = true;
            temp = temp -> left;//saving the next left element in stack
            s.push(temp);
            cout<<s.top() -> data << " ";//printing the current element which is in the LEFT
            
        }
        // if(chkl){
        //     cout<<s.top() -> data<<" ";
        // }
        // else if(!chkl && temp -> left == nullptr && temp -> right == nullptr){//if its a leaf node and I've taken care if the leaf node is a parent as in Pre Order parent is already printed
        //     // s.push(s.top());
        //     cout<<s.top() -> data<<" ";
        // }

        // if(temp -> left == nullptr && temp -> right == nullptr){
        //     cout<<s.top() -> data << " ";//printing the element whose left is null
        //     s.push(temp);
            
        // }

        //to go into right node
        if(temp -> right != nullptr){
            chkr = true;
            temp = temp -> right;//saving the next RIGHT element in stack
            s.push(temp);
            cout<<s.top() -> data << " ";//printing the current element which is in the RIGHT as we've to print Parent First
            
        }

        
        //to remove an element from the tree to traverse 
        if(chkr){
            // cout<<s.top();
            // s.pop();

        }else if (!s.empty() && s.top() -> right == nullptr){
            s.pop();//we need to track parents 
            if(!s.empty()){
                // cout<<" --"<<s.top() -> data<<"-- ";
                //to check which element we've to pop from the tree
                if(s.top() -> left != nullptr){
                    s.top() -> left = nullptr;
                }else if(s.top() -> right != nullptr){
                    s.top() -> right = nullptr;
                }
            }
            

            //to pop the parent (new s.top()) if its becomes leaf node in traversal as its Pre Order that 
            // parent is already printed so we need to pop it from the tree
            if(!s.empty() && s.top() -> left == nullptr && s.top() -> right == nullptr){
                s.pop();

                //to check which node current child node of the parent node (is it left of the its parent or right of its parent)
                if(s.top() -> left != nullptr){
                    s.top() -> left = nullptr;
                }else if(s.top() -> right != nullptr){
                    s.top() -> right = nullptr;
                }
                // cout<<" --"<<s.top() -> data<<"-- ";
            } 
        }
        // else if (!s.empty() && s.top() -> right != nullptr){
        //     // cout<<" --"<<s.top() -> data<<"-- ";
        //     s.top() -> right = nullptr;
        // }

        
        
        
        chkl = chkr = false;
    }


}


// ----------------------------------------------------------------------------------------------------------------------------------------------------------------

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


//Single Stack version-----------------------------------------------------------------------

void iterativePostOrderTraversal1(node* root) {
    if (root == nullptr) return;

    stack<node*> s1, s2;

    s1.push(root);

    while (!s1.empty()) {
        node* curr = s1.top();
        s1.pop();
        s2.push(curr);

        if (curr->left) s1.push(curr->left);
        if (curr->right) s1.push(curr->right);
    }

    while (!s2.empty()) {
        cout << s2.top()->data << " ";
        s2.pop();
    }
}

//2 stack version (Tricker but efficient)-------------------------------------------------------

void iterativePostOrderTraversal2(node* root) {
    if (root == nullptr) return;

    stack<node*> s;
    node* current = root;
    node* lastVisited = nullptr;

    while (current != nullptr || !s.empty()) {
        if (current != nullptr) {
            s.push(current);
            current = current->left;
        } else {
            node* peekNode = s.top();
            if (peekNode->right != nullptr && lastVisited != peekNode->right) {
                current = peekNode->right;
            } else {
                cout << peekNode->data << " ";
                lastVisited = peekNode;
                s.pop();
            }
        }
    }
}


//My one-----------------------------------------------------------------------------------

void iterativePostOrderTraversal(node * root){

    deque <node *> dq;
    stack <node *> s;
    bool chkr = false, chkl = false;
    
    dq.push_back(root);
    s.push(root);
    
    cout<<"Iterative Post Order Traversal: "<<endl;
    
    if(root == nullptr){
        cout<<" "<<endl;
        return;
    }
    while(!s.empty()){
        
        node * temp = s.top();

        while(temp -> left != nullptr){

            chkl = true;
            temp = temp -> left;
            s.push(temp);
            
        }

        if(temp -> right != nullptr){
            temp = temp -> right;
            s.push(temp);
            chkr = true;
        }


        if(s.top() -> left == nullptr && !chkr){//!chkr makes sure that current node is a leaf node if its not it needs to be checked for left nodes ok
            cout<<s.top() -> data << " ";
            s.pop();
        }
        // else if(s.top() -> right != nullptr){//&& temp -> data == s.top() -> data
        //     cout<<s.top() -> data<<" ";
        //     s.pop();
        // }


        if(chkr){
            // cout<<s.top();
            // s.pop();
        }else if (!s.empty() && !chkr){//s.top() -> right == nullptr
            // s.pop();//we need to track parents 
            if(!s.empty()){
                // cout<<" --"<<s.top() -> data<<"-- ";
                //to check which element we've to pop from the tree
                if(s.top() -> left != nullptr){
                    s.top() -> left = nullptr;
                }else if(s.top() -> right != nullptr){
                    s.top() -> right = nullptr;
                }
            }
            

            //to pop the parent (new s.top()) if its becomes leaf node in traversal as its Pre Order that 
            // parent is already printed so we need to pop it from the tree
            if(!s.empty() && s.top() -> left == nullptr && s.top() -> right == nullptr){
                cout<<s.top() -> data << " ";// before removing the leaf parent node we've to print it as its different in Post Order
                s.pop();//to pop the parent from the stack if its leaf node now

                //to check which node current child node of the parent node (is it left of the its parent or right of its parent)
                if(s.top() -> left != nullptr){
                    s.top() -> left = nullptr;
                }else if(s.top() -> right != nullptr){
                    s.top() -> right = nullptr;
                }

                // cout<<" --"<<s.top() -> data<<"-- ";
            } 
        }
        // else if (!s.empty() && s.top() -> right != nullptr){
        //     // cout<<" --"<<s.top() -> data<<"-- ";
        //     s.top() -> right = nullptr;
        // }

        
        chkl = chkr = false;
    }


}




int main(){

    node * root = nullptr;
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    root = buildTree(root);

    //You can't use all 3 of them at once as you destroy the tree in Traversal ok but Optimized ones don't I think

    // cout<<"Inorder Traversal"<<endl;
    // inorderTraversal(root);
    // iterativeInorderTraversal(root);


    // cout<<"Pre Order Traversal: "<<endl;
    // preOrderTraversal(root);cout<<endl;
    // iterativePreOrderTraversal(root);

    
    cout<<"Post Order Traversal: "<<endl;
    postOrderTraversal(root);cout<<endl;
    iterativePostOrderTraversal(root);

}