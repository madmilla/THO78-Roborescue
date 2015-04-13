#ifndef TEST_H
#define TEST_H
//! The test object
/*!
The object will run a test to check te code logics
*/

class Test
{
public:
    //!The Contructor for the test
    Test();
    //!The Decontructor for the test
    ~Test();
    //! run the test
    /*!
    get a the result of the test in a number of failures
    @return int: the int which will contain the number of failures
    */
    int run();
};

#endif // TEST_H
