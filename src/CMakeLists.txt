# aux_source_directory(. SRC_LIST)
# set(SRC_LIST mprpcapplication.cc mprpcconfig.cc)
set(SRC_LIST mprpcapplication.cc mprpcconfig.cc rpcheader.pb.cc rpcprovider.cc mprpcchannel.cc mprpccontroller.cc logger.cc zookeeperutil.cc)
add_library(mprpc ${SRC_LIST})
target_link_libraries(mprpc muduo_net muduo_base pthread zookeeper_mt)   #muduo_base依赖muduo_net库 （静态库的顺序写好）net是muduo核心库   zookeeper_mt多线程版本