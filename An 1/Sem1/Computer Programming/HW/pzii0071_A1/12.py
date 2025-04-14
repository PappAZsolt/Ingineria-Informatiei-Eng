def cnt_digits(number):
  digit_count = {} # Dictionary to store the characteristics of a number

  for digit in number:  
    digit_count[digit] = 1
  return digit_count

def same_digits(num1,num2):
  cnt1 = cnt_digits(num1)
  cnt2 = cnt_digits(num2)

  return cnt1 == cnt2  

num1 = input()
num2 = input()

if same_digits(num1,num2):
  print("They are made up of the same digits")
else:
  print("They are not made up of the same digits")