#include "maptester.h"

#include <iostream>

#include "map.h"

/**
 * @brief MapTester::MapTester
 *
 * Constructor
 */
MapTester::MapTester()
{

}

/**
 * @brief MapTester::~MapTester
 *
 * Desctructor
 */
MapTester::~MapTester()
{

}

/**
 * @brief MapTester::testMap
 * @param fileName
 *
 * Test Map implementation.
 * Step 1: Create map.
 * Step 2: Add random data.
 * Step 3: Save map to temporary file.
 * Step 4: Load map from temporary file.
 * Step 5: Compare data.
 */
void MapTester::testMap(const QString &fileName)
{
    // Make map
    Map map(20, 20);

    // Load with data
    for(unsigned int i = 0; i < map.data.size(); i++)
        map.data[i] = (qrand() % 3);

    // Save map
    map.save(fileName);

    // Load map
    Map loadedMap(fileName);

    // Check data
    for(unsigned int i = 0; i < map.data.size(); i++) {
        if(map.data[i] != loadedMap.data[i]) {
            std::cout << "Test failed!" << std::endl;
            return;
        }
    }

    std::cout << "Test succes!" << std::endl;
}

/**
 * @brief MapTester::testMap
 * @param fileName
 * @param count
 *
 * Test Map implementation multiple times.
 */
void MapTester::testMap(const QString &fileName, int count)
{
    if(count <= 0)
        return;

    if(fileName == NULL)
        return;

    for(int i = 0; i < count; i++) {
        testMap(fileName);
    }
}
