class Solution:
    def minDays(self, bloomDay: List[int], m: int, k: int) -> int:
        if len(bloomDay)<m*k: return -1
        a=0
        b=max(bloomDay)
        res=-1
        while b>=a:
            mid=(a+b)>>1
            x,y,cnt=0,0,0
            
            while y<len(bloomDay):
                if bloomDay[y]<=mid:
                    if (y-x)==k-1:
                        cnt+=1
                        y+=1
                        x=y
                    elif (y-x)>k-1:
                        x+=1
                    else:
                        y+=1
                else:
                    y+=1
                    x=y
            
            if cnt>=m:
                res=mid
                b=mid-1
            else:
                a=mid+1
        
        return res