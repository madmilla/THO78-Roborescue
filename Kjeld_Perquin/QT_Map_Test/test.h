#ifndef TEST_H
#define TEST_H
#include <string>

class Test
{
    /*!
     * \brief Outputs whether a test failed or not.
     *
     * \param testSucceeded Boolean stating whether the test failed or not
     * \param testName The name of the executed test.
     */
    void assert(bool testSucceeded, const std::string &testName);

    /*!
     * The number of errors encountered during a test.
     */
    int errors;
public:

    /*!
     * \brief Run an automated test on this program.
     *
     * \return The exit code afet running the tests
     * 0 means all tests have passed succesfully,
     * -1 means one or more tests have failed.
     */
    int runTests();
};
#endif // TEST_H
