#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
  Q_OBJECT //!OCLINT

public:
  explicit Dialog(QWidget *parent = 0);
  ~Dialog();

  QString text() const noexcept;

public slots:
  void keyPressEvent(QKeyEvent * event);

private:
  Ui::Dialog *ui;
};

#endif // DIALOG_H
