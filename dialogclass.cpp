#include "dialogclass.h"
#include "ui_dialogclass.h"

DialogClass::DialogClass(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogClass)
{
    ui->setupUi(this);
}

DialogClass::~DialogClass()
{
    delete ui;
}
