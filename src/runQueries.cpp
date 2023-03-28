#include "runQueries.h"
#include "QueryResult.h"
#include "TextQuery.h"
#include <iostream>
#include <string>


void runQueries(std::ifstream& infile)
{
    // infile是一个ifstream，指向我们要处理的文件。
    TextQuery tq(infile); // 保存文件并建立查询map
    // 与用户交互：提示用户输入要查询的单词，完成查询并打印结果
    while (true) {
        std::cout << "请输入要查询的单词，输入 q 退出：";
        std::string s;
        // 若遇到文件尾或用户输入q退出时，循环终止
        if (!(std::cin >> s) || s == "q") {
            break;
        }
        // 指向查询并打印结果
        print(std::cout, tq.query(s)) << std::endl;
    }
}

extern "C" void find_word(char* path_p)
{
    std::string path(path_p);
    std::cout << "文件路径：" << path << std::endl;
    std::ifstream input(path);

    if (input) {
        std::cout << "文件打开成功！" << std::endl;
        runQueries(input);
        
    } else {
        std::cout << "文件打开失败！" << std::endl;
    }

    if (input.is_open()) {
        input.close();
        std::cout << "文件已关闭。" << std::endl;
    }
}
