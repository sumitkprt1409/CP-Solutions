class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        map<int, int> mpp;
        for(int x : nums){
            mpp[x]++;
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        for(auto x : mpp){
            pq.push({x.second, x.first});

            if(pq.size() > k){
                pq.pop();
            }
        }

        vector<int> ans;

        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }


};