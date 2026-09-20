def main():
    m = int(input())

    lo: list[int] = []
    hi: list[int] = []

    for _ in range(m):
        l, h = map(int, input().split())
        lo.append(l)
        hi.append(h)

    dur: list[list[int]] = []

    for _ in range(m):
        dur.append(list(map(int, input().split())))


main()
