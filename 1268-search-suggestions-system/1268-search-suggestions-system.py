class Solution:
    def suggestedProducts(self, products: List[str], searchWord: str) -> List[List[str]]:
        products.sort()
        res=[]
        for i in range(0,len(searchWord)):
            substr=searchWord[:i+1]
        #    print(substr)
            sublist=[]
            m=0
            high,low=len(products)-1,0
            
            while high>low:
                mid=(high+low)>>1
                if products[mid].startswith(substr) or products[mid]>=substr:
                    high=mid
                else: low=mid+1
            smlist=[]
            #print(products[high],substr)
            for j in range(0,3):
                if high<=len(products)-1 and products[high].startswith(substr):
                    smlist.append(products[high])
                    high+=1
            res.append(smlist)
        return res
        