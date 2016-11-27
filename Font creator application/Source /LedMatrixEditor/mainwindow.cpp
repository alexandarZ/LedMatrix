#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect_display();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_button_toggle(bool state)
{
    QString pos_text;
    int button_number;
    int row;
    int col;
    QAbstractButton *buttonWidget;

    //Get button widget
    buttonWidget = qobject_cast<QAbstractButton*>(sender());

    if (!buttonWidget)
    {
          return;
    }

    //Get row, col

    pos_text = buttonWidget->objectName().remove("btn_");

    button_number = pos_text.toInt();

    if(button_number<10)
    {
        row = 0;
        col = button_number;
    }
    else
    {
        row = button_number/10;
        col = button_number%10;
    }

   // qDebug()<<"("<<row<<","<<col<<")"<<": "<<state;
    _matrix.set_pixel(row,col,state);


    /* Update UI with hex values */
    char message[256];

    _matrix.generate_hex(message);

    ui->hex_value->setText(QString(message));
}

void MainWindow::connect_display()
{
    connect(ui->btn_00,SIGNAL(toggled(bool)),this,SLOT(on_button_toggle(bool)));
    connect(ui->btn_01,SIGNAL(toggled(bool)),this,SLOT(on_button_toggle(bool)));
    connect(ui->btn_02,SIGNAL(toggled(bool)),this,SLOT(on_button_toggle(bool)));
    connect(ui->btn_03,SIGNAL(toggled(bool)),this,SLOT(on_button_toggle(bool)));
    connect(ui->btn_04,SIGNAL(toggled(bool)),this,SLOT(on_button_toggle(bool)));
    connect(ui->btn_05,SIGNAL(toggled(bool)),this,SLOT(on_button_toggle(bool)));
    connect(ui->btn_06,SIGNAL(toggled(bool)),this,SLOT(on_button_toggle(bool)));
    connect(ui->btn_07,SIGNAL(toggled(bool)),this,SLOT(on_button_toggle(bool)));

    connect(ui->btn_10,SIGNAL(toggled(bool)),this,SLOT(on_button_toggle(bool)));
    connect(ui->btn_11,SIGNAL(toggled(bool)),this,SLOT(on_button_toggle(bool)));
    connect(ui->btn_12,SIGNAL(toggled(bool)),this,SLOT(on_button_toggle(bool)));
    connect(ui->btn_13,SIGNAL(toggled(bool)),this,SLOT(on_button_toggle(bool)));
    connect(ui->btn_14,SIGNAL(toggled(bool)),this,SLOT(on_button_toggle(bool)));
    connect(ui->btn_15,SIGNAL(toggled(bool)),this,SLOT(on_button_toggle(bool)));
    connect(ui->btn_16,SIGNAL(toggled(bool)),this,SLOT(on_button_toggle(bool)));
    connect(ui->btn_17,SIGNAL(toggled(bool)),this,SLOT(on_button_toggle(bool)));

    connect(ui->btn_20,SIGNAL(toggled(bool)),this,SLOT(on_button_toggle(bool)));
    connect(ui->btn_21,SIGNAL(toggled(bool)),this,SLOT(on_button_toggle(bool)));
    connect(ui->btn_22,SIGNAL(toggled(bool)),this,SLOT(on_button_toggle(bool)));
    connect(ui->btn_23,SIGNAL(toggled(bool)),this,SLOT(on_button_toggle(bool)));
    connect(ui->btn_24,SIGNAL(toggled(bool)),this,SLOT(on_button_toggle(bool)));
    connect(ui->btn_25,SIGNAL(toggled(bool)),this,SLOT(on_button_toggle(bool)));
    connect(ui->btn_26,SIGNAL(toggled(bool)),this,SLOT(on_button_toggle(bool)));
    connect(ui->btn_27,SIGNAL(toggled(bool)),this,SLOT(on_button_toggle(bool)));

    connect(ui->btn_30,SIGNAL(toggled(bool)),this,SLOT(on_button_toggle(bool)));
    connect(ui->btn_31,SIGNAL(toggled(bool)),this,SLOT(on_button_toggle(bool)));
    connect(ui->btn_32,SIGNAL(toggled(bool)),this,SLOT(on_button_toggle(bool)));
    connect(ui->btn_33,SIGNAL(toggled(bool)),this,SLOT(on_button_toggle(bool)));
    connect(ui->btn_34,SIGNAL(toggled(bool)),this,SLOT(on_button_toggle(bool)));
    connect(ui->btn_35,SIGNAL(toggled(bool)),this,SLOT(on_button_toggle(bool)));
    connect(ui->btn_36,SIGNAL(toggled(bool)),this,SLOT(on_button_toggle(bool)));
    connect(ui->btn_37,SIGNAL(toggled(bool)),this,SLOT(on_button_toggle(bool)));

    connect(ui->btn_40,SIGNAL(toggled(bool)),this,SLOT(on_button_toggle(bool)));
    connect(ui->btn_41,SIGNAL(toggled(bool)),this,SLOT(on_button_toggle(bool)));
    connect(ui->btn_42,SIGNAL(toggled(bool)),this,SLOT(on_button_toggle(bool)));
    connect(ui->btn_43,SIGNAL(toggled(bool)),this,SLOT(on_button_toggle(bool)));
    connect(ui->btn_44,SIGNAL(toggled(bool)),this,SLOT(on_button_toggle(bool)));
    connect(ui->btn_45,SIGNAL(toggled(bool)),this,SLOT(on_button_toggle(bool)));
    connect(ui->btn_46,SIGNAL(toggled(bool)),this,SLOT(on_button_toggle(bool)));
    connect(ui->btn_47,SIGNAL(toggled(bool)),this,SLOT(on_button_toggle(bool)));

    connect(ui->btn_50,SIGNAL(toggled(bool)),this,SLOT(on_button_toggle(bool)));
    connect(ui->btn_51,SIGNAL(toggled(bool)),this,SLOT(on_button_toggle(bool)));
    connect(ui->btn_52,SIGNAL(toggled(bool)),this,SLOT(on_button_toggle(bool)));
    connect(ui->btn_53,SIGNAL(toggled(bool)),this,SLOT(on_button_toggle(bool)));
    connect(ui->btn_54,SIGNAL(toggled(bool)),this,SLOT(on_button_toggle(bool)));
    connect(ui->btn_55,SIGNAL(toggled(bool)),this,SLOT(on_button_toggle(bool)));
    connect(ui->btn_56,SIGNAL(toggled(bool)),this,SLOT(on_button_toggle(bool)));
    connect(ui->btn_57,SIGNAL(toggled(bool)),this,SLOT(on_button_toggle(bool)));

    connect(ui->btn_60,SIGNAL(toggled(bool)),this,SLOT(on_button_toggle(bool)));
    connect(ui->btn_61,SIGNAL(toggled(bool)),this,SLOT(on_button_toggle(bool)));
    connect(ui->btn_62,SIGNAL(toggled(bool)),this,SLOT(on_button_toggle(bool)));
    connect(ui->btn_63,SIGNAL(toggled(bool)),this,SLOT(on_button_toggle(bool)));
    connect(ui->btn_64,SIGNAL(toggled(bool)),this,SLOT(on_button_toggle(bool)));
    connect(ui->btn_65,SIGNAL(toggled(bool)),this,SLOT(on_button_toggle(bool)));
    connect(ui->btn_66,SIGNAL(toggled(bool)),this,SLOT(on_button_toggle(bool)));
    connect(ui->btn_67,SIGNAL(toggled(bool)),this,SLOT(on_button_toggle(bool)));

    connect(ui->btn_70,SIGNAL(toggled(bool)),this,SLOT(on_button_toggle(bool)));
    connect(ui->btn_71,SIGNAL(toggled(bool)),this,SLOT(on_button_toggle(bool)));
    connect(ui->btn_72,SIGNAL(toggled(bool)),this,SLOT(on_button_toggle(bool)));
    connect(ui->btn_73,SIGNAL(toggled(bool)),this,SLOT(on_button_toggle(bool)));
    connect(ui->btn_74,SIGNAL(toggled(bool)),this,SLOT(on_button_toggle(bool)));
    connect(ui->btn_75,SIGNAL(toggled(bool)),this,SLOT(on_button_toggle(bool)));
    connect(ui->btn_76,SIGNAL(toggled(bool)),this,SLOT(on_button_toggle(bool)));
    connect(ui->btn_77,SIGNAL(toggled(bool)),this,SLOT(on_button_toggle(bool)));
}

void MainWindow::on_btn_clear_clicked()
{
    ui->btn_00->setChecked(false);
    ui->btn_01->setChecked(false);
    ui->btn_02->setChecked(false);
    ui->btn_03->setChecked(false);
    ui->btn_04->setChecked(false);
    ui->btn_05->setChecked(false);
    ui->btn_06->setChecked(false);
    ui->btn_07->setChecked(false);

    ui->btn_10->setChecked(false);
    ui->btn_11->setChecked(false);
    ui->btn_12->setChecked(false);
    ui->btn_13->setChecked(false);
    ui->btn_14->setChecked(false);
    ui->btn_15->setChecked(false);
    ui->btn_16->setChecked(false);
    ui->btn_17->setChecked(false);

    ui->btn_20->setChecked(false);
    ui->btn_21->setChecked(false);
    ui->btn_22->setChecked(false);
    ui->btn_23->setChecked(false);
    ui->btn_24->setChecked(false);
    ui->btn_25->setChecked(false);
    ui->btn_26->setChecked(false);
    ui->btn_27->setChecked(false);

    ui->btn_30->setChecked(false);
    ui->btn_31->setChecked(false);
    ui->btn_32->setChecked(false);
    ui->btn_33->setChecked(false);
    ui->btn_34->setChecked(false);
    ui->btn_35->setChecked(false);
    ui->btn_36->setChecked(false);
    ui->btn_37->setChecked(false);

    ui->btn_40->setChecked(false);
    ui->btn_41->setChecked(false);
    ui->btn_42->setChecked(false);
    ui->btn_43->setChecked(false);
    ui->btn_44->setChecked(false);
    ui->btn_45->setChecked(false);
    ui->btn_46->setChecked(false);
    ui->btn_47->setChecked(false);

    ui->btn_50->setChecked(false);
    ui->btn_51->setChecked(false);
    ui->btn_52->setChecked(false);
    ui->btn_53->setChecked(false);
    ui->btn_54->setChecked(false);
    ui->btn_55->setChecked(false);
    ui->btn_56->setChecked(false);
    ui->btn_57->setChecked(false);

    ui->btn_60->setChecked(false);
    ui->btn_61->setChecked(false);
    ui->btn_62->setChecked(false);
    ui->btn_63->setChecked(false);
    ui->btn_64->setChecked(false);
    ui->btn_65->setChecked(false);
    ui->btn_66->setChecked(false);
    ui->btn_67->setChecked(false);

    ui->btn_70->setChecked(false);
    ui->btn_71->setChecked(false);
    ui->btn_72->setChecked(false);
    ui->btn_73->setChecked(false);
    ui->btn_74->setChecked(false);
    ui->btn_75->setChecked(false);
    ui->btn_76->setChecked(false);
    ui->btn_77->setChecked(false);

    ui->statusBar->showMessage("Clear",2000);
}

void MainWindow::on_btn_send_clicked()
{
    char message[256];

    _matrix.generate_for_device(message);

    //qDebug()<<"For device: "<<message;

    if(_serial.isOpen())
    {
        _serial.write(message);
        ui->statusBar->showMessage("Data sent sucessfully!",2000);
    }
    else
    {
        ui->statusBar->showMessage("Open serial port first!",2000);
    }

}

void MainWindow::on_btn_serial_start_clicked()
{
    if(_serial.isOpen())
    {
        _serial.close();
        qDebug()<<"Serial port closed";
        ui->statusBar->showMessage("Serial port closed",2000);
    }
    else
    {
        _serial.setPortName(ui->serial_port_name->text());
        _serial.setBaudRate(ui->serial_port_baud->text().toInt());

        if(!_serial.open(QIODevice::WriteOnly))
        {
            qDebug()<<"Can't open serial port!";
            ui->statusBar->showMessage("Can't open serial port!",2000);
            return;
        }

        qDebug()<<"Serial port open";
        ui->statusBar->showMessage("Serial port is open!",2000);
    }
}

void MainWindow::on_actionNew_sprite_triggered()
{
    on_btn_clear_clicked();
}
