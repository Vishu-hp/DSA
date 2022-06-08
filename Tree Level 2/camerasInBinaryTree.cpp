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

int cameras=0;

int solve(TreeNode *root){
    if(root==NULL){
        return 1;
    }

    int leftAns = solve(root->left);
    int rightAns = solve(root->right);

    if(leftAns==-1 || rightAns == -1){
        cameras++;
        return 0;
    }

    if(leftAns ==0 || rightAns==0){
        return 1;
    }
    
    return -1;
}

int MinCamerasInBT(TreeNode *root)
{
    if(solve(root)==-1){
        cameras++;
    }   
    return cameras;
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
    cout << MinCamerasInBT(root) << endl;
}

int main()
{
    solve();
    return 0;
}
