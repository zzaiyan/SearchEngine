#include "layout.h"

// #include <Python.h>
#include <QApplication>
#include <QFile>
#include <QStackedWidget>
#include <QTextStream>

QString readTextFile(QString path) {
  QFile file(path);
  if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
    QTextStream in(&file);
    return in.readAll();
  }
  return {};
}

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  Layout w;
  w.setWindowTitle("My Search Engine");

  w.show();
  return a.exec();
}
