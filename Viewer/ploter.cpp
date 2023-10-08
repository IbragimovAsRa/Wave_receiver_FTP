#include "ploter.h"

Ploter::Ploter(QFrame *parrent): parrentFrame{parrent}
{
    series = new QLineSeries;
    chart = new QChart;
    chartView = new QChartView;
    viewMaxVal = new QLabel(chartView);
    viewMedianVal = new QLabel(chartView);
    axisX = new QValueAxis;
    axisY = new QValueAxis;


    chart->addSeries(series);
    chart->addAxis(axisX, Qt::AlignBottom);
    chart->addAxis(axisY, Qt::AlignLeft);

    series->attachAxis(axisY);
    series->attachAxis(axisX);

    chartView->setParent(parrentFrame);
    chartView->setChart(chart);
    chartView->show();


    chartView->resize(1000,630);
    viewMaxVal->setGeometry(770,10, 200,30);
    viewMedianVal->setGeometry(770,40, 200,30);
    axisX->setRange(0, 4500);
    axisY->setRange(-500, 4500);
    chartView->setStyleSheet("background-color: white;");
}


void Ploter::plot(short * dt)
{
    chart->removeSeries(series);
    series->clear();

    for (int i = 0; i < BUFFER_SIZE/2 - 1; i++)
    {
        series->append(i, dt[i]);
    }

    chart->addSeries(series);
//    series->attachAxis(axisY);
//    series->attachAxis(axisX);

    sort(dt, BUFFER_SIZE/2-1);
    viewMaxVal->setText("Максимальное значение: " + QString::number(dt[BUFFER_SIZE/2-2]));
    viewMedianVal ->setText("Медиана: "+ QString::number(dt[BUFFER_SIZE/4]));
}

void Ploter::sort(short *mas, int size) {
    short i = 0;
    short j = size - 1;
    short mid = mas[size / 2];
    do {
        while(mas[i] < mid) {
            i++;
        }
        while(mas[j] > mid) {
            j--;
        }
        if (i <= j) {
            short tmp = mas[i];
            mas[i] = mas[j];
            mas[j] = tmp;

            i++;
            j--;
        }
    } while (i <= j);
    if(j > 0) {
        sort(mas, j + 1);
    }
    if (i < size) {
        sort(&mas[i], size - i);
    }
}


