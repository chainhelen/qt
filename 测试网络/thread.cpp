#include <thread.h>
#include <QLibrary>
#include <iostream>

#define INTERNET_CONNECTION_MODEM 1
//局域网
#define INTERNET_CONNECTION_LAN 2
//代理上网
#define INTERNET_CONNECTION_PROXY 4
//代理被占用
#define INTERNET_CONNECTION_MODEM_BUSY 8
//定义函数指针
typedef bool (*ConnectFun)(int* lpdwFlags,int dwReserved);
//获得联网方式

Thread::Thread() {
        //this->message= message;
    flag=1;

}

void Thread::run() {
    QString message;
    flag=1;
    while (flag) {
        Thread::GetInternetConnectState(message);
        //std::cout << "In " << message.toStdString()<< "'s run()." << std::endl;
        emit notify(message);
        QThread::msleep(1000);
    }
}
void Thread::stop()
{
    flag=0;
}

void Thread::GetInternetConnectState(QString &message)
{
    QLibrary lib("Wininet.dll");
    //如果正确加载了dll
    if(lib.load())
    {
        bool bOnline=false;//是否在线
        int flags;

        //获取dll库中的函数InternetGetConnectedState函数地址`
        ConnectFun myConnectFun=(ConnectFun)lib.resolve("InternetGetConnectedState");

        //判断是否连网
        bOnline=myConnectFun(&flags,0);
        if(bOnline)
        {
            //在线：拨号上网
            if ( flags & INTERNET_CONNECTION_MODEM )
            {
               // QMessageBox::information(0,QObject::tr("网络连接提示"),QObject::tr("已经连接上了网络 在线：拨号上网"));
                message=QObject::tr("已经连接上了网络 在线：拨号上网");
            }
            else if(flags & INTERNET_CONNECTION_LAN) //在线：通过局域网
            {
                //QMessageBox::information(0,QObject::tr("网络连接提示"),QObject::tr("已经连接上了网络 在线：通过局域网"));
                message=QObject::tr("已经连接上了网络 在线：通过局域网");
            }
            else if(flags & INTERNET_CONNECTION_PROXY)
            {
                //QMessageBox::information(0,QObject::tr("网络连接提示"),QObject::tr("已经连接上了网络 在线：代理"));
                message=QObject::tr("已经连接上了网络 在线：代理");
            }
        }
        else
        {
            //QMessageBox::information(0,QObject::tr("网络连接提示"),QObject::tr("没有连接网络，请连接网络"));
            message=QObject::tr("没有连接网络，请连接网络");
        }
     }
}
