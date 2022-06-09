#include <iostream>
#include <vector>
#include <climits>

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

int idx=0;

TreeNode* solve(vector<int>&preorder,int ll,int rl){
    if(idx>=preorder.size() || preorder[idx]< ll || preorder[idx]>rl){
        return NULL;
    }

    TreeNode* root = new TreeNode(preorder[idx++]);
    root->left = solve(preorder,ll,root->val);
    root->right = solve(preorder,root->val,rl);
    return root;
}

TreeNode *bstFromPreorder(vector<int> &preorder)
{
    return solve(preorder,-1e8,1e8);
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

    TreeNode *root = bstFromPreorder(pre);
    display(root);
}

int main()
{
    solve();
    return 0;
}
