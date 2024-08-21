#include "cardwidget.h"
#include "ui_cardwidget.h"

CardWidget::CardWidget(const QString name, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CardWidget)
{
    ui->setupUi(this);

    QVBoxLayout *cardLayout = new QVBoxLayout(this);

    // 设置卡片内容
    QPushButton *button = new QPushButton(name, this);
    connect(button, &QPushButton::clicked, this, &CardWidget::onCardClicked);
    cardLayout->addWidget(button);

    // 设置QSS样式
    button->setStyleSheet(
        "QPushButton {"
        "    background-color: #ffffff;"  // 白色背景
        "    color: #333333;"             // 文本颜色
        "    border: 1px solid #dddddd;"  // 边框颜色
        "    border-radius: 10px;"        // 圆角
        "    padding: 15px;"              // 内边距
        "    font-size: 16px;"            // 字体大小
        "    font-weight: bold;"          // 字体加粗
        "}"
        "QPushButton:hover {"
        "    background-color: #f0f0f0;"  // 鼠标悬停时背景颜色
        "}"
        "QPushButton:pressed {"
        "    background-color: #e0e0e0;"  // 按下时背景颜色
        "}"
        );

    this->setLayout(cardLayout);
}

void CardWidget::onCardClicked()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if (button) {
        DetailWidget *detailWidget = new DetailWidget(button->text(), this);
        detailWidget->show();
    }
}

CardWidget::~CardWidget()
{
    delete ui;
}
