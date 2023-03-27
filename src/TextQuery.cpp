#include "TextQuery.h"
#include "QueryResult.h"
#include <fstream>
#include <memory>
#include <set>
#include <sstream>
#include <string>
#include <vector>

// 构造函数，读取输入文件并建立单词到行号的映射
TextQuery::TextQuery(std::ifstream& is)
    : file(new std::vector<std::string>)
{
    std::string text;
    while (std::getline(is, text)) {
        file->push_back(text);
        unsigned n = file->size() - 1;
        std::istringstream line(text);
        std::string word;
        while (line >> word) {
            // 如果单词不在wm中，以之为下标在wm中添加一项
            auto& lines = wm[word];
            if (!lines) {
                lines.reset(new std::set<line_no>);
            }
            lines->insert(n);
        }
    }
}


QueryResult TextQuery::query(const std::string& sought) const
{
    // 如果未找到sought，我们返回一个指向此set的指针
    static std::shared_ptr<std::set<line_no>> nodata(new std::set<line_no>);
    // 使用find而不是下标运算符来查找单词，避免将单词添加到wm中
    auto loc = wm.find(sought);
    if (loc == wm.end()) {
        return QueryResult(sought, nodata, file);
    }
    return QueryResult(sought, loc->second, file);
}