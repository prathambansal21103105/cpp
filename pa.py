t=int(input())
while t>0:
    n=int(input())
    ans=0
    for i in range(n):
        arr=input().split()
        check=arr[1]
        if(check=="yes"):
            k=int(arr[2])
            ans+=1
            ans+=k
    print(ans)
    t-=1