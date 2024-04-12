#pragma once


#include "mprpcconfig.h"
#include "mprpcchannel.h"
#include "mprpccontroller.h"

//mprpc框架的基础类，负责框架的一些初始化操作
class MPrpcApplication  //设计为单例模式
{
public:
    static void Init(int argc, char **argv);   //头文件里只有声明没有定义
    static MPrpcApplication& GetInstance();
    // {
    //     static MPrpcApplication app;
    //     return app;
    // }
    static MprpcConfig& GetConfig();
private:
    static MprpcConfig m_config;
    MPrpcApplication(){};
    MPrpcApplication(const MPrpcApplication&) = delete;
    MPrpcApplication(MPrpcApplication&&) = delete;
};