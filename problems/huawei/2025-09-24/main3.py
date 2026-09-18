import heapq


def main():
    M, S_start, S_dest, E = map(int, input().split())

    data: list[list[int]] = []
    networks: list[set[int]] = []

    # data[0] 成本、data[1] 网络中星系数量、星系编号·
    for i in range(M):
        data.append(list(map(int, input().split())))

        networks.append(set(data[i][2:]))

    graph = [[False] * M for _ in range(M)]

    for i in range(M):
        for j in range(i + 1, M):
            set1 = set(data[i][2:])
            set2 = set(data[j][2:])

            inter_ = set1.intersection(set2)
            if len(inter_) != 0:
                graph[i][j] = True
                graph[j][i] = True

    INF = 10**18
    hq: list[tuple[int, int]] = []
    dist = [INF] * M
    pre = [-1] * M

    for i in range(M):
        if S_start in networks[i]:
            dist[i] = data[i][0]
            pre[i] = -1
            heapq.heappush(
                hq,
                (data[i][0], i)
            )

    while hq:
        current_cost, u = heapq.heappop(hq)

        if current_cost != dist[u]:
            continue

        if current_cost > E:
            continue

        for v in range(M):
            if not graph[u][v]:
                continue

            next_cost = current_cost + data[v][0]

            if next_cost < dist[v]:
                dist[v] = next_cost
                pre[v] = u
                heapq.heappush(
                    hq,
                    (next_cost, v)
                )
    ans = INF
    for i in range(M):
        if S_dest in networks[i]:
            if dist[i] < ans:
                ans = dist[i]

    if ans > E or ans == INF:
        print(-1)
    else:
        print(ans)


main()
