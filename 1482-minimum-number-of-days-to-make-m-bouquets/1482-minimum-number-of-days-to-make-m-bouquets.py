class Solution:
    def minDays(self, bloomDay: List[int], m: int, k: int) -> int:
        def slidingWindow(bloomDay,m,k,mid)->bool:
            a=0
            b=0
            cnt=0
            while b<len(bloomDay):
                if bloomDay[b]<=mid:
                    if (b-a)==k-1:
                        cnt+=1
                        b+=1
                        a=b
                    elif (b-a)>k-1:
                        a+=1
                    else:
                        b+=1
                else:
                    b+=1
                    a=b
            if cnt>=m : return True
            else : return False
        
        if len(bloomDay)<m*k: return -1
        
        
        a=0
        b=max(bloomDay)
        res=-1
        while b>=a:
            mid=(a+b)>>1
            if slidingWindow(bloomDay,m,k,mid):
                res=mid
                b=mid-1
            else:
                a=mid+1
        
        return res