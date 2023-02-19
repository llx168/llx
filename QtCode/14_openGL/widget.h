#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QOpenGLWidget>
#include<QOpenGLFunctions_4_5_Core>
#include <QOpenGLShaderProgram>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QOpenGLWidget,QOpenGLFunctions_4_5_Core
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
protected:
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();

private:
    Ui::Widget *ui;
    unsigned int VBO,VAO;
    unsigned int shaderProgram;
    QOpenGLShaderProgram *program;
};
#endif // WIDGET_H
