#include <iostream>
#include <vector>
#include <queue>
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

class levelPair
{
public:
    TreeNode *par = nullptr;
    int lb = -(int)1e8;
    int rb = (int)1e8;

    levelPair()
    {
    }

    levelPair(TreeNode *par, int lb, int rb)
    {
        this->par = par;
        this->lb = lb;
        this->rb = rb;
    }
};

class Pair{
    public:
    TreeNode* node;
    int ll;
    int rl;

    Pair(TreeNode* node,int ll,int rl){
        this->node = node;
        this->ll = ll;
        this->rl = rl;
    }
};

TreeNode *constructBSTFromLevelOrder(vector<int> &arr)
{
    TreeNode* root;
    queue<Pair>q;
    q.push(Pair(NULL,-1e8,1e8));
    int idx=0;
    while(q.size()>0 && idx<arr.size()){
        Pair rem = q.front();
        q.pop();
        
        if(arr[idx]< rem.ll || arr[idx]>rem.rl){
            continue;
        }

        TreeNode* newNode = new TreeNode(arr[idx++]);
        if(rem.node == NULL){
            root = newNode;
        }
        else if(rem.node->val > newNode->val){
            rem.node->left = newNode;
        }
        else if(rem.node->val < newNode->val){
            rem.node->right = newNode;
        }

        q.push(Pair(newNode,rem.ll,newNode->val));
        q.push(Pair(newNode,newNode->val,rem.rl));
    }
    return root;
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

    TreeNode *root = constructBSTFromLevelOrder(pre);
    display(root);
}

int main()
{
    solve();
    return 0;
}
