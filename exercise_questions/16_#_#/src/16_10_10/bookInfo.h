#ifndef _BOOK_INFO_H_
#define _BOOK_INFO_H_

#include <string>
#include <memory>
#include <vector>
#include <cstring>
#include <MyLib/myLib.h>

/**
 * @brief 一本书的属性，由：书名，书的评价，书价 三个值组成。
*/
typedef struct __Book_Review
{
    private:
        std::string title;
        unsigned int rating;
        float price;

    public:
        /**
         * @brief 用来指定排序的升降序。
         * 
         * 1. ASCENDING     升序
         * 2. DESCENDING    降序
        */
        enum Sequence { ASCENDING = 0, DESCENDING };

        /**
         * @brief 用户往 __Book_Review 输入数据。
         * 
         * @return non-return
        */
        bool fillReview(void);

        /**
         * @brief 和另一个 __Book_Review 结构体进行 title 上的比较，
         *        用于 std::sort() 排序算法。
         * 
         * @param __bookReview 另一个 __Book_Review 结构体实例
         * 
         * @return 比较结果 true（a > b）false（a < b）
        */
        bool titleCompare(const __Book_Review & __bookReview, Sequence __seq) const;

        /**
         * @brief 和另一个 __Book_Review 结构体进行 rating 上的比较，
         *        用于 std::sort() 升序排序算法。
         * 
         * @param __bookReview 另一个 __Book_Review 结构体实例
         * 
         * @return 比较结果 true（a > b）false（a < b）
        */
        bool ratingCompare(const __Book_Review & __bookReview, Sequence __seq) const;

        /**
         * @brief 和另一个 __Book_Review 结构体进行 price 上的比较，
         *        用于 std::sort() 升序排序算法。
         * 
         * @param __bookReview 另一个 __Book_Review 结构体实例
         * 
         * @return 比较结果 true（a > b）false（a < b）
        */
        bool priceCompare(const __Book_Review & __bookReview, Sequence __seq) const;

        /**
         * @brief 往标准输出发送该结构体的数据流。
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
    public:
        /**
         * 数据的显示模式枚举，有以下 6 种：
         * 1. IN_ORIGINAL_VECTOR_ORDER          按原始数组顺序显示
         * 2. IN_ALPHABETICAL_ORDER             按字母表顺序显示
         * 3. IN_ASCENDING_ORDER_OF_RATINGS     按评级升序显示
         * 4. IN_DESSCENDING_ORDER_OF_RATINGS   按评级降序显示
         * 5. IN_ASCENDING_PRICE_ORDER          按价格升序显示
         * 6. IN_DESCENDING_PRICE_ORDER         按价格降序显示
        */
        enum Display_Mode 
        { 
            IN_ORIGINAL_VECTOR_ORDER = 0,       // 按原始数组顺序显示
            IN_ALPHABETICAL_ORDER,              // 按字母表顺序显示
            IN_ASCENDING_ORDER_OF_RATING,       // 按评级升序显示
            IN_DESSCENDING_ORDER_OF_RATING,     // 按评级降序显示
            IN_ASCENDING_PRICE_ORDER,           // 按价格升序显示
            IN_DESCENDING_PRICE_ORDER           // 按价格降序显示
        };
    private:
        /**
         * @brief 存储 n 本属性的容器，
         *        应题目要求，容器内的每一个元素都是 `std::shared_ptr<Book_Review>` 类型。
        */
        std::vector<std::shared_ptr<Book_Review>> booksLibrary;

        /**
         * @brief 往 标准输出发送数据说明。
         * 
         * @param __os C++ 标准输出流
         * 
         * @return non-return
        */
        void bookInfoDescribe(std::ostream & __os);

        /**
         * @brief 单次输出容器内数据时调用的函数，具备高复用性。
         * 
         * @param __os          C++ 标准输出流
         * @param __tempLibary  临时容器
         * 
         * @return non-return
        */
        void modeDisplay(std::ostream & __os, const std::vector<std::shared_ptr<Book_Review>> & __tempLibary) const;

    public:

        /**
         * @brief 获取内部容器当前元素数。
        */
        std::size_t getLibrarySize(void) { return booksLibrary.size(); }

        /**
         * @brief 清空整个 booksLibrary 容器。
        */
        void clearCointer(void) { this->booksLibrary.clear(); }
        
        /**
         * @brief 用户往整个 booksLibrary 智能指针矢量中输入数据。
         * 
         * @return non-return
        */
        void fillLibraryReview(void);

        /**
         * @brief 按照不同的输出模式，往标准输出发送指定格式的容器数据。
         * 
         * @param __os          C++ 标准输出流
         * @param __displayMode 输出模式，默认为 按原始数组顺序显示
         * 
         * @return non-return
        */
        void displayBooksLibrary(std::ostream & __os, int __displayMode = IN_ORIGINAL_VECTOR_ORDER);
};

#endif // _BOOK_INFO_H_