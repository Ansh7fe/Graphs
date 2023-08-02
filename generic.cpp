#include <iostream>
#include <list>
#include <string>

using namespace std;

class Book {
public:
    string name;
    int price;

    Book() {}

    Book(string name, int price) {
        this->name = name;
        this->price = price;
    }
};

class BookCompare {
public:
    bool operator()(const Book& A, const Book& B) {
        cout << "Inside the compare function" << endl;
        if (A.name == B.name)
            return true;
        return false;
    }
};

int main() {
    Book b1("c++", 100);
    Book b2("python", 120);
    Book b3("java", 130);

    list<Book> l;
    l.push_back(b1);
    l.push_back(b2);
    l.push_back(b3);

    Book bookToFind("c++", 110);

    BookCompare cmpre;
    if (cmpre(b1, bookToFind)) {
        cout << "Same books" << endl;
    }

    return 0;
}
