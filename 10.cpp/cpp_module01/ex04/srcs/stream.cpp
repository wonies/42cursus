#include "../inc/fileSystem.hpp"

FileSystem::FileSystem(const std::string &fname)
{
    // std::ifstream srcFile(fname.c_str());
    // srcFile.open(fname.c_str());
    srcFile.open(fname);
    if (!srcFile.is_open())
    {
        std::cerr << "NOT OPENED" << std::endl;
        std::exit(2);
    }
    std::string newFile = fname + ".replace";
    destFile.open(newFile);
    if (!destFile.is_open())
        std::cerr << "File cannot be opened" << std::endl;
}

FileSystem::~FileSystem()
{
    if (srcFile.is_open())
        srcFile.close();
    if (destFile.is_open())
        destFile.close();
}

std::ifstream &FileSystem::getSrc()
{
    return (srcFile);
}

std::ofstream &FileSystem::getDest()
{
    return (destFile);
}
