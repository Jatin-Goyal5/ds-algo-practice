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
class Balance{
    
  public:
  int minval,maxval;
  bool check;
  Balance(int minval,int maxval,bool check){
        this->minval = minval;
        this->maxval = maxval;
        this->check = check;
  }
};
Balance isBinarySearch(Node *root){
    if(root == NULL){
        Balance cc =  Balance(INT_MAX,INT_MIN,true);
        return cc;
    }
    
   
    Balance ls = isBinarySearch(root->left);
    Balance rs =isBinarySearch(root->right);
    bool lcheck =  ls.maxval <= root->val ;
    bool rcheck =  rs.minval >= root->val ;
    bool check = lcheck && rcheck;
    if(ls.check && rs.check && check){
        check = true;
    }else{
        check =false; 
    }
    Balance ne =  Balance(0,0,check);
    ne.minval = min(root->val, min(ls.minval,rs.minval));
    ne.maxval = max(root->val, max(ls.maxval,rs.maxval));
    
    return ne;    
    
    
    // return newRoot;
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
    // diameter = 0;
    Balance rs =isBinarySearch(root);
    if(rs.check)
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;
    // cout<< rs.check;
    return 0;
}