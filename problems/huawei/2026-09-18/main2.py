from collections import deque


def main():
    p, e = map(int, input().split())

    graph: list[list[int]] = [[] for _ in range(p + 1)]
    ingree = [0] * (p + 1)
    for _ in range(e):
        u, v = map(int, input().split())
        graph[u].append(v)
        ingree[v] += 1

    que: deque[int] = deque()

    for i, ing in enumerate(ingree):
        if ing == 0:
            que.append(i)

    count = 0

    while que:
        size = len(que)

        for _ in range(size):
            u = que.popleft()
            for v in graph[u]:
                ingree[v] -= 1
                if ingree[v] == 0:
                    que.append(v)

        count += 1

    print(count)


main()
