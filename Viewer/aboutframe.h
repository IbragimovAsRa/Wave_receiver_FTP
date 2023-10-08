#ifndef ABOUTFRAME_H
#define ABOUTFRAME_H

#include <QFrame>
#include <QTextEdit>

class AboutFrame : public QFrame
{
public:
    AboutFrame();
    ~AboutFrame();

private:
    QTextEdit *aboutText;

};

#endif // ABOUTFRAME_H
