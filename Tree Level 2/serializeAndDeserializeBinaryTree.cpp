#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
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

// Encodes a tree to a single string.
void solve(TreeNode* root,string &ans){
    if(root==NULL){
        ans += "* ";
        return;
    }

    ans += to_string(root->val) +" ";
    solve(root->left,ans);
    solve(root->right,ans);
}

string serialize(TreeNode *root)
{
    string ans="";
    solve(root,ans);
    return ans;
}

// Decodes your encoded data to tree.
int idx=0;
TreeNode* construct(vector<string>&preorder){
    if(idx == preorder.size() || preorder[idx]=="*"){
        idx++;
        return NULL;
    }
    int val = stoi(preorder[idx]);
    idx++;
    TreeNode* root = new TreeNode(val);
    root->left = construct(preorder);
    root->right = construct(preorder);
    return root;
}
TreeNode *deserialize(string s)
{
    vector<string>preorder;
    stringstream ss(s);
    string word;
    while(ss >> word){
        preorder.push_back(word);
    }
    return construct(preorder);
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

TreeNode *createTree(vector<int> &arr, vector<int> &IDX)
{

    if (IDX[0] > arr.size() || arr[IDX[0]] == -1)
    {
        IDX[0]++;
        return nullptr;
    }

    TreeNode *node = new TreeNode(arr[IDX[0]++]);
    node->left = createTree(arr, IDX);
    node->right = createTree(arr, IDX);

    return node;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<int> IDX(1, 0);
    TreeNode *root = createTree(arr, IDX);

    string s = serialize(root);
    display(deserialize(s));
}

int main()
{
    solve();
    return 0;
}
