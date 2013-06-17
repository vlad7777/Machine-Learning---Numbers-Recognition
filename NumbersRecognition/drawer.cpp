#include "drawer.h"

Drawer::Drawer(QWidget *parent) :
    QWidget(parent)
{
    this->setFixedSize(300, 300);
    blocks.push_back(0);
    pixmap = QPixmap(300, 300);
}

void Drawer::mouseMoveEvent(QMouseEvent *e)
{
    Qt::MouseButtons state = e->buttons();
    bool isLeftButtonPressed = state & Qt::LeftButton;

    if (isLeftButtonPressed)
    {
        points.push_back(make_pair(e->x(), e->y()));
        blocks[blocks.size()-1] = points.size()-1;
    }

    this->repaint();
}

void Drawer::paintEvent(QPaintEvent *e)
{

    QPainter painter(&pixmap);

    painter.setRenderHint(QPainter::Antialiasing);

    painter.setBrush(QBrush("#000000"));
    painter.setPen(QPen(QBrush("#000000"), penSize));

    painter.fillRect(QRect(-1, -1, 301, 301), QBrush("#FFFFFF"));

    int curBlock = 0;

    for(int i = 0; i<points.size(); i++)
    {
        int j = i;
        while (j != blocks[curBlock])
        {
            painter.drawLine(QPoint(points[j].first, points[j].second), QPoint(points[j+1].first, points[j+1].second));
            j++;
        }
        i = j;
        curBlock++;
    }

    QPainter wPainter(this);
    wPainter.drawPixmap(0, 0, 300, 300, pixmap);
}

void Drawer::mouseReleaseEvent(QMouseEvent *e)
{
    blocks[blocks.size()-1] = points.size()-1;
    blocks.push_back(points.size()-1);
}

void Drawer::ClearCanvas()
{
    points.clear();
    blocks.clear();
    blocks.push_back(0);
    //pixmap = QPixmap(300, 300);
    repaint();
}

bool Drawer::checkRow(int k, QImage img)
{
    int w = img.width();
    QColor check;
    check.setRgb(0, 0, 0);
    for(int i = 0; i<w; i++)
        if (img.pixel(i, k) == check.rgb())
            return false;
    return true;
}

bool Drawer::checkColumn(int k, QImage img)
{
    int h = img.height();
    QColor check;
    check.setRgb(0, 0, 0);
    for(int i = 0; i<h; i++)
    {
        QRgb pix = img.pixel(k, i);
        if (pix == check.rgb())
            return false;
    }
    return true;
}

int Drawer::getAverageTint(int hs, int ws, int h, int w, QImage img)
{
    int sum = 0;
    for(int i = hs; i<hs+h; i++)
        for(int j = ws; j<ws+w; j++)
        {                  
            sum += 255 - qGray(img.pixel(j, i));
        }
    return (sum/(w*h));
}

vector< vector<int> > Drawer::getSimplifiedPic(int w, int h, int cols)
{

    QImage img = pixmap.toImage();

    QImageWriter imagefile;
    imagefile.setFileName("out.png");
    imagefile.setFormat("png");
    imagefile.setQuality(100);
    imagefile.write(img);

    int up = 0;
    int bottom = img.height()-1;
    int left = 0;
    int right = img.width()-1;

    while (checkRow(up, img))
        up++;

    while (checkRow(bottom, img))
        bottom--;

    while (checkColumn(left, img))
        left++;

    while (checkColumn(right, img))
        right--;

    int marginH = w;
    int marginV = h;

    /*up = max(0, up - marginV);
    bottom = min(img.height(), bottom - marginV);
    left = max(0, left - marginH);
    right = min(img.width(), right + marginH);*/

    int blockWidth = max((right - left)/w + 1, 1);
    int blockHeight = max((bottom - up)/h + 1, 1);

    vector< vector<int> > res;
    res.resize(h);

    for(int i = 0; i<res.size(); i++)
    {
        res[i].resize(w);
    }

    for(int i = 0; i<h; i++)
    {
        for(int j = 0; j<w; j++)
        {
            res[i][j] = getAverageTint(up + blockHeight * i, left + blockWidth * j,
                                       blockHeight, blockWidth, img);
        }
    }

    return res;
}
