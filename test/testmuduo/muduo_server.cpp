// #include <muduo/net/TcpServer.h>
// #include <muduo/net/EventLoop.h>
// #include <muduo/net/InetAddress.h>
// #include <functional>  
// #include <iostream>
// #include <string>
// using namespace std;
// using namespace muduo;
// using namespace muduo::net;
// using namespace std::placeholders;


// /*基于muduo库开发服务器程序
// 1. 组合TcpServer对象
// 2. 创建EventLoop事件循环对象指针
// 3. 明确TcpServer构造函数需要什么参数，输出ChatServer的构造函数
// 4. 在当前服务器类的构造函数中，注册处理连接的回调函数和处理读写事件的回调函数
// 5. 设置合适的服务端线程数量，muduo端会自己分配I/O线程和worker线程
// */
// class ChatServer
// {
// public:
//     ChatServer(muduo::net::EventLoop* loop, //事件循环
//         const muduo::net::InetAddress& listenAddr, //ip+端口号
//         const string& nameArg) //服务器名字
//         : _server(loop, listenAddr, nameArg),_loop(loop)
//         {
//             //给服务器注册用户连接的创建和销毁回调
//             _server.setConnectionCallback(std::bind(&ChatServer::onConnection, this, _1));

//             //给服务器注册用户读写事件回调
//             _server.setMessageCallback(std::bind(&ChatServer::onMessage,this,_1,_2,_3));

//             // 设置服务器端的线程数量
//             _server.setThreadNum(4); //1个IO线程 3个worker线程
//         }
//         void start(){
//             _server.start();
//         }

// private:    
//     //专门处理用户连接的创建和销毁  epoll listenfd accept
//     void onConnection(const TcpConnectionPtr& conn){
//              if(conn->connected())
//              {
//                  cout << conn->peerAddress().toIpPort() << " -> " << 
//                      conn->localAddress().toIpPort() <<" state:online "<<endl;
                    
//              }
//              else
//              {
//                  cout << conn->peerAddress().toIpPort() << " -> " << 
//                      conn->localAddress().toIpPort() <<" state:offline "<<endl;
//                  conn->shutdown();
//              }
//     }
//     //专门处理用户的读写事件
//     void onMessage(const TcpConnectionPtr &conn,  //连接
//                    Buffer *buffer,  //缓冲区
//                    Timestamp time) //接收到数据的时间信息  
//     {
//         string buf = buffer->retrieveAllAsString();
//         cout << "recv data:" << buf << "time:" << time.toString() << endl;
//         conn->send(buf);
//     }

//     //定义服务器类
//     muduo::net::TcpServer _server;
//     muduo::net::EventLoop *_loop ;

// };

// int main(){
//     //创建事件循环对象
//     muduo::net::EventLoop loop;
//     //创建服务器对象
//     muduo::net::InetAddress addr("127.0.0.1", 6000);
//     ChatServer server(&loop, addr, "ChatServer");

//     //启动服务器
//     server.start();
//     //启动事件循环
//     loop.loop(); //epoll_wait以阻塞方式等待新用户连接，已连接用户的读写事件

//     return 0;
// }