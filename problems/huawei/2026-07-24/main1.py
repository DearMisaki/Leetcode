
N, E, K, C = map(int, input().split())

scores: list[list[int]] = []

for i in range(N):
    scores.append(list(map(int, input().split())))

expert_capacity: list[int] = [0] * E

for task_index in range(N):
    order = [i for i in range(E)]
    order.sort(key=lambda i: scores[task_index][i], reverse=True)
    for j in order[:K]:
        if expert_capacity[j] < C:
            expert_capacity[j] += 1
        else:
            continue

sumpow = 0

for score in expert_capacity:
    sumpow += score * score

print(sumpow)
print(" ".join(str(i) for i in expert_capacity))
