#ifndef MAP_H
#define MAP_H

#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <QCheckBox>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QRadioButton>
#include <QScreen>
#include <QString>
#include <QVBoxLayout>
#include <QWidget>

namespace Ui {
class Map;
}

class Map : public QWidget
{
    Q_OBJECT

public:
    explicit Map(const QString map, QWidget *parent = nullptr);
    ~Map();

    void initContent(const QString map);
    void initMap(const QString map);
    void addMap(const QString imgPath);
    void removeMap(const QString imgPath);
    void resetMap();
    void showMap(const cv::Mat img);

public slots:
    void djToggled();
    void csdToggled();
    void nameToggled();
    void boxToggled();
    void showDj();
    void hideDj();

private:
    Ui::Map *ui;
    QLabel *imgLabel;
    QLabel *infoLabel;

    cv::Mat sourceImg;
    cv::Mat currentImg;
    int maxHeight;
    int maxWidth;
    QString targetDir;

    // 左上 - 工具栏
    QLabel *toolTitle;
    QPushButton *showNameBtn;
    bool isNameShowing;
    QPushButton *showBoxBtn;
    bool isBoxShowing;


    // 左下 - 地窖刷点
    QLabel *djTitle;
    QCheckBox *djBox1;
    QCheckBox *djBox2;
    QCheckBox *djBox3;
    QCheckBox *djBox4;
    QCheckBox *djBox5;
    QPushButton *showDjBtn;
    QPushButton *hideDjBtn;
    int totDj;

    // 右上 - 出生点刷点
    QLabel *csdTitle;
    QRadioButton *jgzCsdBtn0;
    QRadioButton *jgzCsdBtn1;
    QRadioButton *jgzCsdBtn2;
    QRadioButton *jgzCsdBtn3;
    QRadioButton *jgzCsdBtn4;
    QRadioButton *jgzCsdBtn5;
    QRadioButton *jgzCsdBtn6;
    QRadioButton *jgzCsdBtn7;
    QRadioButton *jgzCsdBtn8;
    QRadioButton *jgzCsdBtn9;
    int curCsdIndex;
    int totCsd;

    // 右下 - 密码机刷点
    QLabel *mmjTitle;
    QPushButton *selectMmjBtn;
    int totMmj;
};

#endif // MAP_H
