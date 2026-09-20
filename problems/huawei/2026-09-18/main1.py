def main():
    p, d = map(int, input().split())

    nodes = []
    total_targs = []
    for _ in range(p):
        parts = input().split()

        nodeid = int(parts[0])

        targs = parts[1:]

        for targ in targs:
            if targ not in total_targs:
                total_targs.append(targ)

        nodes.append([nodeid, targs])

    total_targs.sort()
    nodes.sort()

    for node in nodes:
        targs = node[1]
        targ_bit = 0

        for targ in targs:
            index = total_targs.index(targ)
            targ_bit |= 1 << index
        node.append(targ_bit)

    b = int(input())

    ans = []

    picked = 0
    for batch in range(1, b + 1):
        q = p // b
        r = p % b

        capacity = 0

        if batch <= b - r:
            capacity = q
        else:
            capacity = q + 1

        ans.append([])
        seen = 0
        for _ in range(capacity):
            max_index = -1
            max_gain = -1
            best_targ_bit = 0

            for nodeid, targs, targ_bit in nodes:
                if (1 << nodeid) & picked:
                    continue

                count = bin(targ_bit & ~seen).count("1")

                if count > max_gain:
                    max_gain = count
                    max_index = nodeid
                    best_targ_bit = targ_bit

            seen |= best_targ_bit
            picked |= 1 << max_index
            ans[-1].append(max_index)

    for a in ans:
        a.sort()
        print(" ".join(map(str, a)))


main()
