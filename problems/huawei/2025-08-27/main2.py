
def main():
    n, m = map(int, input().split())
    sequence = list(map(int, input().split()))

    prefix = [0] * (n + 1)

    for i in range(1, n + 1):
        prefix[i] = prefix[i - 1] + sequence[i - 1]

    INF = 10**18

    dp: list[list[int]] = [[INF] * (n + 1) for _ in range(m + 1)]
    dp[0][0] = 0

    pre: list[list[int]] = [[0] * (n + 1) for _ in range(m + 1)]

    for k in range(1, m + 1):
        for i in range(k, n + 1):
            for j in range(k - 1, i):
                if dp[k - 1][j] == INF:
                    continue

                cost = dp[k - 1][j] + (prefix[i] - prefix[j]) ** 2

                if cost < dp[k][i]:
                    dp[k][i] = cost
                    pre[k][i] = j

    i = n
    route: list[int] = []
    for k in range(m, 0, -1):
        j = pre[k][i]

        route.append(i - j)

        i = j

    route.reverse()

    print(" ".join(str(n) for n in route))


if __name__ == "__main__":
    main()
