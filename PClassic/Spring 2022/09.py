# curteosy to ntarsis for cheesing this problem

import math

def efficientTrip(mountainList):
    nums = mountainList
    n = len(mountainList)
    for i in range(n):
        for j in range(i+1,n):
            for k in range(j+1,n):
                if abs(nums[i]-nums[j])<=abs(nums[j]-nums[k]):
                    return False
    return True

if __name__ == '__main__':
    tests = int(input())
    for test in range(tests):
        length = int(input())
        line = input().split()
        mountainList = []
        for e in line:
            mountainList.append(int(e))
        res = efficientTrip(mountainList)
        if res:
            print(1)
        else:
            print(0)
