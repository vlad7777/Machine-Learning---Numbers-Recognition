#include "preview.h"

Preview::Preview(QWidget *parent) :
    QWidget(parent)
{
    this->setFixedSize(300, 300);
}

void Preview::drawMap(vector<vector<int> > v)
{
    this->v = v;
    this->repaint();
}

void Preview::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);

    if (v.size() == 0) return;

    int h = v.size();
    int w = v[0].size();
    int height = 300/h;
    int width = 300/w;

    for(int i = 0; i<h; i++)
    {
        for(int j = 0; j<w; j++)
        {
            //printf("%d ", v[i][j]);
            painter.setBrush(QBrush(QColor(v[i][j], v[i][j], v[i][j])));
            painter.drawRect(width*j, height*i, width*(j+1), height*(i+1));
        }
        //printf("\n");
    }
}
