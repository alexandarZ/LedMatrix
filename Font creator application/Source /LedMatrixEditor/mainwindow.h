#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include "matrix.h"
#include <QtSerialPort/QtSerialPort>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_button_toggle(bool state);

    void on_btn_clear_clicked();

    void on_btn_send_clicked();

    void on_btn_serial_start_clicked();

    void on_actionNew_sprite_triggered();

private:

    void connect_display();
    Ui::MainWindow *ui;
    QSerialPort _serial;
    Matrix _matrix;
};

#endif // MAINWINDOW_H
