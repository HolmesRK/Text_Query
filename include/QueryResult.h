#pragma onec
#ifndef QUERYRESULT_H
#define QUERYRESULT_H


#include <memory>
#include <ostream>
#include <set>
#include <string>
#include <vector>
class QueryResult {
    friend std::ostream& print(std::ostream&, const QueryResult&);

public:
    using line_no = std::vector<std::string>::size_type;

    QueryResult(std::string s, std::shared_ptr<std::set<line_no>> p, std::shared_ptr<std::vector<std::string>> f)
        : sought(s)
        , lines(p)
        , file(f)
    {
    }

private:
    std::string sought;                                 // 查询单词
    std::shared_ptr<std::set<line_no>> lines;           // 出现的行号
    std::shared_ptr<std::vector<std::string>> file;     //输入文件
};

#endif