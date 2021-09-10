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
void levelOrder(Node *root){
    queue<Node> q;
    q.push(Node(root->val,root->left,root->right));
    (root);
    while(q.size() > 0){
        int size = q.size();
        for(int i =0 ; i < q.size() ; i++){
            Node cn = q.front();
            q.pop();
            cout<< cn.val<< " ";
            if(cn.left != NULL){
                Node *node = cn.left;
                q.push(Node(node->val,node->left,node->right));
            }
            if(cn.right != NULL){
                Node *node = cn.right;
                q.push(Node(node->val,node->left,node->right));
            }
            cout<< endl;
        }
        
    }
}

void levelOrder2Helper(Node *root , int level){
    if(root == NULL){
        return;
    }
    if(level == 1){
        cout<< root->val<<" ";
    }else{
        levelOrder2Helper(root->left,level-1);
        levelOrder2Helper(root->right,level-1);
    }

}
void levelOrder2(Node *root){
    int h = height(root);
    for(int i =1 ; i <= h ; i++){
        levelOrder2Helper(root,i);
        cout<< endl;
    }
    
}

// k deep down
void kDeepDown(Node *root , int target){
    queue<Node> q;
    q.push(Node(root->val,root->left,root->right));
    int idx=0;
    while(q.size() > 0){
        int size = q.size();
        if(target == idx)
            break;
        for(int i =0 ; i < size ; i++){
            Node cn = q.front();
            q.pop();
            if(cn.left != NULL){
                Node *ln = cn.left;
                q.push(Node(ln->val,ln->left,ln->right));
            }
            if(cn.right != NULL){
                Node *rn = cn.right;
                q.push(Node(rn->val,rn->left,rn->right));
            }
        }
        idx++;
        
    }
    while(q.size()){
        Node ce = q.front();
        q.pop();
        cout<< ce.val<< endl;
    }
    
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
//    cout<< size(root)<< endl;
//     cout<< sum(root)<< endl;
//     cout<< maxNode(root)<< endl;
// cout<< height(root)-1<< endl;
levelOrder2(root);
    return 0;
}