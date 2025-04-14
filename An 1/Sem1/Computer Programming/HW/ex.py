class Inventory:
    def __init__(self):
        self.parts = {}

    def add_part(self, part_name, price, quantity):
        if part_name in self.parts:
            self.parts[part_name]['quantity'] += quantity
        else:
            self.parts[part_name] = {'price': price, 'quantity': quantity}

    def remove_part(self, part_name, quantity):
        if part_name in self.parts and self.parts[part_name]['quantity'] >= quantity:
            self.parts[part_name]['quantity'] -= quantity
            if self.parts[part_name]['quantity'] == 0:
                del self.parts[part_name]
        else:
            raise ValueError(f"Not enough {part_name} in inventory or part does not exist.")

    def get_part_price(self, part_name):
        if part_name in self.parts:
            return self.parts[part_name]['price']
        else:
            raise ValueError(f"Part {part_name} not found in inventory.")

    def display_inventory(self):
        return self.parts


class RepairScheduler:
    def __init__(self, inventory, hourly_rate):
        self.inventory = inventory
        self.hourly_rate = hourly_rate
        self.appointments = []

    def schedule_repair(self, car_model, part_name, work_hours):
        if part_name not in self.inventory.parts or self.inventory.parts[part_name]['quantity'] < 1:
            raise ValueError(f"{part_name} is not available in inventory.")
        
        part_price = self.inventory.get_part_price(part_name)
        labor_cost = work_hours * self.hourly_rate
        total_cost = part_price + labor_cost
        
        self.inventory.remove_part(part_name, 1)
        appointment = {
            'car_model': car_model,
            'part_name': part_name,
            'work_hours': work_hours,
            'total_cost': total_cost
        }
        self.appointments.append(appointment)
        return appointment


# Unit Testing
import unittest

class TestCarServiceSystem(unittest.TestCase):
    def setUp(self):
        self.inventory = Inventory()
        self.scheduler = RepairScheduler(self.inventory, hourly_rate=50)

    def test_inventory_management(self):
        self.inventory.add_part('Brake Pad', 30, 10)
        self.assertEqual(self.inventory.parts['Brake Pad']['quantity'], 10)
        
        self.inventory.remove_part('Brake Pad', 5)
        self.assertEqual(self.inventory.parts['Brake Pad']['quantity'], 5)
        
        with self.assertRaises(ValueError):
            self.inventory.remove_part('Brake Pad', 10)

    def test_repair_scheduling(self):
        self.inventory.add_part('Brake Pad', 30, 10)
        appointment = self.scheduler.schedule_repair('Car A', 'Brake Pad', 2)
        
        self.assertEqual(appointment['total_cost'], 130)  # Part price (30) + labor (2 * 50)
        self.assertEqual(self.inventory.parts['Brake Pad']['quantity'], 9)

        with self.assertRaises(ValueError):
            self.scheduler.schedule_repair('Car B', 'Engine', 3)

if __name__ == "__main__":
    unittest.main()
