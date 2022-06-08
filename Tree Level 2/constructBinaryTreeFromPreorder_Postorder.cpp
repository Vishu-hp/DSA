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

TreeNode* solve(vector<int>&pre,int s1,int e1,
vector<int>&post,int s2,int e2){
    if(s1>e1 || s2>e2){
        return NULL;
    }

    TreeNode* root = new TreeNode(pre[s1]);
    if(s1==e1){
        return root;
    }
    int findElem = pre[s1+1];
    int idx;
    for(int i=0;i<post.size();i++){
        if(findElem == post[i]){
            idx=i;
            break;
        }
    }
    int tE = idx-s2+1;
    root->left = solve(pre,s1+1,s1+tE,post,s2,idx);
    root->right = solve(pre,s1+tE+1,e1,post,idx+1,e2-1);
    return root;
}
TreeNode *constructFromPrePost(vector<int> &pre, vector<int> &post)
{
    return solve(pre,0,pre.size()-1,post,0,post.size()-1);
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
