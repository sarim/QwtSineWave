#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <qwt_plot.h>
#include <qwt_plot_curve.h>
#include <QVector>
#include <QDebug>

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
    void on_btnStart_clicked();
    void update();


    void on_btn_quit_clicked();

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    QwtPlotCurve *curve;
    QVector<qreal> *xvalue;
    QVector<qreal> *yvalue;
    qreal *currentvalue;

    void initPlot();
};

#endif // MAINWINDOW_H
