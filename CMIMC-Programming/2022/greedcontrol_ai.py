# courtesy to daniel qiu

import sys
import json
import random

# INPUT FORMAT (per turn):
'''
    "yesterday": [] on first day, otherwise a 2D list, where each element is
        [c_1, c_2, ..., c_10] for a specific player.
        The order of the players remains consistent in this list.
    "scores": A list of all playersâ€™ current total money made.
        The order of the players here matches that of "yesterday".
    "my_index": Which index into the above lists you are.
'''
# OUTPUT FORMAT (per turn):
'''
    "buys": A list [c_1, c_2, ..., c_10] of how many of each coin
        you would like to purchase, which must be non-negative integers
        summing to at most 100.
'''
# Function for handling output
def output(buys):
    print(json.dumps({"buys": buys}))


# You can store globals outside of the main loop
my_history = []
day = 0

avg = [0]*10;
pavg = [0]*10;
while True:
    # Fetches input from grader (no need to edit)
    _data = json.loads(input())
    yesterday = _data["yesterday"]
    scores = _data["scores"]
    my_index = _data["my_index"]
    # End input

    
    ## REPLACE STRATEGY BELOW ##
    
    # Sample strategy (random)
    if day == 0: assert yesterday == [] # yesterday is empty on first day
    my_score = scores[my_index]
    if day == 29: print("final score", my_score, file = sys.stderr) # example print

    for i in range(len(yesterday)):
        if i==my_index:
            continue;
        for j in range(len(yesterday[i])):
            avg[j]+=yesterday[i][j];# person i bought 0-100 coins of type j

    precomp = [0]*10;
    cur = [0]*10;
    if len(yesterday)>0:
        for i in range(len(yesterday[0])):
            cur[i] = pavg[i]/(day+1);
            precomp[i] = i/(cur[i]+1);
    buys = [0]*10;
    for mon in range(100):
        lind = 0;
        for i in range(len(precomp)):
            precomp[i] = i/(cur[i]+1);
            if precomp[i]>=precomp[lind]:
                lind = i;
        cur[lind]+=1;
        buys[lind]+=1;
    #buys = [0]*10;
    #buys[5] = 30;
    #buys[6] = 30;
    #buys[7] = 40;
    pavg = avg;
    if day<=5:
        buys = [0]*10;
        buys[9] = 30;
        buys[8] = 40;
        buys[7] = 30;
    if day==0 or day==1:
        buys = [0]*10;
        buys[9] = 30;
        buys[8] = 40;
        buys[7] = 30;
    #if day>20 and day<=26:
        #buys = [0]*10;
        #buys[5] = 40;
        #buys[7] = 20;
        #buys[4] = 40;
    my_history.append(buys)
    output(buys)
    day += 1
