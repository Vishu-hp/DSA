#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
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

class Pair{
    public:
    TreeNode* node;
    int l;

    Pair(TreeNode* node,int l){
        this->node = node;
        this->l = l;
    }
};

vector<int> TopView(TreeNode *root)
{
    vector<int>ans;
    if(root==NULL){
        return ans;
    }
    unordered_map<int,vector<int>>vOT;
    int minL=INT_MAX;
    int maxL=INT_MIN;

    queue<Pair>q;
    q.push(Pair(root,0));
    while(q.size()>0){
        Pair rem = q.front();
        q.pop();

        minL=min(minL,rem.l);
        maxL=max(maxL,rem.l);

        vOT[rem.l].push_back(rem.node->val);

        TreeNode* tmp=rem.node;
        if(tmp->left!=NULL){
            q.push(Pair(tmp->left,rem.l-1));
        }
        if(tmp->right!=NULL){
            q.push(Pair(tmp->right,rem.l+1));
        }
    }

    while(minL<=maxL){
        vector<int>v = vOT[minL];
        ans.push_back(v[0]);
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

    vector<int> ans = TopView(root);

    for (int i : ans)
    {
        cout << i << " ";
    }
}

int main()
{
    solve();
    return 0;
}
