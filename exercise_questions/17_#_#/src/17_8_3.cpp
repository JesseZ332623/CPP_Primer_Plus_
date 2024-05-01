#include <MyLib/cinCheck.h>

#include <fstream>
#include <cstring>
#include <chrono>

/*
    TIMER                           计算一个函数的执行时间
*/
#define TIMER(Run) [&]() { \
    auto t1 = std::chrono::system_clock::now(); \
    Run; \
    auto t2 = std::chrono::system_clock::now(); \
    auto dt = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count(); \
    return dt; \
}()

#define WINDOWS_X86 true
#define LINUX_UBUNTU false 

/**
 * 从命令行中（即 argv[1] ~ argv[2] 中）获取文件路径，
 * 将路径 argv[1] 所指向的文件的内容拷贝到 argv[2] 的文件夹中去
 * 
 * 示例：
 * 
 * mycp ./a.txt ./data/ # 将 文件 a.txt 的内容拷贝到 ./data/ 目录下
 * mycp --help 输出帮助
 * mycp --version 输出版本号
*/

using namespace MyLib::MyLoger;

class FileCopyOperator
{
    public:
        using byte = unsigned char;

    private:
        const std::string version{"1.0.0"};
        const char osSpecificSlash = (WINDOWS_X86 ? '\\' : '/');
        static constexpr std::size_t bufferSize = 1024 * 1024;

        /**
         * @brief 字节缓冲区，以 1024 字节作为一段数据，避免单字节拷贝
        */
        byte byteBuffer[bufferSize];

        std::ifstream readFStream;
        std::ofstream writeFstream;

        std::size_t sourceFileByteCount{0ULL};

        /**
         * @brief 获取文件的格式（. 字符后面的所有字符）
         * 
         * @param __srcFile 文件名（但一般是路径）
         * 
         * @return 文件后缀名（如 .cpp .exe .txt 等）
        */
        std::string getFileType(const std::string & __srcFile);

        /**
         * @brief __srcFile 去除掉一个文件路径的所有路径名（如把 ./data/test.txt 变成 test.txt）【明天完成】
         * 
         * @param __srcFile 文件名（但一般是路径）
         * 
         * @return 不带路径的文件名
        */
        std::string getFileName(const std::string & __srcFile);

        /**
         * @brief 对文件路径的斜杠进行正反切换，以适应不同的操作系统。
         * 
         * @param __path    文件路径
         * @param __state   斜杠状态，使用 FOWARD 还是 BACKWARD
         * 
         * @return non-return
        */
        void forwardBackwardSwitch(std::string & __path);
    
    public:
        /**
         * @brief 输出版本号。
        */
        void showVersion(void) 
        { 
            printSplitLine(45, '-');
            WARNING_LOG("Software version: " + version + '\n'); 
            printSplitLine(45, '-');
        }

        /**
         * @brief 输出帮助信息
        */
        void showHelp(void) 
        {
            printSplitLine(65, '-');

            loger(
                std::clog, NOTIFY,
                "Usage:\n",
                "mycp --help     Get help info.\n",
                "mycp --version  Get version.\n",
                "mycp [sorce file] [target path] Copy sorce file to target path.\n"
            );

            printSplitLine(65, '-');
        }

        void copyFile(std::string __srcFile, std::string __tarFile);

        ~FileCopyOperator() 
        {   
            this->readFStream.clear();
            this->writeFstream.clear();
            this->readFStream.close();
            this->writeFstream.close();
        }
};

void FileCopyOperator::forwardBackwardSwitch(std::string & __path)
{
    /*
        若在 __srcFile 中没有找到 / 或 \ 字符，
        则代表它可能是一个纯文件，或者非法字符串，直接原路返回就好。
    */
    if ((__path.find('/') == __path.npos) && (__path.find('\\') == __path.npos)) { return; }

    std::replace(__path.begin(), __path.end(), '/', osSpecificSlash);
    std::replace(__path.begin(), __path.end(), '\\', osSpecificSlash);
}

std::string FileCopyOperator::getFileType(const std::string & __srcFile)
{
    /*获取 . 字符第一次出现在字符串 __srcFile 中的位置。*/
    std::size_t dotPos = __srcFile.find('.');

    /*在确保字符串 __srcFile 有 . 字符的情况下 */
    if (dotPos != __srcFile.npos)
    {
        /*分割 . 字符后面的所有字符，并返回*/
        return __srcFile.substr(dotPos + 1);
    }
    else { return ""; } // 在 __srcFile 找不到 . 字符就返回空字符
}

std::string FileCopyOperator::getFileName(const std::string & __srcFile)
{
    // 查找最后一个 '/' 或 '\' （由于已使用 forwardBackwardSwitch 统一过，此处可只查找 '/'
    std::size_t pathPos = __srcFile.rfind('\\');

    // 若找不到 '/'，则返回空字符串
    if (pathPos == std::string::npos) { return ""; }

    // 分割最后一个 '/' 后面的所有字符，并返回
    return __srcFile.substr(pathPos + 1);
}

void FileCopyOperator::copyFile(std::string __srcFile, std::string __tarPath)
{
    this->forwardBackwardSwitch(__srcFile);
    this->forwardBackwardSwitch(__tarPath);

    /*由于可能传入的非法字符，所以需要有异常机制*/
    try
    {
        /*打开要被复制的文件*/
        this->readFStream.open(__srcFile, std::ios_base::binary);

        if (!this->readFStream.is_open()) 
        { 
            throw std::runtime_error(__srcFile + " is not exist!\n");
        }

        /*
            将要被复制的文件和要被复制到的路径组成新的文件路径，
            如 ./data/The_Art_of_Patience.txt 或 .\data\The_Art_of_Patience.txt
        */
       std::string targetFile;
        if (*(__tarPath.end() - 1) == this->osSpecificSlash)
            targetFile = (__tarPath + this->getFileName(__srcFile));
        else 
            targetFile = (__tarPath + this->osSpecificSlash + this->getFileName(__srcFile));

        loger(
                std::cout, NOTIFY,
                "Copy [", __srcFile, "] to [", targetFile, "]\n"
        );

        /*打开 或 创建（在目标文件不存在的情况下）targetFile*/
        this->writeFstream.open(targetFile, std::ios_base::out | std::ios_base::binary);

        if (!this->writeFstream.is_open())
        {
            throw std::runtime_error("Failed to open the target file: " + targetFile + '\n');
        }

        /*当没有读到源文件末尾时*/
        while (!this->readFStream.eof())
        {
            /*从源文件挖 bufferSize 字节的数据到 byteBuffer*/
            readFStream.read(reinterpret_cast<char *>(&this->byteBuffer), this->bufferSize);
            std::streamsize bytesRead = readFStream.gcount();   // 确定一共读了多少字节的数据，避免文件本身比缓冲区还小的情况。

            /*把 缓冲区内的数据全部写入目标文件*/
            writeFstream.write(reinterpret_cast<char *>(&this->byteBuffer), bytesRead);

            /*写入字节数累加*/
            this->sourceFileByteCount += bytesRead;

            if (readFStream.eof()) { break; }
        }

        loger(
                std::cout, NOTIFY,
                "Total byte of", __srcFile, " = ", this->sourceFileByteCount, " Bytes.\n"
        );
    }
    catch (const std::exception & __except)
    {
        ERROR_LOG(__except.what());
    }

}

/**
 * @brief 检查那些无效的命令行参数输入，
 *        在 argc 为 1（没有参数）以及大于 3（参数过多）时，返回 false
 * 
 * @param __argCount    参数数量
 * 
 * @return 命令行参数数量是否合理
*/
bool checkInvalidArgc(const int __argCount) { return (__argCount == 1) || (__argCount > 3); };

int main(int argc, char const *argv[])
{
    system("cls");

    FileCopyOperator FileCopyOp;

    if (checkInvalidArgc(argc)) { ERROR_LOG("Not or invalid argument!\n"); FileCopyOp.showHelp(); }

    else if ((std::strcmp(argv[1], "--help") == 0) && argc == 2) { FileCopyOp.showHelp(); }

    else if ((std::strcmp(argv[1], "--version") == 0) && argc == 2) { FileCopyOp.showVersion(); }

    else if (argc == 3) 
    {   
        int64_t costTime = TIMER( FileCopyOp.copyFile(argv[1], argv[2]));

        loger(
            std::cout, NOTIFY,
            "Copy cost ", costTime, " ms.\n"
        ); 
    }

    else 
    {
        ERROR_LOG("Invalid argument!\n"); 
        FileCopyOp.showHelp();
    }


    DONE
    return EXIT_SUCCESS;
}
