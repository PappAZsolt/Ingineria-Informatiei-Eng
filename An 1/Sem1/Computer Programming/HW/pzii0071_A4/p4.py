import numpy as np
import matplotlib as plt

class MyVector:
  def __init__(self,name_id,color,type,values):

    self.name_id = name_id
    self.color = color
    self.type = type
    self.values = np.array(values)

  def setNameId(self,name_id):
      self.name_id = name_id
    
  def setColor(self, color):
      self.color = color
    
  def setType(self, type):
      self.type = type
    
  def setValue(self, values):
      self.values = np.array(values)
    
  def getNameId(self):
      return self.name_id
    
  def getColor(self):
      return self.color
  
  def getType(self):
      return self.type
    
  def getValue(self):
      return self.values.tolist()
  
  def __repr__(self):
      return (f"MyVector(name_id = {self.name_id}, color='{self.color}', type={self.type}, values={self.values.tolist()})\n")
      
    
  def add_scalar(self,num):
      new_values = []
      for x in self.values:
        new_values.append(x + num) # We add to every value in the vector the num
      return MyVector(self.name_id,self.color,self.type,new_values)
  
  def add(self,other):
      if len(self.values) != len(other.values):
          raise ValueError("Vectors not the same length")
      new_values = []
      for x,y in zip(self.values,other.values): #It goes through both vectors the same time
          new_values.append(x + y)
      return MyVector(self.name_id, self.color, self.type, new_values)
    
  def subtract(self,other):
      if len(self.values) != len(other.values):
          raise ValueError("Vectors not the same length")
      new_values = []
      for x,y in zip(self.values,other.values):
          new_values.append(x - y)
      return MyVector(self.name_id,self.color,self.type,new_values)
  
  def multiply(self,other):
      if len(self.values) != len(other.values):
          raise ValueError("Vectors not the same length")
      new_values = []
      for x,y in zip(self.values,other.values):
          new_values.append(x * y)
      return MyVector(self.name_id,self.color,self.type,new_values)

  def sum(self):
      s = 0
      for x in self.values:
          s += x
      return s

  def product(self):
      p = 1
      for x in self.values:
          p *= x
      return p

  def average(self):
      s = 0
      cnt = 0
      for x in self.values:
          s += x
          cnt += 1
      return s / cnt
  
  def minimum(self):
      minV = self.values[0]
      for x in self.values:
          if x < minV:
              minV = x
      return minV

  def maximum(self):
      maxV = self.value[0]
      for x in self.values:
          if x > maxV:
              maxV = x
      return maxV
  
class VectorRepository:
    def __init__(self):
        self.vectors = []
      
    def add_vector(self,vector):
        self.vectors.append(vector)
    
    def get_vector(self):
        return self.vectors
    
    def get_vector_index(self,index):
        if 0 <= index < len(self.vectors):
            return self.vectors[index]
        raise IndexError("Out of range")
    
    def update_vector_at_index(self,index,new_vector):
        if 0 <= index < len(self.vectors):
            self.vectors[index] = new_vector
        else:
            raise IndexError("Index out of range")
    
    def update_vector_by_id(self,name_id,new_vector):
        for i,vector in enumerate(self.vectors):
            if vector.name_id == name_id:
                self.vectors[i]= new_vector
                return
        raise ValueError("No vector found")
        
    def delete_vector_by_index(self,index):
        if 0 <= index < len(self.vectors):
            del self.vectors[index]
        else:
            raise IndexError("Index out of range")
    
    def delete_vector_by_id(self,name_id):
        for i,vector in enumerate(self.vectors): # Goes through the vector and in i it memorises it's position
            if vector.name_id == name_id:
                del self.vectors[i]
                return
        raise ValueError("No vector found")
    
    def get_consecutive_multiplication(self):
        result = []
        for i in range(len(self.vectors) - 1):
            v1 = self.vectors[i].values
            v2 = self.vectors[i+1].values
            multiplied = [a * b for a,b in zip(v1,v2)] # Goes through the elements in v1 and v2 and multiplies them in multiplied
            result.append(multiplied)
        return result

    def del_by_value(self,value):
        for i in range(len(self.vectors)):
            maximum = max(self.vectors[i].values)
            if maximum == value:
                del self.vectors[i]
    
    def update_color_by_type(self,type,new_color):
        for i,vector in enumerate(self.vectors):
            if vector.type == type:
                self.vectors[i].color = new_color


    
def assertion_test():
    test = VectorRepository()
    v1 = MyVector("v1","r", 1, [1,2,3])
    v2 = MyVector("v2","y", 2, [4,5,6])
    v3 = MyVector("v3","g", 3, [7,8,9])
    test.add_vector(v1)
    test.add_vector(v2)
    test.add_vector(v3)

    #Test 1
    assert len(test.get_vector()) == 3, "Length test failed" 

    #Test 2
    assert test.get_vector_index(0) == v1, "Wrong vector at index 0" 

    #Test 3
    v2_new = MyVector("v2_new","yellow", 0, [0,0,0])
    test.update_vector_at_index(1,v2_new)
    assert test.get_vector_index(1) == v2_new, "Vector not updated correctly"

    print("No test errors\n")
  
    
def main():
    repo = VectorRepository()
    v1 = MyVector("v1","r", 1, [1,2,3])
    v2 = MyVector("v2","y", 2, [4,5,6])
    v3 = MyVector("v3","g", 1, [7,8,9])
    repo.add_vector(v1)
    repo.add_vector(v2)
    repo.add_vector(v3)

    assertion_test()

    while True:
        print("\n1. Add vector\n2. Get all vector\n3. Get vector by index\n4. Update vector by index\n5. Update vector by name_id\n6. Delete vector by index\n7. Delete vector by name_id\n8. Plot vectors\n9. Multiplication of consecutive vectors\n10. Delete vectors that have max value equal to a given value\n11. Update all vector's colors that are equal to a given type\n0. Exit")
        choice = int(input("Enter feature: "))
        try:
            if choice == 1:
                id = input("Choose name_id: ")
                color = input("Choose color: ")
                type = int(input("Choose type: "))
                values = list(map(int,input("Enter vector: ").split()))
                new_vector = MyVector(id,color,type,values)
                repo.add_vector(new_vector)

            elif choice == 2:
                print(repo.get_vector())
            
            elif choice == 3:
                index = int(input("Enter index: "))
                print(repo.get_vector_index(index))
            
            elif choice == 4:
                index = int(input("Enter index: "))
                id = input("Choose new name_id: ")
                color = input("Choose new color: ")
                type = int(input("Choose new type: "))
                values = list(map(int,input("Enter vector: ").split()))
                new_vector = MyVector(id,color,type,values)
                repo.update_vector_at_index(index,new_vector)
            
            elif choice == 5:
                id = input("Enter name_id: ")
                id = input("Choose new name_id: ")
                color = input("Choose new color: ")
                type = int(input("Choose new type: "))
                values = list(map(int,input("Enter vector: ").split()))
                new_vector = MyVector(id,color,type,values)
                repo.update_vector_at_index(index,new_vector)

            elif choice == 6:
                index = int(input("Enter index: "))
                repo.delete_vector_by_index(index)

            elif choice == 7:
                id = input("Enter name_id: ")
                repo.delete_vector_by_id(id)
            
            elif choice == 8:
                repo.plot_vectors()

            elif choice == 9:
                print(repo.get_consecutive_multiplication())

            elif choice == 10:
                value = int(input("Enter value: "))
                repo.del_by_value(value)
            
            elif choice == 11:
                type = int(input("Enter type: "))
                new_color = input("Enter new color: ")
                repo.update_color_by_type(type,new_color)
                
            elif choice == 0:
                break

        except (ValueError,IndexError) as error:
            print("Error: ", error)

if __name__ == "__main__":
    main()

            
        
        


