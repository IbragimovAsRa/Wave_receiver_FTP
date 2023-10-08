#ifndef PLOTER_H
#define PLOTER_H

#define BUFFER_SIZE  8192

#include <QVector>
#include <QChart>
#include <QLineSeries>
#include <QChartView>
#include <QValueAxis>
#include <QMainWindow>
#include <QLabel>
#include <iostream>

class Ploter
{
public:
    explicit Ploter(QFrame *parrent = nullptr);
    void plot(short *dt);

private:
    QChartView *chartView;
    QValueAxis *axisX;
    QValueAxis *axisY;
    QLineSeries* series;
    QChart *chart;
    QFrame *parrentFrame;
    QStatusBar* statusBar;
    QLabel* viewMaxVal;
    QLabel* viewMedianVal;

    void sort(short *mas, int size);

};

#endif // PLOTER_H
