#ifndef DIALOG_TEST_H
#define DIALOG_TEST_H

#include <QtTest/QtTest>

class dialog_test : public QObject
{
    Q_OBJECT //!OCLINT

private slots:

  //These are the main tests

  //Uses a QKeyEvent
  void key_event_1_should_have_an_effect();

  //Uses a QKeyEvent
  void key_event_2_should_have_no_effect_initially();

  //Uses a QKeyEvent
  void key_event_2_should_have_an_effect_after_key_1();

  //Uses a QKeyEvent
  void key_event_3_should_never_have_an_effect();


  //These are alternatioves

  //Uses QTest::keyClick
  void key_click_1_should_have_an_effect();

  //Uses QTest::keyClick
  void key_click_2_should_have_no_effect_initially();

  //Uses QTest::keyClick
  void key_click_2_should_have_an_effect_after_key_1();

  //Uses QTest::keyClick
  void key_click_3_should_never_have_an_effect();
};

#endif // DIALOG_TEST_H
