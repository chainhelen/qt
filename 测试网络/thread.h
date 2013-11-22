#ifndef THREAD_H
#define THREAD_H
#include <QThread>

class Thread : public QThread {
    Q_OBJECT
public:
    Thread();
    void run();
    void stop();
    void GetInternetConnectState(QString &message);
signals:
    void notify(QString);
public:
    int flag;
};

#endif // THREAD_H


