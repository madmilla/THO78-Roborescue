#ifndef MAPTESTER_H
#define MAPTESTER_H

#include <QString>

class MapTester
{
public:
    MapTester();
    ~MapTester();

    static void testMap(const QString &fileName);
    static void testMap(const QString &fileName, int count);
};

#endif // MAPTESTER_H
