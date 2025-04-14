from library import Book,Library


def run_tests():
    library = Library()

    # Initialize books
    assert library.add_book("1984", "George Orwell", "Fiction", 1949) == True
    assert library.add_book("Pride and Prejudice", "Jane Austen", "Romance", 1813) == True
    assert library.add_book("A Brief History of Time", "Stephen Hawking", "Science", 1988) == True

    # Test adding valid and invalid books
    assert library.add_book("The Martian", "Andy Weir", "Science", 2014) == True
    assert library.add_book("Unknown Book", "Unknown Author", "Adventure", 2000) == False  # Invalid genre
    assert library.add_book("Future Book", "Sci-Fi Author", "Fiction", -50) == False       # Invalid year

    # Display all books and verify count
    print("\n--- Displaying All Books ---")
    all_books = library.display_books()
    assert len(all_books) == 4

    # Display Fiction books and verify count
    print("\n--- Displaying Fiction Books ---")
    fiction_books = library.display_fiction()
    assert len(fiction_books) == 1
    assert fiction_books[0].get_title() == "1984"

    # Delete books published before a certain year
    print("\n--- Deleting Old Books ---")
    deleted_count = library.delete_books_before_year(1900)
    assert deleted_count == 1

    # Display all books again to verify deletion
    print("\n--- Displaying All Books After Deletion ---")
    all_books_after_deletion = library.display_books()
    assert len(all_books_after_deletion) == 3


