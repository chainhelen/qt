#ifndef MYWIDGET_H
#define MYWIDGET_H
#include "thread.h"
#include <QLabel>
#include <QWidget>
#include <QTextBrowser>
#include <QDialogButtonBox>
#include <QDialog>
#include <QPushButton>
#include <QHBoxLayout>

class Mywidget : public QWidget
{
    Q_OBJECT
public:
    explicit Mywidget(QWidget *parent = 0);
    ~Mywidget();
private:
    QDialogButtonBox *buttonBox;
    QWidget *downWidget;
    QWidget *onWidget;
    Thread render;
    QTextBrowser *textBrowser;

public slots:
    void OnClicked();
    void OnNotify(QString);
    void OnCancel();

};

#endif // MYWIDGET_H
