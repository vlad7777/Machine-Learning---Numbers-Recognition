#ifndef DRAWER_H
#define DRAWER_H

#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include <vector>
#include <QPixmap>
#include <cstdio>
#include <QImage>
#include <QFile>
#include <QTextStream>
#include <QByteArray>
#include <QBuffer>
#include <QImageWriter>

using namespace std;

class Drawer : public QWidget
{
    Q_OBJECT
public:
    explicit Drawer(QWidget *parent = 0);
    void ClearCanvas();
    vector< vector<int> > getSimplifiedPic(int w, int h, int cols);

private:
    static const int penSize = 10;
    vector< pair<int, int> > points;
    vector<int> blocks;
    QPixmap pixmap;

    bool checkRow(int k, QImage img);
    bool checkColumn(int k, QImage img);

    int getAverageTint(int ws, int hs, int w, int h, QImage img);

signals:
    
public slots:

protected:
    void mouseMoveEvent(QMouseEvent *);
    void paintEvent(QPaintEvent *);
    void mouseReleaseEvent(QMouseEvent *);

    
};

#endif // DRAWER_H
