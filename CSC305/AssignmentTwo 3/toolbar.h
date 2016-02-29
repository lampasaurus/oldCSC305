#ifndef TOOLBAR_H
#define TOOLBAR_H

#include <QDialog>

namespace Ui {
class toolbar;
}

class toolbar : public QDialog
{
    Q_OBJECT
    
public:
    explicit toolbar(QWidget *parent = 0);
    ~toolbar();
    
private:
    Ui::toolbar *ui;
};

#endif // TOOLBAR_H
