class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        
        int res=0;
        int a=0,b=0;
        int sum=0;
        unordered_set<int> s;
        for(;b<nums.size();b++){
            
            while(s.find(nums[b])!=s.end()){
                s.erase(nums[a]);
                sum-=nums[a];
                a++;
            }
            s.insert(nums[b]);
            sum+=nums[b];
            res=max(res,sum);
            
        }
        
        return res;
        
        /*int a=0;
        int b=0;
        unordered_map<int,int> mp;
        int lmax=0;
        int gmax=0;
        while(b<nums.size()){
            while(b<nums.size()&&mp[nums[b]]==0){
                lmax+=nums[b];
                mp[nums[b]]=1;
            }
            gmax=max(lmax,gmax);
            while(nums[a]==nums[b]){
                a++;
            }
            a++;
        }
        
        return gmax;
        
        /*unordered_map<int,int> mp;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            
            if(mp[nums[i]]>=1){
                mp[nums[i]]++;
                cout<<mp[nums[i]]<<endl;
            }else{
                mp[nums[i]]=1;
            }
        }
        int gmax=0;
        for(int i=0;i<nums.size();i++){
            int lmax=0;
            while(mp[nums[i]]==1&&i<nums.size()){
                lmax=max(lmax,lmax+nums[i]);
                i++;
            }
            gmax=max(gmax,lmax);
        }
        
        cout<<sum<<endl;
        cout<<gmax<<endl;
        
        return gmax;*/
    }
};