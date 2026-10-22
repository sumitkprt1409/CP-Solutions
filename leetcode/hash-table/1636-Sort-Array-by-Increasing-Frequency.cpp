class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        map<int, int> mpp;

        for (int x : nums) {
            mpp[x]++;
        }

        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;

        for (auto x : mpp) {
            pq.push({x.second, -x.first});
        }

        vector<int> ans;

        while (!pq.empty()) {
            int freq = pq.top().first;
            int val = -pq.top().second;
            pq.pop();

            for (int i = 0; i < freq; i++) {
                ans.push_back(val);
            }
        }

        return ans;
    }
};