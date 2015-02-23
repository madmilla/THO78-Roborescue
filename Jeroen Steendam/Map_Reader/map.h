#ifndef MAP_H
#define MAP_H

#include <QString>
#include <vector>

class MapWidget;

class Map
{
public:
    static const int VALUE_FREE = 0;
    static const int VALUE_WALL = 1;
    static const int VALUE_QUAD = 2;
public:
    Map();
    Map(const QString &fileName);
    Map(int width, int height);
    ~Map();

    void load(const QString &fileName);
    void save(const QString &fileName);

    int getWidth() { return width; }
    int getHeight() { return height; }
private:
    std::vector<char> data;
    int width;
    int height;
    friend class MapWidget;
    friend class MapTester;
};

#endif // MAP_H
