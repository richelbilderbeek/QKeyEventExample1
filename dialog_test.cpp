#include "dialog_test.h"

#include "dialog.h"

void dialog_test::can_it_be_detected_if_key_press_had_an_effect()
{
  Dialog d;
  d.show();
  QVERIFY(1 == 2);
}
