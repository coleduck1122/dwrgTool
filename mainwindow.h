#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "map.h"
#include "cardpage.h"

#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <QDebug>
#include <QDir>
#include <QFile>
#include <QHBoxLayout>
#include <QLabel>
#include <QMainWindow>
#include <QScreen>
#include <QStackedWidget>
#include <QStandardItem>
#include <QStandardItemModel>
#include <QTreeView>
#include <QVBoxLayout>
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void cropped();
    void diff();
    void loadMap(QLabel *imgLabel, QString t);
    void initWindowSize();
    void initSidebar();
    void initContent();

private:
    Ui::MainWindow *ui;

    QTreeView *treeView;
    QStandardItemModel *model;
    QStandardItem *rootItem;
    QStandardItem *tr_maps;
    QStandardItem *tr_map1;
    QStandardItem *tr_map2;
    QStandardItem *tr_map3;
    QStandardItem *tr_map4;
    QStandardItem *tr_map5;
    QStandardItem *tr_map6;
    QStandardItem *tr_map7;
    QStandardItem *tr_map8;
    QStandardItem *tr_watch;
    QStandardItem *tr_wiki;
    QStandardItem *tr_jgz;
    QStandardItem *tr_qsz;

    QStackedWidget *stackedWidget;
    Map *map1;
    Map *map2;
    Map *map3;
    Map *map4;
    Map *map5;
    Map *map6;
    Map *map7;
    Map *map8;

    CardPage *jgz;
    CardPage *qsz;
};
#endif // MAINWINDOW_H
