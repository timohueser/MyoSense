#include "ledindicator.h"
#include <QPainter>

LedIndicator::LedIndicator(QWidget *parent) :
    QWidget(parent)
{
    setFixedSize(20, 10);
    lit = false;
    ledOnColor=Qt::green;
    ledOffColor=Qt::gray;
    ledOnPattern = Qt::SolidPattern;
    ledOffPattern = Qt::SolidPattern;
    ledSize=10;
}

void LedIndicator::paintEvent(QPaintEvent *) {
  QPainter p(this);
  lit ?  p.setBrush(QBrush(ledOnColor, ledOnPattern)) : p.setBrush(QBrush(ledOffColor, ledOffPattern));
  p.setPen(Qt::NoPen);
  p.drawEllipse(0,0,ledSize,ledSize);
}

void LedIndicator::switchLedIndicator() {
  lit = ! lit;
  repaint();
}
void LedIndicator::setState(bool state)
{
    lit = state;
    repaint();
}
void LedIndicator::toggle()
{
    lit = ! lit;
    repaint();
}

void LedIndicator::setOnColor(QColor onColor)
{
    ledOnColor=onColor;
    repaint();
}
void LedIndicator::setOffColor(QColor offColor)
{
    ledOffColor=offColor;
    repaint();
}
void LedIndicator::setOnPattern(Qt::BrushStyle onPattern)
{
    ledOnPattern=onPattern;
    repaint();
}
void LedIndicator::setOffPattern(Qt::BrushStyle offPattern)
{
    ledOffPattern=offPattern;
    repaint();
}
void LedIndicator::setLedSize(int size)
{
    ledSize=size;
    setFixedSize(size+10, size+10);
    repaint();
}
