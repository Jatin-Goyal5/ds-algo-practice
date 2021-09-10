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
Node* removeLeaf(Node *root){
    if(root == NULL){
        return NULL;
    }
    if(root->left ==NULL && root->right == NULL){
        return NULL;
    }
    Node *newRoot=root;
    Node *ln = removeLeaf(root->left);
    Node *rn =removeLeaf(root->right);
    
    newRoot->left = ln;
    newRoot->right = rn;
    
    return newRoot;
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
   Node *root = construct(a);
    
    Node *newRoot = removeLeaf(root);
    display(newRoot);
    return 0;
}