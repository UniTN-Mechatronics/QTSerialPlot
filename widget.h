#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtSerialPort>
#include <QTimer>
#include "../../../../../../qcustomplot/qcustomplot.h"

#define MAXSUBPLOTS 3
#define MAXLINES 3

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_Initchar_lineEdit_textChanged(const QString &arg1);
    void on_Serialavailable_comboBox_currentIndexChanged(const QString &arg1);
    void on_Serialbaud_comboBox_currentIndexChanged(const QString &arg1);
    void on_Start_pushButton_clicked();
    void on_Stop_pushButton_clicked();
    void on_Save_pushButton_clicked();
    void readData();
    void update_plot();
    void selectionChanged();
    void mousePress();
    void mouseWheel();

    void on_Numbersubplots_spinBox_valueChanged(int arg1);

    void number_of_lines_changed(int val);
    void color_changed(int val);

private:
    Ui::Widget *ui;
    QString serialportname;
    QString serialbaud;
    QString initchar;
    QSerialPort serialport;
    QStringList datalist_console;
    QStringList datalist;
    QString lastdatalistline;
    QString firstdatalistline;
    QString data;

    QList<QList<double> > parseddatalist;

    QTimer* timer;

    int databefore;

    double initialtime;
    double finaltime;
    bool isfirst;

// line struct
    struct Line_struct_t{
        QWidget* Line_Groupbox;
        QSpinBox* Xdata_Spinbox;
        QSpinBox* Ydata_Spinbox;
        QComboBox* Color_Combobox;
        QCPGraph* graph;
    };

//    struct Subplot
    struct Subplot_struct_t {
        QCPAxisRect* AxesRect;
        QWidget* Subplot_Groupbox;
        QSpinBox* NofLines_Spinbox;
        Line_struct_t lines[MAXLINES];
    };

    Subplot_struct_t Subplots[MAXSUBPLOTS];

//    QList<QCPAxisRect*> allAxesRect;
//    QCPAxisRect* allAxesRect_[MAXSUBPLOTS];

    void updateconsole(QByteArray incomingdata);

    QColor getcolor(int idx);
};

#endif // WIDGET_H
