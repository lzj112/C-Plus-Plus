# 常用解析函数

--- 

```
cJSON *cJSON_Parse(const char *value)
参数：
    value(const char*):char*指针，指向待解析的JSON数据
返回值：
    JSON树的根节点
函数功能：
    解析JSON数据，将数据填入JSON树中
输入示例：
    {
        "name": "Jack (\"Bee\") Nimble", 
        "format": {"type":       "rect", 
        "width":      1920, 
        "height":     1080, 
        "interlace":  false,
        "frame rate": 24
    }
```

```
char  *cJSON_Print(cJSON *item)
参数：
    item(cJSON *)：cJSON根节点
返回值：
    item节点解析后的全树字符串
函数功能：
    从item节点开始递归遍历，将节点树转换为字符串
输出示例：
    {
    	"name":	"Jack (\"Bee\") Nimble",
    	"format":	{
    		"type":	"rect",
    		"width":	1920,
    		"height":	1080,
    		"interlace":	false,
    		"frame rate":	24
    	}
    }
备注：
    使用该函数后，需要根据返回的char *指针释放内存。
    eg：
        out=cJSON_Print(json);
		printf("%s\n",out);
		free(out);
```

```
void   cJSON_Delete(cJSON *c)
参数：
    c(cJSON):cJSON根节点
返回值：
    无
函数功能：
    从根节点c开始递归删除JSON树各个节点，释放内存。
```

```
int   cJSON_GetArraySize(cJSON *array);

获取cjson对象数组成员的个数
```

```
cJSON *cJSON_GetArrayItem(cJSON*array,int item);

根据下标获取cjosn对象数组中的对象
```

```
cJSON *cJSON_GetObjectItem(cJSON*object,const char *string);

根据键获取对应的值（cjson对象）
```


# 解析数组

> 对象里的数组就先解析对象, 拿到对象里对应的数组 (使用 cJSON_GetObjectItem 先根据对象里的数组名获取对应的值)


- 解析数组第一类 

```
"iplist" :
[
    {
        "ip" : "172.18.75.89",
        "mask" : "255.255.254.0"
    },
    {
        "ip" : "172.18.75.60",
        "mask" : "255.255.254.0"
    },
    {
        "ip" : "172.18.75.61",
        "mask" : "255.255.254.0"
    },
],
```
像以上格式的数据解析可以使用如下方式：



```
    cJSON *ip_arry     = cJSON_GetObjectItem( clientlist, "iplist");  //clientlist 是使用 cjson对象
    if( NULL != ip_arry )
    {
        cJSON *client_list  = ip_arry->child;
        if( client_list != NULL )
        { 
            char * ip   = cJSON_GetObjectItem( client_list , "ip")->valuestring ;
            char * mask = cJSON_GetObjectItem( client_list , "mask")->valuestring ;
            printf("ip: %s  mask: %s",ip,mask);
            client_list = client_list->next ;
        }
    }
```

- 解析数组第二类

```
"Maclist": 
[
    "00:00:00:00:00:01",
    "00:00:00:00:00:02",
    "00:00:00:00:00:03"
],
```

有时候得到的数据需要是这个样子的，这时候就需要如下的解析方法了

```
cJSON *MAC_arry     = cJSON_GetObjectItem( clientlist, "Maclist");
if( MAC_arry != NULL ){
    int  array_size   = cJSON_GetArraySize ( MAC_arry );

    for( iCnt = 0 ; iCnt < array_size ; iCnt ++ ){
        cJSON * pSub = cJSON_GetArrayItem(MAC_arry, iCnt);
        if(NULL == pSub ){ continue ; }

        char * ivalue = pSub->valuestring ;
        printf("Maclist[%d] : %s",iCnt,ivalue);
    }
}
```
通过判断判断MAC_arry探知数组是否有值，可以减少程序错误的情况。


---

# 用来构建JSON对象的函数

```
cJSON *cJSON_CreateObject(void)
参数：
    无
返回值：
    指向一个cJSON_Object类型节点的指针
函数功能：
    创建一个cJSON节点，并设置节点类型为cJSON_Object

cJSON *cJSON_CreateString(const char *string)
参数：
    string(const char *):新创建节点的名称
返回值：
    cJSON_String类型的节点的指针
函数功能：
    创建一个cJSON_Object类型的节点，并且将节点的值valuestring设置为string
```

```
cJSON *cJSON_CreateString(const char *string)
参数：
    string(const char *):新创建节点的名称
返回值：
    cJSON_String类型的节点的指针
函数功能：
    创建一个cJSON_Object类型的节点，并且将节点的值valuestring设置为string
```

```
cJSON *cJSON_CreateNumber(double num)	
参数：
    num(double):新创建节点的值
返回值：
    cJSON_String类型的节点的指针
函数功能：
    创建一个cJSON_Number类型的节点，并且将节点的值valuedouble设置为num, valueint设置为(int)num
```

```
cJSON *cJSON_CreateArray(void)	
参数：
    无
返回值：
    cJSON_Array类型的节点的指针
函数功能：
    创建一个cJSON_Array类型的节点
```

```
cJSON *cJSON_CreateBool(int b)		
参数：
    b(int):新创建节点的类型，非0为cJSON_True，0为cJSON_False
返回值：
    cJSON_False/cJSON_True类型的节点的指针
函数功能：
    创建一个cJSON_False/cJSON_True类型的节点
```

```
cJSON *cJSON_CreateTrue(void)	
参数：
    无
返回值：
    cJSON_True类型的节点的指针
函数功能：
    创建一个cJSON_True类型的节点
```

```
cJSON *cJSON_CreateFalse(void)	
参数：
    无
返回值：
    cJSON_False类型的节点的指针
函数功能：
    创建一个cJSON_False类型的节点
```
```
cJSON *cJSON_CreateNull(void)	
参数：
    无
返回值：
    cJSON_Null类型的节点的指针
函数功能：
    创建一个cJSON_Null类型的节点
```

```
void	cJSON_AddItemToObject(cJSON *object,const char *string,cJSON *item)
参数：
    object(cJSON *):被添加节点的节点
    string(char *):要添加节点的名称
    item(cJSON *):要添加节点
返回值：
    无
函数功能：
    将item节点的名称设置为string。如果object节点有没有子节点，就将item设置为object子节点，否则将item添加object->child链表的尾部，成为object->child的兄弟节点
```
