#ifndef DIALOGCLASS_H
#define DIALOGCLASS_H

#include <QDialog>

namespace Ui {
class DialogClass;
}

class DialogClass : public QDialog
{
    Q_OBJECT

public:
    explicit DialogClass(QWidget *parent = 0);
    ~DialogClass();

private:
    Ui::DialogClass *ui;
};

#endif // DIALOGCLASS_H
