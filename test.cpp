#include <mysql/mysql.h>

#include <iostream>

using namespace  std; 

void Print(MYSQL* sqlRet) 
{
    MYSQL_RES* result; 
    MYSQL_ROW row;
    result = mysql_store_result(sqlRet); //获取检索结果
    if (result == nullptr)
        return ;

    int rows = mysql_num_rows(result);
    int fieldNum = mysql_num_fields(result); //获取结果集的字段数
    for (int i = 0; i < rows; i++) 
    {
        row = mysql_fetch_row(result); //从结果集中获取下一行
        if (row == nullptr) 
            break;
        for (int j = 0; j < fieldNum; j++) //打印array中的每个字段
            std::cout << row[j] << '\t';
        std::cout << std::endl;
    }

    mysql_free_result(result);
}
//执行sql命令,并将结果直接打印到屏幕
int ExeSql(MYSQL* mysql, std::string sql) 
{
    //执行sql命令
    int ret = mysql_query(mysql, sql.c_str()); 
    //对于C++来说返回0为成功,否则时失败
    if (ret == 0)
        Print(mysql);   //获取结果并打印
    else 
        std::cout << "query failed" << std::endl;

    return (ret == 0) ? ret : mysql_errno(mysql);
}


int main() 
{
    MYSQL* sql;
    sql = new MYSQL();
    mysql_init(sql);

    if (!mysql_real_connect(sql, 
                            "localhost",
                            "root",
                            "123456lzj",
                            nullptr,
                            0,
                            nullptr,
                            0)) 
    {
        cout << "error" << endl;
    }

    ExeSql(sql, "use blackDB");
    ExeSql(sql, "select * from test");
    mysql_close(sql);
    delete sql;
}