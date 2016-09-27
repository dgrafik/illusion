#ifndef DIALOG_H
#define DIALOG_H
#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();


private slots:
    void on_pushButton_clicked();
    bool event(QEvent * event);

private:
    Ui::Dialog *ui;
    QTimer *timer;
    bool myTimerEnabled = false;

};

#endif // DIALOG_H
