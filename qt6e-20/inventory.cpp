#include "inventory.h"

Inventory::Inventory(QObject *parent) : QObject(parent)
{
    load();
}

void Inventory::add(QString name, int qty)
{
    if(m_items.contains(name))
    {
        m_items[name] += qty;
    }
    else
    {
        m_items.insert(name,qty);
    }
}

void Inventory::remove(QString name, int qty)
{
    if(m_items.contains(name))
    {
        m_items[name] -= qty;
        if(m_items.value(name) < 0) m_items.remove(name);
        qInfo() << "Item removed";
    }
    else
    {
        qWarning() << "No item of that name!";;
    }
}

void Inventory::list()
{
    qInfo() << "Items:" << m_items.size();
    foreach(QString key, m_items.keys())
    {
        qInfo() << key << " = " << m_items.value(key);
    }
}

void Inventory::save()
{
    QFile file("inventory.txt");
    if(!file.open(QIODevice::WriteOnly))
    {
        qCritical() << "Could not save file:" << file.errorString();
        return;
    }

    QDataStream stream(&file);
    stream.setVersion(QDataStream::Qt_6_0);

    int len = m_items.size();
    stream << len;

    qInfo() << "Number of items to save:" << len;

    foreach(QString key, m_items.keys())
    {
        qInfo() << "Saving:" << key;
        stream << key;
        stream << m_items.value(key);
    }

    file.close();

    qInfo() << "File saved";

}

void Inventory::load()
{
    QFile file("inventory.txt");

    if(!file.exists())
    {
        qWarning() << "File does not exist!";
        return;
    }

    if(!file.open(QIODevice::ReadOnly))
    {
        qCritical() << "Could not open file:" << file.errorString();
        return;
    }

    QDataStream stream(&file);
    if(stream.version() != QDataStream::Qt_6_0)
    {
        qCritical() << "Wrong data stream version!";
        file.close();
        return;
    }

    m_items.clear();
    int max;
    stream >> max;

    qInfo() << "Number of items to load:" << max;

    for(int i = 0; i < max; i ++)
    {
        QString key;
        int qty;
        stream >> key;
        stream >> qty;
        m_items.insert(key,qty);
    }

    file.close();

    qInfo() << "File loaded";
}
