#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

typedef struct _Review
{
    std::string _title;
    int _rating;

} Review;

bool Fill_Review(Review & _r_view);

void Show_Review(const Review & _r_view);

void print_line(const char _ch, size_t _length);

int main(int argc, char const *argv[])
{
    using std::printf, std::vector;

    vector<Review> _books;
    vector<Review> _old_list;
    vector<Review>::iterator _books_iter;
    size_t _books_size = 0;

    Review _temp;

    while (Fill_Review(_temp)) { _books.push_back(_temp); }

    if ((_books_size = _books.size()) > 0)
    {
        system("cls");
        printf("Thank you! You Enter The Following:\n");
        for (auto & index : _books)     /*for each loop (-std = C++11)*/
        {
            printf("<%s>:\tRating %d\n", index._title.c_str(), index._rating);
        }
        print_line('-', 30);
        for (_books_iter = _books.begin(); _books_iter != _books.end(); ++_books_iter)  /*for loop with iterator*/
        {
            Show_Review(*_books_iter);
        }
        print_line('-', 30);
        for (int index = 0; index < _books_size; ++index)       /*for loop with counter*/
        {
            Show_Review(_books[index]);
        }
        print_line('-', 30);
        _old_list = _books;
        if (_books_size > 3)
        {
            printf("delete book if rating = 6\n");
            for (_books_iter = _books.begin(); _books_iter != _books.end(); ++_books_iter)
            {
                _books.erase(std::remove_if(_books.begin(), _books.end(), [](const Review & _r_view) { return _r_view._rating == 6; }) , _books.end());
            }

            _books_size = _books.size();
            printf("Now the contence of vector _books:\n");
            for (int index = 0; index < _books_size; ++index)       /*for loop with counter*/
            {
                Show_Review(_books[index]);
            }
            print_line('-', 30);
        }

        printf("swap _old_list to _books:\n");
        _books.swap(_old_list);
        for (auto & index : _books)     /*for each loop (-std = C++11)*/
        {
            printf("<%s>:\tRating %d\n", index._title.c_str(), index._rating);
        }
        print_line('-', 30);
    }

    puts("Done.");
    
    return EXIT_SUCCESS;
}

bool Fill_Review(Review & _r_view)
{
    printf("Enter Book Title (press q to quit): ");
    std::getline(std::cin, _r_view._title);

    if (_r_view._title == "quit" || _r_view._title == "Quit") { return false; }

    printf("Enter Book Rating (0 - 10): ");
    if(!scanf("%d", &_r_view._rating)) { return false; }

    if (_r_view._rating > 10) { _r_view._rating = 10; }
    else if (_r_view._rating < 0) { _r_view._rating = 0; }

    while (getchar() != '\n') { continue; }

    return true;
}

void Show_Review(const Review & _r_view)
{
    printf("<%s>:\tRating %d\n", _r_view._title.c_str(), _r_view._rating);
    
    //std::cout << _r_view._title << '\t' << _r_view._rating;
}

void print_line(const char _ch, size_t _length)
{
    for (int _len = 0; _len < _length; ++_len)
    {
        std::putchar(_ch);
    }
    std::putchar('\n');
}