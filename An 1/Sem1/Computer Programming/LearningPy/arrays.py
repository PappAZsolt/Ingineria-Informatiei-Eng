#################### LISTS ######################
thislist = ["apple", "banana", "cherry"]
print(thislist[0])

# Insert Items

thislist.insert(2,"watermelon")


## Append Items (add to end of list)

thislist.append("orange")

## Extend List

tropical = ["mango", "pineapple"]
thislist.extend(tropical)

print(thislist)

## Removing Specified Index

thislist.pop(1) ## Not specify-ing the number automatically removes last item
print(thislist)

## Sorting Lists

thislist.sort(reverse = True) ## Sorting descending
print(thislist)

## Reversing List

thislist.reverse()
print(thislist) 

## Copying Lists

mylist = thislist.copy()

# OR

mylist = list(thislist)


############## TUPLE ##################

thistuple = ("apple","banana")
print(type(thistuple))

# Unpacking a tuple

(green,yellow) = thistuple
print(green)

fruits = ("apple", "banana","cherry")

(green, *red) = fruits # Using asterisk adds the rest of the list

print(red)

mytuple = fruits * 2

print(mytuple)

############# SETS #################

thisset = {"apple", "banana", "cherry", False, True, 0}

print(thisset)  ## STUDY THEM MORE!!!!


########### DICTIONARIES ##################

thisdict = {
  "brand" : "Ford",
  "model" : "Mustang",
  "year"  : "1964"
}

print(thisdict)
