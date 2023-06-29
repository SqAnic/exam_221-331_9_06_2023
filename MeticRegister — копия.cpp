#include "MeticRegister.h"

MeticRegister::MeticRegister()
{

}


MeticRegister::~MeticRegister()
{

}


bool MeticRegister::add_metr(int resp_t, int wait_t)
{
    int first_size = ac_mas.size();
    ac_mas.insert(ac_mas.size() + 1, qMakePair(resp_t,wait_t));
    if (first_size != ac_mas.size())
    {
        qDebug() << "add_metr complete";
        return 1;
    }
    else
    {
        qDebug() << "add_metr false";
        return 0;
    }
}

bool MeticRegister::show_mert()
{
    bool flag;
    for (QMap<int, QPair<int,int>>::iterator it = ac_mas.begin(); it != ac_mas.end(); ++it)
    {
        qDebug() << "Key:" << it.key() << "Values:" << it.value().first << it.value().second;
        flag = true;
    }
    if (flag == true)
        return flag;
    else
        return false;
}

int MeticRegister::coutn_cometr(int key)
{
    if (ac_mas.contains(key))
    {
        QPair<int,int> values_map = ac_mas.value(key);
        int value1 = values_map.first;
        int value2 = values_map.second;
        int sum = value1 + value2;
        qDebug() << "Sum" << sum;
        return sum;
    }
    else
    {
        qDebug() << "Key is not in QMap";
        return 0;
    }
}

void MeticRegister::init(QString filename)
{
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Ошибка открытия файла";
    }

    QTextStream in(&file);

    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList parts = line.split(',');

        int time_key = parts[0].toInt();
        int value1 = parts[1].toInt();
        int value2 = parts[2].toInt();
        ac_mas.insert(time_key, qMakePair(value1, value2));
    }
    qDebug() << ac_mas;
}

MeticRegister* MeticRegister::p_instance;
MeticRegister_Destroyer MeticRegister::destroyer;
