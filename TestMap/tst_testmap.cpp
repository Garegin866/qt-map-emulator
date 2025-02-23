#include <QCoreApplication>
#include <QtTest>

#include "mainwindow.h"
#include "ui_mainwindow.h"

class TestMap : public QObject {
    Q_OBJECT

public:
    TestMap();
    ~TestMap();

private slots:
    void initTestCase();
    void cleanupTestCase();

    // Первая группа тестов.
    void TestSizeInit();
    void TestSizeWithBooks();
    void TestSizeWithAddedItem();

    // // Вторая группа тестов.
    void TestMainWidgetInit();
    void TestMainWidgetWithBooks();
    void TestMainWidgetWithAddedItem();

    // // Третья группа тестов.
    void TestEnableButtonsInit();
    void TestEnableButtonsWithBooks();
    void TestEnableButtonsWithAddedItem();
};

TestMap::TestMap() {}

TestMap::~TestMap() {}

void TestMap::initTestCase() {}

void TestMap::cleanupTestCase() {}

void TestMap::TestSizeInit() {
    MainWindow w;
    QVERIFY2(w.ui->txt_size, "Не найден элемент txt_size");
    QCOMPARE(w.ui->txt_size->text(), QString::number(0));
}

void TestMap::TestSizeWithBooks() {
    MainWindow w;

    QVERIFY2(w.ui->btn_books, "Не найден элемент btn_books");

    QTest::mouseClick(w.ui->btn_books, Qt::LeftButton);

    auto books_size = authors_and_books.size();
    QCOMPARE(w.ui->txt_size->text(), QString::number(books_size));
}

void TestMap::TestSizeWithAddedItem() {
    MainWindow w;

    QVERIFY2(w.ui->txt_elem_key, "Не найден элемент txt_elem_key");
    QVERIFY2(w.ui->txt_elem_value, "Не найден элемент txt_elem_value");
    QVERIFY2(w.ui->btn_set_by_key, "Не найден элемент btn_set_by_key");

    QTest::keyClicks(w.ui->txt_elem_key, "Test");
    QTest::keyClicks(w.ui->txt_elem_value, "Test");
    QTest::mouseClick(w.ui->btn_set_by_key, Qt::LeftButton);

    QCOMPARE(w.ui->txt_size->text(), QString::number(1));
}

void TestMap::TestMainWidgetInit() {
    MainWindow w;

    QVERIFY2(w.ui->list_widget, "Не найден элемент list_widget");
}

void TestMap::TestMainWidgetWithBooks() {
    MainWindow w;

    QVERIFY2(w.ui->btn_books, "Не найден элемент btn_books");
    QTest::mouseClick(w.ui->btn_books, Qt::LeftButton);

    auto books = authors_and_books;
    QCOMPARE(w.ui->list_widget->count() - 1, books.size());

    for (int i = 0; i < w.ui->list_widget->count() - 1; i++) {
        QString key = w.ui->list_widget->item(i)->text().split(": ")[0];
        QString value = w.ui->list_widget->item(i)->text().split(": ")[1];
        auto value_in_map = books[key.toStdString()];

        QCOMPARE(value, QString::fromStdString(value_in_map));
    }

    QCOMPARE(w.ui->list_widget->item(w.ui->list_widget->count() - 1)->text(), "end");
}

void TestMap::TestMainWidgetWithAddedItem() {
    MainWindow w;

    QVERIFY2(w.ui->txt_elem_key, "Не найден элемент txt_elem_key");
    QVERIFY2(w.ui->txt_elem_value, "Не найден элемент txt_elem_value");
    QVERIFY2(w.ui->btn_set_by_key, "Не найден элемент btn_set_by_key");

    QTest::keyClicks(w.ui->txt_elem_key, "Test");
    QTest::keyClicks(w.ui->txt_elem_value, "Test");
    QTest::mouseClick(w.ui->btn_set_by_key, Qt::LeftButton);

    QCOMPARE(w.ui->list_widget->count(), 2);
    QCOMPARE(w.ui->list_widget->item(0)->text(), "Test: Test");
}

void TestMap::TestEnableButtonsInit() {
    MainWindow w;

    QVERIFY2(w.ui->btn_inc_iterator, "Не найден элемент btn_inc_iterator");
    QVERIFY2(w.ui->btn_dec_iterator, "Не найден элемент btn_dec_iterator");
    QVERIFY2(w.ui->btn_erase, "Не найден элемент btn_erase");

    QVERIFY2(!w.ui->btn_inc_iterator->isEnabled(), "Кнопка btn_inc_iterator активна");
    QVERIFY2(!w.ui->btn_dec_iterator->isEnabled(), "Кнопка btn_dec_iterator активна");
    QVERIFY2(!w.ui->btn_erase->isEnabled(), "Кнопка btn_erase активна");
}

void TestMap::TestEnableButtonsWithBooks() {
    MainWindow w;

    QVERIFY2(w.ui->btn_books, "Не найден элемент btn_books");
    QTest::mouseClick(w.ui->btn_books, Qt::LeftButton);

    QVERIFY2(w.ui->btn_inc_iterator->isEnabled(), "Кнопка btn_inc_iterator не активна");
    QVERIFY2(!w.ui->btn_dec_iterator->isEnabled(), "Кнопка btn_dec_iterator активна");
    QVERIFY2(w.ui->btn_erase->isEnabled(), "Кнопка btn_erase не активна");
}

void TestMap::TestEnableButtonsWithAddedItem() {
    MainWindow w;

    QVERIFY2(w.ui->txt_elem_key, "Не найден элемент txt_elem_key");
    QVERIFY2(w.ui->txt_elem_value, "Не найден элемент txt_elem_value");
    QVERIFY2(w.ui->btn_set_by_key, "Не найден элемент btn_set_by_key");

    QTest::keyClicks(w.ui->txt_elem_key, "Test");
    QTest::keyClicks(w.ui->txt_elem_value, "Test");
    QTest::mouseClick(w.ui->btn_set_by_key, Qt::LeftButton);

    QVERIFY2(w.ui->btn_inc_iterator->isEnabled(), "Кнопка btn_inc_iterator не активна");
    QVERIFY2(!w.ui->btn_dec_iterator->isEnabled(), "Кнопка btn_dec_iterator активна");
    QVERIFY2(w.ui->btn_erase->isEnabled(), "Кнопка btn_erase не активна");
}

QTEST_MAIN(TestMap)

#include "tst_testmap.moc"
