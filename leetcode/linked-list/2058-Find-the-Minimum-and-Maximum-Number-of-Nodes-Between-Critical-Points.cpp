/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> arr;
        while(head != nullptr){
            arr.push_back(head->val);
            head = head->next;
        }

        int n = arr.size();
        if(n == 2){
            return {-1, -1};
        }

        vector<int> dist;
        for(int i=1; i<n-1; i++){
            if((arr[i-1] < arr[i]) && (arr[i] > arr[i+1])){
                dist.push_back(i);
            }

            if((arr[i-1] > arr[i]) && (arr[i] < arr[i+1])){
                dist.push_back(i);
            }
        }

        int num = dist.size();
        if(num < 2){
            return {-1, -1};
        }

        int maxi_dist = dist[num-1] - dist[0];
        int mini_dist = INT_MAX;
        for(int i=0; i<num-1; i++){
            mini_dist = min(mini_dist, dist[i+1]-dist[i]);
        }
        
        if(mini_dist == INT_MAX){
            return {-1, -1};
        }
        return {mini_dist, maxi_dist};
    }
};