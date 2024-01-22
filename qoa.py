sentence="Time to write great code"
words=sentence.split()
max1=0
ans=""
for i in words:
    if len(i)%2==0 and len(i)>max1:
        print(i)
        max1=len(i)
        ans=i
if(ans==""):
    ans="00"
print(ans)