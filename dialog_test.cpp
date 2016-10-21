#include "dialog_test.h"

#include <cassert>
#include "dialog.h"

void dialog_test::key_click_1_should_have_an_effect()
{
  Dialog d;
  const auto text_before = d.text();
  QTest::keyClick(&d, Qt::Key_1);
  const auto text_after = d.text();
  QVERIFY(text_before != text_after);
}

void dialog_test::key_click_2_should_have_no_effect_initially()
{
  Dialog d;
  const auto text_before = d.text();
  QTest::keyClick(&d, Qt::Key_2);
  const auto text_after = d.text();
  QVERIFY(text_before == text_after);
}

void dialog_test::key_click_2_should_have_an_effect_after_key_1()
{
  Dialog d;
  const auto text_before = d.text();
  QTest::keyClick(&d, Qt::Key_1);
  QTest::keyClick(&d, Qt::Key_2);
  const auto text_after = d.text();
  QVERIFY(text_before == text_after);

}

void dialog_test::key_click_3_should_never_have_an_effect()
{
  Dialog d;
  const auto text_before = d.text();
  QTest::keyClick(&d, Qt::Key_3);
  const auto text_after = d.text();
  QVERIFY(text_before == text_after);
}


void dialog_test::key_event_1_should_have_an_effect()
{
  Dialog d;
  QKeyEvent * const event1
    = new QKeyEvent(QKeyEvent::KeyPress, Qt::Key_1, Qt::NoModifier)
  ;
  event1->setAccepted(false);
  d.keyPressEvent(event1);
  QVERIFY(event1->isAccepted());
  delete event1;
}

void dialog_test::key_event_2_should_have_no_effect_initially()
{
  Dialog d;
  QKeyEvent * const event2
    = new QKeyEvent(QKeyEvent::KeyPress, Qt::Key_2, Qt::NoModifier)
  ;
  event2->setAccepted(false);
  d.keyPressEvent(event2);
  QVERIFY(!event2->isAccepted());
  delete event2;
}

void dialog_test::key_event_2_should_have_an_effect_after_key_1()
{
  Dialog d;
  {
    QKeyEvent * const event1
      = new QKeyEvent(QKeyEvent::KeyPress, Qt::Key_1, Qt::NoModifier)
    ;
    event1->setAccepted(false);
    d.keyPressEvent(event1);
    assert(event1->isAccepted());
    delete event1;
  }
  QKeyEvent * const event2
    = new QKeyEvent(QKeyEvent::KeyPress, Qt::Key_2, Qt::NoModifier)
  ;
  event2->setAccepted(false);
  d.keyPressEvent(event2);
  QVERIFY(event2->isAccepted());
  delete event2;
}

void dialog_test::key_event_3_should_never_have_an_effect()
{
  Dialog d;
  QKeyEvent * const event3
    = new QKeyEvent(QKeyEvent::KeyPress, Qt::Key_3, Qt::NoModifier)
  ;
  event3->setAccepted(false);
  d.keyPressEvent(event3);
  QVERIFY(!event3->isAccepted());
  delete event3;
}
