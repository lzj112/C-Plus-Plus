#include <stdio.h>
#include "cJSON.h"

int main(int argc, char **argv)
{
char *s = "{\"list\":[{\"name\":\"xiao hong\",\"age\":10},{\"name\":\"hua hua\",\"age\":11}]}";
cJSON *root = cJSON_Parse(s);
if(!root) {
    printf("get root faild !\n");
    return -1;
}
cJSON *js_list = cJSON_GetObjectItem(root, "list"); //js_list是数组
if(!js_list){
    printf("no list!\n");
    return -1;
}
int array_size = cJSON_GetArraySize(js_list);
printf("array size is %d\n",array_size);
int i = 0;
cJSON *item,*it, *js_name, *js_age;
char *p  = NULL;
for(i=0; i< array_size; i++) {
    item = cJSON_GetArrayItem(js_list, i);  //item是数组中的每一个对象
    if(!item) {
        //TODO...
    }
    p = cJSON_PrintUnformatted(item);
    it = cJSON_Parse(p);
    if(!it)
     continue ;
    // js_name = cJSON_GetObjectItem(item, "name");
    js_name = cJSON_GetObjectItem(it, "name");
    printf("name is %s\n",js_name->valuestring);
    js_age = cJSON_GetObjectItem(it, "age");
    printf("age is %d\n",js_age->valueint);
 
}
 
if(root)
    cJSON_Delete(root);
    return 0;
}
