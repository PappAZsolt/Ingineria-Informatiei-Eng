"""
Text Type:	str
Numeric Types:	int, float, complex
Sequence Types:	list, tuple, range
Mapping Type:	dict
Set Types:	set, frozenset
Boolean Type:	bool
Binary Types:	bytes, bytearray, memoryview
None Type:	NoneType
"""

import random

x = 1

#converting from int to float
x = float(x)

print(type(x))

print(random.randrange(1,10))

#STRINGS

#a = """Lorem ipsum dolor sit amet,
#consectetur adipiscing elit,
#sed do eiusmod tempor incididunt
#ut labore et dolore magna aliqua."""

a = "Hello"
print(a[0])
print(len(a))

## Looping through a string
for x in a:
  print(x)

## Checking if something is in a str

txt = "Ana are mere"
if "mere" in txt:
  print("Yes")

## Slicing Strings

b = "Hello World"
print(b[2:7])

a = " Hello, World " 
print(a.strip()) # removes whitespace from begining or end
print(a.replace("H", "J"))
print(a.split(",`")) # returns ['Hello', ' World!']

## Concatenation

a = "Hello"
b = "World"
c = a + " " + b

x = 5
y = 2
print (x ** y)