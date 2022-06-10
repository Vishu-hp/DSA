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

class Pair{
    public:
    int maxLen;
    int forwardSlope;
    int backwardSlope;
};

Pair solve(TreeNode* root){
    if(root==NULL){
        Pair tmpAns;
        tmpAns.maxLen=-1;
        tmpAns.forwardSlope = -1;
        tmpAns.backwardSlope = -1;

        return tmpAns;
    }

    Pair ans;
    Pair leftAns = solve(root->left);
    Pair rightAns = solve(root->right);

    ans.maxLen = max(max(leftAns.maxLen,rightAns.maxLen),max(leftAns.backwardSlope,rightAns.forwardSlope)+1);
    ans.forwardSlope = leftAns.backwardSlope+1;
    ans.backwardSlope = rightAns.forwardSlope+1;
    return ans; 
}

int longestZigZagPath(TreeNode *root)
{
    Pair ans = solve(root);
    return ans.maxLen;
}

// input_Section_====================================================================

TreeNode *createTree(vector<int> &arr, vector<int> &IDX)
{
    if (IDX[0] > arr.size() || arr[IDX[0]] == -1){
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

    cout << longestZigZagPath(root) << endl;
}

int main()
{
    solve();
    return 0;
}
