class Solution {
public:
int find(int v,int parent[]){
  if(parent[v]==v){
    return v;
  }

  int tmp = find(parent[v],parent);
  parent[v] = tmp;
  return tmp;
}

bool union_(int a,int b,int parent[],int size[]){
  a = find(a,parent);
  b= find(b,parent);

  if(a!=b){
    if(size[a]<size[b]){
      int tmp=a;
      a=b;
      b=tmp;
    }
    parent[b] = a;
    size[a] += size[b];
    return true;
  }
  return false;
}
    static bool comp(const vector<int>&a,const vector<int>&b){
        return a[0]>b[0];
    }
    
    int maxNumEdgesToRemove(int n, vector<vector<int>>&edges) {
        sort(edges.begin(),edges.end(),comp);
        int parenta[n+1];
    int sizea[n+1];
    int parentb[n+1];
    int sizeb[n+1];

    for(int i=0;i<n+1;i++){
      parenta[i]=i;
      parentb[i]=i;
      sizea[i]=1;
      sizeb[i]=1;
    }

    int mergeda=1,mergedb=1;
    int rem=0;

    for(auto x:edges){
      if(x[0]==3){
        bool tmpa = union_(x[1],x[2],parenta,sizea);
        bool tmpb = union_(x[1],x[2],parentb,sizeb);

        if(tmpa== true){
          mergeda++;
        }
        if(tmpb == true){
          mergedb++;
        }

        if(tmpa==false && tmpb==false){
          rem++;
        }
      }
      else if(x[0]==1){
        bool tmpa = union_(x[1],x[2],parenta,sizea);
        if(tmpa== true){
          mergeda++;
        }
        if(tmpa==false){
          rem++;
        }
      }
      else if(x[0]==2){
        bool tmpb = union_(x[1],x[2],parentb,sizeb);
        if(tmpb== true){
          mergedb++;
        }
        if(tmpb==false){
          rem++;
        }
      }
    }

    if(mergeda!=n || mergedb!=n){
      return -1;
    }
    return rem;
    }
};
