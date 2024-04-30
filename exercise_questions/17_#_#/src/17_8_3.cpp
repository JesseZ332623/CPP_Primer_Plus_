#include <MyLib/cinCheck.h>

#include <fstream>
#include <cstring>

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
        static constexpr std::size_t bufferSize = 128;

        /**
         * @brief 字节缓冲区，以 128 字节作为一段数据，避免单字节拷贝
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

        void copyFile(const std::string __srcFile, const std::string __tarFile);

        ~FileCopyOperator() 
        {   
            this->readFStream.clear();
            this->writeFstream.clear();
            this->readFStream.close();
            this->writeFstream.close();
        }
};

std::string FileCopyOperator::getFileType(const std::string & __srcFile)
{
    std::size_t dotPos = __srcFile.find('.');

    if (dotPos != __srcFile.npos)
    {
        return __srcFile.substr(dotPos + 1);
    }
    else { return ""; }
}

void FileCopyOperator::copyFile(const std::string __srcFile, const std::string __tarPath)
{
    try
    {
        /*打开要被复制的文件*/
        this->readFStream.open(__srcFile, std::ios_base::binary);

        if (!this->readFStream.is_open()) 
        { 
            throw std::runtime_error(__srcFile + " is not exist!\n");
        }

        /*
            将要被复制的文件和要被复制到的路径组成新的文件名，
            如 ./data/a.txt
        */
        std::string targetFile = __tarPath + '/' + __srcFile + '.' + getFileType(__srcFile);

        this->writeFstream.open(targetFile, std::ios_base::out | std::ios_base::binary);

        if (!this->writeFstream.is_open())
        {
            throw std::runtime_error("Failed to open the target file: " + targetFile + '\n');
        }

        while (!this->readFStream.eof())
        {
            readFStream.read(reinterpret_cast<char *>(&this->byteBuffer), this->bufferSize);
            std::streamsize bytesRead = readFStream.gcount();

            writeFstream.write(reinterpret_cast<char *>(&this->byteBuffer), bytesRead);
            this->sourceFileByteCount += bytesRead;

            if (readFStream.eof()) { break; }
        }
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

    else if (argc == 3) { FileCopyOp.copyFile(argv[1], argv[2]); }

    else 
    {
        ERROR_LOG("Not or invalid argument!\n"); 
        FileCopyOp.showHelp();
    }


    DONE
    return EXIT_SUCCESS;
}
