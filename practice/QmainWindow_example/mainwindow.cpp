#include "mainwindow.h"
#include <QDebug>
#include <QAction>
#include <QMenuBar>
#include <QToolBar>
#include <QDockWidget>
#include <QListWidget>
#include <QMdiArea>
#include <QMdiSubWindow>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QMenu *fileMenu;

    // 리소스로 등록된 아이콘 설정
    QAction *newAct = new QAction(QIcon(":/resources/new.png"), tr("New"), this);
    QAction *openAct = new QAction(QIcon(":/resources/open.png"), tr("Open"), this);

    // 메뉴 설정
    newAct->setShortcut(QKeySequence::New);
    newAct->setStatusTip("Create a new file");
    connect(newAct, SIGNAL(triggered(bool)), this, SLOT(slot_newFile()));

    openAct->setShortcut(QKeySequence::Open);
    openAct->setStatusTip("Open an existing file");
    connect(openAct, SIGNAL(triggered(bool)), this, SLOT(slot_open()));

    fileMenu = menuBar() -> addMenu("&File");
    fileMenu->addAction(newAct);
    fileMenu->addAction(openAct);

    // 툴바 설정 , 위에서 사용한 action 재활용 가능
    QToolBar *fileToolBar;
    fileToolBar = addToolBar("File");
    fileToolBar->addAction(newAct);
    fileToolBar->addAction(openAct);

    // DockWidget 설정
    QDockWidget *dock = new QDockWidget("Target", this);
    dock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);

    QListWidget *customerList = new QListWidget();

    // DockWidget 안에 들어갈 내용 / 리스트 설정
    QStringList lists;
    lists << "One" << "Two" << "Three" << "Four" << "Five";
    customerList->addItems(lists);

    dock->setWidget(customerList);
    addDockWidget(Qt::RightDockWidgetArea, dock);


    // CentralWidget 설정
    QMdiArea *area = new QMdiArea();
    area->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    QMdiSubWindow *subWindow1 = new QMdiSubWindow();
    subWindow1->resize(300,200);
    QPushButton *btn = new QPushButton("Button");
    subWindow1->setWidget(btn);

    QMdiSubWindow *subWindow2 = new QMdiSubWindow();
    subWindow2->resize(300,200);

    area->addSubWindow(subWindow1);
    area->addSubWindow(subWindow2);

    setCentralWidget(area);
}

void MainWindow::slot_newFile()
{
    qDebug() << Q_FUNC_INFO;
}

void MainWindow::slot_open()
{
    qDebug() << Q_FUNC_INFO;
}

MainWindow::~MainWindow() {}
