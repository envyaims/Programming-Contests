def pog(n) :
    j = n - 1
    while(j >= 0) :
        print(j*" ",end="")
        i = 0
        while(i + j < n ):
            if (i&j!=0) :
                print(" ", end = " ")
            else :
                print("/"+"\\", end = "")
            i+=1
        print()
        j-=1
t = int(input())
for i in range(t):
    n = int(input())
    pog(n)
