class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size() < 3) {
            return {};
        }
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() && nums[i] <= 0 ; i++){
            if(i > 0 && nums[i] == nums[i-1])
                continue;
            int low = i + 1;
            int high = nums.size() - 1;
            while(low < high){
                int sum = nums[low] + nums[i] + nums[high];
                if(sum == 0){
                    ans.push_back({nums[low], nums[i], nums[high]});
                    while(low < high && nums[low] == nums[low+1]){
                        low++;
                    }while(low < high && nums[high] == nums[high-1]){
                        high--;
                    }
                    low++;
                    high--;
                }
                else if(sum < 0){
                    low++;
                }else{
                    high--;
                }
            }
        }
        return ans;
    }
};