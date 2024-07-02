#include "Calculator.h"

Numbers::Numbers(QWidget* parent) : QWidget(parent) {
    setupUI();
    setupConnections();
    currentOperation = ""; 
    storedValue = 0.0;
    vaule = true;
}

void Numbers::setupUI() {
    setWindowTitle("Calculator");
    resize(300, 500);

    QPalette windowPalette = palette();
    windowPalette.setColor(QPalette::Window, Qt::black);
    setPalette(windowPalette);

    label = new QLabel("0", this);
    label->setAlignment(Qt::AlignRight);
    label->setStyleSheet("font-size: 50px; background-color: black; color: white; border: 10px solid black;");
    label->setFixedHeight(80);
    label->setFixedWidth(300);
    label->move(0, 0);

    auto createButton = [this](const QString& text, int x, int y, int width, int height, const QColor& bgColor, const QColor& textColor) {
        QPushButton* button = new QPushButton(text, this);
        button->setFixedSize(width, height);
        button->move(x, y);

        QPalette palette = button->palette();
        palette.setColor(QPalette::Button, bgColor);
        palette.setColor(QPalette::ButtonText, textColor);
        button->setPalette(palette);
        button->setFont(QFont("Arial", 20));

        return button;
        };

    button = createButton("C", 0, 190, 70, 60, QColor("red"), Qt::black);
    buttonNum7 = createButton("7", 0, 250, 70, 60, Qt::white, Qt::black);
    buttonNum4 = createButton("4", 0, 310, 70, 60, Qt::white, Qt::black);
    buttonNum1 = createButton("1", 0, 370, 70, 60, Qt::white, Qt::black);
    buttonPercent = createButton("%", 0, 430, 70, 60, Qt::white, Qt::black);
    buttonDivision = createButton("÷", 75, 190, 70, 60, Qt::white, Qt::black);
    buttonNum8 = createButton("8", 75, 250, 70, 60, Qt::white, Qt::black);
    buttonNum5 = createButton("5", 75, 310, 70, 60, Qt::white, Qt::black);
    buttonNum2 = createButton("2", 75, 370, 70, 60, Qt::white, Qt::black);
    buttonNum0 = createButton("0", 75, 430, 70, 60, Qt::white, Qt::black);
    buttonMult = createButton("*", 150, 190, 70, 60, Qt::white, Qt::black);
    buttonNum9 = createButton("9", 150, 250, 70, 60, Qt::white, Qt::black);
    buttonNum6 = createButton("6", 150, 310, 70, 60, Qt::white, Qt::black);
    buttonNum3 = createButton("3", 150, 370, 70, 60, Qt::white, Qt::black);
    buttonDot = createButton(".", 150, 430, 70, 60, Qt::white, Qt::black);
    buttonDel = createButton("Del", 225, 190, 70, 60, QColor("#d9d9d9"), Qt::black);
    buttonMinus = createButton("-", 225, 250, 70, 60, Qt::white, Qt::black);
    buttonPlus = createButton("+", 225, 310, 70, 60, Qt::white, Qt::black);
    buttonEqual = createButton("=", 225, 370, 70, 120, QColor("#66ccff"), Qt::black);
}

void Numbers::setupConnections() {
    connect(buttonNum7, &QPushButton::clicked, this, &Numbers::ClickButton);
    connect(buttonNum4, &QPushButton::clicked, this, &Numbers::ClickButton);
    connect(buttonNum1, &QPushButton::clicked, this, &Numbers::ClickButton);
    connect(buttonPercent, &QPushButton::clicked, this, &Numbers::ClickButton);
    connect(buttonDivision, &QPushButton::clicked, this, &Numbers::ClickButton);
    connect(buttonNum8, &QPushButton::clicked, this, &Numbers::ClickButton);
    connect(buttonNum5, &QPushButton::clicked, this, &Numbers::ClickButton);
    connect(buttonNum2, &QPushButton::clicked, this, &Numbers::ClickButton);
    connect(buttonNum0, &QPushButton::clicked, this, &Numbers::ClickButton);
    connect(buttonMult, &QPushButton::clicked, this, &Numbers::ClickButton);
    connect(buttonNum9, &QPushButton::clicked, this, &Numbers::ClickButton);
    connect(buttonNum6, &QPushButton::clicked, this, &Numbers::ClickButton);
    connect(buttonNum3, &QPushButton::clicked, this, &Numbers::ClickButton);
    connect(buttonDot, &QPushButton::clicked, this, &Numbers::ClickButton);
    connect(buttonDel, &QPushButton::clicked, this, &Numbers::ClickButton);
    connect(buttonMinus, &QPushButton::clicked, this, &Numbers::ClickButton);
    connect(buttonPlus, &QPushButton::clicked, this, &Numbers::ClickButton);
    connect(buttonEqual, &QPushButton::clicked, this, &Numbers::ClickButton);
    connect(button, &QPushButton::clicked, this, &Numbers::ClickButton);
}

void Numbers::ClickButton() {
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    if (button) {
        QString buttonText = button->text();

        if (buttonText == "C") {
            label->setText("0");
            storedValue = 0.0;
            currentOperation.clear();
            vaule = true;
            return;
        }

        if (buttonText == "Del") {
            QString currentText = label->text();
            if (currentText.length() > 1) {
                currentText.chop(1);
            }
            else {
                currentText = "0"; 
            }
            label->setText(currentText);
            return;
        }

        if (buttonText == "+" || buttonText == "-" || buttonText == "*" || buttonText == "÷") {
            storedValue = label->text().toDouble();
            currentOperation = buttonText;
            vaule = true;
            return;
        }

        if (buttonText == "%") {
            double currentValue = label->text().toDouble() / 100.0;
            label->setText(QString::number(currentValue));
            currentOperation = "%";
            vaule = true;
            return;
        }

        if (buttonText == "=") {
            double currentValue = label->text().toDouble();
            double result = 0.0;

            if (currentOperation == "+") {
                result = storedValue + currentValue;
            }
            else if (currentOperation == "-") {
                result = storedValue - currentValue;
            }
            else if (currentOperation == "*") {
                result = storedValue * currentValue;
            }
            else if (currentOperation == "÷") {
                if (currentValue != 0) {
                    result = storedValue / currentValue;
                }
                else {
                    label->setText("Error");
                    return;
                }
            }

            label->setText(QString::number(result));
            currentOperation.clear();
            vaule = true;
            return;
        }

        QString currentText = label->text();

        if (buttonText == ".") {
            if (currentText.contains(".")) {
                return;
            }
        }

        if (vaule) {
            currentText = buttonText;
            vaule = false;
        }
        else {
            if (currentText == "0" && buttonText != ".") {
                currentText = buttonText;
            }
            else {
                currentText += buttonText;
            }
        }

        label->setText(currentText);
    }
}


