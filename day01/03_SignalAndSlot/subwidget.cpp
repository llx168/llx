#include "subwidget.h"

SubWidget::SubWidget(QWidget *parent) : QWidget(parent)
{
    p1.setText("切换到父窗口");
    this->setWindowTitle("子窗口");
    p1.move(100,100);
    p1.show();
    p1.setParent(this);
    resize(300,300);
    connect(&p1,&QPushButton::released,this,&SubWidget::EmitSignal);

}
void SubWidget::EmitSignal()
{
    emit MySignal();
    emit MySignal(100,"hello");
}
