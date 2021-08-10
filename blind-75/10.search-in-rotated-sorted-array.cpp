class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() == 1)
            return nums[0] == target ? 0 : -1;
        int left = 0, right = nums.size() - 1;
        while(left <= right){
            int mid = right - (right - left)/2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] >= nums[left]){
                if(target >= nums[left] && target <= nums[mid])
                    right = mid - 1;
                else
                    left = mid + 1;
            }// first half is sorted
            else{
                if(target <= nums[right] && target >= nums[mid])
                    left = mid + 1;
                else
                    right = mid - 1;
            }//second half is sorted
        }
        return -1;
    }
};