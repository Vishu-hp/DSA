#include <iostream>
#include <vector>
#include <queue>
#include<climits>
#include <unordered_map>
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
    TreeNode* node;
    int l;

    Pair(TreeNode* node,int l){
        this->node=node;
        this->l=l;
    }
};

vector<vector<int>> verticalOrderTraversal(TreeNode *root)
{
    unordered_map<int,vector<int>>ump;
    vector<vector<int>>ans;
    int minL=INT_MAX;
    int maxL=INT_MIN;
    queue<Pair>q;
    q.push(Pair(root,0));
    while(q.size()>0){
        Pair rem = q.front();
        q.pop();

        minL = min(minL,rem.l);
        maxL = max(maxL,rem.l);
        ump[rem.l].push_back(rem.node->val);
        TreeNode* tmp=rem.node;
        if(tmp->left!=NULL){
            q.push(Pair(tmp->left,rem.l-1));
        }
        if(tmp->right!=NULL){
            q.push(Pair(tmp->right,rem.l+1));
        }
    }
    
    while(minL<=maxL){
        ans.push_back(ump[minL]);
        minL++;
    }
    return ans;
}

// input_section=================================================

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

    vector<vector<int>> ans = verticalOrderTraversal(root);
    int idx = 0;
    for (vector<int> &i : ans)
    {
        cout << idx++ << " -> ";
        for (int j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

int main()
{
    solve();
    return 0;
}
