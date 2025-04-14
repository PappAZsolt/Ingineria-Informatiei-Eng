f = open("input.txt","r")
c = open("output.txt","w")

###################### FIRST ITERATION #########################

def add(list,value):
  list.append(value)
  return list
  
def insert(list,value,index):
  if 0 <= index < len(list):  ## Check if the given index isn't out of bounds
    list.insert(index,value)
    return list
  else:
    c.write("Invalid index.")


def remove_at_index(list,index):
  if 0 <= index < len(list):
    removed = list.pop(index)
    return list
  else:
    c.write("Invalid index.")
    
def remove_between_indexes(list,start,end):
  if 0 <= start < end <= len(list):
    del list[start:end]
  else:
    c.write("Invalid indexes.")

def replace(list,index):
  if 0 <= index < len(list):
    new_value = int(input(f"Input new value to replace at {index}: "))
    list[index] = new_value

def first_iteration(list):
  for i in range(6):
    feature_choice = int(f.readline())
    if feature_choice == 1:
      value = int(f.readline())
      add(list,value)
      c.write(f"{str(list)}\n")
    elif feature_choice == 2:
      value = int(f.readline())
      index = int(f.readline())
      insert(list,value,index)
      c.write(f"{str(list)}\n")
    elif feature_choice == 3:
      index = int(f.readline())
      remove_at_index(list,index)
      c.write(f"{str(list)}\n")
    elif feature_choice == 4:
      start = int(f.readline())
      end = f.readline()
      remove_between_indexes(list,start,end)
      c.write(f"{str(list)}\n")
    elif feature_choice == 5:
      index = int(f.readline())
      replace(list,index)
      c.write(f"{str(list)}\n")
    elif feature_choice == 0:
      break
#####################################################################

###################### SECOND ITERATION  ############################

def less(list,value):
  return [item for item in list if item < value] ## Returns only the values in the list which are smaller than value

def sorted(list):
  new_list = list.copy() # We make a copy of the list 
  new_list.sort() # We sort it
  return new_list

def higher_sorted(list,value):
  new_list = []
  for i in list:
    if i > value:
      new_list.append(i) # We save all participants in a new list which are bigger than the given value
  return new_list

def avg(list,start,end):
  if 0 <= start < end <=len(list):
    new_list = list[start:end+1]
    return sum(new_list) / len(new_list) ## Calculate average
  else:
    c.write("Invalid indexes.")
  
def minimum(list,start,end):
  if 0 <= start < end < len(list):
    new_list = list[start:end+1]
    return min(new_list)
  else:
    c.write("Invalid indexes.")

def mul(list,value,start,end):
  if 0 <= start < end < len(list):
    temp_list = []
    for i in range(start,end):
      if (list[i] % value == 0):  ## Multiplies of value
        temp_list.append(list[i])
    return temp_list
  else:
    c.write("Invalid Indexes:")

def second_iteration(list):
  for i in range(3):
    feature_choice = int(f.readline())
    if feature_choice == 1:
      value = int(f.readline())
      new_list = less(list,value)
      c.write(f"{str(new_list)}\n")
    elif feature_choice == 2:
      new_list = sorted(list)
      c.write(f"{str(new_list)}\n")
    elif feature_choice == 3:
      value = int(f.readline())
      new_list = higher_sorted(list,value)
      c.write(f"{str(new_list)}\n")
    elif feature_choice == 4:
      start = int(f.readline())
      end = int(f.readline())
      new_list = avg(list,start,end)
      c.write(f"{str(new_list)}\n")
    elif feature_choice == 5:
      start = int(f.readline())
      end = int(f.readline())
      new_list = minimum(list,start,end)
      c.write(f"{str(new_list)}\n")
    elif feature_choice == 6:
      value = int(f.readline())
      start = int(f.readline())
      end = int(f.readline())
      new_list = mul(list,value,start,end)
      c.write(f"{str(new_list)}\n")
    elif feature_choice == 0:
      break
#####################################################################

######################### THIRD ITERATION ###########################

def filter_mul(list,value):
  list[:] = [i for i in list if i % value == 0]

def filter_greater(list,value):
  list[:] = [i for i in list if i > value]

def undo(list,old_list):
  list[:] = old_list.copy()


def third_iteration(list):
  old_list = list.copy()
  for i in range(3):
    feature_choice = int(f.readline())
    if feature_choice == 1:
      value = int(f.readline())
      filter_mul(list,value)
      c.write(f"{list}\n")
    elif feature_choice == 2:
      value = int(f.readline())
      filter_greater(list,value)
      c.write(f"{list}\n")
    elif feature_choice == 3:
      undo(list,old_list)
      c.write(f"{list}\n")
    elif feature_choice == 9:
      c.write(f"Old list: {list}\n")
    elif feature_choice == 0:
      break

#####################################################################

def main():
  list = []
  c.write("First Iteration:\n")
  first_iteration(list)
  c.write("\nSecond Iteration:\n")
  second_iteration(list)
  c.write("\nThird Iteration:\n")
  third_iteration(list)

if __name__ == "__main__":
  main()
    