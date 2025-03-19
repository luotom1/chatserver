#include "json.hpp"
using json = nlohmann::json;

#include <iostream>
#include <vector>
#include <map>
using namespace std;

//  json序列化示例 1
string fun1(){
    json js;
    js["msg_type"] = 2;
    js["from"] = "zhangsan";
    js["to"] = "lisi";
    js["msg"] = "hello world";
    
    return  js.dump();
}

//  json序列化示例 2
string fun2(){
    json js;
    js["id"] = {1, 2, 3, 4, 5};
    js["name"] = "zhangsan";
    // js["msg"]["zhangsan"] = "hello world";
    // js["msg"]["lisi"] = "hello china";

    js["msg"] = {
        {"zhangsan", "hello world"},
        {"lisi", "hello china"}
    };
    return js.dump();

}

//  json序列化示例 3
string fun3(){
    json js;
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    js["list"] = vec;
    
    map<int, string> m;
    m.insert({1, "zhangsan"});
    m.insert({2, "lisi"});
    m.insert({3, "wangwu"});
    js["list2"] = m;

    return js.dump();
}

int main(){
    string recvBuf = fun3();
    json js = json::parse(recvBuf);
    // cout<<js["msg_type"]<<endl;
    // cout<<js["from"]<<endl;
    // cout<<js["to"]<<endl;
    // cout<<js["msg"]<<endl;

    // cout<<js["id"]<<endl;
    // auto arr = js["id"];
    // for(auto it = arr.begin(); it != arr.end(); ++it){
    //     cout<<*it<<endl;
    // }

    vector<int> vec = js["list"];
    for(auto it = vec.begin(); it != vec.end(); ++it){
        cout<<*it<<endl;
    }

    map<int, string> m = js["list2"];
    for(auto it = m.begin(); it != m.end(); ++it){
        cout<<it->first<<" "<<it->second<<endl;
    }
    return 0;
}