#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // we create a simple timer, with the widget being its parent
    animationTimer = new QTimer(this);
    // the timer will send a signal timeout at regular intervals.
    // whenever this timeout signal occurs, we want it to call our drawOpenGL
    // function
    connect(animationTimer, SIGNAL(timeout()), ui->widget, SLOT(repaint()));
    // we start the timer with a timeout interval of 20ms
    animationTimer->start(20);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
