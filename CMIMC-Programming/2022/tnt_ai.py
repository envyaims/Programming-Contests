import sys
import json
import random

# INPUT FORMAT (per turn):
'''
    "arena": A 2D (25 x 25) list of integers representing the current
        arena state, 1 for a present tile and 0 for empty.
        Can be indexed via arena[i][j].
    "players": For every player, a dict containing
        "alive": whether they are alive or dead.
        "i", "j": their zero-indexed coordinates.
        The order of the players remains consistent in this list.
    "my_index": Which index into the "players" list you are.
    "grace_moves_left": How many grace moves are remaining (if any),
        i.e. if this is 1, then on your next move, the ground currently
        underneath you does not disappear, but if this is 0 it does.
'''
# OUTPUT FORMAT (per turn):
'''
    "i", "j": Your destination coordinates. Each coordinate can differ by
        at most 2 from your previous coordinates.
'''
# Function for handling output
def output(i, j):
    print(json.dumps({"i": i, "j": j}))

def printerr(x):
    print(x, file=sys.stderr)
# You can store globals outside of the main loop
n = 25

while True:
    # Fetches input from grader (no need to edit)
    _data = json.loads(input())
    arena = _data["arena"]
    players = _data["players"]
    my_index = _data["my_index"]
    grace_moves_left = _data["grace_moves_left"]
    me = players[my_index]
    me_i, me_j = me["i"], me["j"]
    # End input
    
    # if grace_moves_left > 0:
    #     output(me_i,me_j)
    #     continue

    canjumpto = [[1]*25 for i in range(25)]
    for x in range(len(players)):
        if x == my_index:
            continue
        if players[x]["alive"] == True:
            ti = players[x]["i"]
            tj = players[x]["j"]
            arena[ti][tj] = 0
            totaljump = 0
            for i in range(ti-2,ti+3):
                for j in range(tj-2, tj+3):
                    if i < 0 or i >= n or j < 0 or j >= n or arena[i][j] == 0:
                        continue
                    totaljump += 1

            for i in range(ti - 2, ti + 3):
                for j in range(tj - 2, tj + 3):
                    if i < 0 or i >= n or j < 0 or j >= n or arena[i][j] == 0:
                        continue
                    canjumpto[i][j] -= 1/totaljump

    arena[me_i][me_j] = 0
    jpi = me_i
    jpj = me_j

    from collections import deque

    def bfs(sr, sc):
        q = deque()
        visited = [[False]*25 for i in range(25)]
        cnt = 0
        q.append([sr,sc])
        visited[sr][sc] = True
        while len(q) > 0:
            [r,c] = q.popleft()
            for i in range(r-2,r+3):
                for j in range(c-2,c+3):
                    if i < 0 or i >= n or j < 0 or j >= n or arena[i][j] == 0 or visited[i][j]:
                        continue
                    cnt += max(0,canjumpto[i][j])
                    visited[i][j] = True
                    q.append([i,j])
        return cnt


    def dist(r,c,nr,nc):
        return (r-nr)*(r-nr) + (c-nc)*(c-nc)
    maxcomp = -1
    mintocenter = 1e9
    for i in range(me_i-2,me_i+3):
        for j in range(me_j-2,me_j+3):
            if i < 0 or i >= n or j < 0 or j >= n or arena[i][j] == 0:
                continue
            # if canjumpto[i][j] < maxprob:
            #     maxprob = canjumpto[i][j]
            #     jpi = i
            #     jpj = j
            #     maxcmp = bfs(i,j)
            # elif canjumpto[i][j] == maxprob:
            #     cmp = bfs(i,j)
            #     if cmp < maxcomp:
            #         jpi = i
            #         jpj = j
            #         maxcomp = cmp
            cmp = bfs(i,j)
            if cmp > maxcomp or (cmp == maxcomp and dist(i,j,13,13) < mintocenter):
                maxcomp = cmp
                jpi = i
                jpj = j
                mintocenter = dist(i,j,13,13)

                #maxprob = canjumpto[i][j]
            # elif cmp == maxcomp and canjumpto[i][j] < maxprob:
            #     jpi = i
            #     jpj = j
            #     maxprob = canjumpto[i][j]
    #printerr(maxprob)
    output(jpi,jpj)




    
    ## REPLACE STRATEGY BELOW ##
    
    # Sample strategy (random)
    # me = players[my_index]
    # me_i, me_j = me["i"], me["j"]
    # my_history.append((me_i, me_j))
    #
    # new_i, new_j = -1, -1
    # while not (0 <= new_i < size and 0 <= new_j < size):
    #     di, dj = random.randint(-2, 2), random.randint(-2, 2)
    #     new_i, new_j = me_i + di, me_j + dj
    # output(new_i, new_j)
