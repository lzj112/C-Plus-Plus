/*************************************************************************
	> File Name: Tour_guide.cpp
	> Author: 吕白
	> Purpose:数据结构课设，校园导航
	> Created Time: 2018年01月02日 星期二 08时14分54秒
 ************************************************************************/

#include<fstream>
#include<iostream>
#include<string>
#include<cassert>
#include<stack>
#include<vector>
#include<queue>
using namespace std;

#define MAXVEX 100
#define INFINITY 65535
vector < int > Patharc;
vector < int > ShortPath;
class login     //登录
{
public:
    login() {  }
    int log_in();   //登录
    int log_in_file();  //从文件读取用户名 密码
    void sign_up();     //注册
};

typedef struct 
{
    //string vex[100]; //顶点表
    vector < string > vex;
    int arc[100][100]; //邻接矩阵
    int numVertexes; //图中当前顶点数
} MGraph;

class school_map    //地图
{
public:
    school_map();
    ~school_map() { delete M; }
    void menu( int flag );
    void prim();
    void dijkstra();
    void DFS( int i );
    void DFSTraverse();
private:
    MGraph *M;
    bool visited[ MAXVEX ];
};

int login :: log_in()   //登录 
{
    while( 1 )
    {
        cout << "1.管理员登录\n"
             << "2.用户登录\n"
             << "3.注册用户\n"
             << "按0退出" << endl;
        int choose;
        string name,code;
        cin >> choose;
        if( choose == 0 )
        {
            return -1;
        }
        else if( choose == 1 )  //管理员唯一
        {
            cout << "\n输入用户名：\n";
            cin >> name;
            cout << "\n输入密码：\n";
            cin >> code;
            if( name == "111111" && code == "000000" )
            {
                return 1;
            }
            else 
            {
                cout << "error!\n";
            }
        }
        else if( choose == 2 )  //用户登录 
        {
            int n = log_in_file(); //文件读取用户名 密码
            if( n == 1 )
            {
                cout << "log in successfuly\n";
                return 2;
            }
            else
            {
                cout << "error!\n";
            }
        }
        else if( choose == 3 )
        {
            sign_up();
        }
    }
}

int login :: log_in_file() //文件 登录 
{
    int flag = 0;
    string name1,code1,name2,code2;
    cout << "输入用户名：\n";
    cin >> name1;
    cout << "输入密码：\n";
    cin >> code1;

    ifstream filein( "denglu" );
    if( !filein.is_open() )
    {
        cout << "Error opening\n";
        return -1;
    }
    while( !filein.eof() )
    {
        filein >> name2;
        filein >> code2;
        if( name1 == name2 && code1 == code2 )
        {
            flag = 1;
            break;
        }
    }
    filein.close();
    return flag;
}

void login :: sign_up() //注册
{
    ofstream fileout( "denglu", ios_base :: app );
    if( !fileout.is_open() )
    {
        cout << "Error opening\n";
        return ;
    }
    string name,code,tmp;
    cout << "输入用户名：\n";
    cin >> name;
    cout << "输入密码：\n";
    cin >> code;
    cout << "确认密码：\n";
    cin >> tmp;
    if( tmp != code )
    {
        cout << "code error\n";
        return ;
    }
    fileout << name;
    fileout << " ";
    fileout << code;
    fileout << "\n";
    fileout.close();
}

school_map :: school_map()  //从文件读取地图 初始化邻接矩阵
{
    M = new MGraph;
    int i,j,k;
    string tmp;
    ifstream filein( "school_map" ); //打开文件
    assert( filein.is_open() );
    
    filein >> M->numVertexes;
    for( i = 0;i < M->numVertexes;i++ )    //初始化为都不连通
        for( j = 0;j < M->numVertexes;j++ )
            M->arc[i][j] = INFINITY;

    for( i = 0;i < M->numVertexes;i++ )
    {
        filein >> tmp;
        M->vex.push_back( tmp );
    }
    while( !filein.eof() )
    {
        filein >> i >> j >> k;
        M->arc[i][j] = k;
        M->arc[j][i] = k;
    }
}

void school_map :: DFSTraverse()
{
    int i;
    for( i = 0;i < M->numVertexes;i++ )
    {
        visited[ i ] = false;
    }
    for( i = 0;i < M->numVertexes;i++ )
    {
        if( !visited[i] )
        {
            DFS( i );
        }
    }
    cout << endl;
}

void school_map :: DFS( int i )
{
    int j;
    visited[i] = true;
    cout << M->vex[i] << " ";
    for( j = 0;j < M->numVertexes;j++ )
    {
        if( M->arc[i][j] != INFINITY && !visited[j] )
        {
            DFS( j );
        }
    }
}

void school_map :: prim()   //最短连通图
{
    int min,i,j,k;
    vector < int > adjvex;  //保存相关顶点下标
    vector < int > lowcost;     //保存相关顶点间边的权值
    lowcost.push_back( 0 );
    adjvex.push_back( 0 );
    for( i = 1;i < M->numVertexes;i++)
    {
        lowcost.push_back( M->arc[0][i] );
        adjvex.push_back( 0 );
    }
    for( i = 1;i < M->numVertexes;i++ )
    {
        min = INFINITY;
        j = 1;
        k = 0;
        while( j < M->numVertexes )
        {
            if( lowcost[j] != 0 && lowcost[j] < min )
            {
                min = lowcost[j];
                k = j;
            }
            j++;
        }
        cout << '(' << M->vex[ adjvex[k] ] << ',' << M->vex[ k ] << ')';
        lowcost[k] = 0;
        for( j = 1;j < M->numVertexes;j++ )
        {
            if( lowcost[j] != 0 && M->arc[k][j] < lowcost[j] )
            {
                lowcost[j] = M->arc[k][j];
                adjvex[j] = k;
            }
        }
    }
    cout << endl;
}

void school_map :: dijkstra()    //最短路径
{
    string str1,str2;
    cout << "输入起始点:\n";
    cin >> str1 >> str2;
    struct Path
    {
        int vertex, dist;
        string path;
    };

    struct PathLess
    {
        bool operator()(const Path &a, const Path &b)
        {
            return a.dist > b.dist;
        }
    };
    

    int v0,v1;
    int v,w,k,min,i;

    for( i = 0;i < M->numVertexes;i++ )
    {
        if( str1 == M->vex[i] )
        {
            v0 = i;
        }
        if( str2 == M->vex[i] )
        {
            v1 = i;
        }
    }
    
    priority_queue<Path, vector<Path>, PathLess> Q;
    Q.push({v0, 0, M->vex[v0]});

    while (!Q.empty())
    {
        Path u = Q.top(); Q.pop();

        if (u.vertex == v1)
        {
            cout << u.path << endl;
            break;
        }

        for (int i = 0; i < M->numVertexes; i++) 
        {
            if (M->arc[u.vertex][i] != INFINITY) 
                Q.push({i, u.dist + M->arc[u.vertex][i], u.path + "->" + M->vex[i]});
        }
    }
}


void school_map :: menu( int flag )    //选项菜单
{
    string choose;
    cout << "0.退出\n"
         << "1.显示地图所有地点\n"
         << "2.查看最短连通图\n"
         << "3.查看两点间最短路径\n"
         << "4.查看两点间所有简单路径\n"
         << "5.查询某地点信息\n"
         << "6.增加地点\n"
         << "7.删除地点\n";
    cout << "输入选项：" << endl; 
    cin >> choose;
    while( choose != "0" )
    {
        if( choose == "1" )
        {
            DFSTraverse();
        }
        if( choose == "2" )
        {
            prim();
        }
        if( choose == "3" )
        {
            dijkstra();
        }
        if( choose == "4" )
        {
            
        }
        if( choose == "5" )
        {

        }
        if( choose == "6" )
        {
            
        }
        if( choose == "7" )
        {

        }
        cout << '\n' << "输入选项:" << endl;
        cin >> choose;
    
    }
}

int main()
{
    int flag = 0;
    login user;
    flag = user.log_in();
    if( flag == -1 )
    {
        return 0;
    }
    
    school_map map;
    map.menu( flag );
}

