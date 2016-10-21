#include "dialog.h"
#include "dialog_test.h"
#include <QApplication>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);

  //Run the test
  if (argc == 1)
  {
    dialog_test t;
    return QTest::qExec(&t, argc, argv);
  }
  //Run the application
  Dialog w;
  w.show();
  return a.exec();
}
