#include "chatserver.hpp"
#include "chatservice.hpp"
#include <iostream>
#include <signal.h>
#include <cstdlib> // for atoi
using namespace std;

// 处理服务器ctrl+c信号
void resetHandler(int sig)
{
    ChatService::instance()->reset();
    exit(0);
}

int main(int argc, char **argv)
{
    signal(SIGINT, resetHandler);

    // 检查命令行参数
    if (argc < 3) // 需要两个参数：IP 和端口号
    {
        cerr << "Usage: " << argv[0] << " <IP> <port>" << endl;
        return -1;
    }

    // 从命令行获取 IP 地址和端口号
    string ip = argv[1];
    int port = atoi(argv[2]);
    if (port <= 0 || port > 65535)
    {
        cerr << "Invalid port number: " << port << endl;
        return -1;
    }

    // 初始化服务器
    EventLoop loop;
    InetAddress addr(ip, port); // 使用命令行参数指定的 IP 和端口
    ChatServer server(&loop, addr, "ChatServer");

    server.start();
    loop.loop();
    return 0;
}