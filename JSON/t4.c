#include <stdio.h>
#include <stdlib.h>
#include "cJSON.h"

int main() 
{
    char *s = "{\"list\":{\"name\":\"xiao hong\",\"age\":10},\"other\":{\"name\":\"hua hua\"}}";
    cJSON *root = cJSON_Parse(s);
    if(!root) 
    {
        printf("get root faild !\n");
        return -1;
    }
    
    cJSON *js_list = cJSON_GetObjectItem(root, "list");
    if(!js_list) 
    {
        printf("no list!\n");
        return -1;
    }
    printf("list type is %d\n",js_list->type);
    
    cJSON *name = cJSON_GetObjectItem(js_list, "name");
    if(!name) 
    {
        printf("No name !\n");
        return -1;
    }
    printf("name type is %d\n",name->type);
    printf("name is %s\n",name->valuestring);
    
    cJSON *age = cJSON_GetObjectItem(js_list, "age");
    if(!age) 
    {
        printf("no age!\n");
        return -1;
    }
    printf("age type is %d\n", age->type);
    printf("age is %d\n",age->valueint);
    
    cJSON *js_other = cJSON_GetObjectItem(root, "other");
    if(!js_other) 
    {
        printf("no list!\n");
        return -1;
    }
    printf("list type is %d\n",js_other->type);
    
    cJSON *js_name = cJSON_GetObjectItem(js_other, "name");
    if(!js_name) 
    {
        printf("No name !\n");
        return -1;
    }
    printf("name type is %d\n",js_name->type);
    printf("name is %s\n",js_name->valuestring);
    
    if(root)
        cJSON_Delete(root);
    return 0;

}