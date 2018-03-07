/*************************************************************************
	> File Name: client.cpp
	> Author: 吕白
	> Purpose:
	> Created Time: 2018年02月03日 星期六 15时02分07秒
 ************************************************************************/

#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<sys/types.h>
#include<pthread.h>
#include<unistd.h>
#include<assert.h>
#include<iostream>
#include<fcntl.h>
#include<cstdlib>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
using namespace std;

const char *ip = "127.0.0.1";
const int port = 4507;

class TcpTest  
{
private:
    static int sock;
public:
    TcpTest();
    ~TcpTest(){}
    void Init();
    void Run();
    static void *Recv( void *arg );
    static pthread_mutex_t mutex;
};

int TcpTest:: sock;
pthread_mutex_t TcpTest :: mutex = PTHREAD_MUTEX_INITIALIZER;


TcpTest :: TcpTest() 
{
    sock = 0;
}

void TcpTest :: Init() 
{
    int ret;
    struct sockaddr_in address;
    bzero( &address, sizeof(address) );
    address.sin_family = AF_INET;
    inet_pton( AF_INET, ip, &address.sin_addr );
    address.sin_port = htons( port );

    sock = socket( PF_INET, SOCK_STREAM, 0 );
    assert( sock != -1 );
    
    ret = connect( sock, (struct sockaddr*)&address, sizeof(address) );
    assert( ret != -1 ); 
}

struct buffer
{
    int number;
    char buf[256];
};
void TcpTest :: Run() 
{
    int ret;
    string judge;
    buffer tmp; 
    bzero( &tmp.buf, sizeof(tmp.buf) );
    tmp.number = 0;
    while ( 1 ) 
    {
        cin >> judge;
        if ( judge == "echo" ) 
        {
            tmp.number = 1;
            cin >> tmp.buf;
        }
        else if ( judge == "discard" ) 
        {
            tmp.number = 2;
        }
        else if ( judge == "chargen" )
        {
            tmp.number = 3;
        }
        else if ( judge == "daytime" ) 
        {
            tmp.number = 4;
        }
        else if ( judge == "time" ) 
        {
            tmp.number = 5;
        }
        else if ( judge == "exit" ) 
        {
            break;
        }
        if ( tmp.number > 0 && tmp.number < 6 ) 
        {
            ret = send( sock, (void *)&tmp, sizeof(tmp), MSG_WAITALL );
        }
        bzero( &tmp, sizeof(tmp) );
        if ( ret >= 0 ) 
        {
            cout << "发送数据" << ret << endl;
        }
    }
}

void* TcpTest :: Recv( void *arg ) 
{
    int ret;
    char buf[256];
    while ( 1 ) 
    {

        ret = recv( sock, (void *)buf, sizeof(buf), 0 );
        assert( ret != -1 );
        
        if ( ret <= 0 ) 
        {
            break;
        }
        pthread_mutex_lock( &mutex );
        cout << buf << endl;
        pthread_mutex_unlock( &mutex );
    }
}

int main()
{
    pthread_t tid;
    TcpTest Try;
    Try.Init();
    
    pthread_create( &tid, nullptr, Try.Recv, nullptr );
    
    Try.Run();
    pthread_mutex_destroy( &Try.mutex );
}
