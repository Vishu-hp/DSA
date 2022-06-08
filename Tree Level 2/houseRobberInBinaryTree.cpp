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

vector<int>solve(TreeNode* root){
    if(root==NULL){
        vector<int>tmp(2);
        tmp[0]=0;
        tmp[1]=0;
        return tmp;
    }

    vector<int>ans(2);
    vector<int>leftAns = solve(root->left);
    vector<int>rightAns = solve(root->right);

    ans[0] = root->val + leftAns[1]+rightAns[1];
    ans[1] = max(leftAns[0],leftAns[1]) + max(rightAns[0],rightAns[1]);
    return ans;
}

int HouseRobber(TreeNode *root)
{
    vector<int>ans = solve(root);
    return max(ans[0],ans[1]);
}

// input_Section_====================================================================

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
    cout << HouseRobber(root) << endl;
}

int main()
{
    solve();
    return 0;
}
