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
 TreeNode* constructFromPrePost(vector<int>& pre,int prs , int pe ,vector<int>& post , int pos , int poe) {
        if(prs > pe || pos > poe){
            return NULL;
        }
        
        if(prs== pe){
            return new TreeNode(pre[prs]);
        }
        TreeNode* node = new TreeNode(pre[prs]);
        int c = pos;
        while(pre[prs+1] != post[c]){
            c++;
        }
        
        int count = c-pos+1;
        
        node->left = constructFromPrePost(pre,prs+1 ,prs+count , post , pos,c);
        node->right = constructFromPrePost(pre,prs+count+1 ,pe , post , c+1,poe-1);
        return node;
        
        
    }
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        int n = pre.size();
        return constructFromPrePost(pre, 0, n-1 , post ,0 ,n-1);
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

    vector<int> pre(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> pre[i];
    }

    TreeNode *root = constructFromPrePost(pre, post);
    display(root);
}

int main()
{
    solve();
    return 0;
}
