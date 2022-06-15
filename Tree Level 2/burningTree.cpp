#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class TreeNode
{
public:
  int val = 0;
  TreeNode* left = nullptr;
  TreeNode* right = nullptr;

  TreeNode(int val)
  {
    this->val = val;
  }
};

bool nodeToRoot(TreeNode* root,int tar,vector<TreeNode*>&path){
    if(root==NULL){
      return false;
    }

    if(root->val==tar){
      path.push_back(root);
      return true;
    }


    bool left = nodeToRoot(root->left,tar,path);
    if(left){
      path.push_back(root);
      return true;
    }

    bool right = nodeToRoot(root->right,tar,path);
    if(right){
      path.push_back(root);
      return true;
    }
}

void burnTree(TreeNode* node,int &tmpAns,int t,TreeNode* block){
  if(node==NULL || node==block){
    return;
  }

  tmpAns = max(tmpAns,t);

  burnTree(node->left,tmpAns,t+1,block);
  burnTree(node->right,tmpAns,t+1,block);
}

int burningTree(TreeNode* root, int fireNode)
{
  vector<TreeNode*>path; 
  nodeToRoot(root,fireNode,path);
  int ans=0;
  for(int i=0;i<path.size();i++){
    int tmpAns=0;
    burnTree(path[i],tmpAns,i,(i==0)?NULL:path[i-1]);
    ans=max(ans,tmpAns);
  }
  return ans;
}

// input_section=================================================

TreeNode* createTree(vector<int>& arr, vector<int>& IDX)
{

  if (IDX[0] > arr.size() || arr[IDX[0]] == -1)
  {
    IDX[0]++;
    return nullptr;
  }

  TreeNode* node = new TreeNode(arr[IDX[0]++]);
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
  TreeNode* root = createTree(arr, IDX);

  int fireNode;
  cin >> fireNode;
  int ans = burningTree(root, fireNode);
  cout << ans << endl;
}

int main()
{
  solve();
  return 0;
}
