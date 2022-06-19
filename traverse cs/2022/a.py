n = int(input())
words = []
for i in range(n):
    s = input()
    words.append(s)
ans = []
for i in range(0,n,2):
    if words[i]<words[i+1]:
        ans.append(words[i]+"-"+words[i+1])
    else:
        ans.append(words[i+1]+"-"+words[i])
ans.reverse()
print(*ans)
