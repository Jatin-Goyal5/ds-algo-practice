// build a tree using preorder and inorder traversal
#include<bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val = 0;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;

    TreeNode(int val)
    {
        this->val = val;
    }
};

TreeNode *buildTree(vector<int> &preorder, int pst , int ped ,vector<int> &inorder,int ist ,int ied){
    if(pst >ped || ist > ied ){
        return NULL;
    }
    
    TreeNode *node = new TreeNode(preorder[pst]);
    int cs = ist;
    
    while(preorder[pst] != inorder[cs]){            /// this loop can be improved by using map of inorder index Vs element
        cs++;
    }

    
    int count = cs -ist;
    node->left = buildTree(preorder,pst+1 ,pst+count, inorder,ist ,cs-1); // left subtree
    
    node->right = buildTree(preorder,pst+count+1 ,ped , inorder , cs+1 , ied);
    return node;
}


TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    int n = preorder.size();
    return buildTree(preorder,0 ,n-1 , inorder,0 ,n-1);
    // return nullptr;
}

// input_Section_====================================================================

void display(TreeNode *node)
{
    if (node == nullptr)
        return;

    string str = "";
    str += ((node->left != nullptr ? to_string(node->left->val) : "."));
    str += (" -> " + to_string(node->val) + " <- ");
    str += ((node->right != nullptr ? to_string(node->right->val) : "."));

    cout << str << endl;

    display(node->left);
    display(node->right);
}

void solve()
{
    int n;
    cin >> n;
    vector<int> pre(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> pre[i];
    }

    vector<int> in(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> in[i];
    }

    TreeNode *root = buildTree(pre, in);
    display(root);
}

int main()
{
    solve();
    return 0;
}