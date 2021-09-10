#include <iostream>
#include <vector>
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

 TreeNode* buildTree(vector<int>& inorder,int ist ,int ied ,vector<int>& postorder , int pst , int ped) {
        
        if(ist > ied || pst > ped){
            return NULL;
        }
        
        TreeNode* node = new TreeNode(postorder[ped]);
        
        int c = ist;
        while(inorder[c] != postorder[ped]){
            c++;
        }
        int count = c-ist;
        node->left = buildTree(inorder , ist, c-1, postorder, pst,pst+count-1);
        node->right = buildTree(inorder , c+1,ied,postorder , pst+count ,ped-1);
        return node;
        
    }

TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
{int n = inorder.size();
        return buildTree(inorder,0,n-1,postorder ,0,n-1);
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
    vector<int> post(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> post[i];
    }

    vector<int> in(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> in[i];
    }

    TreeNode *root = buildTree(in, post);
    display(root);
}

int main()
{
    solve();
    return 0;
}