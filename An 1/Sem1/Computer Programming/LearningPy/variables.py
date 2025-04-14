x = 4 # x is now of type int
x = "CS" # x is now of type str

x = str(3)
x = int(3)
z = float(3)

x = 5
y = "Zs" # also can be used with ' '
print(type(x)) #getting the type
print(type(y))

# Multiple Variable at once
x,y,z = "Orange", "Banana", "Cherry"

print(x)
print(y)
print(z)

#Unpacking a collection

fruits = ["apple", "banana", "cherry"]
x,y,z = fruits
print(x)
print(y)
print(z)

x = "Python"
y = "is"
z = "awesome"
print(x,y,z) # outputs with spaces
print(x + y + z) # outputs without

x = 5
y = 10
print(x + y)

## GLOBAL VARIABLES 
x = "awesome"

def myfunc():
  x = "fantastic" # If you want it outside function use global!!!
  print("python is " + x)

myfunc()

print("Python is " + x)

