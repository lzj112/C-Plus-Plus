#include <stdio.h>
#include <string.h>
#include <mysql/mysql.h>

int main() 
{
    MYSQL* con;
    MYSQL_RES* res;
    MYSQL_ROW row;

    char server[] = "localhost";
    char user[] = "root";
    char password[] = "123456lzj";
    char database[] = "mysql";

    con = mysql_init(NULL);
    if (!mysql_real_connect(con, server, user, password, database, 0, NULL, 0)) 
    {
        printf(">>>>>>>>\n");
        exit(1);
    }
    if (mysql_query(con, "show tables")) 
    {
        printf("<<<<<<<");
        exit(1);
    }
    res = mysql_use_result(con);

    while ((row = mysql_fetch_row(res)) != NULL) 
    {
        printf("%s \n", row[0]);
    }

    mysql_free_result(res);
    mysql_close(con);

    printf("finish!\n");

    return 0;
}