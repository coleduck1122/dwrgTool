#ifndef CARDWIDGET_H
#define CARDWIDGET_H

#include "detailwidget.h"

#include <QWidget>
#include <QString>
#include <QGridLayout>
#include <QPushButton>
#include <QVBoxLayout>

namespace Ui {
class CardWidget;
}

class CardWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CardWidget(const QString name, QWidget *parent = nullptr);
    ~CardWidget();

private slots:
    void onCardClicked();

private:
    Ui::CardWidget *ui;
};

#endif // CARDWIDGET_H
