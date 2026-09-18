from collections import OrderedDict


def main():
    D = int(input())
    N = int(input())

    sequence: list[str] = []

    for _ in range(N):
        sequence.append(input())

    target: str = input()

    ans: OrderedDict[int, list[str]] = OrderedDict()

    for sub_seq in sequence:
        dp = [[0] * (len(sub_seq) + 1) for _ in range(len(target) + 1)]

        dp[0][0] = 0

        for i in range(1, len(target) + 1):
            dp[i][0] = i

        for j in range(1, len(sub_seq) + 1):
            dp[0][j] = j

        for i in range(1, len(target) + 1):
            for j in range(1, len(sub_seq) + 1):
                if target[i - 1] == sub_seq[j - 1]:
                    dp[i][j] = dp[i - 1][j - 1]
                else:
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1],
                                   dp[i - 1][j - 1]) + 1
        if dp[-1][-1] not in ans:
            ans[dp[-1][-1]] = []

        ans[dp[-1][-1]].append(sub_seq)

    ans2: list[str] = []

    for dis, sub_seq in ans.items():
        if dis == 0:
            for ele in sorted(sub_seq):
                ans2.append(ele)
            break
        elif dis <= D:
            for ele in sorted(sub_seq):
                ans2.append(ele)

    if len(ans2) == 0:
        print("None")
    else:
        print(" ".join(ele for ele in ans2))


if __name__ == '__main__':
    main()
