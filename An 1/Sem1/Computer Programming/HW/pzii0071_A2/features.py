###################### FIRST ITERATION #########################

def add(list):
  value = int(input("Enter value: "))
  list.append(value)
  return list
  
def insert(list):
  value = int(input("Enter value: "))
  index = int(input(f"Enter index to add {value} to: "))
  if 0 <= index < len(list):  ## Check if the given index isn't out of bounds
    list.insert(index,value)
    return list
  else:
    print("Invalid index.")


def remove_at_index(list):
  index = int(input("Enter index: "))
  if 0 <= index < len(list):
    removed = list.pop(index)
    return list
  else:
    print("Invalid index.")
    
def remove_between_indexes(list):
  start = int(input("Start index: "))
  end = int(input("End index: "))
  if 0 <= start < end <= len(list):
    del list[start:end]
  else:
    print("Invalid indexes.")

def replace(list):
  index = int(input("Enter index: "))
  if 0 <= index < len(list):
    new_value = int(input(f"Input new value to replace at {index}: "))
    list[index] = new_value

def first_iteration(list):
  for i in range(10):
    print("\nIteration: ", i)
    print("1. Add element\n2. Insert element\n3. Remove at index\n4. Remove between indexes\n5. Replace value\n9. Show list\n0. Exit")
    feature_choice = int(input("Choose feature: "))
    if feature_choice == 1:
      add(list)
      print(list)
    elif feature_choice == 2:
      insert(list)
      print(list)
    elif feature_choice == 3:
      remove_at_index(list)
      print(list)
    elif feature_choice == 4:
      remove_between_indexes(list)
      print(list)
    elif feature_choice == 5:
      replace(list)
      print(list)
    elif feature_choice == 9:
      show_list(list)
    elif feature_choice == 0:
      break
#####################################################################

###################### SECOND ITERATION  ############################

def less(list):
  value = int(input("Get value: "))
  return [item for item in list if item < value] ## Returns only the values in the list which are smaller than value

def sorted(list):
  new_list = list.copy() # We make a copy of the list 
  new_list.sort() # We sort it
  return new_list

def higher_sorted(list):
  value = int(input("Get value: "))
  new_list = []
  for i in list:
    if i > value:
      new_list.append(i) # We save all participants in a new list which are bigger than the given value
  return new_list

def avg(list):
  start = int(input("Start index: "))
  end = int(input("End index: "))
  if 0 <= start < end <=len(list):
    new_list = list[start:end+1]
    return sum(new_list) / len(new_list) ## Calculate average
  else:
    print("Invalid indexes.")
  
def minimum(list):
  start = int(input("Start index: "))
  end = int(input("End index: "))
  if 0 <= start < end < len(list):
    new_list = list[start:end+1]
    return min(new_list)
  else:
    print("Invalid indexes.")

def mul(list):
  start = int(input("Start index: "))
  end = int(input("End index: "))
  if 0 <= start < end < len(list):
    value = int(input("Get value: "))
    temp_list = []
    for i in range(start,end):
      if (list[i] % value == 0):  ## Multiplies of value
        temp_list.append(list[i])
    return temp_list
  else:
    print("Invalid Indexes:")

def second_iteration(list):
  for i in range(10):
    print("\nIteration: ", i)
    print("1. Participants with score less than value\n2. Sort by score\n3. Sort by value\n4. Average score between indexes\n5. Get minimum score between two indexes\n6. Get score of participants between indexes which are multiplies of a value\n9. Show list\n0. Exit")
    feature_choice = int(input("Choose feature: "))
    if feature_choice == 1:
      print(less(list))
    elif feature_choice == 2:
      print(sorted(list))
    elif feature_choice == 3:
      print(higher_sorted(list))
    elif feature_choice == 4:
      print(avg(list))
    elif feature_choice == 5:
      print(minimum(list))
    elif feature_choice == 6:
      print(mul(list))
    elif feature_choice == 9:
      show_list(list)
    elif feature_choice == 0:
      break
#####################################################################

######################### THIRD ITERATION ###########################

def filter_mul(list):
  value = int(input("Get value: "))
  list[:] = [i for i in list if i % value == 0]

def filter_greater(list):
  value = int(input("Get value: "))
  list[:] = [i for i in list if i > value]

def undo(list,old_list):
  list[:] = old_list.copy()


def third_iteration(list):
  old_list = list.copy()
  for i in range(10):
    print("\nIteration: ", i)
    print("1. Filter multiplies of value\n2. Filter participants higher than value\n3. Undo last operation\n9. Show list\n0. Exit")
    feature_choice = int(input("Choose feature: "))
    if feature_choice == 1:
      filter_mul(list)
      print(list)
    elif feature_choice == 2:
      filter_greater(list)
      print(list)
    elif feature_choice == 3:
      undo(list,old_list)
      print(list)
    elif feature_choice == 9:
      show_list(list)
    elif feature_choice == 0:
      break

#####################################################################

def show_list(list):
  print(list)