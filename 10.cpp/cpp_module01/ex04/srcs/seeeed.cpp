#include <iostream>
#include <fstream>

/*
replace : 시작 위치 , 치환할 길이, 치환문자

*/

std::string replace(std::string line, int pos, int srclen, std::string convert)
{
    line.erase(pos, srclen);
    line.insert(pos, convert);
    
    return line;
}

void program(const std::string &filename, const std::string &s1, const std::string &s2)
{
    std::string newFile = filename + ".replace";
    std::ifstream srcFile(filename);
    std::ofstream destFile(newFile);

    int srclen = s1.length();

    if (srcFile.is_open())
    {
        std::string line;
        int index;
        
        if (!destFile.is_open())
        {
            std::cerr << "File cannot be opened." << std::endl;
            return ;
        }
        while (getline(srcFile, line))
        {   
            size_t pos = line.find(s1);
            while ((pos = line.find(s1)) != std::string::npos)
            {
                std::cout << "find line\t" << line.find(s1) << std::endl;
                line  = replace(line, pos, srclen, s2);
                pos += s2.length();
            }
            destFile << line << std::endl;
        }
    }
    else
    {
        std::cerr << "File cannot be opened." << std::endl;
    }
    
    srcFile.close();
    destFile.close();
}


int main(void)
{
    program("wonie", "wonie", "konie");
    // program("konie", "konie", "wonie");
    // program("error", "err", "e");
}