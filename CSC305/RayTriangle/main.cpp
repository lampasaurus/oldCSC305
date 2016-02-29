#include <QtGui/QApplication>
#include "mainwindow.h"
#include "QtGui"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);





    QMessageBox msgBox;
    msgBox.setText("The intersection point is: ");
    msgBox.exec();






    MainWindow w;
    w.show();
    
    return a.exec();
}
