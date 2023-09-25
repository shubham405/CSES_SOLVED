import sys
def get_ints(): return map(int, sys.stdin.readline().strip().split())
t = int(input())
while t>0:
    t-=1
    x,y = get_ints()
    r = max(x,y)
    num= r**2-r+1
    diff = max(x,y)-min(x,y)
    if x>y:
         if x%2==1:
        
           print(num-diff)
         else:
           print(num+diff)
    else:
       if y%2==1:
        
            print(num+diff)
        
       else:
        
            print(num-diff)
        
