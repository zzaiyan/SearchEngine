#ifndef HOME_H
#define HOME_H

#include <QString>
#include <QWidget>
#include <cstring>
#include <string>
#include <vector>
#include "processer.hpp"

QT_BEGIN_NAMESPACE
namespace Ui {
class Home;
}
QT_END_NAMESPACE

class Home : public QWidget {
  Q_OBJECT

 public:
  Home(QWidget* parent = nullptr);
  ~Home();

 private:
  Ui::Home* ui;
  Processer pro;

  void test();
};
#endif  // HOME_H
