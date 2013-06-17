#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QBoxLayout>
#include <QPushButton>
#include <QLineEdit>

#include <drawer.h>
#include <clearbutton.h>
#include <preview.h>
#include <addbutton.h>

class MainWindow : public QWidget
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);

private:
    Drawer *drawer;
    Preview *preview;
    QLineEdit *edit;
    
signals:
    
public slots:
    void showPreview();
    void AddClicked();
};

#endif // MAINWINDOW_H
