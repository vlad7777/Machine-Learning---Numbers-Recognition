#include "addbutton.h"

AddButton::AddButton(QWidget *parent, Drawer *drawer) :
    QWidget(parent)
{

    this->drawer = drawer;
    QPushButton *add = new QPushButton("Add to the training set", this);
    add->setFixedWidth(130);
    connect(add, SIGNAL(clicked()), this, SLOT(AddClicked()));

    QGridLayout *grid = new QGridLayout();
    edit = new QLineEdit(this);
    edit->setFixedWidth(150);

    grid->addWidget(add, 0, 0);
    grid->addWidget(edit, 0, 1);


    //edit->setInputMask(QString("9"));

    //hLayout.addWidget(edit);

    this->setLayout(grid);

}

void AddButton::AddClicked()
{
    out = fopen("training set.txt", "a");
    vector< vector<int> > v = drawer->getSimplifiedPic(20, 20, 16);
    for(int i = 0; i<v.size(); i++)
    {
        for(int j = 0; j<v[i].size(); j++)
            fprintf(out, "%d ", v[i][j]);
        fprintf(out, "\n");
    }
    int num = edit->text().toInt();
    fprintf(out, "%d\n", num);

    fclose(out);

    printf("\n");
}
