n = int(input())
ans = [int(input())]    # Первую машину вводим сразу сюда для сравнения

for _ in range(n-1):
  next = int(input())
  if next > ans[-1]:
    ans.append(ans[-1])
  else:
    ans.append(next)

print(*ans)