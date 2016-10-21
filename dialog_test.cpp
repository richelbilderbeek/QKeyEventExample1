#include "dialog_test.h"

#include <cassert>
#include "dialog.h"

void dialog_test::can_it_be_detected_if_key_press_had_an_effect()
{
  Dialog d;
  QKeyEvent * const event1
    = new QKeyEvent(QKeyEvent::KeyPress, Qt::Key_1, Qt::NoModifier)
  ;
  QKeyEvent * const event2
    = new QKeyEvent(QKeyEvent::KeyPress, Qt::Key_2, Qt::NoModifier)
  ;
  QKeyEvent * const event3
    = new QKeyEvent(QKeyEvent::KeyPress, Qt::Key_3, Qt::NoModifier)
  ;
  event1->setAccepted(false);
  event2->setAccepted(false);
  event3->setAccepted(false);
  assert(!event1->isAccepted());
  assert(!event2->isAccepted());
  d.keyPressEvent(event2); //Will not be accepted now
  d.keyPressEvent(event1); //Will be accepted now
  d.keyPressEvent(event3); //Will never be accepted
  QVERIFY( event1->isAccepted());
  QVERIFY(!event2->isAccepted());
  QVERIFY(!event3->isAccepted());

  event1->setAccepted(false);
  event2->setAccepted(false);
  event3->setAccepted(false);
  assert(!event1->isAccepted());
  assert(!event2->isAccepted());
  assert(!event3->isAccepted());
  d.keyPressEvent(event1); //Will not be accepted now
  d.keyPressEvent(event2); //Will be accepted now
  d.keyPressEvent(event3); //Will never be accepted
  QVERIFY(!event1->isAccepted());
  QVERIFY( event2->isAccepted());
  QVERIFY(!event3->isAccepted());
}
