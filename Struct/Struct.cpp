

#include <iostream>
#include <string>

struct Book {
    std::string bookName;
    std::string authorName;
    int* reviews;
    int sizeOfReviewsArray;

    void allocate(std::string bName, std::string aName, int size) {
        bookName = bName;
        authorName = aName;
        sizeOfReviewsArray = size;
        reviews = new int[sizeOfReviewsArray];
    }

    void print() {
        std::cout << "Book Name: " << bookName << "\n";
        std::cout << "Author Name: " << authorName << "\n";
        std::cout << "Reviews: ";
        for (int i = 0; i < sizeOfReviewsArray; i++) {
            std::cout << reviews[i] << " ";
        }
        std::cout << "\n";
    }

    float averageReview() {
        int sum = 0;
        for (int i = 0; i < sizeOfReviewsArray; i++) {
            sum += reviews[i];
        }
        return (float)sum / sizeOfReviewsArray;
    }

    void deallocate() {
        delete[] reviews;
    }
};

int countWords(std::string str) {
    int count = 0;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == ' ') {
            count++;
        }
    }
    return count + 1;
}

int main() {
    int n;
    std::cout << "Enter the number of books: ";
    std::cin >> n;
    Book* books = new Book[n];

    for (int i = 0; i < n; i++) {
        std::string bName, aName;
        int rSize;
        std::cout << "Enter book name for book " << i+1 << ": ";
        getline(std::cin, bName);
        std::cin.ignore();

        std::cout << "Enter author name for book " << i+1 << ": ";
        getline(std::cin, aName);
        std::cin.ignore();

        std::cout << "Enter number of reviews for book " << i+1 << ": ";
        std::cin >> rSize;


        books[i].allocate(bName, aName, rSize);
        std::cout << "Enter the reviews: ";
        for (int j = 0; j < rSize; j++) {
            std::cin >> books[i].reviews[j];
        }
        std::cin.ignore();
    }

    for (int i = 0; i < n; i++) {
        books[i].print();
    }

    for (int i = 0; i < n; i++) {
        std::cout << "Number of words in book name '" << books[i].bookName << "': " << countWords(books[i].bookName) << "\n";
    }

    float maxAvg = 0;
    int maxIndex = 0;
    for (int i = 0; i < n; i++) {
        float avg = books[i].averageReview();
        if (avg > maxAvg) {
            maxAvg = avg;
            maxIndex = i;
        }
    }
    std::cout << "Index of book with greatest average review: " << maxIndex << "\n";

    for (int i = 0; i < n; i++) {
        books[i].deallocate();
    }

    delete[] books;

    return 0;
}