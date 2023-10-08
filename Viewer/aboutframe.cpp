#include "aboutframe.h"
#include <QFile>

AboutFrame::AboutFrame()
{
    aboutText = new QTextEdit(this);
    aboutText->resize(1000,680);
    aboutText->setReadOnly(true);
    QString contents = "<body>"
                            "<h2>"
                       "Тестовое задание"
                       "</h2>"
                       "<div>"
                       "Необходимо разработать десктопное приложение, принимающее данные по сетевому протоколу и выполняющее визуализацию этих данных"
                       "<div>"
                       "<body>";
    aboutText->setHtml(contents);
}

AboutFrame::~AboutFrame()
{
    delete aboutText;
}
