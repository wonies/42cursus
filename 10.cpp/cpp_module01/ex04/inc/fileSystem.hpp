#include <fstream>
#include <iostream>

class FileSystem
{
private:
    std::ifstream srcFile;
    std::ofstream destFile;
public:
    FileSystem(const std::string &fname);
    ~FileSystem();
    std::ifstream &getSrc();
    std::ofstream &getDest();
};