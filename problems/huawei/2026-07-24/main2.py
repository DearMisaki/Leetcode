n, p, T = map(int, input().split())

layer_time = list(map(int, input().split()))

comm = None

if n > 1:
    comm_tmp = list(map(int, input().split()))
    comm = [0] * (n + 1)
    comm[1:] = comm_tmp
else:
    exit(0)


INF = 10**18

dp: list[list[int]] = [[INF] * (n + 1) for _ in range(p + 1)]

dp[0][0] = 0

for seg_index in range(1, p + 1):
    for layer_index in range(seg_index, n + 1):
        for j in range(seg_index - 1, layer_index):
            if dp[seg_index - 1][j] == INF:
                continue

            if sum(i for i in layer_time[j: layer_index]) > T:
                continue

            dp[seg_index][layer_index] = min(
                dp[seg_index][layer_index],
                dp[seg_index - 1][j] + comm[j]
            )

if dp[p][n] == INF:
    print(-1)
else:
    print(dp[p][n])
