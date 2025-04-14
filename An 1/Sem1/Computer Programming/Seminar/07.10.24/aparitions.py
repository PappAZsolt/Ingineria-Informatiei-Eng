dict = { }
n = 1222334445
while (n > 0):
    cif = n % 10
    dict[cif] += 1
    n /= 10
    max = 0
    for cif in dict.value():
        if (max < cif):
          max = cif
print(max)
 