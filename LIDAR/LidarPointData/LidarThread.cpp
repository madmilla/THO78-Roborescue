#include "LidarThread.h"
#include <QThread>
#include <QObject>
#include <QDebug>

LidarThread::LidarThread(Lidar &l):
    Stop(false),
    isPaused(false),
    lidar(l)
{}

void LidarThread::run()
{
    lidar.connectDriversLidar();
    int i = 0;
    while(!Stop) {
        sync.lock();
        if(isPaused){
            pauseCond.wait(&sync);
        }
        sync.unlock();

        std::vector<scanDot> data = lidar.startSingleLidarScan();

        if(data.empty()) {
            qDebug()<< "From lidar thread: "<<currentThreadId() << " failed";
        }
        else {
            i++;
            emit updateUI(printReadyData(data,i));
        }

    }
    qDebug()<<"After while lidar thread: "<<currentThreadId() << "state: " << Stop;
    //exec();
}

void LidarThread::resume()
{
    sync.lock();
    isPaused = false;
    sync.unlock();
    pauseCond.wakeAll();
}

void LidarThread::pause()
{
    sync.lock();
    isPaused = true;
    sync.unlock();
}

QString LidarThread::printReadyData(std::vector<scanDot> data, int i)
{

    QString s;
    s.append(QString("Scan: %1\n").arg(QString::number(i)));

    for (int pos = 0; pos < (int)data.size(); ++pos) {
        QString angle = QString::number(data[pos].angle);
        QString dist = QString::number(data[pos].dist);
        QString qual = QString::number(data[pos].quality);

        s.append(QString("%1\t %2\t %3\t \n").arg(angle).arg(dist).arg(qual));
    }
    s.append("\n");

    return s;
}
