found = False
n = int(input("n = "))
i = 0

while found is False:
  i += 1
  if (2 ** i) > n:
    found = True

print(f"2^{i-1} is the greatest number smaller or equal to {n}")