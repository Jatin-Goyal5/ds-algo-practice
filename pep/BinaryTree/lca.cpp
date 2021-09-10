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


vector<int> find(Node *root, int target){
    if(root == NULL){
        vector<int> res;
        return res;
    }
    if(root->val == target){
        vector<int> ans;
        ans.push_back(root->val);
        return ans;
    }
    vector<int> la;
    if(root->val > target){
        la= find(root->left,target);
        
    }else{
        la = find(root->right,target);    
    }
    
    if(la.size()){
        la.push_back(root->val);
    }
    return la;    
    
}
int minNode(Node *root){
    if(root == NULL){
        return INT_MAX;
    }
    int ln = minNode(root->left);
    int rn = minNode(root->right);
    
    

    return min(root->val ,min(ln,rn));
}

int height(Node *root){
    if(root == NULL){
        return 0;
    }
    int ln = height(root->left);
    int rn = height(root->right);
    
    

    return max(ln,rn)+1;
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
    int target1,target2;
    cin>> target1>> target2;
   Node *root = construct(a);
    vector<int> path = find(root,target1);
    vector<int> path2 = find(root,target2);
    int i =path.size()-1;
    int j = path2.size()-1;
    while( i >= 0 && j >= 0 && path[i] == path2[j]){
        // cout<< path[i]<<path2[j]
        i--;
        j--;
    }
    cout<< path[i+1];
// levelOrder2(root);
    return 0;
}