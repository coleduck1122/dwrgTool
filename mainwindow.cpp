#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    initWindowSize();
    initSidebar();
    initContent();

    // 创建 QWidget 用于存放侧边栏和右侧内容
    QWidget *centralWidget = new QWidget(this);

    // 创建布局管理器
    QHBoxLayout *mainLayout = new QHBoxLayout(centralWidget);

    // 将侧边栏列表和堆叠窗口添加到主布局中
    mainLayout->addWidget(treeView);
    mainLayout->addWidget(stackedWidget);

    // 将中心部件设置为 QWidget
    setCentralWidget(centralWidget);

    // 连接 QTreeView 的 clicked 信号到槽函数
    QObject::connect(treeView, &QTreeView::clicked, [=](const QModelIndex &index){
        // 获取选中项的自定义标识
        QString itemIdentifier = index.data(Qt::UserRole + 1).toString();
        if (itemIdentifier == "tr_maps" || itemIdentifier == "tr_wiki")
        {
            // 判断项是否可展开
            if (model->itemFromIndex(index)->isSelectable())
            {
                // 判断项是否已经展开
                if (treeView->isExpanded(index))
                    treeView->collapse(index);
                else
                    treeView->expand(index);
            }
        } else {
            if (itemIdentifier == "tr_map1")
            {
                stackedWidget->setCurrentIndex(0);
            }
            else if (itemIdentifier == "tr_map2")
            {
                stackedWidget->setCurrentIndex(1);
            }
            else if (itemIdentifier == "tr_map3")
            {
                stackedWidget->setCurrentIndex(2);
            }
            else if (itemIdentifier == "tr_map4")
            {
                stackedWidget->setCurrentIndex(3);
            }
            else if (itemIdentifier == "tr_map5")
            {
                stackedWidget->setCurrentIndex(4);
            }
            else if (itemIdentifier == "tr_map6")
            {
                stackedWidget->setCurrentIndex(5);
            }
            else if (itemIdentifier == "tr_map7")
            {
                stackedWidget->setCurrentIndex(6);
            }
            else if (itemIdentifier == "tr_map8")
            {
                stackedWidget->setCurrentIndex(7);
            }

            else if (itemIdentifier == "tr_watch")
            {
                stackedWidget->setCurrentIndex(0);
            }
            else if (itemIdentifier == "tr_jgz")
            {
                stackedWidget->setCurrentIndex(8);
            }
            else if (itemIdentifier == "tr_qsz")
            {
                stackedWidget->setCurrentIndex(9);
            }
        }
    });
}

void MainWindow::initSidebar()
{
    // 创建 QTreeView 作为侧边栏
    treeView = new QTreeView;

    // 创建树形模型
    model = new QStandardItemModel;
    rootItem = model->invisibleRootItem();

    // 设置模型，设置侧边栏固定宽度
    treeView->setModel(model);
    treeView->setMinimumWidth(200);
    treeView->setMaximumWidth(200);

    // 添加列表项
    tr_maps = new QStandardItem("地图");
    tr_map1 = new QStandardItem("军工厂");
    tr_map2 = new QStandardItem("红教堂");
    tr_map3 = new QStandardItem("圣心医院");
    tr_map4 = new QStandardItem("湖景村");
    tr_map5 = new QStandardItem("月亮河公园");
    tr_map6 = new QStandardItem("里奥的回忆");
    tr_map7 = new QStandardItem("永眠镇");
    tr_map8 = new QStandardItem("唐人街");
    tr_watch = new QStandardItem("观测枢");
    tr_wiki = new QStandardItem("百科");
    tr_jgz = new QStandardItem("监管者");
    tr_qsz = new QStandardItem("求生者");

    // 设置标识名
    tr_maps->setData("tr_maps", Qt::UserRole + 1);
    tr_map1->setData("tr_map1", Qt::UserRole + 1);
    tr_map2->setData("tr_map2", Qt::UserRole + 1);
    tr_map3->setData("tr_map3", Qt::UserRole + 1);
    tr_map4->setData("tr_map4", Qt::UserRole + 1);
    tr_map5->setData("tr_map5", Qt::UserRole + 1);
    tr_map6->setData("tr_map6", Qt::UserRole + 1);
    tr_map7->setData("tr_map7", Qt::UserRole + 1);
    tr_map8->setData("tr_map8", Qt::UserRole + 1);
    tr_watch->setData("tr_watch", Qt::UserRole + 1);
    tr_wiki->setData("tr_wiki", Qt::UserRole + 1);
    tr_jgz->setData("tr_jgz", Qt::UserRole + 1);
    tr_qsz->setData("tr_qsz", Qt::UserRole + 1);

    // 绑定父子关系
    rootItem->appendRow(tr_maps);
    rootItem->appendRow(tr_watch);
    rootItem->appendRow(tr_wiki);
    tr_maps->appendRow(tr_map1);
    tr_maps->appendRow(tr_map2);
    tr_maps->appendRow(tr_map3);
    tr_maps->appendRow(tr_map4);
    tr_maps->appendRow(tr_map5);
    tr_maps->appendRow(tr_map6);
    tr_maps->appendRow(tr_map7);
    tr_maps->appendRow(tr_map8);
    tr_wiki->appendRow(tr_jgz);
    tr_wiki->appendRow(tr_qsz);

    // 禁止子项可编辑的功能
    tr_maps->setEditable(false);
    tr_map1->setEditable(false);
    tr_map2->setEditable(false);
    tr_map3->setEditable(false);
    tr_map4->setEditable(false);
    tr_map5->setEditable(false);
    tr_map6->setEditable(false);
    tr_map7->setEditable(false);
    tr_map8->setEditable(false);
    tr_watch->setEditable(false);
    tr_wiki->setEditable(false);
    tr_jgz->setEditable(false);
    tr_qsz->setEditable(false);

    // 设置 QTreeView 样式
    QString style = "QTreeView {"
                    "    background-color: #f0f0f0;"
                    "    border: 1px solid #d0d0d0;"
                    "}"
                    "QTreeView::item {"
                    "    padding: 5px;"
                    "}"
                    "QTreeView::item:selected {"
                    "    background-color: #c0c0c0;"
                    "    border: none;"
                    "    color: #ffffff;"
                    "}";
    treeView->setStyleSheet(style);
}

void MainWindow::initContent()
{
    // 创建堆叠窗口用于存放右侧内容
    stackedWidget = new QStackedWidget;

    map1 = new Map(QString("jun_gong_chang"));
    map2 = new Map(QString("hong_jiao_tang"));
    map3 = new Map(QString("sheng_xin_yi_yuan"));
    map4 = new Map(QString("hu_jing_cun"));
    map5 = new Map(QString("yue_liang_he_gong_yuan"));
    map6 = new Map(QString("li_ao_de_hui_yi"));
    map7 = new Map(QString("yong_mian_zhen"));
    map8 = new Map(QString("tang_ren_jie"));
    jgz = new CardPage(this);
    qsz = new CardPage(this);

    // 向堆叠窗口中添加内容
    stackedWidget->addWidget(map1);
    stackedWidget->addWidget(map2);
    stackedWidget->addWidget(map3);
    stackedWidget->addWidget(map4);
    stackedWidget->addWidget(map5);
    stackedWidget->addWidget(map6);
    stackedWidget->addWidget(map7);
    stackedWidget->addWidget(map8);
    stackedWidget->addWidget(jgz);
    stackedWidget->addWidget(qsz);
}

void MainWindow::cropped()
{
    // jun_gong_chang_2 - 375, 75, 1100, 950 - revolve
    // hong_jiao_tang_2 - 465, 75, 935, 935
    // sheng_xin_yi_yuan_2 - 425, 75, 1005, 935 - revolve
    // hu_jing_cun - 435, 75, 1000, 935
    // yue_liang_he_gong_yuan - 345, 100, 1185, 820
    // li_ao_de_hui_yi - 375, 75, 1110, 935 - revolve
    // yong_mian_zhen - 465, 0, 935, 1080
    // tang_ren_jie - 380, 75, 1100, 950

    QString targetDir = "E:/Filescenter/Image/person5/li_ao_de_hui_yi/";
    QDir dir(targetDir);
    QStringList fileList = dir.entryList(QDir::Files);

    foreach (const QString &fileName, fileList)
    {
        QString filePath = targetDir + fileName;

        // 读取图像
        cv::Mat image = cv::imread(filePath.toStdString());

        // 检查图像是否成功读取
        if (image.empty())
        {
            std::cerr << "Failed to read image." << std::endl;
            return;
        }

        // 截取的区域
        cv::Rect roi(375, 75, 1110, 935);
        cv::Mat croppedImage = image(roi);

        // 保存裁剪后的图像到指定路径
        cv::imwrite(filePath.toStdString(), croppedImage);

        qDebug() << filePath;
    }

//    QString targetDir = "E:/Filescenter/Image/person5/li_ao_de_hui_yi/";
//    QDir dir(targetDir);
//    QStringList fileList = dir.entryList(QDir::Files);

//    cv::Mat image = cv::imread(QString(targetDir + "source.png").toStdString());
//    cv::Rect roi(375, 75, 1110, 935);
//    cv::Mat croppedImage = image(roi);

//    cv::imshow("Cropped Image", croppedImage);
//    cv::waitKey(0);
}

void MainWindow::diff()
{
    // jun_gong_chang - 950, 1100
    // hong_jiao_tang - 935, 935
    // sheng_xin_yi_yuan - 935, 1005
    // hu_jing_cun - 1000, 935
    // yue_liang_he_gong_yuan - 1185, 820
    // li_ao_de_hui_yi - 935, 1110
    // yong_mian_zhen - 935, 1080
    // tang_ren_jie - 1100, 950

    // 指定目标目录
    QString targetDir = "E:/Filescenter/Image/person5/tang_ren_jie/";
    QDir dir(targetDir);
    QStringList fileList = dir.entryList(QDir::Files);

    // 读取基准图片
    cv::Mat baseImage = cv::imread(QString(targetDir + "source.png").toStdString());
//    baseImage += baseImage;

//    // 保存裁剪后的图像到指定路径
//    cv::imwrite(QString(targetDir + "source2.png").toStdString(), baseImage);

    foreach (const QString &fileName, fileList)
    {
        if (fileName == "source.png") continue;

        // 读取图像
        QString filePath = targetDir + fileName;
        cv::Mat rsvImage = cv::imread(filePath.toStdString());

        // 检查图像是否成功读取
        if (baseImage.empty() || rsvImage.empty())
        {
            std::cerr << "Failed to read images." << std::endl;
            qDebug() << filePath;
            return;
        }

        // 保存图标到指定路径
        cv::Mat differenceImage = rsvImage - baseImage ;
        filePath = targetDir + "tb_" + fileName;
        cv::imwrite(filePath.toStdString(), differenceImage);

        qDebug() << filePath;
    }
}

void MainWindow::initWindowSize()
{
    // 获取主屏幕
    QScreen *primaryScreen = QGuiApplication::primaryScreen();
    // 获取主屏幕的可用大小，不包括任务栏或状态栏
    QRect availableGeometry = primaryScreen->availableGeometry();
    setFixedSize(availableGeometry.width(), availableGeometry.height());
    move(availableGeometry.topLeft());
}

MainWindow::~MainWindow()
{
    delete ui;
}
