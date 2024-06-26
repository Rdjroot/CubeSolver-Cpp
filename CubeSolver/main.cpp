#include "mainwindow.h"
#include "welcome.h"
#include <opencv2/core.hpp> // 包含 OpenCV 核心模块
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // 注册 Mat 类型
    qRegisterMetaType<cv::Mat>("cv::Mat");

    Welcome w;
    w.setWindowTitle("CubeSolver");
    w.show();
    return a.exec();
}
