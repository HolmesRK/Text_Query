#pragma onec
#ifndef TEXTQUERY_H
#define TEXTQUERY_H


#include <fstream>
#include <map>
#include <memory>
#include <set>
#include <string>
#include <vector>
class QueryResult;
class TextQuery {
public:
    using line_no = std::vector<std::string>::size_type;

    // 构造函数，读取输入文件并建立单词到行号的映射
    explicit TextQuery(std::ifstream&);

    [[nodiscard]] QueryResult query(const std::string&) const;

private:
    // 输入文件
    std::shared_ptr<std::vector<std::string>> file;
    // 每个单词到它所在的行号的集合的映射
    std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;
};


#endif