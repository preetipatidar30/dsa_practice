class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        arr1=[]
        n=len(nums)
        k=k% n
        for i in range(n-k,len(nums)):
            arr1.append(nums[i])
        for i in range(0,n-k):
            arr1.append(nums[i])
        nums[:]=arr1
        