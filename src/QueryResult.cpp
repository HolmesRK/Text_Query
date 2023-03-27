#include "QueryResult.h"
#include <cstddef>
#include <ostream>
#include <string>

std::string make_plural(size_t ctr, const std::string& word, const std::string& ending)
{
    return (ctr > 1) ? word + ending : word;
}

std::ostream& print(std::ostream& os, const QueryResult& qr)
{
    // 如果找到了单词，打印出现次数和所有出现位置
    os << qr.sought << " occurs " << qr.lines->size() << " "
       << make_plural(qr.lines->size(), "time", "s") << std::endl;
    // 打印单词出现的每一行
    for (auto num : *qr.lines) {
        os << "\t(line" << num + 1 << ") "
           << *(qr.file->begin() + num) << std::endl;
    }
    return os;
}