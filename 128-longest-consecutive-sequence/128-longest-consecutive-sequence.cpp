class Solution {
public:
    int parent[100001];
    int size[100001];
    
    int find(int x){
        if(parent[x]==x) return x;
        return parent[x]=find(parent[x]);//path compression
    }
    
    void union_set(int x,int y){
        int rootX=find(x);
        int rootY=find(y);
        if(rootX!=rootY){
            parent[rootX]=rootY;
            size[rootY]+=size[rootX];
        }
    }
    
    
    int longestConsecutive(vector<int>& nums) {
        
        for(int i=0;i<nums.size();i++){
            parent[i]=i;
            size[i]=1;
            
        }
        
        unordered_map<int,int> mp;
        
        
        for(int i=0;i<nums.size();i++){
            if(mp[nums[i]]!=0){
                //cout<<nums[i]<<endl;
                continue;
            }
            if(mp[nums[i]+1]!=0){
                //cout<<nums[i]<<endl;
                union_set(i,mp[nums[i]+1]-1);
            }
            if(mp[nums[i]-1]!=0){
                union_set(i,mp[nums[i]-1]-1);
            }
            //cout<<nums[i]<<endl;
            mp[nums[i]]=i+1;
        }
        
        int res=0;
        for(int i=0;i<nums.size();i++){
            if(parent[i]==i){
                res=max(res,size[i]);
            }
        }
        
        return res;
    }
};