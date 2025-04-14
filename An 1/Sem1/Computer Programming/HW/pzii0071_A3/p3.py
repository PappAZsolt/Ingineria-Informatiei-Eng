import math
import matplotlib.pyplot as plt


class MyPoint:
  def __init__(self,x,y,c):

    self.coord_x = x
    self.coord_y = y
    self.color = c

  def getCoordX(self):
    return self.coord_x
  
  def getcoordY(self):
    return self.coord_y
  
  def getColor(self):
    return self.color
  
  def setCoordX(self):
    self.coord_x
  
  def setCoordY(self):
    self.coord_y

  def setColor(self):
    self.color


  def __repr__(self):
    return f"Point ({self.coord_x},{self.coord_y}) of color {self.color}"
  
########## 2nd Iteration ########

class PointRepository:
  def __init__(self):
    self.points = []
  
  ## Adding point to the repo
  def add_point(self,point):
    self.points.append(point)
  
  ## Get all points
  def get_points(self):
    return self.points
  
  ## Get point at a given index
  def get_point_at_index(self,index):
    if  0 <= index < len(self.points):
      return self.points[index]
    else:
      raise IndexError("Index out of range")
    
  ## Get all points of a given color
  def get_points_by_color(self,color):
    new_points = []
    for point in self.points:
      if point.color == color:
        new_points.append(point)
    return new_points
  
  ## Get all points that are inside a given square
  def get_points_in_square(self,x_min,y_max,length):
   
    x_max = x_min + length

    new_points = []
    for point in self.points:
      if ((x_min <= point.coord_x <= x_max) and (y_max >= point.coord_y <= y_max)):
        new_points.append(point)
    return new_points
  
  ## Get the minimum distance between two points
  def minimum_distance(self,p1,p2):
    dist = math.sqrt((p2.coord_x - p1.coord_x) ** 2 + (p2.coord_y - p1.coord_y) ** 2)
    return dist

  ## Update a point at a given index
  def update_point(self,index,new_point):
    if 0 <= index < len(self.points):
      self.points[index] = new_point
    else:
      raise IndexError("Index out of range")
    
  ## Delete a point using index
  def delete_point(self,index):
    if 0 <= index < len(self.points):
      del self.points[index]
    else:
      raise IndexError("Index out of range")  
    
  ## Delete all points in a given square
  def delete_points_in_square(self, x_min, y_max, length):
    x_max = x_min + length
    new_points = []
    for point in self.points:
      if not ((x_min <= point.coord_x <= x_max) and (y_max >= point.coord_y <= y_max)):
        new_points.append(point)
    self.points = new_points

  def plot_points(self):
    x_coords = []
    y_coords = []
    colors = []
    for point in self.points:
      x_coords.append(point.coord_x)
      y_coords.append(point.coord_y)
      colors.append(point.color)
    plt.scatter(x_coords, y_coords, c = colors)
    plt.show()

  def shift(self,value):
    for point in self.points:
     point.coord_y += int(value)

  def number_of_points_by_color(self,color):
    cnt = 0
    for point in self.points:
      if (point.color == color):
        cnt += 1
    return cnt

  def update_color(self,x,y,color):
    for point in self.points:
      if (x == point.coord_x and y == point.coord_y):
        point.color = color


def main():
  repo = PointRepository()
  with open("input.txt","r") as file:
    for line in file:
      values = line.strip().split()
      x = values[0]
      y = values[1]
      color = values[2]
      point = MyPoint(x,y,color)
      repo.add_point(point)
      
  while True:
    print("\n1. Add point to the repo\n2. Get all points\n3. Get point at index\n4. Get all points of a given color\n5. Get all points that are inside a given square\n6. Get the minimum distance between two points\n7. Update point by index\n8. Delete point by index\n9. Delete all points inside square\n10. Plot all points\n11. Get number of points by color\n12. Update color by coordinates\n13. Shift by value\n0. Exit")
    choice = int(input("Select choice: "))
    try:
      if choice == 1:
        x = float(input("X coordinate: "))
        y = float(input("Y coordinate: "))
        color = input("Enter color: ")
        point = MyPoint(x,y,color)
        repo.add_point(point)
      
      elif choice == 2:
        points = repo.get_points()
        print("All points: ", points)
      
      elif choice == 3:
        index = int(input("Enter index: "))
        point = repo.get_point_at_index(index)
        print(f"Point at index {index}: ", point)
      
      elif choice == 4:
        color = input("Enter color: ")
        points = repo.get_points_by_color(color)
        print(f"Points with color {color}:" , points)
      
      elif choice == 5:
        x = float(input("Enter top left x coord: "))
        y = float(input("Enter top left y coord: "))
        length = float(input("Enter length of square: "))
        points = repo.get_points_in_square(x,y, length)
        print("Points inside square: ", points)
      
      elif choice == 6:
        index1 = int(input("First index: "))
        index2 = int(input("Second index: "))
        p1 = repo.get_point_at_index(index1)
        p2 = repo.get_point_at_index(index2)
        dist = repo.minimum_distance(p1,p2)
        print(f"Distance between {p1} and {p2}:", dist)

      elif choice == 7:
        index = int(input("Enter index to update: "))
        x = float(input("Enter new x coord: "))
        y = float(input("Enter new y coord: "))
        color = input("Enter new color: ")
        new_point = MyPoint(x,y,color)
        repo.update_point(index,new_point)

      elif choice == 8:
        index = int(input("Index to delete: "))
        repo.delete_point(index)
      
      elif choice == 9:
        x = float(input("Enter top left x coord: "))
        y = float(input("Enter top left y coord: "))
        length = float(input("Enter length of square: "))
        repo.delete_points_in_square(x,y, length)
      
      elif choice == 10:
        repo.plot_points()
      
      elif choice == 11:
        color = input("Enter color: ")
        cnt = repo.get_points_by_color(color)
        print(cnt)

      elif choice == 12:
        x = float(input("Enter x coord: "))
        y = float(input("Enter y coord: "))
        color = input("Enter color: ")
        repo.update_color(x,y,color)

      elif choice == 13:
        value = int(input("Enter value to shift y axis: "))
        repo.shift(value)

      elif choice == 0:
        break

      else:
        print("Invalid choice, try again.")

    except (ValueError, IndexError) as error:
      print("Error: ", error)


if __name__ == "__main__":
  main()