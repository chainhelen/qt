
#include <mywidget.h>
#include <QApplication>
#include <QMainWindow>
int main(int argc, char *argv[])
{
   QApplication a(argc, argv);

    Mywidget w;
    w.show();

    return a.exec();
}

