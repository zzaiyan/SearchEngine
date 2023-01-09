#include "layout.h"
#include "ui_layout.h"

#include "QtAwesome/QtAwesome.h"
#include "QtAwesome/QtAwesomeAnim.h"

#include <QColor>
#include <QDebug>
#include <QDesktopServices>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QPalette>
#include <QPushButton>
#include <QTextStream>

Layout::Layout(QWidget *parent) : QMainWindow(parent), ui(new Ui::Layout) {
  ui->setupUi(this);

  QtAwesome *awesome = new QtAwesome(this);
  awesome->initFontAwesome(); // This line is important as it loads the font and
  ui->SearchButton->setEnabled(false);
  QListWidgetItem *listItem =
      new QListWidgetItem(QStringLiteral("文件列表"), ui->fileList);
  ui->fileList->addItem(listItem);
}

Layout::~Layout() { delete ui; }

void Layout::on_SearchButton_clicked() {
  ui->textEdit->clear();
  // first val
  std::string SearchValue = ui->lineEdit->text().toStdString();
  // call search
  RetVal = Trie.newSearch(SearchValue);  /*list*/
  int NumberOfWords = Trie.WordCounts(); /* val */
  ui->lineEdit_2->setText(QString::number(NumberOfWords));
  ui->statusBar->showMessage(
      "Searching Time: " + QString::number(Trie.SearchingTime()) + " Sec");
  GetFiles(RetVal);
  ui->stackedWidget->setCurrentIndex(1);
}

// 显示搜索结果
void Layout::GetFiles(std::list<QString> FileNames) {
  QFont font;
  if (FileNames.empty()) {
    ui->statusBar->showMessage("Not Find");
    return;
  }

  //  int i = FileNames.size();
  QFont font2;
  QColor color, color2;
  color.setBlue(180);
  font2.setFamily("微软雅黑");
  for (auto &File : FileNames) {
    QFile file(dirPath + "/" + File);
    if (!file.open(QIODevice ::ReadOnly)) {
      QMessageBox ::warning(this, "Opening Problem", "Current Files Not Found");
      return;
    }
    QTextStream in(&file);
    in.setCodec("utf-8");
    QString str = file.fileName();
    QStringList parts = str.split("/");
    QString lastBit = parts.at(parts.size() - 1);
    //-----------------------标题---------------------------
    font2.setPointSize(14);
    ui->textEdit->setCurrentFont(font2);
    ui->textEdit->setTextColor(color);
    ui->textEdit->insertPlainText(lastBit + "\n");
    //-----------------------rank---------------------------
    font2.setPointSize(10);
    color2.setGreen(120);
    ui->textEdit->setCurrentFont(font2);
    ui->textEdit->setTextColor(color2); // wolai !
    ui->textEdit->insertPlainText(
        "Rank Score: " + QString::number(Trie.textRank[lastBit]) + "\n");
    //-----------------------正文---------------------------
    // 通过关键词位置计算并显示上下文
    int leftpace = 50;
    int rightpace = 50;
    QString body;
    int begin = -1;
    int end = 0;
    QString text = in.readAll();

    { // keep the pace with Trie
      text.remove(' ');
      text.remove('\n');
      text.remove('\t');
    }

    QString requied_text = ui->lineEdit->text();
    int offset = Trie.getOffset(requied_text.toStdString(), File);
    //    qDebug() << QString::number(offset);
    int length = requied_text.size();
    begin = (offset - leftpace >= end) ? (offset - leftpace) : end;
    end = (offset + length + rightpace < text.size())
              ? (offset + length + rightpace)
              : text.size();
    body += text.mid(begin, end - begin);
    body += "...";
    // 对搜索字符串进行分词
    vector<string> words = Trie.pro.cut(requied_text.toStdString());
    // 通过html给关键词高亮
    for (int i = 0; i < words.size(); i++) {
      body.replace(QString::fromStdString(words[i]),
                   "<span style='color:red'>" +
                       QString::fromStdString(words[i]) + "</span>");
    }
    ui->textEdit->insertHtml(body + "<br><br>");
    //    qDebug() << QString::number(words.size());
  }
  QTextCursor textCursor = ui->textEdit->textCursor();
  textCursor.movePosition(QTextCursor::Start, QTextCursor::MoveAnchor, 1);
  ui->textEdit->setTextCursor(textCursor);
}

// void Layout::on_searchForward_clicked() {
//   ui->textEdit->find(ui->lineEdit->text());
// }

// void Layout::on_searchBackward_clicked() {
//   ui->textEdit->find(ui->lineEdit->text(), QTextDocument::FindBackward);
// }

// 读取目录下所有txt文件
void Layout::on_actionNew_triggered() {
  dirPath = QFileDialog::getExistingDirectory(this, "选择目录", "./",
                                              QFileDialog::ShowDirsOnly);
  ui->SearchButton->setEnabled(true);
  Trie.build_trie(dirPath);
  ui->statusBar->showMessage("Build Finish,     Time To Build: " +
                             QString::number(Trie.TimeBulding()) + " Sec");
  // qDebug() << dirPath;
  QDir Dir(dirPath);          // 查看工作路径是否存在
  Dir.setFilter(QDir::Files); // 设置过滤器只查看文件
  QStringList list = Dir.entryList(QDir::Files); // 获取所有文件
  foreach (QFileInfo file, list) { // 遍历只加载.txt到文件列表
    if (file.fileName().split(".").back() == "txt" ||
        file.fileName().split(".").back() == "md") {
      // 判断进行再次确认是.txt文件
      QListWidgetItem *item = new QListWidgetItem(file.fileName());
      ui->fileList->addItem(item);
    }
  }
}

void Layout::on_actionRedo_triggered() {
  ui->stackedWidget->setCurrentIndex(1);
}

void Layout::on_actionUndo_triggered() {
  ui->stackedWidget->setCurrentIndex(0);
}

void Layout::on_GetButton_clicked() {

  QDesktopServices::openUrl(QUrl("C:/Users/1/Desktop/csdn/run.bat"));
}
