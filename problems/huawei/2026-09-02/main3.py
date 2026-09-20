import heapq


def main():
    c, d, t = map(int, input().split())

    graph = [[] for _ in range(c)]
    cost = [[0] * c for _ in range(c)]

    for _ in range(d):
        x, y, b = map(int, input().split())
        graph[x].append(y)
        graph[y].append(x)
        cost[x][y] = cost[y][x] = b

    INF = 10**18

    # dist[u][k] 代表到达 u 时且提升次数为 k 时的最小带宽
    dist = [[-1] * (t + 1) for _ in range(c)]

    dist[0][0] = INF

    hq = [(-INF, 0, 0)]

    while hq:
        bandwidth, u, k = heapq.heappop(hq)

        bandwidth = -bandwidth

        if bandwidth != dist[u][k]:
            continue

        for v in graph[u]:
            new_bandwith = min(bandwidth, cost[u][v])

            if new_bandwith > dist[v][k + 1]:
                dist[v][k] = new_bandwith
                heapq.heappush(hq, (-new_bandwith, v, k))

            if k < t:
                new_bandwith = min(bandwidth, 2 * cost[u][v])
                if new_bandwith > dist[v][k]:
                    dist[v][k + 1] = new_bandwith
                    heapq.heappush(hq, (-new_bandwith, v, k + 1))
    ans = dist[c - 1][t]

    if ans == -1:
        print(-1)
    else:
        print(ans)


main()
