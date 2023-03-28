#include "TextQuery.h"
#include "QueryResult.h"
#include "runQueries.h"
#include <fstream>
#include <iostream>
#include <string>


int main()
{
    std::string path("../test/example.txt");    //相对路径
    std::ifstream input(path);

    if (input) {
        std::cout << "文件打开成功！" << std::endl;
        runQueries(input);
    }else {
        std::cout << "文件打开失败！" << std::endl;
    }
    
    if (input.is_open()) {
        input.close();
        std::cout << "文件已关闭。" << std::endl;
    }
    
    return 0;
}
