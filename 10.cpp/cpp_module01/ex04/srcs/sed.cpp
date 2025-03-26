#include "../inc/sed.hpp"

static std::string replace(std::string line, int pos, int srclen, std::string convert);

Sed::Sed(const std::string &fname, const std::string &src, const std::string &dest)
:_fname(fname), _src(src), _dest(dest)
{
}

void    Sed::program(void)
{
    std::ifstream &input = _fname.getSrc();
    std::ofstream &output = _fname.getDest();
    std::string line;

    int srclen = _src.length();

    while (getline(input, line))
    {
        size_t pos = line.find(_src);
        while ((pos = line.find(_src)) != std::string::npos)
        {
            line = replace(line, pos, srclen, _dest);
            pos += _dest.length();
        }
        output << line << std::endl;
    }

}

static std::string replace(std::string line, int pos, int srclen, std::string _dest)
{
    line.erase(pos, srclen);
    line.insert(pos, _dest);
    return (line);
}
