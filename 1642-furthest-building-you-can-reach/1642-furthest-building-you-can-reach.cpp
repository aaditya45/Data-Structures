class Solution {
public:
    int furthestBuilding(vector<int>& h, int bricks, int l) {
        //using greedy
        int res=0;
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=1;i<h.size();i++){
            if(h[i]>h[i-1]){
                pq.push(h[i]-h[i-1]);
                if(l<pq.size()){
                    bricks-=pq.top();
                    //cout<<pq.top()<<endl;
                    pq.pop();
                    if(bricks<0) return i-1;
                }
            }
            
        }
        return h.size()-1;
    }
};