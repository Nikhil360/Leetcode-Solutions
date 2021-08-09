class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> sumIndexMap;
        for(int i = 0; i < nums.size(); i++){
            if(sumIndexMap.find(target - nums[i]) != sumIndexMap.end()){
                return {sumIndexMap[target - nums[i]], i};
            }
            sumMapIndex[nums[i]] = i;
        }
        return {};
    }
};
