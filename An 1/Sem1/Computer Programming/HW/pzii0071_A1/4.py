def smallest_num(n):
  digits = list(n) # Transform the string into a list

  digits.sort() # Sort ascending

  if digits[0] == '0': # If there are zeroes present 
    for i in range(1,len(digits)):
      if (digits[i] != '0'): # we find the first digit that isn't a zero and
        digits[0],digits[i] = digits[i], digits[0] # swap with the first zero
        break
  return int(''.join(digits)) # Join the list back to an integer

n = str(input("n = "))

new_n = smallest_num(n)

print (new_n) 