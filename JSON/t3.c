#include <stdio.h>
#include <stdlib.h>
#include "cJSON.h"

//创建一个数组，并向数组添加一个字符串和一个数字
void createJS() 
{
    cJSON* root;

    root = cJSON_CreateArray();
    cJSON_AddItemToArray(root, cJSON_CreateString("i am lvbai!"));
    cJSON_AddItemToArray(root, cJSON_CreateNumber(100));
    cJSON_AddItemToArray(root, cJSON_CreateNumber(0.2));

    {
        char* s = cJSON_PrintUnformatted(root);
        if (s) 
        {
            printf("%s\n", s);
            free(s);
        }
    }

    if (root) 
    {
        cJSON_Delete(root);
    }
}

//对象里面包括一个数组，数组里面包括对象，对象里面再添加一个字符串和一个数字：
void createJS_1() 
{
    cJSON* root;
    cJSON* js_body, *js_list;
    root = cJSON_CreateObject();
    cJSON_AddItemToObject(root, "body", js_body = cJSON_CreateArray());
    cJSON_AddItemToArray(js_body, js_list = cJSON_CreateObject());
    cJSON_AddStringToObject(js_list, "name", "lvbai");
    cJSON_AddNumberToObject(js_list, "status", 100);
    
    cJSON* usr = cJSON_GetObjectItem(js_list, "status");
    printf("%d\n", usr->valueint);
    
    // {
    //     //        char *s = cJSON_Print(root);
    //     char *s = cJSON_PrintUnformatted(root);
    //     if(s){
    //         printf(" %s \n",s);
    //         free(s);
    //     }
    // }
    // if(root)
    cJSON_Delete(root);
    cJSON_Delete(usr);
}

int main() 
{
    // createJS();
    createJS_1();
}