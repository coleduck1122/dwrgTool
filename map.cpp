#include "map.h"
#include "ui_map.h"

Map::Map(const QString map, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Map)
{
    ui->setupUi(this);

    initContent(map);

    QGridLayout *gridLayout = new QGridLayout(this);

    QVBoxLayout *toolLayout = new QVBoxLayout();
    toolLayout->addWidget(toolTitle);
    toolLayout->addWidget(showNameBtn);
    toolLayout->addWidget(showBoxBtn);
    toolLayout->addWidget(showDjBtn);
    toolLayout->addWidget(hideDjBtn);
    QWidget *toolWidget = new QWidget(this);
    toolWidget->setObjectName("toolWidget");
    toolWidget->setLayout(toolLayout);
    toolWidget->setStyleSheet("#toolWidget { border: 1px solid black; }");

    QVBoxLayout *djLayout = new QVBoxLayout();
    djLayout->addWidget(djTitle);
    if (totDj >= 1) {
        djLayout->addWidget(djBox1);
    }
    if (totDj >= 2) {
        djLayout->addWidget(djBox2);
    }
    if (totDj >= 3) {
        djLayout->addWidget(djBox3);
    }
    if (totDj >= 4) {
        djLayout->addWidget(djBox4);
    }
    if (totDj >= 5) {
        djLayout->addWidget(djBox5);
    }
    QWidget *djWidget = new QWidget(this);
    djWidget->setObjectName("djWidget");
    djWidget->setLayout(djLayout);
    djWidget->setStyleSheet("#djWidget { border: 1px solid black; }");

    QVBoxLayout *csdLayout = new QVBoxLayout();
    csdLayout->addWidget(csdTitle);
    if (totCsd >= 0) {
        csdLayout->addWidget(jgzCsdBtn0);
    }
    if (totCsd >= 1) {
        csdLayout->addWidget(jgzCsdBtn1);
    }
    if (totCsd >= 2) {
        csdLayout->addWidget(jgzCsdBtn2);
    }
    if (totCsd >= 3) {
        csdLayout->addWidget(jgzCsdBtn3);
    }
    if (totCsd >= 4) {
        csdLayout->addWidget(jgzCsdBtn4);
    }
    if (totCsd >= 5) {
        csdLayout->addWidget(jgzCsdBtn5);
    }
    if (totCsd >= 6) {
        csdLayout->addWidget(jgzCsdBtn6);
    }
    if (totCsd >= 7) {
        csdLayout->addWidget(jgzCsdBtn7);
    }
    if (totCsd >= 8) {
        csdLayout->addWidget(jgzCsdBtn8);
    }
    if (totCsd >= 9) {
        csdLayout->addWidget(jgzCsdBtn9);
    }
    QWidget *csdWidget = new QWidget(this);
    csdWidget->setObjectName("csdWidget");
    csdWidget->setLayout(csdLayout);
    csdWidget->setStyleSheet("#csdWidget { border: 1px solid black; }");

    QVBoxLayout *mmjLayout = new QVBoxLayout();
    mmjLayout->addWidget(mmjTitle);
    mmjLayout->addWidget(selectMmjBtn);
    QWidget *mmjWidget = new QWidget(this);
    mmjWidget->setObjectName("mmjWidget");
    mmjWidget->setLayout(mmjLayout);
    mmjWidget->setStyleSheet("#mmjWidget { border: 1px solid black; }");

    gridLayout->addWidget(imgLabel, 0, 0, 7, 4);
    gridLayout->addWidget(infoLabel, 7, 0, 1, 4);
    gridLayout->addWidget(toolWidget, 0, 4, 4, 1);
    gridLayout->addWidget(djWidget, 4, 4, 4, 1);
    gridLayout->addWidget(csdWidget, 0, 5, 4, 1);
    gridLayout->addWidget(mmjWidget, 4, 5, 4, 1);

//    for (int row = 0; row < 8; ++row) {
//        for (int col = 0; col < 6; ++col) {
//            if (col != 4) {
//                continue;
//            }
//            QLabel *emptyLabel = new QLabel(this);
//            gridLayout->addWidget(emptyLabel, row, col);
//        }
//    }

    setLayout(gridLayout);

    initMap(map);
}

void Map::initContent(const QString map)
{
    if (map == "jun_gong_chang") {
        totCsd = 6;
        totDj = 3;
        totMmj = 5;
    } else if (map == "hong_jiao_tang") {
        totCsd = 6;
        totDj = 3;
        totMmj = 5;
    } else if (map == "sheng_xin_yi_yuan") {
        totCsd = 6;
        totDj = 3;
        totMmj = 5;
    } else if (map == "hu_jing_cun") {
        totCsd = 7;
        totDj = 5;
        totMmj = 5;
    } else if (map == "yue_liang_he_gong_yuan") {
        totCsd = 7;
        totDj = 5;
        totMmj = 5;
    } else if (map == "li_ao_de_hui_yi") {
        totCsd = 9;
        totDj = 5;
        totMmj = 5;
    } else if (map == "yong_mian_zhen") {
        totCsd = 7;
        totDj = 3;
        totMmj = 5;
    } else if (map == "tang_ren_jie") {
        totCsd = 6;
        totDj = 3;
        totMmj = 6;
    }

    imgLabel = new QLabel(this);
    infoLabel = new QLabel(this);

    // 左上 - 工具栏
    toolTitle = new QLabel("工具栏", this);
    toolTitle->setFixedHeight(30);
    // 显隐地名按钮
    {
        showNameBtn = new QPushButton(this);
        showNameBtn->setText("显隐地名");
        connect(showNameBtn, &QPushButton::clicked, this, &Map::nameToggled);
        isNameShowing = false;
    }
    // 显隐区选按钮
    {
        showBoxBtn = new QPushButton(this);
        showBoxBtn->setText("显隐区选");
        connect(showBoxBtn, &QPushButton::clicked, this, &Map::boxToggled);
        isBoxShowing = false;
    }
    // 显示地窖图标按钮
    {
        showDjBtn = new QPushButton(this);
        showDjBtn->setText("显示地窖图标");
        connect(showDjBtn, &QPushButton::clicked, this, &Map::showDj);
    }
    // 隐藏地窖图标按钮
    {
        hideDjBtn = new QPushButton(this);
        hideDjBtn->setText("隐藏地窖图标");
        connect(hideDjBtn, &QPushButton::clicked, this, &Map::hideDj);
    }


    // 左下 - 地窖刷点
    // 复选框
    djTitle = new QLabel("地窖刷点", this);
    djTitle->setFixedHeight(30);
    if (totDj >= 1) {
        djBox1 = new QCheckBox(this);
        connect(djBox1, &QCheckBox::toggled, this, &Map::djToggled);
    }
    if (totDj >= 2) {
        djBox2 = new QCheckBox(this);
        connect(djBox2, &QCheckBox::toggled, this, &Map::djToggled);
    }
    if (totDj >= 3) {
        djBox3 = new QCheckBox(this);
        connect(djBox3, &QCheckBox::toggled, this, &Map::djToggled);
    }
    if (totDj >= 4) {
        djBox4 = new QCheckBox(this);
        connect(djBox4, &QCheckBox::toggled, this, &Map::djToggled);
    }
    if (totDj >= 5) {
        djBox5 = new QCheckBox(this);
        connect(djBox5, &QCheckBox::toggled, this, &Map::djToggled);
    }


    // 右上 - 出生点刷点（监管）
    csdTitle = new QLabel("出生点刷点(监管)", this);
    csdTitle->setFixedHeight(30);
    if (totCsd >= 0) {
        jgzCsdBtn0 = new QRadioButton("隐藏出生点", this);
        connect(jgzCsdBtn0, &QRadioButton::toggled, this, &Map::csdToggled);
    }
    if (totCsd >= 1) {
        jgzCsdBtn1 = new QRadioButton(this);
        connect(jgzCsdBtn1, &QRadioButton::toggled, this, &Map::csdToggled);
    }
    if (totCsd >= 2) {
        jgzCsdBtn2 = new QRadioButton(this);
        connect(jgzCsdBtn2, &QRadioButton::toggled, this, &Map::csdToggled);
    }
    if (totCsd >= 3) {
        jgzCsdBtn3 = new QRadioButton(this);
        connect(jgzCsdBtn3, &QRadioButton::toggled, this, &Map::csdToggled);
    }
    if (totCsd >= 4) {
        jgzCsdBtn4 = new QRadioButton(this);
        connect(jgzCsdBtn4, &QRadioButton::toggled, this, &Map::csdToggled);
    }
    if (totCsd >= 5) {
        jgzCsdBtn5 = new QRadioButton(this);
        connect(jgzCsdBtn5, &QRadioButton::toggled, this, &Map::csdToggled);
    }
    if (totCsd >= 6) {
        jgzCsdBtn6 = new QRadioButton(this);
        connect(jgzCsdBtn6, &QRadioButton::toggled, this, &Map::csdToggled);
    }
    if (totCsd >= 7) {
        jgzCsdBtn7 = new QRadioButton(this);
        connect(jgzCsdBtn7, &QRadioButton::toggled, this, &Map::csdToggled);
    }
    if (totCsd >= 8) {
        jgzCsdBtn8 = new QRadioButton(this);
        connect(jgzCsdBtn8, &QRadioButton::toggled, this, &Map::csdToggled);
    }
    if (totCsd >= 9) {
        jgzCsdBtn9 = new QRadioButton(this);
        connect(jgzCsdBtn9, &QRadioButton::toggled, this, &Map::csdToggled);
    }
    curCsdIndex = 0;

    // 右下 - 密码机刷点
    // 切换刷点 - 选择框
    // 复选框 - 密码机
    mmjTitle = new QLabel("密码机刷点", this);
    mmjTitle->setFixedHeight(30);
    selectMmjBtn = new QPushButton(this);
    selectMmjBtn->setText("查询刷点");
}

void Map::djToggled() {
    QCheckBox *checkBox = qobject_cast<QCheckBox *>(sender());
    QString status = QString(checkBox->text()).at(0);
    if (checkBox->isChecked()) {
        if (status == "1") {
            addMap("tb_dj_1.png");
        } else if (status == "2") {
            addMap("tb_dj_2.png");
        } else if (status == "3") {
            addMap("tb_dj_3.png");
        } else if (status == "4") {
            addMap("tb_dj_4.png");
        } else if (status == "5") {
            addMap("tb_dj_5.png");
        }
    } else {
        if (status == "1") {
            removeMap("tb_dj_1.png");
        } else if (status == "2") {
            removeMap("tb_dj_2.png");
        } else if (status == "3") {
            removeMap("tb_dj_3.png");
        } else if (status == "4") {
            removeMap("tb_dj_4.png");
        } else if (status == "5") {
            removeMap("tb_dj_5.png");
        }
    }
}

void Map::csdToggled()
{
    QString curCsd = QString("tb_csd_%1.png").arg(curCsdIndex);

    if (jgzCsdBtn0 && jgzCsdBtn0->isChecked()) {
        if (curCsdIndex != 0) {
            removeMap(curCsd);
        }
        curCsdIndex = 0;
    } else if (jgzCsdBtn1 && jgzCsdBtn1->isChecked()) {
        if (curCsdIndex == 0) {
            addMap("tb_csd_1.png");
        } else if (curCsdIndex != 1) {
            removeMap(curCsd);
            addMap("tb_csd_1.png");
        }
        curCsdIndex = 1;
    } else if (jgzCsdBtn2 && jgzCsdBtn2->isChecked()) {
        if (curCsdIndex == 0) {
            addMap("tb_csd_2.png");
        } else if (curCsdIndex != 2) {
            removeMap(curCsd);
            addMap("tb_csd_2.png");
        }
        curCsdIndex = 2;
    } else if (jgzCsdBtn3 && jgzCsdBtn3->isChecked()) {
        if (curCsdIndex == 0) {
            addMap("tb_csd_3.png");
        } else if (curCsdIndex != 3) {
            removeMap(curCsd);
            addMap("tb_csd_3.png");
        }
        curCsdIndex = 3;
    } else if (jgzCsdBtn4 && jgzCsdBtn4->isChecked()) {
        if (curCsdIndex == 0) {
            addMap("tb_csd_4.png");
        } else if (curCsdIndex != 4) {
            removeMap(curCsd);
            addMap("tb_csd_4.png");
        }
        curCsdIndex = 4;
    } else if (jgzCsdBtn5 && jgzCsdBtn5->isChecked()) {
        if (curCsdIndex == 0) {
            addMap("tb_csd_5.png");
        } else if (curCsdIndex != 5) {
            removeMap(curCsd);
            addMap("tb_csd_5.png");
        }
        curCsdIndex = 5;
    } else if (jgzCsdBtn6 && jgzCsdBtn6->isChecked()) {
        if (curCsdIndex == 0) {
            addMap("tb_csd_6.png");
        } else if (curCsdIndex != 6) {
            removeMap(curCsd);
            addMap("tb_csd_6.png");
        }
        curCsdIndex = 6;
    } else if (jgzCsdBtn7 && jgzCsdBtn7->isChecked()) {
        if (curCsdIndex == 0) {
            addMap("tb_csd_7.png");
        } else if (curCsdIndex != 7) {
            removeMap(curCsd);
            addMap("tb_csd_7.png");
        }
        curCsdIndex = 7;
    } else if (jgzCsdBtn8 && jgzCsdBtn8->isChecked()) {
        if (curCsdIndex == 0) {
            addMap("tb_csd_8.png");
        } else if (curCsdIndex != 8) {
            removeMap(curCsd);
            addMap("tb_csd_8.png");
        }
        curCsdIndex = 8;
    } else if (jgzCsdBtn9 && jgzCsdBtn9->isChecked()) {
        if (curCsdIndex == 0) {
            addMap("tb_csd_9.png");
        } else if (curCsdIndex != 9) {
            removeMap(curCsd);
            addMap("tb_csd_9.png");
        }
        curCsdIndex = 9;
    }
}

void Map::nameToggled()
{
    if (isNameShowing) {
        removeMap("tb_name.png");
        isNameShowing = false;
    } else {
        addMap("tb_name.png");
        isNameShowing = true;
    }
}

void Map::boxToggled()
{
    if (isBoxShowing) {
        removeMap("tb_box.png");
        isBoxShowing = false;
    } else {
        addMap("tb_box.png");
        isBoxShowing = true;
    }
}

void Map::showDj()
{
    if (djBox1 && !djBox1->isChecked()) {
        djBox1->setChecked(true);
    }
    if (djBox2 && !djBox2->isChecked()) {
        djBox2->setChecked(true);
    }
    if (djBox3 && !djBox3->isChecked()) {
        djBox3->setChecked(true);
    }
    if (totDj >= 4 && djBox4 && !djBox4->isChecked()) {
        djBox4->setChecked(true);
    }
    if (totDj >= 5 && djBox5 && !djBox5->isChecked()) {
        djBox5->setChecked(true);
    }
}

void Map::hideDj()
{
    if (djBox1 && djBox1->isChecked()) {
        djBox1->setChecked(false);
    }
    if (djBox2 && djBox2->isChecked()) {
        djBox2->setChecked(false);
    }
    if (djBox3 && djBox3->isChecked()) {
        djBox3->setChecked(false);
    }
    if (totDj >= 4 && djBox4 && djBox4->isChecked()) {
        djBox4->setChecked(false);
    }
    if (totDj >= 5 && djBox5 && djBox5->isChecked()) {
        djBox5->setChecked(false);
    }
}

void Map::initMap(const QString map)
{
    targetDir = ":/";

    if (map == "jun_gong_chang")
    {
        targetDir += "jun_gong_chang/person5/jun_gong_chang/";
        infoLabel->setText("成功加载地图：军工厂");
        jgzCsdBtn1->setText("大门废墟");
        jgzCsdBtn2->setText("大房旁");
        jgzCsdBtn3->setText("沙包废墟");
        jgzCsdBtn4->setText("月亮门");
        jgzCsdBtn5->setText("小房旁");
        jgzCsdBtn6->setText("树林");
        djBox1->setText("1-大房地窖");
        djBox2->setText("2-小房地窖");
        djBox3->setText("3-中场地窖");
    }
    else if (map == "hong_jiao_tang")
    {
        targetDir += "hong_jiao_tang/person5/hong_jiao_tang/";
        infoLabel->setText("成功加载地图：红教堂");
        jgzCsdBtn1->setText("墓地里");
        jgzCsdBtn2->setText("墓地外围(南)");
        jgzCsdBtn3->setText("墓地外围(北)");
        jgzCsdBtn4->setText("红毯");
        jgzCsdBtn5->setText("大推");
        jgzCsdBtn6->setText("教堂");
        djBox1->setText("1-大推地窖");
        djBox2->setText("2-墓地地窖");
        djBox3->setText("3-小门地窖");
    }
    else if (map == "sheng_xin_yi_yuan")
    {
        targetDir += "sheng_xin_yi_yuan/person5/sheng_xin_yi_yuan/";
        infoLabel->setText("成功加载地图：圣心医院");
        jgzCsdBtn1->setText("女神像地窖");
        jgzCsdBtn2->setText("女神像");
        jgzCsdBtn3->setText("无敌废墟");
        jgzCsdBtn4->setText("木屋旁");
        jgzCsdBtn5->setText("人皇机旁");
        jgzCsdBtn6->setText("医院");
        djBox1->setText("1-医院正北");
        djBox2->setText("2-T墙地窖");
        djBox3->setText("3-医院正南");
    }
    else if (map == "hu_jing_cun")
    {
        targetDir += "hu_jing_cun/person5/hu_jing_cun/";
        infoLabel->setText("成功加载地图：湖景村");
        jgzCsdBtn1->setText("海边");
        jgzCsdBtn2->setText("大船");
        jgzCsdBtn3->setText("大门三板");
        jgzCsdBtn4->setText("双十一旁");
        jgzCsdBtn5->setText("小房南侧");
        jgzCsdBtn6->setText("苞米地");
        jgzCsdBtn7->setText("小船旁");
        djBox1->setText("1-小船地窖");
        djBox2->setText("2-双十一地窖");
        djBox3->setText("3-双板旁");
        djBox4->setText("4-大船楼梯下");
        djBox5->setText("5-海边地窖");
    }
    else if (map == "yue_liang_he_gong_yuan")
    {
        targetDir += "yue_liang_he_gong_yuan/person5/yue_liang_he_gong_yuan/";
        infoLabel->setText("成功加载地图：月亮河公园");
        jgzCsdBtn1->setText("鬼屋后门");
        jgzCsdBtn2->setText("死木马");
        jgzCsdBtn3->setText("鬼屋里");
        jgzCsdBtn4->setText("起点");
        jgzCsdBtn5->setText("鬼屋桥上");
        jgzCsdBtn6->setText("鬼屋桥外");
        jgzCsdBtn7->setText("狮笼");
        djBox1->setText("1-鬼屋后门");
        djBox2->setText("2-二站西侧");
        djBox3->setText("3-活木马地窖");
        djBox4->setText("4-狮笼地窖");
        djBox5->setText("5-人皇桥北侧");
    }
    else if (map == "li_ao_de_hui_yi")
    {
        targetDir += "li_ao_de_hui_yi/person5/li_ao_de_hui_yi/";
        infoLabel->setText("成功加载地图：里奥的回忆");
        jgzCsdBtn1->setText("西北角");
        jgzCsdBtn2->setText("大房旁");
        jgzCsdBtn3->setText("大门集装箱");
        jgzCsdBtn4->setText("月亮门旁");
        jgzCsdBtn5->setText("木屋西");
        jgzCsdBtn6->setText("木屋南");
        jgzCsdBtn7->setText("油罐旁");
        jgzCsdBtn8->setText("大房里");
        jgzCsdBtn9->setText("大房集装箱");
        djBox1->setText("1-大门集装箱旁");
        djBox2->setText("2-ladhy地窖2");
        djBox3->setText("3-大房正南");
        djBox4->setText("4-小门废墟");
        djBox5->setText("5-大房北侧");
    }
    else if (map == "yong_mian_zhen")
    {
        targetDir += "yong_mian_zhen/person5/yong_mian_zhen/";
        infoLabel->setText("成功加载地图：永眠镇");
        jgzCsdBtn1->setText("S板");
        jgzCsdBtn2->setText("假门");
        jgzCsdBtn3->setText("大门");
        jgzCsdBtn4->setText("独栋");
        jgzCsdBtn5->setText("二站");
        jgzCsdBtn6->setText("墓地");
        jgzCsdBtn7->setText("墓地门");
        djBox1->setText("1-四站");
        djBox2->setText("2-墓地前");
        djBox3->setText("3-中场地窖");
    }
    else if (map == "tang_ren_jie")
    {
        targetDir += "tang_ren_jie/person5/tang_ren_jie/";
        infoLabel->setText("成功加载地图：唐人街");
        jgzCsdBtn1->setText("裁缝角");
        jgzCsdBtn2->setText("人皇机南侧");
        jgzCsdBtn3->setText("街道中央");
        jgzCsdBtn4->setText("酒店");
        jgzCsdBtn5->setText("灯笼门");
        jgzCsdBtn6->setText("蜡像馆门前");
        djBox1->setText("1-西南角");
        djBox2->setText("2-狮子楼");
        djBox3->setText("3-花坛东侧");
    }

    sourceImg = cv::imread(QString(targetDir + "source2.png").toStdString());
    currentImg = sourceImg;

    // 获取主屏幕的可用大小，不包括任务栏或状态栏
    QScreen *primaryScreen = QGuiApplication::primaryScreen();
    QRect availableGeometry = primaryScreen->availableGeometry();
    maxHeight = availableGeometry.height() >= 950 ? 950 : availableGeometry.height();
    maxWidth = 1100 * maxHeight / 950;

    nameToggled();
    boxToggled();
}

void Map::addMap(const QString imgPath)
{
    cv::Mat img = cv::imread(QString(targetDir + imgPath).toStdString());
    currentImg = currentImg + img;
    showMap(currentImg);
}

void Map::removeMap(const QString imgPath)
{
    cv::Mat img = cv::imread(QString(targetDir + imgPath).toStdString());
    currentImg = currentImg - img;
    showMap(currentImg);
}

void Map::resetMap()
{
    currentImg = sourceImg;
    showMap(currentImg);
}

void Map::showMap(const cv::Mat img)
{
    QImage image(img.data, img.cols, img.rows, img.step, QImage::Format_BGR888);
    // 动态调整图像大小以适应窗口
    imgLabel->setMinimumSize(440, 380);
    imgLabel->setMaximumSize(maxWidth, maxHeight);
    imgLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    imgLabel->setScaledContents(true); // 启用图像缩放
    imgLabel->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored); // 忽略控件的大小策略
    imgLabel->setPixmap(QPixmap::fromImage(image));
}


Map::~Map()
{
    delete ui;
}
