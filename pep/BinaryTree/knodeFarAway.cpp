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

vector<Node*> nodeToRoot(Node *root , int target){
    if(root == NULL){
        return vector<Node*> ();
    }
    if(root->val == target){
        vector<Node*> res;
        res.push_back(root);
        return res;
    }
    vector<Node*> ln = nodeToRoot(root->left,target);
    if(ln.size()){
        ln.push_back(root);
        return ln;
    }
    vector<Node*> rn = nodeToRoot(root->right,target);
    if(rn.size()){
        rn.push_back(root);
        return rn;
    }
    return vector<Node*>();
    
}
// Node* findNode(Node *root , int data){
//     if(root == NULL){
//         return NULL;
//     }
//     if(root->val == data){
//         return root;
//     }
//     if(root->left!= NULL)
//         return findNode(root->left,data);
//     if(root->right!= NULL)
//     return findNode(root->right,data);
// }

void kdistanceAway(Node *root , int k, Node *block){
    if(k < 0 || root == NULL || root == block){
        return;
    }
    if(k == 0){
        cout<< root->val<< endl;
    }
    
        kdistanceAway(root->left ,k-1,block);
        kdistanceAway(root->right ,k-1 ,block);    
    
    
    
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
    int data;
    cin>> data;
    int k;
    cin>> k;
   Node *root = construct(a);
   vector<Node*> s = nodeToRoot(root,data);
   for(int i =0 ; i < s.size() ; i++){
       Node *block = i > 0 ? s[i-1]:NULL;
        kdistanceAway(s[i],k-i,block);    
   }
  
   

    return 0;
}