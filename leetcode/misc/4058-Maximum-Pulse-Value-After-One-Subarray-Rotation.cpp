class Solution {
public:

    long long kadane(vector<long long>& nums) {
        long long currentSum = nums[0];
        long long minSum = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            currentSum = min(nums[i], currentSum + nums[i]);
            minSum = min(minSum, currentSum);
        }

        return minSum;
    }

    long long maxValue(vector<int>& nums) {
        int n = nums.size();

        long long sum = 0;

        for (int i = 0; i < n; i++) {
            if (i & 1)
                nums[i] = -nums[i];

            sum += nums[i];
        }

        vector<long long> eve, odd;

        for (int i = 0; i + 1 < n; i += 2) {
            eve.push_back(nums[i] + nums[i + 1]);
        }

        for (int i = 1; i + 1 < n; i += 2) {
            odd.push_back(nums[i] + nums[i + 1]);
        }

        long long ans = 0;

        if (!eve.empty())
            ans = min(ans, kadane(eve));

        if (!odd.empty())
            ans = min(ans, kadane(odd));

        return sum - 2 * ans;
    }
};