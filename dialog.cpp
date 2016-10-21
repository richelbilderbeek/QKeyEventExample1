#include "dialog.h"
#include <QKeyEvent>
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::Dialog)
{
  ui->setupUi(this);
}

Dialog::~Dialog()
{
  delete ui;
}

void Dialog::keyPressEvent(QKeyEvent * event)
{
  if (ui->label->text() == "Press 1" && event->key() == Qt::Key_1)
  {
    ui->label->setText("Press 2");
    event->setAccepted(true);
    return;
  }
  if (ui->label->text() == "Press 2" && event->key() == Qt::Key_2)
  {
    ui->label->setText("Press 1");
    event->setAccepted(true);
    return;
  }
}
