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

TreeNode* solve(vector<int>&preorder,int s1,int e1,vector<int>&inorder,int s2,int e2){
    if(s1>e1 || s2>e2){
        return NULL;
    }
    TreeNode* root = new TreeNode(preorder[s1]);
    int idx=0;
    for(int i=0;i<inorder.size();i++){
        if(inorder[i]==preorder[s1]){
            idx=i;
            break;
        }
    }
    int totalElem = idx-s2;
    root->left = solve(preorder,s1+1,s1+totalElem,inorder,s2,idx-1);
    root->right = solve(preorder,s1+totalElem+1,e1,inorder,idx+1,e2);
    return root;
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    int n=preorder.size();
    return solve(preorder,0,n-1,inorder,0,n-1);
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
