from collections import deque

N = int(input())

S = list(map(int, input().split()))


def main():
    maxQ: deque[int] = deque()
    minQ: deque[int] = deque()

    l: int = 0
    max_len = 0

    ans: list[tuple[int, int]] = []

    for r in range(0, len(S)):
        if S[r] > 24 or S[r] < 18:
            minQ.clear()
            maxQ.clear()

            l = r + 1

            continue

        while len(maxQ) != 0 and S[maxQ[-1]] <= S[r]:
            _ = maxQ.pop()

        maxQ.append(r)

        while len(minQ) != 0 and S[minQ[-1]] >= S[r]:
            _ = minQ.pop()

        minQ.append(r)

        while len(maxQ) != 0 and len(minQ) != 0 and (S[maxQ[0]] - S[minQ[0]]) > 4:
            if minQ[0] == l:
                _ = minQ.popleft()

            if maxQ[0] == l:
                _ = maxQ.popleft()

            l += 1

        if r - l + 1 > max_len:
            max_len = r - l + 1

            ans.clear()
            ans.append((l, r))
        elif r - l + 1 == max_len:
            ans.append((l, r))

    for a in ans:
        print(a[0], a[1])


main()
