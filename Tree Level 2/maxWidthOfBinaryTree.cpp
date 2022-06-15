/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */


class Pair{
  public:
  TreeNode* node;
  unsigned long long idx;

  Pair(TreeNode* node,unsigned long long idx){
    this->node=node;
    this->idx=idx;
  }
};

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
          queue<Pair>q;
          q.push(Pair(root,0));
          unsigned long long maxWidth=0;
          while(q.size()>0){
            unsigned long long  lm=q.front().idx;
            unsigned long long rm=q.front().idx;
            int n=q.size();
            // cout<<n<<endl;
            for(int i=0;i<n;i++){
              Pair rem = q.front();
              q.pop();

              TreeNode* tmp=rem.node;
              lm = min(lm,rem.idx);
              rm = max(rm,rem.idx);

              unsigned long long nidx = rem.idx;
              // cout<<tmp->val<<endl;
              if(tmp->left!=NULL){
                q.push(Pair(tmp->left,2*nidx + 1));
              }
              if(tmp->right!=NULL){
                q.push(Pair(tmp->right,2*nidx + 2));
              }
            }
            // cout<<rm<<" "<<lm<<endl;
            maxWidth = max(maxWidth,rm-lm+1);
          }
          return maxWidth;
    }
};
