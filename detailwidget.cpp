#include "detailwidget.h"
#include "ui_detailwidget.h"

DetailWidget::DetailWidget(const QString name, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DetailWidget)
{
    ui->setupUi(this);
    QVBoxLayout *layout = new QVBoxLayout(this);
    label = new QLabel(name, this);
    layout->addWidget(label);
    setLayout(layout);
}

DetailWidget::~DetailWidget()
{
    delete ui;
}
