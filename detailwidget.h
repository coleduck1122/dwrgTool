#ifndef DETAILWIDGET_H
#define DETAILWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QString>

namespace Ui {
class DetailWidget;
}

class DetailWidget : public QWidget
{
    Q_OBJECT

public:
    explicit DetailWidget(const QString name, QWidget *parent = nullptr);
    ~DetailWidget();

private:
    Ui::DetailWidget *ui;
    QLabel *label;
};

#endif // DETAILWIDGET_H
