class Patient:
    def __init__(self, first_name, second_name, id, disease): #initializing patient class
        self.first_name = first_name
        self.second_name = second_name
        self.id = id
        self.disease = disease

    def setFirstName(self, first_name):
        self.first_name = first_name

    def setSecondName(self, second_name):
        self.second_name = second_name

    def setId(self, id):
        self.id = id

    def setDisease(self, disease):
        self.disease = disease

    def getFirstName(self):
        return self.first_name

    def getSecondName(self):
        return self.second_name

    def getId(self):
        return self.id

    def getDisease(self):
        return self.disease

    def __repr__(self):
        return f"Patient: Name = {self.first_name} {self.second_name}, ID = {self.id}, Disease = {self.disease}"


class Department:
    def __init__(self, id, name, num_beds): #Create
        self.id = id
        self.name = name
        self.num_beds = num_beds
        self.patients = []

    def add_patient(self, patient): #Update
        self.patients.append(patient)

    def remove_patient(self, patient_id): #Remove
        self.patients = [p for p in self.patients if p.id != patient_id]

    def get_patients(self):
        return self.patients

    def sort_patients_by_id(self):
      self.patients.sort(key=lambda p: p.id) # Sorting using pythons sort function 

    def __repr__(self):
        return f"Department: ID = {self.id}, Name = {self.name}, Beds = {self.num_beds}, Patients = {len(self.patients)}"


class Hospital:
    def __init__(self):
        self.departments = []

    def add_department(self, department):
        self.departments.append(department)

    def remove_department(self, department_id):
        self.departments = [d for d in self.departments if d.id != department_id]

    def get_departments(self):
        return self.departments

    def sort_departments_by_patient_count(self):
       
        self.departments.sort(key=lambda d: len(d.patients), reverse=True)

    def sort_departments_by_name(self):
       
        self.departments.sort(key=lambda d: d.name)

    def sort_all_patients_by_id(self):
        
        for department in self.departments:
            department.sort_patients_by_id()
        print("Patients sorted by ID in all departments.")

    def filter_departments_by_patient_first_name(self, first_name):
        
        return [d for d in self.departments if any(p.first_name.lower() == first_name.lower() for p in d.patients)]

    def filter_departments_by_patient_age(self, age_limit):
        
        return [d for d in self.departments if any(int(p.id[:2]) < age_limit for p in d.patients)]

    def group_patients_by_disease(self, k):
       
        groups = {}
        for d in self.departments:
            for p in d.patients:
                if p.disease not in groups:
                    groups[p.disease] = []
                groups[p.disease].append(p)
        return {disease: patients for disease, patients in groups.items() if len(patients) == k}

    def group_departments_by_patient_disease_limit(self, k, p):
       
        return [d for d in self.departments if len(set(pat.disease for pat in d.patients)) <= k and len(d.patients) <= p]


def main():
    hospital = Hospital()

    # Preinitializing some data
    p1 = Patient("Papp", "Zsolt", "89010112345", "Flu")
    p2 = Patient("Runcan", "Roxana", "87020254321", "Cold")
    p3 = Patient("Runcan", "Calin", "90030367890", "Fever")

    d1 = Department(1, "Emergency", 10)
    d2 = Department(2, "Pediatry", 15)

    d1.add_patient(p1)
    d1.add_patient(p2)
    d2.add_patient(p3)

    hospital.add_department(d1)
    hospital.add_department(d2)

    while True:
        print("\n--- Hospital Management System ---") 
        print("1. Manage Patients")
        print("2. Manage Departments")                  ##  MAIN MENU
        print("3. Manage Hospital")
        print("0. Exit")
        choice = int(input("Enter your choice: "))

        try:
            if choice == 1:
                print("\n--- Patient Management ---")
                print("1. Add Patient to Department")
                print("2. View Patients in a Department")
                print("3. Remove Patient from Department")
                print("0. Go Back")
                patient_choice = int(input("Enter your choice: "))

                if patient_choice == 1:
                    department_id = int(input("Enter Department ID: "))
                    first_name = input("Enter First Name: ")
                    second_name = input("Enter Second Name: ")
                    id = input("Enter Patient ID: ")
                    disease = input("Enter Disease: ")
                    patient = Patient(first_name, second_name, id, disease)

                    department = next((d for d in hospital.get_departments() if d.id == department_id), None)
                    if department:
                        department.add_patient(patient)
                        print("Patient added successfully.")
                    else:
                        print("Department not found.")

                elif patient_choice == 2:
                    department_id = int(input("Enter Department ID: "))
                    department = next((d for d in hospital.get_departments() if d.id == department_id), None)
                    if department:
                        print("\nPatients in Department:")
                        print(department.get_patients())
                    else:
                        print("Department not found.")

                elif patient_choice == 3:
                    department_id = int(input("Enter Department ID: "))
                    patient_id = input("Enter Patient ID to Remove: ")
                    department = next((d for d in hospital.get_departments() if d.id == department_id), None)
                    if department:
                        department.remove_patient(patient_id)
                        print("Patient removed successfully.")
                    else:
                        print("Department not found.")

            elif choice == 2:
                print("\n--- Department Management ---")
                print("1. Add Department")
                print("2. View Departments")
                print("3. Remove Department")
                print("4. Sort Departments by Patient Count")
                print("5. Sort Departments Alphabetically by Name")
                print("6. Sort Patients by ID in all departments") 
                print("0. Go Back")
                department_choice = int(input("Enter your choice: "))

                if department_choice == 1:
                    department_id = int(input("Enter Department ID: "))
                    name = input("Enter Department Name: ")
                    num_beds = int(input("Enter Number of Beds: "))
                    department = Department(department_id, name, num_beds)
                    hospital.add_department(department)
                    print("Department added successfully.")

                elif department_choice == 2:
                    print("\nDepartments:")
                    print(hospital.get_departments())

                elif department_choice == 3:
                    department_id = int(input("Enter Department ID to Remove: "))
                    hospital.remove_department(department_id)
                    print("Department removed successfully.")

                elif department_choice == 4:
                    hospital.sort_departments_by_patient_count()
                    print("Departments sorted by patient count.")

                elif department_choice == 5:
                    hospital.sort_departments_by_name()
                    print("Departments sorted alphabetically by name.")

                elif department_choice == 6:
                    hospital.sort_all_patients_by_id()
                    print("Patients sorted by ID in all departments.")

            elif choice == 3:
                print("\n--- Hospital Management ---")
                print("1. Filter Departments by Patient First Name")
                print("2. Filter Departments by Patient Age")
                print("3. Group Patients by Disease")
                print("4. Group Departments by Disease and Patient Limits")
                print("0. Go Back")
                hospital_choice = int(input("Enter your choice: "))

                if hospital_choice == 1:
                    first_name = input("Enter Patient First Name to Filter: ")
                    print("\nDepartments with patients having first name:")
                    print(hospital.filter_departments_by_patient_first_name(first_name))

                elif hospital_choice == 2:
                    age_limit = int(input("Enter Age Limit (in years): "))
                    print("\nDepartments with patients under the age limit:")
                    print(hospital.filter_departments_by_patient_age(age_limit))

                elif hospital_choice == 3:
                    k = int(input("Enter Number of Patients per Disease Group: "))
                    print("\nPatients grouped by disease:")
                    print(hospital.group_patients_by_disease(k))

                elif hospital_choice == 4:
                    k = int(input("Enter Maximum Number of Diseases per Department: "))
                    p = int(input("Enter Maximum Total Patients per Department: "))
                    print("\nDepartments grouped by disease and patient limits:")
                    print(hospital.group_departments_by_patient_disease_limit(k, p))

            elif choice == 0:
                print("Exiting the program. Goodbye!")
                break

            else:
                print("Invalid choice. Please try again.")

        except ValueError as error:
            print("Input Error:", error)
        except Exception as e:
            print("Error:", e)


if __name__ == "__main__":
    main()
