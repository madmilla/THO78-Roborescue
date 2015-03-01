#ifndef MAP_H
#define MAP_H


class Map
{
public:
    static const int MAP_WIDTH = 20;
    static const int MAP_HEIGHT = 20;
    static const char CHAR_FREE = '0';
    static const char CHAR_BLOCK = '1';
    static const char CHAR_QUAD = '2';
    static const int FREE = 0;
    static const int BLOCK = 1;
    static const int QUAD = 2;

    Map();
    ~Map();

    void set(int x, int y, int value);
    int get(int x, int y);

    static Map * loadFromFile(const char * filename);
    void saveToFile(const char * filename);

private:
    int objectMatrix[MAP_WIDTH][MAP_HEIGHT];
};

#endif // MAP_H
