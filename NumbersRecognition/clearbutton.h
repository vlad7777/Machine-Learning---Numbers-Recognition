#ifndef CLEARBUTTON_H
#define CLEARBUTTON_H

#include <QWidget>
#include <drawer.h>
#include <QPushButton>

class ClearButton : public QWidget
{
    Q_OBJECT
public:
    explicit ClearButton(QWidget *parent, Drawer *d);

private:
    Drawer *drawer;
signals:
    
public slots:
    void ClearClicked();
    
};

#endif // CLEARBUTTON_H
