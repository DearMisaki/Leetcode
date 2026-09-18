def main():
    n, m = map(int, input().split())

    initial = list(map(int, input().split()))

    target = 0

    for i, v in enumerate(initial):
        if v == 1:
            target |= 1 << i

    gates = [0] * n

    for i in range(n):
        gates[i] |= 1 << i

    for _ in range(m):
        x, y = map(int, input().split())

        x -= 1
        y -= 1

        gates[x] |= 1 << y

    # initial XOR {G1, G2, ... , Gn} = 0, so initial == {G1, G2, ... , Gn}

    min_count = n
    ans: list[int] | None = None

    for mask in range(1 << n):
        state = 0
        current: list[int] = []

        for i in range(n):
            if (1 << i) & mask:
                state ^= gates[i]
                current.append(i + 1)

        if state != target:
            continue

        # find it
        count = bin(mask).count("1")

        if ans is None:
            ans = current
            min_count = count
        elif count < min_count:
            min_count = count
            ans = current
        elif count == min_count:
            if current < ans:
                ans = current

    if ans is None:
        print(-1)
    else:
        print(" ".join(str(i) for i in ans))


main()
