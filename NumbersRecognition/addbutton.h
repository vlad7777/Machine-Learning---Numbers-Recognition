#ifndef ADDBUTTON_H
#define ADDBUTTON_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QBoxLayout>
#include <QGridLayout>

#include <cstdio>

#include <drawer.h>

class AddButton : public QWidget
{
    Q_OBJECT
public:
    explicit AddButton(QWidget *parent, Drawer *drawer);

private:
    Drawer *drawer;
    QLineEdit *edit;
    FILE *out;
    
signals:
    
public slots:
    void AddClicked();
    
};

#endif // ADDBUTTON_H
