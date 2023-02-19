#include "httpwidget.h"

#include <QApplication>
#include "httplib.h"
#include<iostream>
using namespace httplib;

void Hello(const httplib::Request& req,httplib::Response& res){
    res.set_content("Hello world","text/plain");
    res.status=200;
  }

int main(int argc, char *argv[])
{

    httplib::Server server;//定义sercer对象
        //注册处理函数
        server.Get("/hi",Hello);
//        server.Post("/file",File);
        server.listen("0.0.0.0",8081);//启动服务器


    QApplication a(argc, argv);
    HTTPWidget w;
    w.show();

    return a.exec();
}
