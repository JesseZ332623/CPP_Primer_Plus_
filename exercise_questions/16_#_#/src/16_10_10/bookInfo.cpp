#include "./bookInfo.h"

bool __Book_Review::titleCompare(const __Book_Review & __bookReview, Sequence __seq) const
{
    if (__seq == ASCENDING)
    {
        return this->title < __bookReview.title;
    }
    else if (__seq == DESCENDING)
    {
        return this->title > __bookReview.title;
    }
    
    return false;
}

bool __Book_Review::ratingCompare(const __Book_Review & __bookReview, Sequence __seq) const
{
    if (__seq == ASCENDING)
    {
        return this->rating < __bookReview.rating;
    }
    else if (__seq == DESCENDING)
    {
        return this->rating > __bookReview.rating;
    }

    return false;
}

bool __Book_Review::priceCompare(const __Book_Review & __bookReview, Sequence __seq) const
{
    if (__seq == ASCENDING)
    {
        return this->price < __bookReview.price;
    }
    else if (__seq == DESCENDING)
    {
        return this->price > __bookReview.price;
    }

    return false;
}

std::ostream & operator<<(std::ostream & __os, __Book_Review & __bookReview)
{
    using MyLib::MyDelay::delay;

    __os.setf(std::ios_base::left); 
    __os.width(15);
    __os << __bookReview.rating;            
    delay(45); 

    __os.width(45); 
    __os << __bookReview.title;   
    delay(45);

    __os.precision(5); 
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

    loger(std::cout, NOTIFY, "Enter book price $: ");
    std::cin >> this->price;

    if (!std::cin) { return false; }

    while (std::cin.get() != '\n') { continue; }

    return true;
}

void Book_Infomation_Storage::bookInfoDescribe(std::ostream & __os)
{
    __os.width(15); __os.setf(std::ios_base::left); // 添加左对齐设置

    __os << "Rating";
    __os.width(45); __os << "Name";    
    __os.width(5);  __os << "Price$";               

    __os << std::endl;                                   // 替换为单独的换行符，避免干扰列宽度设置

    MyLib::MyLoger::printSplitLine(80, '-');
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

void Book_Infomation_Storage::modeDisplay(std::ostream & __os, const std::vector<std::shared_ptr<Book_Review>> & __tempLibary) const
{
    std::for_each(
                    __tempLibary.begin(), __tempLibary.end(), 
                    [& __os] (const std::shared_ptr<Book_Review> & __reviewPtr) 
                    {
                        __os << *__reviewPtr;
                        MyLib::MyDelay::delay(45);
                    }
                );
    MyLib::MyLoger::printSplitLine(80, '-');
}

void Book_Infomation_Storage::displayBooksLibrary(std::ostream & __os, int __displayMode)
{
    using namespace MyLib::MyLoger;

    system("cls");

    loger(__os, NOTIFY, "OK! Show booksLibrary content ");
    std::vector<std::shared_ptr<Book_Review>> tempLibary(this->booksLibrary);

    switch (__displayMode)
    {
        case IN_ORIGINAL_VECTOR_ORDER:
            loger(__os, CORRECT, "[IN_ORIGINAL_VECTOR_ORDER Mode]: \n");
            bookInfoDescribe(__os);
            modeDisplay(__os, booksLibrary);
            break;

        case IN_ALPHABETICAL_ORDER:
            std::sort(
                        tempLibary.begin(), tempLibary.end(),
                        [](const auto & a, const auto & b) { return a->titleCompare(*b, Book_Review::ASCENDING); }
                    );
            loger(__os, CORRECT, "[IN_ALPHABETICAL_ORDER Mode]: \n");
            bookInfoDescribe(__os);
            modeDisplay(__os, tempLibary);

            break;

        case IN_ASCENDING_ORDER_OF_RATING:
            std::sort(
                        tempLibary.begin(), tempLibary.end(),
                        [](const auto & a, const auto & b) { return a->ratingCompare(*b, Book_Review::ASCENDING); }
                    );
            loger(__os, CORRECT, "[IN_ASCENDING_ORDER_OF_RATINGS Mode]: \n");
            bookInfoDescribe(__os);
            modeDisplay(__os, tempLibary);

            break;  

        case IN_DESSCENDING_ORDER_OF_RATING:
            std::sort(
                        tempLibary.begin(), tempLibary.end(),
                        [](const auto & a, const auto & b) { return a->ratingCompare(*b, Book_Review::DESCENDING); }
                    );
            loger(__os, CORRECT, "[IN_DESSCENDING_ORDER_OF_RATINGS Mode]: \n");
            bookInfoDescribe(__os);
            modeDisplay(__os, tempLibary);

            break;

        case IN_ASCENDING_PRICE_ORDER:
            std::sort(
                        tempLibary.begin(), tempLibary.end(),
                        [](const auto & a, const auto & b) { return a->priceCompare(*b, Book_Review::ASCENDING); }
                    );
            loger(__os, CORRECT, "[IN_ASCENDING_PRICE_ORDER Mode]: \n");
            bookInfoDescribe(__os);
            modeDisplay(__os, tempLibary);
            break;

        case IN_DESCENDING_PRICE_ORDER:
            std::sort(
                        tempLibary.begin(), tempLibary.end(),
                        [](const auto & a, const auto & b) { return a->priceCompare(*b, Book_Review::DESCENDING); }
                    );
            loger(__os, CORRECT, "[IN_DESCENDING_PRICE_ORDER Mode]: \n");
            bookInfoDescribe(__os);
            modeDisplay(__os, tempLibary);
            break;

        default:
            ERROR_LOG("Unknow options!\n");
            break;
    };
}