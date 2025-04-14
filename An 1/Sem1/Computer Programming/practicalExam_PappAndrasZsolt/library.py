class Book:
    def __init__(self, title, author, genre, year):
        self._title = title
        self._author = author
        self._genre = genre
        self._year = year

    def get_title(self):
        return self._title          ## CRUD OPERATIONS

    def set_title(self, title):
        self._title = title

    def get_author(self):
        return self._author

    def set_author(self, author):
        self._author = author

    def get_genre(self):
        return self._genre

    def set_genre(self, genre):
        self._genre = genre

    def get_year(self):
        return self._year

    def set_year(self, year):
        self._year = year

    def __repr__(self):
        return f"Book(title={self._title}, author={self._author}, genre={self._genre}, year={self._year})"

class Library:
    correct_genre = ["Fiction", "Romance", "Science"]

    def __init__(self):
        self.books = []

    def add_book(self, title, author, genre, year):
        if year <= 0:               ## CHECK IF CORRECT GENRE OR POSITIVE YEAR
            return False
        if genre not in Library.correct_genre:
            return False
        book = Book(title, author, genre, year)
        self.books.append(book)
        return True

    def delete_books_before_year(self, year):
        initial_count = len(self.books)
        self.books = [book for book in self.books if book.get_year() >= year] ## Remake list with books only surpassing the year
        return initial_count - len(self.books)

    def display_fiction(self):
        fiction_books = sorted(
            [book for book in self.books if book.get_genre() == "Fiction"], ## Only getting fiction books
            key=lambda x: x.get_year()      ## Using lambda to sort by year
        )
        for book in fiction_books:
            print(book)
        return fiction_books

    def display_books(self):
        for book in self.books:
            print(book)
        return self.books