#include <QtTest>
#include "MeticRegister.h"

// add necessary includes here

class exam_tests : public QObject
{
    Q_OBJECT

public:
    exam_tests();
    ~exam_tests();

private slots:
    void test_coutn_cometr();
};

exam_tests::exam_tests()
{

}

exam_tests::~exam_tests()
{

}


void exam_tests::test_coutn_cometr()
{
    MeticRegister::getInstance()->init("/Users/macbookegor/Desktop/Metric.txt");
    QCOMPARE(61,MeticRegister::getInstance()->coutn_cometr(6));
    QCOMPARE(32,MeticRegister::getInstance()->coutn_cometr(10));
    QCOMPARE(80,MeticRegister::getInstance()->coutn_cometr(1));
    QCOMPARE(20,MeticRegister::getInstance()->coutn_cometr(3));
    QCOMPARE(94,MeticRegister::getInstance()->coutn_cometr(25));
    QCOMPARE(101,MeticRegister::getInstance()->coutn_cometr(5));
    QCOMPARE(61,MeticRegister::getInstance()->coutn_cometr(67));
    QCOMPARE(88,MeticRegister::getInstance()->coutn_cometr(100));
    QCOMPARE(94,MeticRegister::getInstance()->coutn_cometr(45));
    QCOMPARE(44,MeticRegister::getInstance()->coutn_cometr(9));
}


QTEST_APPLESS_MAIN(exam_tests)

#include "tst_exam_tests.moc"
