#include <QApplication> 
#include <QWidget> 
#include <QLabel> 
#include <QPushButton> 
#include <QVBoxLayout> 
#include <iostream>
#include "Calculator.h"
#include <QImageReader> 


int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    Numbers window;
    QIcon icon("C:\\visual\\QtWidgetsApplication1\\calculator.png");

    window.setWindowFlags(Qt::WindowCloseButtonHint | Qt::WindowMinimizeButtonHint);
    window.setWindowIcon(icon);
    app.setWindowIcon(icon);
    window.show();
    app.exec();

    return 0;
}