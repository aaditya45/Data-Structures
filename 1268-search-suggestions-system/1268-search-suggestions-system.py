class Solution:
    def suggestedProducts(self, products: List[str], searchWord: str) -> List[List[str]]:
        products.sort()
        res=[]
        for i in range(0,len(searchWord)):
            substr=searchWord[:i+1]
            #print(substr)
            sublist=[]
            m=0
            for j in range(0,len(products)):
                if m>=3:
                    break
                elif products[j].startswith(substr):
                    sublist.append(products[j])
                    m+=1
            res.append(sublist)
        return res
        