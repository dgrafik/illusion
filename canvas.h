#ifndef CANVAS_H
#define CANVAS_H

#include <QWidget>

class Canvas : public QWidget
{
    Q_OBJECT
public:
    explicit Canvas(QWidget *parent = 0);
    void paintEvent(QPaintEvent * event);

signals:

public slots:
    void nextFrame();

private:
    int currentIndex;
};

#endif // CANVAS_H
