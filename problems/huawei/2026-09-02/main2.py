from math import ceil


def main():
    r, n, t = map(int, input().split())
    m = ceil(n / 2)

    prefix = r ** (m - 1) + (t - 1)

    number = 0
    if n % 2 == 1:
        x = prefix // r
    else:
        x = prefix

    ans = prefix
    while x != 0:
        number = x % r
        ans = ans * r + number
        x //= r

    print(ans)


main()
