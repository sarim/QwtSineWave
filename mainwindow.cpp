#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->initPlot();

    this->timer = new QTimer(this);
    connect(this->timer, SIGNAL(timeout()), this, SLOT(update()));

    this->currentvalue = new qreal(0);


}

void MainWindow::initPlot(){
    ui->qwtPlot->setTitle("Sine Wave");
    ui->qwtPlot->setCanvasBackground(QColor(Qt::white));

    ui->qwtPlot->setAutoReplot(false);

    // axis
    ui->qwtPlot->setAxisTitle(QwtPlot::xBottom, "X Axis");
    ui->qwtPlot->setAxisTitle(QwtPlot::yLeft, "Y Axis");

    this->curve = new QwtPlotCurve("y = sin(x)");

    this->curve->attach(ui->qwtPlot);

    this->xvalue = new QVector<qreal>();
    this->yvalue = new QVector<qreal>();


}

void MainWindow::update(){

    (*this->currentvalue)+= 0.1;

    this->xvalue->append(*this->currentvalue);
    this->yvalue->append(qSin(*this->currentvalue));

    this->curve->setSamples( *this->xvalue,*this->yvalue);

    qDebug() << *this->currentvalue;

    ui->qwtPlot->replot();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnStart_clicked()
{
    this->timer->start(10);
    ui->btnStart->setEnabled(false);

}

void MainWindow::on_btn_quit_clicked()
{
    qApp->quit();
}
