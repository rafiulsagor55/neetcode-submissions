class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> freq;

        // Frequency count
        for (int num : nums) {
            freq[num]++;
        }

        // Buckets
        vector<vector<int>> bucket(nums.size() + 1);

        for (auto& [num, count] : freq) {
            bucket[count].push_back(num);
        }

        // Get top k
        vector<int> result;

        for (int i = nums.size(); i >= 1; i--) {
            for (int num : bucket[i]) {
                result.push_back(num);

                if (result.size() == k) {
                    return result;
                }
            }
        }

        return result;
    }
};