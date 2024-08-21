#ifndef CARDPAGE_H
#define CARDPAGE_H

#include "detailwidget.h"
#include "cardwidget.h"

#include <QWidget>
#include <QScrollArea>
#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QVBoxLayout>

namespace Ui {
class CardPage;
}

class CardPage : public QWidget
{
    Q_OBJECT

public:
    explicit CardPage(QWidget *parent = nullptr);
    ~CardPage();

private:
    Ui::CardPage *ui;
};

#endif // CARDPAGE_H
