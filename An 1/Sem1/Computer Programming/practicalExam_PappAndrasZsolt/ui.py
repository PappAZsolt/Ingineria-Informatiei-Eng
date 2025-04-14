from library import Book,Library


def library_ui():
    library = Library()
    #Pre defined inputs
    library.add_book("1984", "George Orwell", "Fiction", 1949)
    library.add_book("Pride and Prejudice", "Jane Austen", "Romance", 1813) 
    library.add_book("A Brief History of Time", "Stephen Hawking", "Science", 1988)
    library.add_book("The Martian", "Andy Weir", "Science", 2014) 
    library.add_book("Invalid Book", "Author", "Adventure", 2000) 
    library.add_book("Future Book", "Author", "Fiction", -50) 


    while True:
        print("\n###### Library #####")
        print("1. Add Book")
        print("2. Delete Old Books")
        print("3. Display All Books")
        print("4. Display Fiction Books Sorted by Year")
        print("0. Exit")
        choice = input("Enter your choice: ")

        if choice == "1":
            title = input("Enter Book Title: ")
            author = input("Enter Book Author: ")
            genre = input("Enter Genre (Fiction, Romance, Science): ")
            try:
                year = int(input("Enter Publication Year: "))
                if library.add_book(title, author, genre, year):
                    print("Book added successfully.")
                else:
                    print("Invalid genre or year.")
            except ValueError:
                print("Year must be a number.")

        elif choice == "2":
            try:
                year = int(input("Enter Year: "))
                deleted_count = library.delete_books_before_year(year)
                print(f"Deleted {deleted_count} book(s) published before {year}.")
            except ValueError:
                print("Year must be a number.")

        elif choice == "3":
            books = library.display_books()
            if books:
                print("\n#### Books in Library ####")
            else:
                print("No books in the library.")

        elif choice == "4":
            fiction_books = library.display_fiction()
            if fiction_books:
                print("\n#### Fiction Books ####")
                for book in fiction_books:
                    print(book)
            else:
                print("No Fiction books found.")
            
        elif choice == "0":
            break

        else:
            print("Invalid choice. Please try again.")

   