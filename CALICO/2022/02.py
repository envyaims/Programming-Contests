t = int(input())
for i in range(t):
    s = input().split()
    curr = " ".join(s[3:len(s)-2])
    if curr[:2]=="up":
        print("what's that")
    else:
        print("what's " + curr)
