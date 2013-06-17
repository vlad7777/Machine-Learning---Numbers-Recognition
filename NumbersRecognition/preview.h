#ifndef PREVIEW_H
#define PREVIEW_H

#include <QWidget>
#include <vector>
#include <QPainter>

using namespace std;

class Preview : public QWidget
{
    Q_OBJECT
public:
    explicit Preview(QWidget *parent = 0);
    void drawMap(vector< vector<int> > v);
private:
    vector< vector<int> > v;
signals:
    
public slots:

protected:
    void paintEvent(QPaintEvent *);
    
};

#endif // PREVIEW_H
