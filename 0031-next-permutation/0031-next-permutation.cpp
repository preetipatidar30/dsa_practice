class Solution {
public:
    void nextPermutation(vector<int>& nums) {
       int n=nums.size();
       int index=-1;

   for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                index = i;
                break;
            }
        }

        // Step 2: If no such index exists, reverse the entire array
        if (index == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // Step 3: Find the smallest element in nums[index+1...n-1] that is greater than nums[index]
        for (int i = n - 1; i > index; i--) {
            if (nums[i] > nums[index]) {
                swap(nums[index], nums[i]);
                break;
            }
        }
        reverse(nums.begin() + index + 1, nums.end());


}
};