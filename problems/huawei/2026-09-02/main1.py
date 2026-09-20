def main():
    h, w = map(int, input().split())
    map_ = []

    for _ in range(h):
        map_.append(input())

    vallagys = []

    for i in range(h):
        for j in range(w):
            if map_[i][j] == 'V':
                vallagys.append([i, j])

    def dfs(x, y, visited):

        if x == h - 1 or y == w - 1 or x == 0 or y == 0:
            return True

        if map_[x][y] == 'W':
            return False

        if visited[x][y]:
            return False

        visited[x][y] = True

        left = right = up = down = False
        if x - 1 >= 0:
            left = dfs(x - 1, y, visited)

        if x + 1 < w:
            right = dfs(x + 1, y, visited)

        if y - 1 >= 0:
            up = dfs(x, y - 1, visited)

        if y + 1 < h:
            down = dfs(x, y + 1, visited)

        return left or right or up or down

    ans = 0
    for x, y in vallagys:
        visited = [[False] * w for _ in range(h)]
        if dfs(x, y, visited):
            ans += 1

    print(ans)


main()
