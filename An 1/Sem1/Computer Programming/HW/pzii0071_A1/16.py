def special_cond(number):
  u = number % 10 # Units
  t = int((number / 10) % 10) # Tens
  return u < t

cnt = 0
x = int(input())
while x != 0:
  if special_cond(x) == True:
    cnt += 1
  x = int(input())

print(cnt)
