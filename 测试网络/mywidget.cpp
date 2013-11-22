#include "mywidget.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QLayout>

Mywidget::Mywidget(QWidget *parent):
    QWidget(parent)
{
   // setFixedSize(300,300);
    resize(300,200);
    setWindowTitle("hello world");

    textBrowser = new QTextBrowser();



    buttonBox=new QDialogButtonBox();

    buttonBox->setStandardButtons(QDialogButtonBox::Ok|QDialogButtonBox::Cancel);

    buttonBox->button(QDialogButtonBox::Ok)->setText("start");
    buttonBox->button(QDialogButtonBox::Cancel)->setText("cancel");

    QVBoxLayout*    vLayout = new QVBoxLayout;
    vLayout->setAlignment(Qt::AlignHCenter);
    vLayout->addWidget(buttonBox);
    vLayout->addWidget(textBrowser);

    setLayout(vLayout);

    QObject::connect(buttonBox->button(QDialogButtonBox::Ok), SIGNAL(clicked()), this, SLOT(OnClicked()));
    QObject::connect(buttonBox->button(QDialogButtonBox::Cancel), SIGNAL(clicked()), this, SLOT(OnCancel()));


}
void Mywidget::OnClicked()
{
    connect(&render,SIGNAL(notify(QString)),this,SLOT(OnNotify(QString)));
    render.start();
}

void Mywidget::OnNotify(QString message)
{
    textBrowser->append(message);
}
void Mywidget::OnCancel()
{
    textBrowser->clear();
    render.stop();
}

Mywidget::~Mywidget()
{
    render.stop();
}
