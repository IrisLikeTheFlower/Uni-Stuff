#include <iostream>
#include <vector>
#include <algorithm>

class Book {
public:
    std::string name;
    int rating;
    int year;

    Book(std::string n, int r, int y) : name(n), rating(r), year(y) {}
};

bool compareByName(const Book& a, const Book& b) {
    return a.name < b.name;
}

bool compareByRating(const Book& a, const Book& b) {
    return a.rating > b.rating;
}

int main() {
    std::vector<Book> books;

    books.push_back(Book("Book3", 5, 2005));
    books.push_back(Book("Book1", 4, 2010));
    books.push_back(Book("Book2", 3, 2015));

    std::sort(books.begin(), books.end(), compareByName);

    std::cout << "Sorted by name:\n";
    for (const auto& book : books) {
        std::cout << book.name << " " << book.rating << " " << book.year << '\n';
    }

    std::sort(books.begin(), books.end(), compareByRating);

    std::cout << "\nSorted by rating:\n";
    for (const auto& book : books) {
        std::cout << book.name << " " << book.rating << " " << book.year << '\n';
    }

    int index;
    std::cout << "\n\n\nEnter index to output: ";
    std::cin >> index;

    try {
        Book book = books.at(index);
        std::cout << "Book at index " << index << ": " << book.name << " " << book.rating << " " << book.year << '\n';
    }
    catch (const std::out_of_range& ex) {
        std::cerr << "Out of range error: " << ex.what() << '\n';
    }


    return 0;
}
