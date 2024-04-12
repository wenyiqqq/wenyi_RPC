#include "mprpcapplication.h"
#include <iostream>
#include <unistd.h>
#include <string>


MprpcConfig MPrpcApplication::m_config;  //静态成员初始化

void ShowArgsHelp(){
    std::cout<< "format: command -i <configfile>"<< std::endl;
}
void MPrpcApplication::Init(int argc, char **argv)
{
    if(argc < 2){
        ShowArgsHelp();
        exit(EXIT_FAILURE);
    }
    int c = 0;
    std::string config_file;
    while((c = getopt(argc, argv, "i:")) != -1)
    {
        switch (c)
        {
            case 'i':
                config_file = optarg;
                break;
            case '?':
                // std::cout<<"invalid args!" << std::endl;
                ShowArgsHelp();
                exit(EXIT_FAILURE);
            case ':':
                // std::cout<<"need <configfile>!" << std::endl;
                ShowArgsHelp();
                exit(EXIT_FAILURE);
            default:
                break;
        }
    }

    //开始加载配置文件  rpcserver_ip , rpcserver_port , zookeeper_ip , zookeeper_port
    m_config.LoadConfigFile(config_file.c_str());

    // std::cout << "rpcServerIp:" << m_config.Load("rpcserverip") << std::endl;
    // std::cout << "rpcServerPort:" << m_config.Load("rpcserverport") << std::endl;
    // std::cout << "ZooKeeperIp:" << m_config.Load("zookeeperip") << std::endl;
    // std::cout << "ZooKeeperPort:" << m_config.Load("zookeeperport") << std::endl;
}  
MPrpcApplication& MPrpcApplication:: GetInstance()
{
    static MPrpcApplication app;
    return app;
}

MprpcConfig& MPrpcApplication::GetConfig()
{
    return m_config;
}