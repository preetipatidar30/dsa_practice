class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        n=len(s)
        l=0
        r=0
        if n==0:
            return 0
        dict1={}
        maxs=1
        while l<n and r<n:
            ch=s[r]
            ch1=s[l]
            if dict1.get(ch,0)==0:
                dict1[ch]=dict1.get(ch,0)+1
                a=r-l+1
                maxs=max(maxs,a)
                r+=1
            else :
                dict1[ch1]=dict1.get(ch1,0)-1
                l+=1

            
        return maxs
                

            
        