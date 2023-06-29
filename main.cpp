#include <QCoreApplication>
#include "MeticRegister.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString filename = "/Users/macbookegor/Desktop/Metric.txt";
    MeticRegister::getInstance()->init(filename);

    MeticRegister::getInstance()->add_metr(200,3);

    MeticRegister::getInstance()->show_mert();

    int key = 5;
    qDebug() << "Sum for key:" << key << "= "<< MeticRegister::getInstance()->coutn_cometr(key);

    return a.exec();
}
