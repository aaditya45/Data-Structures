class Solution:
    def longestSubarray(self, n: List[int]) -> int:
        i,j=0,0
        prev=0
        gmax=0
        while j<len(n):
            if n[j]==0:
                if i==j:
                    gmax=max(gmax,prev)
                    prev=prev
                elif n[i]!=0:
                    gmax=max(gmax,prev+j-i)
                    prev=j-i
                else :
                    gmax=max(gmax,prev+j-i-1)
                    prev=j-i-1
                i=j
            j+=1
        if n[i]==0: gmax=max(gmax,prev+j-i-1)
        else : gmax=max(gmax,prev+j-i-1)
        return gmax