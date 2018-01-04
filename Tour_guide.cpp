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
    vector < string > vex;
    int arc[100][100]; //邻接矩阵
    int numVertexes; //图中当前顶点数
} MGraph;

class school_map    //地图
{
public:
    school_map();
    ~school_map() { delete M; }
    int find_vex( string str );
    void menu( int flag );
    void prim();
    void dijkstra();
    void DFS( int i );
    void DFSTraverse();
    void Shortest();
    void all_path();
    void dfs_all( int v1,int v2 );
    void add_place();
    void del_place();
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

school_map :: school_map()  //构造函数 从文件读取地图 初始化邻接矩阵
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

int school_map :: find_vex( string str )
{
    int i;
    for( i = 0;i < M->numVertexes;i++ )
    {
        if( str == M->vex[i] )
        {
            return i;
        }
    }
    return -1;
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

void school_map :: dijkstra()    //最短路径
{
    string str1,str2;
    cout << "输入起始点:\n";
    cin >> str1 >> str2;
    
    int v0,v1;
    int v,w,k,min,i;

    v0 = find_vex( str1 );
    if( v0 == -1 )
    {
        cout << "无此地点\n";
        return ;
    }

    v1 = find_vex( str2 );
    if( v1 == -1 )
    {
        cout << "无此地点\n";
        return ;
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
         << "5.增加地点\n"
         << "6.删除地点\n";
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
            cout << "最短权值路径：\n";
            dijkstra();
            cout << "\n最少中转次数路径：\n";
            Shortest();
        }
        if( choose == "4" )
        {
           all_path(); 
        }
        if( choose == "5" )
        {
            if( flag != 1 )
            {
                cout << "缺少权限" << endl;
            }
            else
            {
                add_place();
            }
        }
        if( choose == "6" )
        {
            if( flag != 1 )
            {
                cout << "缺少权限" << endl;
            }
            else
            {
                del_place();
            }
        }
        cout << '\n' << "输入选项:" << endl;
        cin >> choose;
    
    }
}

struct pathtable
{
    int num;
    vector < int > path;
};
void school_map :: Shortest()   //最短中转路径
{
    int book[ M->numVertexes ] = { 0 };
    int i,j,v1,v2;
    queue < pathtable> Q;
    string str1,str2;
    cout << "输入起始点：\n";
    cin >> str1 >> str2;
    
    v1 = find_vex( str1 );
    if( v1 == -1 )
    {
        cout << "无此地点\n";
        return ;
    }
    v2 = find_vex( str2 );
    if( v2 == -1 )
    {
        cout << "无此地点\n";
        return ;
    }
    
    pathtable place1,place2;
    place1.num = v1;
    place1.path.push_back( v1 );
    Q.push( place1 );   //起点进去队列
    book[ v1 ] = 1;
    j = v1;
    place2 = Q.front();
    while( 1 )
    {
        for( i = 0;i < M->numVertexes;i++ )
        {
            if( M->arc[j][i] != INFINITY && book[i] == 0 )  //如果连通且尚未入队
            {
                book[ i ] = 1;
                place1.num = i;
                place1.path = place2.path;
                place1.path.push_back( i );
                Q.push( place1 );

                if( place1.num == v2 )  //到达终点
                {
                    for( int i : place1.path )
                    {
                        cout << M->vex[i] << ' ';
                    }
                    cout << endl;
                    return ;
                }
            }
        }
        Q.pop();    //队头出队
        place2 = Q.front();
        j = place2.num;
    }
}

int book[100];
vector < int > V;
void school_map :: all_path()   //所有简单路径
{
    book[100] = {0};
    string str1,str2;
    int v1,v2;
    cout << "输入起始点：\n";
    cin >> str1 >> str2;

    v1 = find_vex( str1 );
    if( v1 == -1 )
    {
        cout << "无此地点\n";
        return ;
    }
    v2 = find_vex( str2 );
    if( v2 == -1 )
    {
        cout << "无此地点\n";
        return ;
    }
    dfs_all( v1,v2 );

}

void school_map :: dfs_all( int v1,int v2 )
{
    int i,j;
    V.push_back( v1 );
    book[ v1 ] = 1;
    if( v1 == v2 )
    {
        for( int i : V )
        {
            cout << M->vex[i] << ' ';
        }
        cout << endl;
    }
    else 
    {
        for( i = 0;i < M->numVertexes;i++ )
        {
            if( M->arc[ v1 ][i] != INFINITY && book[i] == 0 )
            {
                dfs_all( i,v2 );
            }
        }
    }
    book[ v1 ] = 0;
    v1--;
    V.pop_back();

}

void school_map :: add_place()  //添加地点
{
    ofstream fileout( "school_map" );
    if( !fileout.is_open() )
    {
         cout << "add_place-opening error\n";
        return ;
    }
    string str;
    cout << "输入新地点名称：\n";
    cin >> str;
    M->vex.push_back( str );
    M->numVertexes++;
    cout << M->numVertexes << "asasasas\n";
    cout << "输入该地点与各地联系：\n";
    for( int i = 0;i < M->numVertexes;i++ )
    {
        cin >> M->arc[ M->numVertexes-1 ][i];
        M->arc[i][ M->numVertexes-1 ] = M->arc[ M->numVertexes-1 ][i];
    }
    fileout << M->numVertexes;
    fileout << '\n';
    for( int i = 0;i < M->numVertexes;i++ )
    {
        fileout << M->vex[i];
        fileout << ' ';
    }
    fileout << '\n';
    for( int i = 0;i < M->numVertexes;i++ )
    {
        for( int j = 0;j < M->numVertexes;j++ )
        {
            if( M->arc[i][j] != INFINITY )
            {
                fileout << i << ' ' << j << ' ' << M->arc[i][j] << '\n'; 
            }
        }
    }
    fileout.close();
}

void school_map :: del_place()  //删除地点
{
    ofstream fileout( "school_map" );
    string str;
    cout << "输入地点：\n";
    cin >> str;
    int v = find_vex( str );
    if( v == -1 )
    {
        cout << "无此地点\n";
        return ;
    }
    for( int i = 0;i < M->numVertexes;i++ )
    {
        M->arc[v][i] = INFINITY;
        M->arc[i][v] = INFINITY;
    }
    M->vex.erase( M->vex.begin()+v );
    fileout << M->numVertexes-1;
    fileout << '\n';
    for( string str : M->vex )
    {
        fileout << str;
        fileout << ' ';
    }
    fileout << '\n';
    cout << "M->numVertexes === " << M->numVertexes << endl;//////
    for( int i = 0;i < M->numVertexes;i++ )
    {
        for( int j = 0;j < M->numVertexes;j++ )
        {
            if( M->arc[i][j] != INFINITY )
                fileout << i << ' ' << j << ' ' << M->arc[i][j] << '\n';
        }
    }
    M->numVertexes--;
    fileout.close();

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

