#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent)
{
    QVBoxLayout *vLayout = new QVBoxLayout(this);


    drawer = new Drawer(this);
    drawer->setFixedSize(300, 300);

    preview = new Preview(this);
    ClearButton *cButton = new ClearButton(this, drawer);
    QPushButton *showPreview = new QPushButton("Show Preview", this);
    AddButton *add = new AddButton(this, drawer);
    add->setFixedSize(300, 50);



    connect(showPreview, SIGNAL(clicked()), this, SLOT(showPreview()));

    vLayout->setAlignment(Qt::AlignCenter);

    vLayout->addWidget(drawer);
    vLayout->addWidget(cButton);
    vLayout->addWidget(preview);
    vLayout->addWidget(showPreview);
    vLayout->addWidget(add);

    this->setLayout(vLayout);


}
void MainWindow::showPreview()
{
    preview->drawMap(drawer->getSimplifiedPic(20, 20, 16));
}

void MainWindow::AddClicked()
{

}
