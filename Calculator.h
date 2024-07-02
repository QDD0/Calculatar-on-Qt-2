#pragma once
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QImageReader> 
#include <QIcon> 

class Numbers : public QWidget {
public:
    Q_OBJECT

public:
    Numbers(QWidget* parent = nullptr);

private:
    QLabel* label;
    QPushButton* button;
    QPushButton* buttonNum7;
    QPushButton* buttonNum4;
    QPushButton* buttonNum1;
    QPushButton* buttonPercent;
    QPushButton* buttonDivision;
    QPushButton* buttonNum8;
    QPushButton* buttonNum5;
    QPushButton* buttonNum2;
    QPushButton* buttonNum0;
    QPushButton* buttonMult;
    QPushButton* buttonNum9;
    QPushButton* buttonNum6;
    QPushButton* buttonNum3;
    QPushButton* buttonDot;
    QPushButton* buttonDel;
    QPushButton* buttonMinus;
    QPushButton* buttonPlus;
    QPushButton* buttonEqual;
    QString currentOperation;

    double storedValue;
    bool vaule;

    void setupUI();
    void setupConnections();
    void ClickButton();

};