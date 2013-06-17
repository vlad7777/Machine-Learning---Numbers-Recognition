#include "clearbutton.h"

ClearButton::ClearButton(QWidget *parent, Drawer *d  ) :
    QWidget(parent)
{
    this->drawer = d;
    this->setFixedSize(100, 30);
    QPushButton *clear = new QPushButton("Clear", this);
    connect(clear, SIGNAL(clicked()), this, SLOT(ClearClicked()));
}

void ClearButton::ClearClicked()
{
    drawer->ClearCanvas();
}
