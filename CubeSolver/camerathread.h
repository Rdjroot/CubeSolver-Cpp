#ifndef CAMERATHREAD_H
#define CAMERATHREAD_H

#include<vector>
#include<string>
#include <QWidget>
#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<unordered_map>
#include<QMessageBox>
#include<QDebug>
#include<QThread>

using namespace std;
using namespace cv;

class CameraThread : public QThread
{
    Q_OBJECT
public:
    CameraThread();
    ~CameraThread();

    // 线程停止
    void stop();

signals:
    // 控制显示的画面
    void frameReady(const Mat &frame);
    void framePause(const Mat &frame);

protected:
    // 函数重载，线程运行
    void run() override;

private:
    // 程序运行状态位
    bool running;

    VideoCapture cap;
    // 该信号用于决定，画面是继续分析，还是暂停处理
    bool flag;

public slots:
    // 修改画面用途
    void runOrPause(const bool f);
};

#endif // CAMERATHREAD_H