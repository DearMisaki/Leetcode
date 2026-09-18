def main():
    n = int(input())
    energy = list(map(int, input().split()))

    target = int(input())

    pos = -1

    for i in range(n):
        left = energy[(i - 1) % n]
        right = energy[i]

        if left <= right:
            if left <= target <= right:
                pos = i
                break
        else:
            if target >= left or target <= right:
                pos = i
                break
    if pos != -1:
        energy.insert(pos, target)
    else:
        print(-1)

    print(" ".join(str(ele) for ele in energy))


if __name__ == '__main__':
    main()
