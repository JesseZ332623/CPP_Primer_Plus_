#include "./bookInfo.h"

bool __Book_Review::operator<(const __Book_Review & __bookReview)
{
    if (this->title < __bookReview.title) { return true; }

    else if (this->title == __bookReview.title && this->rating < __bookReview.rating) { return true; }

    else { return false; } 
}

bool __Book_Review::ratingCompare(const __Book_Review & __bookReview)
{
    if (this->rating < __bookReview.rating) { return true; }

    return false;
}

std::ostream & operator<<(std::ostream & __os, __Book_Review & __bookReview)
{
    using MyLib::MyDelay::delay;
    
    __os.width(15);
    __os.setf(std::ios_base::left);

    __os << __bookReview.rating;        __os.width(15);     delay(45);
    __os << __bookReview.title;         __os.width(15);     delay(45);
    __os << __bookReview.price << std::endl;

    return __os;
}

bool __Book_Review::fillReview(void)
{
    using namespace MyLib::MyLoger;

    loger(std::cout, NOTIFY, "Enter book title (Press quit to QUIT): ");
    std::getline(std::cin, this->title);

    if (this->title == "quit") { return false; }

    loger(std::cout, NOTIFY, "Enter book rating: ");
    std::cin >> this->rating;

    if (!std::cin) { return false; }

    loger(std::cout, NOTIFY, "Enter book price: ");
    std::cin >> this->price;

    if (!std::cin) { return false; }

    while (std::cin.get() != '\n') { continue; }

    return true;
}

void Book_Infomation_Storage::bookInfoDescribe(std::ostream & __os)
{
    //__os.width(15);
    //__os.setf(std::ios_base::left);

    __os << "Rating";   __os.width(15);
    __os << "Name";     __os.width(20);
    __os << "Price\n";    

    MyLib::MyLoger::printSplitLine(45, '-');
}

void Book_Infomation_Storage::fillLibraryReview(void)
{
    using namespace MyLib::MyLoger;

    Book_Review tempReview;
    std::size_t bookCount = 1L;

    loger(std::cout, NOTIFY, "Recording No.", bookCount++, " books.\n");
    while (tempReview.fillReview())
    {
        this->booksLibrary.push_back(std::shared_ptr<Book_Review>(new Book_Review(tempReview)));

        loger(std::cout, NOTIFY, "Recording No.", bookCount++, " books.\n");
    }
}

void Book_Infomation_Storage::displayBooksLibrary(std::ostream & __os)
{
    bookInfoDescribe(__os);
    std::for_each(
                    booksLibrary.begin(), booksLibrary.end(), 
                    [& __os] (const std::shared_ptr<Book_Review> & __reviewPtr) 
                    {
                        __os << *__reviewPtr;
                        MyLib::MyDelay::delay(45);
                    }
                 );
}

int main(int argc, char const *argv[])
{
    using namespace MyLib::MyLoger;

    system("cls");

    Book_Infomation_Storage bookLib;

    bookLib.fillLibraryReview();

    bookLib.displayBooksLibrary(std::cout);

    DONE;
    return EXIT_SUCCESS;
}
