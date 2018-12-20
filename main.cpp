#include "mywidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    srand(time(0));
    QApplication app(argc, argv);
    MyWidget widget;
    widget.setGeometry(100, 100, 500, 355);
    widget.show();

    return app.exec();
}
