#include "cardpage.h"
#include "ui_cardpage.h"

CardPage::CardPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CardPage)
{
    ui->setupUi(this);

    // 创建滚动区域
    QScrollArea *scrollArea = new QScrollArea(this);
    QWidget *scrollWidget = new QWidget(scrollArea);
    QGridLayout *gridLayout = new QGridLayout(scrollWidget);

    // 设置滚动区域
    scrollWidget->setLayout(gridLayout);
    scrollArea->setWidget(scrollWidget);
    scrollArea->setWidgetResizable(true);

    // 创建主布局并添加滚动区域
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(scrollArea);
    setLayout(mainLayout);

    // 创建卡片
    int numRows = 4; // 10行
    int numCols = 4; // 4列

    for (int i = 0; i < numRows * numCols; ++i) {
        QWidget *card = new CardWidget("幸运儿", this);
        int row = i / numCols;
        int col = i % numCols;
        gridLayout->addWidget(card, row, col);
    }
}

CardPage::~CardPage()
{
    delete ui;
}
