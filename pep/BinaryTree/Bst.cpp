#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int val;
    Node *right;
    Node *left;
    Node(int val, Node *left ,Node *right){
        this->left= left;
        this->right = right;
        this->val = val;
    }
};

class Pair{
    public:
    Node *node;
    int state;
    Pair(int state , Node *node){
        this->state = state;
        this->node = node;
    }
};

Node *construct(vector<int> a){
    stack<Pair> st;
    Node *root = new Node(a[0],NULL,NULL);
    st.push(Pair(1,root));
    int idx =0;
    while(st.size() > 0){
       Pair e = st.top();
       st.pop();
       if(e.state == 1){
           idx++;
           if(a[idx] != -1){
               Node *nTa = new Node(a[idx],NULL,NULL);
               e.node->left = nTa;
               st.push(Pair(e.state+1,e.node));
               st.push(Pair(1,nTa));
           }else{
               e.node->left = NULL;
               st.push(Pair(e.state+1,e.node));
           }
        //    e.state++;
       }else if (e.state == 2){
           idx++;
           if(a[idx] != -1){
               Node *nTa = new Node(a[idx],NULL,NULL);
               e.node->right = nTa;
               st.push(Pair(e.state+1,e.node));
               st.push(Pair(1,nTa));

           }else{
                e.node->right = NULL;
                st.push(Pair(e.state+1,e.node));
           }
        //    e.state++;
           
       }
       
            
    }
    return root;
}

void display(Node *root){
    if(root == NULL){
        return;
    }
    
    string str = "";
    str += root->left == NULL ? "." :to_string(root->left->val) + "";
    str += " <- " + to_string(root->val) + " -> ";
    str += root->right == NULL ? "." : to_string(root->right->val) + "";
    cout<< str<< endl;

    display(root->left);
    display(root->right);
}

int size(Node *root){
    if(root == NULL){
        return 0;
    }
    

    return size(root->left)+ size(root->right)+1;
}
int sum(Node *root){
    if(root == NULL){
        return 0;
    }
    

    return sum(root->left)+ sum(root->right)+root->val;
}

int maxNode(Node *root){
    if(root == NULL){
        return INT_MIN;
    }
    int ln = maxNode(root->left);
    int rn = maxNode(root->right);
    
    

    return max(root->val ,max(ln,rn));
}

int height(Node *root){
    if(root == NULL){
        return 0;
    }
    int ln = height(root->left);
    int rn = height(root->right);
    
    

    return max(ln,rn)+1;
}


// add a node in bst
Node* insert(Node* root, int nodeToAdd) {
    // Your code here
    if(root == NULL){
        Node *nn = new Node(nodeToAdd,NULL,NULL);
        return nn;
    }
   if(root->val < nodeToAdd){
       root->right = insert(root->right,nodeToAdd);
   }
   else if(root->val > nodeToAdd)
        root->left =insert(root->left,nodeToAdd);
    else{
        
    }
    return root;
}

// remove a node in bst
// algo 
// check whether a node has 0 child ,1 child ,2 child
// if 0 child then it is leaf simply remove node 
// if 1 child make child parent 
// if 2 child find max node from left and replace that with that max node 

Node *removeNode(Node *root , int target){
    if(root == NULL){
        return NULL;
    }
    if(root->val > target){
        root->left= removeNode(root->left,target);
    }else if (root->val < target){
        root->right = removeNode(root->right,target);
    }else{
        // child
        if(root->left == NULL && root->right == NULL)
            return NULL;
        // one child
        else if(root->left == NULL){
            return root->right;
        }else if(root->right == NULL){
            return root->left;
        }
        // two child
        else{
            // cout<<"@";
             int tobeReplace = maxNode(root->left);
            root->val = tobeReplace;
            root->left = removeNode(root->left,tobeReplace);
            return root;
            
        }
        
    }
    return root;

}

int main(){
    int n;
    cin>> n;
    vector<int> a(n);
    for(int i =0 ; i < n ; i++){
        string s;
        cin>> s;
        if(s == "n"){
            a[i] = -1;
        }else{
            a[i] = stoi(s);
        }
    }
    int nodeToAdd ;
    cin>> nodeToAdd;
   Node *root = construct(a);
    Node *parent = removeNode(root,nodeToAdd);
    display(root);

    return 0;
}