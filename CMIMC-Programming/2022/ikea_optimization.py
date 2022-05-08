import sys
import json
import random

# INPUT FORMAT (initial, ONLY HAPPENS ONCE):
'''
    "layout": A 2D (64x64) list of 0, 1, or 2, describing the grid layout,
        where 0 is a floor, 1 is a wall, and 2 is the target destination.
        Can be indexed via layout[i][j].
'''
# INPUT FORMAT (per turn):
'''
    "view": A 2D (3x3) list of 0, 1, or 2, describing the area immediately
        around the robot, oriented in the direction the robot is facing.
        Can be indexed via view[i][j].
'''
# OUTPUT FORMAT (per turn):
'''
    "move": one of "forward", "backward", "left", "right", "apparate"
'''


# Function for handling output
def output(move):
    # printerr(move)
    print(json.dumps({"move": move}))


def printerr(x):
    print(x, file=sys.stderr)


# You can store globals outside of the main loop
commands = ("forward", "left", "right", "backward", "apparate")
revcommands = ("backward", "right", "left", "forward", "apparate")
n = 64

# Fetches input from grader (no need to edit)
_data = json.loads(input())
grid = _data["layout"]  # a 64 x 64 grid

def getend():
    for i in range(n):
        for j in range(n):
            if grid[i][j] == 2:
                return [i,j]
[endr, endc] = getend()
printerr([endr,endc])
# -----------------------------SOLUTION STARTS HERE---------------------------#
import timeit


# first simulate all the possible views and map them to indexes

upr = [1, 1, 1, 0, -1, -1, -1, 0]
upc = [-1, 0, 1, 1, 1, 0, -1, -1]

leftr = [-1, 0, 1, 1, 1, 0, -1, -1]
leftc = [-1, -1, -1, 0, 1, 1, 1, 0]

rightr = [1, 0, -1, -1, -1, 0, 1, 1]
rightc = [1, 1, 1, 0, -1, -1, -1, 0]

downr = [-1, -1, -1, 0, 1, 1, 1, 0]
downc = [1, 0, -1, -1, -1, 0, 1, 1]

dirx = [leftr, upr, rightr, downr]
diry = [leftc, upc, rightc, downc]

dx = [-1, 0, 0, 1]
dy = [0, -1, 1, 0]

viewr = [0, 1, 1, 2]  # view oriented
viewc = [1, 0, 2, 1]

dirlabel = ['U', 'L', 'R', 'D']
opplabel = ['D', 'R', 'L', 'U']


def inputmove():
    _data = json.loads(input())
    view = _data["view"]  # a 3 x 3 grid
    newview = []
    for i in range(8):
        newview.append(view[1 + upr[i]][1 + upc[i]])
    # [packed, unpacked]
    return [newview,view]


posview = {}
# 0 = upright, 1 = to the left, 2 = to the right, 3 = looking down
def getorientations():
    for i in range(1, n - 1):
        for j in range(1, n - 1):
            res = [[] for i in range(4)]
            for k in range(4):
                for l in range(8):
                    res[k].append(grid[i + dirx[k][l]][j + diry[k][l]])
            posview[(i, j)] = res

getorientations()


# if you dont know where you are and you just want to move
def randommove(view):
    for i in range(4):
        if view[viewr[i]][viewc[i]] != 1:
            return i
    assert(False)
    return -1

dirfacing = {"forward":0,"left": -1 ,"right":1,"backward":2}
def updfacing(facing,x):
    # 1 = up, 0 = left, 2 = right, 3 = down
    facing += dirfacing[x]
    if facing < 0:
        facing += 4
    return facing % 4

# figure out where the fuck we are
def where(candidates):
    [res,view] = inputmove()

    if len(candidates) == 0:
        for k, v in posview.items():
            r = k[0]
            c = k[1]
            if grid[r][c] != 1:
                for x in v:
                    if x == res:
                        candidates.append([r, c])
                        break

    for i in range(20):
        do = randommove(view)
        output(commands[do])

        [res,view] = inputmove()
        newcandidates = []
        for i in candidates:
            r = i[0]
            c = i[1]
            for j in range(4):
                nr = r + dx[j]
                nc = c + dy[j]
                if nr == 0 or nr == n-1 or nc == 0 or nc == n-1:
                    continue
                if res in posview[(nr,nc)]:
                    newcandidates.append((nr, nc))

        candidates = list(set(newcandidates))
        if len(candidates) == 1:
            break
    assert(len(candidates) > 0)
    if len(candidates) == 1:
        return [candidates[0][0], candidates[0][1], view]
    else:
        printerr(candidates)
        x = random.randint(0,len(candidates)-1)
        return [candidates[x][0],candidates[x][1],view]


[currow, curcol, curview] = where([])
#printerr([currow,curcol])

fcr = [0,-1,0,1]
fcc = [-1,0,1,0]
def getfacing(row, col, view):
    maxmoves = 10
    orientations = []
    res = []
    for bruh in range(maxmoves):
        do = randommove(view)
        output(commands[do])
        [res, view] = inputmove()
        orientations.append([commands[do],res])

    ret = []
    for face in range(0,4):
        r,c = row,col
        ok = True
        facing = face
        for x in orientations:
            facing = updfacing(facing,x[0])
            r += fcr[facing]
            c += fcc[facing]
            if x[1] not in posview[(r,c)]:
                ok = False
                break
        if ok is True:
            ret.append([r,c,facing])
    assert(len(ret) == 1)
    return ret[0]

from collections import deque

def bfs(sr, sc):
    q = deque()
    q.append([sr, sc])
    start = timeit.timeit()
    dist = [[1e9] * 64 for i in range(64)]
    end = timeit.timeit()
    printerr(end - start)
    dist[sr][sc] = 0
    while len(q) > 0:
        cur = q.popleft()
        r = cur[0]
        c = cur[1]
        for i in range(4):
            nr = dx[i] + r
            nc = dy[i] + c
            if nr == 0 or nr == n - 1 or nc == 0 or nc == n - 1:
                continue
            if dist[nr][nc] == 1e9:
                dist[nr][nc] = dist[r][c] + 1
                q.append([nr, nc])
    return dist

#printerr(dist)

# always move in the distance where it is closest to the end
def optimalmove(r, c, dist, visited):
    mindist = dist[r][c]
    mover = -1
    movec = -1
    diridx = -1
    for i in range(4):
        nr = r + dx[i]
        nc = c + dy[i]
        if nr == 0 or nr >= n-1 or nc == 0 or nc >= n-1:
            continue
        if dist[nr][nc] < mindist and grid[nr][nc] != 1 and visited[nr][nc] == 0:
            mover = nr
            movec = nc
            diridx = i
            mindist = dist[nr][nc]
    # diridx mapping: 0 = up, 1 = left, 2 = right, 3 = down
    if diridx == -1:
        # we are in a corner
        minvis = 1e9
        for i in range(4):
            nr = r + dx[i]
            nc = c + dy[i]
            if nr == 0 or nr >= n - 1 or nc == 0 or nc >= n - 1:
                continue
            if grid[nr][nc] != 1 and visited[nr][nc] < minvis:
                mover = nr
                movec = nc
                diridx = i
                minvis = visited[nr][nc]
    assert(diridx != -1)
    #printerr(mindist)
    return [mover, movec, diridx]

# face mapping: 1 = up, 0 = left, 2 = right, 3 = down

def samecomp(row, col, face, endx, endy,dist):
    visited = [[0]*n for i in range(n)]
    while row != endx or col != endy:
        visited[row][col] += 1
        [newrow, newcol, direction] = optimalmove(row,col,dist, visited)
        if newrow == row-1:
            # you need to go up
            if face == 1:
                output("forward")
            elif face == 0:
                output("right")
            elif face == 2:
                output("left")
            else:
                output("backward")

            face = 1
        elif newcol == col-1:
            # you need to go left
            if face == 1:
                output("left")
            elif face == 0:
                output("forward")
            elif face == 2:
                output("backward")
            else:
                output("right")

            face = 0
        elif newcol == col+1:
            # you need to go right
            if face == 1:
                output("right")
            elif face == 0:
                output("backward")
            elif face == 2:
                output("forward")
            else:
                output("left")

            face = 2
        elif newrow == row+1:
            # you need to go down
            if face == 1:
                output("backward")
            elif face == 0:
                output("left")
            elif face == 2:
                output("right")
            else:
                output("forward")
            face = 3
        [res,view] = inputmove()
        #printerr([row, col,newrow,newcol,res])
        row = newrow
        col = newcol
    printerr([row,col,endx,endy])

#samecomp(currow,curcol,curface)


# DSU teleport thing bruh
class DSU:
    def __init__(self, size: int) -> None:
        self.parents = [-1 for _ in range(size)]
        self.sizes = [1 for _ in range(size)]

    def get(self, x: int) -> int:
        if self.parents[x] == -1:
            return x
        self.parents[x] = self.get(self.parents[x])
        return self.parents[x]

    def unite(self, x: int, y: int) -> bool:
        x_root = self.get(x)
        y_root = self.get(y)
        if x_root == y_root:
            return False

        if self.sizes[x_root] < self.sizes[y_root]:
            x_root, y_root = y_root, x_root
        self.parents[y_root] = x_root
        self.sizes[x_root] += self.sizes[y_root]
        return True

    def connected(self, x: int, y: int) -> bool:
        return self.get(x) == self.get(y)

dsu = DSU(n*n+n+1)

def hash(r,c):
    return r * n + c



def initdsu():
    for i in range(n-1):
        for j in range(n-1):
            if grid[i][j] != 1:
                if grid[i+1][j] != 1:
                    dsu.unite(hash(i, j), hash(i + 1, j))
                if grid[i][j+1] != 1:
                    dsu.unite(hash(i,j),hash(i,j+1))
                if grid[i-1][j] != 1:
                    dsu.unite(hash(i,j),hash(i-1,j))
                if grid[i][j-1] != 1:
                    dsu.unite(hash(i, j), hash(i, j - 1))

initdsu()

def hash_orientation(x):
    curhash = 0
    for i in range(8):
        if x[i] == 1:
            curhash += (1 << i)
    return curhash

canteleport = [[] for i in range(1<<8)]
# binary hashed
def getteleport():
    for k, v in posview.items():
        r, c = k[0], k[1]
        if grid[r][c] == 1:
            continue
        for x in v:
            curhash = hash_orientation(x)
            if curhash > 0:
                canteleport[curhash].append([r,c])

getteleport()

# keep randomly teleport until you end up in the same component as target

def randomteleport(row, col, view):
    visited = [False for i in range(n*n+n+1)]
    endcomponent = dsu.get(hash(endr,endc))
    currcomponent = dsu.get(hash(row,col))
    res = []
    visited[currcomponent] = True

    printerr(endcomponent)

    while currcomponent != endcomponent:
        # try to randomly move for a while so it wouldnt get stuck in a loop
        # try to optimize this with a finding
        # for i in range(3):
        #     do = randommove(view)
        #     output(commands[do])
        #     [res, view] = inputmove()

        # while True:
        #     can = False
        #     for x in canteleport[hash_orientation(res)]:
        #         if not visited[dsu.get(hash(x[0],x[1]))]:
        #             can = True
        #             break
        #     if not can or 1 not in res:
        #         do = randommove(view)
        #         output(commands[do])
        #         printerr([res])
        #     else:
        #         break

        output("apparate")
        [row,col,view] = where([])
        currcomponent = dsu.get(hash(row,col))
        visited[currcomponent] = True
    assert(currcomponent == endcomponent)
    printerr(currcomponent)
    printerr(['init',row,col])
    # now they are in the same component we can bfs it
    dist = bfs(endr,endc)
    [row,col,face] = getfacing(row,col,view)
    #printerr(['face',face])
    samecomp(row,col,face,endr,endc,dist)
   # printerr(where([]))


randomteleport(currow,curcol,curview)
