#ifndef _BOOK_INFO_H_
#define _BOOK_INFO_H_

#include <string>
#include <memory>
#include <vector>
#include <cstring>
#include <MyLib/myLib.h>

/**
 * @brief 一本书的属性，由：书名，书的评价，书价 三个值组成
*/
typedef struct __Book_Review
{
    private:
        std::string title;
        unsigned int rating;
        float price;

    public:
        /**
         * @brief 用户往 __Book_Review 输入数据
         * 
         * @return non-return
        */
        bool fillReview(void);

        /**
         * @brief 和另一个 __Book_Review 结构体进行 title 和 rating 上的比较，
         *        用于 std::sort() 升序排序算法。
         * 
         * @param __bookReview 另一个 __Book_Review 结构体实例
         * 
         * @return 比较结果 true（a > b）false（a < b）
        */
        bool operator<(const __Book_Review & __bookReview);

        /**
         * @brief 和另一个 __Book_Review 结构体进行 rating 上的比较，
         *        用于 std::sort() 升序排序算法。
         * 
         * @param __bookReview 另一个 __Book_Review 结构体实例
         * 
         * @return 比较结果 true（a > b）false（a < b）
        */
        bool ratingCompare(const __Book_Review & __bookReview);

        /**
         * @brief 往标准输出发送该结构体的数据流
         * 
         * @param __os C++ 标准输出流
         * @param __bookReview __Book_Review 结构体实例
         * 
         * @return C++ 标准输出流，用于链式调用
        */
        friend std::ostream & operator<<(std::ostream & __os, __Book_Review & __bookReview);

} Book_Review;

/**
 * @brief 对书的存储与操作类
*/
class Book_Infomation_Storage
{
    private:
        std::vector<std::shared_ptr<Book_Review>> booksLibrary;

        void bookInfoDescribe(std::ostream & __os);

    public:
        /**
         * @brief 用户往整个 booksLibrary 智能指针矢量中输入数据
         * 
         * @return non-return
        */
        void fillLibraryReview(void);

        void displayBooksLibrary(std::ostream & __os);
};

#endif // _BOOK_INFO_H_