#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <sys/types.h>

#include <cstring>
#include <iostream>

#include "cJSON.h"

using namespace std;

class Solution 
{
public:
    static void configFile(const char* fileName) 
    {
        struct stat s;
        if ((stat(fileName, &s)) < 0) 
        {
            perror("stat");
            return;
        }

        int srcfd = open(fileName, O_RDONLY, 0);

        char* addr = (char *)mmap(nullptr, s.st_size, PROT_READ, MAP_PRIVATE, srcfd, 0);

        cJSON* root = cJSON_Parse(addr);    //整个对象
        
        cJSON* pName = cJSON_GetObjectItem(root, "name");   //name
        printf("name : %s\n", pName->valuestring);

        cJSON* pArray = cJSON_GetObjectItem(root, "array"); //array数组

        int arraySize = cJSON_GetArraySize(pArray);

        for (int i = 0; i < arraySize; i++) 
        {
            cJSON* p = cJSON_GetArrayItem(pArray, i);
            printf("数组中元素: %d\n", p->valueint);
        }
        
        cJSON* pIP = cJSON_GetObjectItem(root, "ip");   //IP
        printf("ip : %s\n", pIP->valuestring);

        
        cJSON* pPort = cJSON_GetObjectItem(root, "port");   //port
        printf("port : %s\n", pPort->valuestring);

    }
};


int main() 
{
    Solution::configFile("net.json");
}