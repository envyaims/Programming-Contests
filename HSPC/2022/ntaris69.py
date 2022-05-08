n,m = map(int,input().split())
lines = []
for i in range(m):
    lines.append(input().split())
for num in range(1<<n):
    check = True
    bits = []
    for i in range(n):
        bits.append((num>>(n-1-i))&1)
    for i in lines:
        stated = bits[ord(i[0])-ord("A")]
        if len(i) == 5 and len(i[-1])==4 and bits[ord(i[2])-ord("A")]!=stated:
            check = False
        if len(i) == 5 and len(i[-1])>4 and bits[ord(i[2])-ord("A")]==stated:
            check = False
        if len(i) == 8 and stated == 0 and bits[ord(i[3])-ord("A")]== 1 and bits[ord(i[5])-ord("A")]==1 and len(i[-1])==4:
            check = False
        if len(i)==8 and stated == 0 and bits[ord(i[3])-ord("A")]== 0and bits[ord(i[5])-ord("A")]==0 and len(i[-1])>4:
            check = False
        case1 = len(i)==8 and stated ==1 and bits[ord(i[3])-ord("A")]==1 and bits[ord(i[5])-ord("A")]==1 and len(i[-1])==4
        case2 = len(i)==8 and stated ==1 and bits[ord(i[3])-ord("A")]==0 and bits[ord(i[5])-ord("A")]==0 and len(i[-1])>4
        if stated == 1 and len(i)==8 and not(case1 or case2):    
            check = False
    if check:
        for i in bits:
            if i:
                print("real")
            else:
                print("mimic")

    
        
        
            
            
            
            




    