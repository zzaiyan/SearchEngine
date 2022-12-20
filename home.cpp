#include "home.h"
#include <QDebug>
#include "ui_home.h"
using std::string;
using std::vector;

Home::Home(QWidget* parent) : QWidget(parent), ui(new Ui::Home) {
  ui->setupUi(this);
  test();
}

Home::~Home() {
  delete ui;
}

void Home::test() {
  auto vec = pro.cut(
      "由于种种原因，开发者往往会选择 Linux 作为编程环境，但 Linux "
      "的碎片化和严重滞后的软件生态阻碍了许多尝试，幸运的是，我们可以用 wsl2 "
      "来无痛解决 Linux 环境需求。");
  QString buf;
  for (auto&& s : vec)
    buf.append(QString(s.data()) + "/");
  qDebug() << buf;
}
