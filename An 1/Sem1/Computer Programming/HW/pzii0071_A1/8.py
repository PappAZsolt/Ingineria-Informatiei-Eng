import math

def is_prime(n): #Checking if the number is a prime
  if n <= 1:
    return False
  if n == 2:
    return True
  if n % 2 == 0:
    return False
  lim = int(math.sqrt(n))
  for i in range(3,lim + 1, 2):
    if n % i == 0:
      return False
  return True

def nearest_prime(n):
  if n < 2:
    return 2
  lower, upper = n,n
  while True:
    if is_prime(lower):
      return lower
    if is_prime(upper):
      return upper
    lower -= 1
    upper += 1

n = int(input("n = "))
nearest = nearest_prime(n)
print(nearest)