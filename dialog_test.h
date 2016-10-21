#ifndef DIALOG_TEST_H
#define DIALOG_TEST_H

#include <QtTest/QtTest>

class dialog_test : public QObject
{
    Q_OBJECT //!OCLINT

private slots:
  void can_it_be_detected_if_key_press_had_an_effect();
};

#endif // DIALOG_TEST_H
