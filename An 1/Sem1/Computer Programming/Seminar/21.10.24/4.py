import math

#Verify if a number is a perfect square

n = int(input("n = "))
sqrt_n = int(math.sqrt(n))

if sqrt_n * sqrt_n == n:
  print("pp")
else:
  print("nu e pp")