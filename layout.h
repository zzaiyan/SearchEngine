#ifndef LAYOUT_H
#define LAYOUT_H

#include "DataProcessesingFiles/trie.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE namespace Ui { class Layout; }
QT_END_NAMESPACE

class Layout : public QMainWindow {
  Q_OBJECT

public:
  Layout(QWidget *parent = nullptr);
  ~Layout();
private slots:

  void on_SearchButton_clicked();

  //  void on_searchForward_clicked();

  //  void on_searchBackward_clicked();

  void on_actionNew_triggered();

  void on_actionRedo_triggered();

  void on_actionUndo_triggered();

  void on_GetButton_clicked();

private:
  Ui::Layout *ui;
  QString dirPath;
  void GetFiles(std::list<QString> FileNames);
  list<QString> RetVal;
  trie Trie;
};
#endif // LAYOUT_H
