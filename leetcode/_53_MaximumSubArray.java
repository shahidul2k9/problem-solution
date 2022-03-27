
class _53_MaximumSubArray {
    public int maxSubArray(int[] nums) {
        int localMax, globalMax;
        localMax = globalMax = nums[0];
        for (int i = 1; i < nums.length;i++){
            localMax = Math.max(nums[i], localMax + nums[i]);
            globalMax = Math.max(globalMax, localMax);
        }
        return globalMax;
    }
}