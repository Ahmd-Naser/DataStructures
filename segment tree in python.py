class SegmentTree():
    def __init__(self , n):
        self.n = n*4 +5
        self.seg = [0] * self.n

    
    def build (self , p , s ,e , arr ):

        # print(self.n , p , s , e)
        if s == e :
            self.seg[p] = arr[s]
            return

        mid = (s+e)//2

        self.build(p*2 , s , mid , arr)
        self.build(p*2 +1, mid +1 , e , arr)

        self.seg[p] = max(self.seg[p*2] , self.seg[p*2 + 1] )
        


    def update( self ,p , s , e , i , v):
        if s == e :
            self.seg[p] = v
            return

        md = (s+e)//2;

        if i<= md :
            self.update(p*2 , s , md , i , v )

        else :
            self.update(p *2 +1 , md+1 , e , i , v )
        
        self.seg[p] = max(self.seg[p*2] , self.seg[p *2+1] )

    def get_max_leftmost(self, p , s , e , val):
        
        if s == e :
            return -1 if self.seg[p] < val else s
        
        mid = (s+e)//2
        # print( f"p = {p} , s = {s} , e = {e} , seg[p] = {self.seg[p]} ,seg[p*2] = {self.seg[p*2]} , seg[p*2+1] = {self.seg[p*2+1]} , val = {val} ")
        if self.seg[p*2] >= val :
            return self.get_max_leftmost(p*2 , s , mid , val)

        elif self.seg[p*2 +1] >= val :
            return self.get_max_leftmost(p*2 +1, mid+1 , e , val)
        
        return -1
    





class Solution:
    def numOfUnplacedFruits(self, fruits: List[int], baskets: List[int]) -> int:
        n = len(fruits)
        tree = SegmentTree(n)

        tree.build(1 , 0 , n-1 , baskets)

        ans = 0

        for i in range(n) :
            
            idx = tree.get_max_leftmost(1 , 0 , n-1 , fruits[i])

            if idx != -1 :
                tree.update(1 , 0 , n-1 , idx , 0)
                ans +=1
        
            # print(i ,idx ,fruits[i] , baskets[idx] )

        return n-ans


#https://leetcode.com/problems/fruits-into-baskets-iii/?envType=daily-question&envId=2025-08-06