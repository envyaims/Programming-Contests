def magicSquare(grid):
    for i in range(len(grid)-2):
        for j in range(len(grid[0])-2):
            a = grid[i][j]+grid[i+1][j]+grid[i+2][j]
            b = grid[i][j+1]+grid[i+1][j+1]+grid[i+2][j+1]
            c = grid[i][j+2]+grid[i+1][j+2]+grid[i+2][j+2]
            d = grid[i][j]+grid[i][j+1]+grid[i][j+2]
            e = grid[i+1][j]+grid[i+1][j+1]+grid[i+1][j+2]
            f = grid[i+2][j]+grid[i+2][j+1]+grid[i+2][j+2]
            g = grid[i][j]+grid[i+1][j+1]+grid[i+2][j+2]
            h = grid[i][j+2]+grid[i+1][j+1]+grid[i+2][j]
            if a == b and a == c and a == d and a == e and a == f and a == g and a == h:
                return True
    return False


tests = int(input().strip())
for test in range(tests):
    grid = []
    while True:
        s = input().strip()
        if s == '':
            break
        row = s.split(" ")
        row = list(map(int, row))
        grid.append(row)
    if magicSquare(grid):
        print("true")
    else:
        print("false")
