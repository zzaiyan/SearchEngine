#include "trie.h"
#include <QDebug>
#include <QDir>
#include <QFile>
#include <ctime>

node *getNewTrieNode() {
  node *new_node = new node;
  return new_node;
}
trie::trie() { root = nullptr; }

void trie::insert(string word_name, QString file_name, int offset) {
  //  wordSet.insert(word_name);
  if (root == nullptr)
    root = getNewTrieNode();
  node *temp = root;
  for (int i = 0; i < word_name.length(); i++) {
    char x = word_name[i];
    if (temp != nullptr && temp->child.count(x) == 0) {
      temp->child[x] = getNewTrieNode();
    }
    //    temp->child[x]->count++;
    //    temp->child[x]->v.push_back(file_name);
    temp = temp->child[x];
  }
  //如果分词没有在这篇文章出现过，就添加记录
  if (temp->firstOffset.count(file_name) == 0)
    temp->firstOffset[file_name] = offset;
  temp->count++;
  temp->v.push_back(file_name);
  temp->freq[file_name]++; // 分词在文章中出现的次数
  temp = nullptr;
}

bool trie::build_trie(QString path) {
  clock_t starting_build_time = clock();
  QDir Dir(path);             // 查看工作路径是否存在
  Dir.setFilter(QDir::Files); // 设置过滤器只查看文件
  QStringList list = Dir.entryList(QDir::Files); // 获取所有文件
  foreach (QFileInfo file, list) { // 遍历只加载.txt到文件列表
    QString fileName = path + "/" + file.fileName();
    // qDebug() << fileName;
    QFile inFile(fileName);
    if (!inFile.open(QIODevice::ReadOnly)) {
      qDebug() << "DATA_FILE read error!";
      exit(1);
    }
    QTextStream in(&inFile);
    in.setCodec("utf-8");
    QString text = in.readAll();
    // 移除空格，显示起来好看一点 那个偏移会变，
    // 万一显示时候也移除呢okk
    text.remove(' ');
    text.remove('\n');
    text.remove('\t');
    vector<string> words = pro.cut(text.toStdString());

    textLen[file.fileName()] = text.length();
    qDebug() << QString("%1.size = %2").arg(file.fileName()).arg(text.length());
    //    for (auto &str : words) { // 记录每篇文章的词汇表
    //      textWordSet[file.fileName()].insert(str);
    //    }

    for (int i = 0; i < words.size(); i++) {
      int offset = text.indexOf(QString::fromStdString(words[i]));
      insert(words[i], file.fileName(), offset);
    }
  }
  clock_t end_build_time = clock();
  BuildingTime = static_cast<float>(static_cast<float>(end_build_time) -
                                    starting_build_time) /
                 CLOCKS_PER_SEC;
  return true;
}

node *trie::getNode(string word) {
  node *temp = root;
  for (int j = 0; j < word.length(); j++) {
    if (temp != nullptr) // 找到分词对应的 node
      temp = temp->child[word[j]];
    else
      return nullptr;
  }
  temp->v.sort();
  temp->v.unique();
  return temp;
}

#include <QSet>
list<QString> trie::newSearch(string requied_word_name) {
  WordSCount = 0;
  vector<string> words = pro.cut(requied_word_name); // 对搜索字符串进行分词
  QHash<QString, int> textTypeCnt;                   // 文章的分词种类数
  QHash<QString, int> textWordNum;                   // 文章的关键词总数
  list<QString> resList;
  clock_t startingSearchtime = clock();
  for (int i = 0; i < words.size(); i++) { // 遍历所有分词
    node *temp = getNode(words[i]);
    if (temp == nullptr)
      continue;
    // 此时，temp即为对应的 node
    // 包含分词 i 出现的书名列表
    WordSCount += temp->count;
    for (auto &&text : temp->v) { // 对于出现该次的所有文章
      textTypeCnt[text]++;        // 文章的分词种类数
      qDebug() << text;
      //      temp->freq[text]++;         // 文章的分词种类数
    }
    qDebug() << QString::fromStdString(words[i]);
    // 合并文章列表 = temp->v.end(); it++) {
    //      resList.push_back(*it);
    //    }
  }
  //    for(auto& Ab:)
  vector<SortUnit> sortVec;
  for (auto it = textTypeCnt.begin(); it != textTypeCnt.end(); it++) {
    //    qDebug() << it.key() << it.value();
    sortVec.push_back({it.key(), it.value()});
  }

  for (size_t i = 0; i < sortVec.size(); i++) { // 对于每个文章
    auto &text = sortVec.at(i).name;

    //    set<string> Alphabet = textWordSet[text];
    for (auto &st : words) { // 对于每个分词
      auto temp = getNode(st);
      if (temp == nullptr)
        continue;
      int f = temp->freq[text]; // 该词在文章中的出现次数
      textWordNum[text] += f;   // 更新该文章的次数和
    }

    sortVec.at(i).cnt = textWordNum[text];
    sortVec.at(i).len = textLen[text];
    qDebug() << sortVec.at(i).name << sortVec.at(i).times << sortVec.at(i).cnt
             << sortVec.at(i).len;
    qDebug() << "Mark =" << sortVec.at(i).mark();

    textRank[text] = sortVec.at(i).mark(); // 就酱！
  }

  std::sort(sortVec.begin(), sortVec.end());

  clock_t EndSearchtime = clock();
  TimeForCurrentSearch = static_cast<float>((static_cast<float>(EndSearchtime) -
                                             startingSearchtime)) /
                         CLOCKS_PER_SEC;

  resList.clear();
  for (auto &i : sortVec) {
    resList.push_back(i.name);
  }
  return resList;
}

// list<QString> trie::search(string requied_word_name) { //已弃用
//   WordSCount = 0;
//   vector<string> words = pro.cut(requied_word_name); // 对搜索字符串进行分词
//   list<QString> resList;
//   clock_t startingSearchtime = clock();
//   for (int i = 0; i < words.size(); i++) {
//     node *temp = root;
//     list<QString> empty_list{};
//     for (int j = 0; j < words[i].length(); j++) {
//       temp = temp->child[words[i][j]];
//       if (temp == nullptr)
//         return empty_list;
//     }
//     WordSCount += temp->count;
//     // 合并文章列表
//     for (auto it = temp->v.begin(); it != temp->v.end(); it++) {
//       resList.push_back(*it);
//     }
//   }
//   clock_t EndSearchtime = clock();
//   TimeForCurrentSearch =
//   static_cast<float>((static_cast<float>(EndSearchtime) -
//                                              startingSearchtime)) /
//                          CLOCKS_PER_SEC;
//   resList.sort();   // 使列表有序
//   resList.unique(); // 对有序列表去重
//   return resList;
// }

int trie::getOffset(string requied_word_name, QString fileName) {
  vector<string> words = pro.cut(requied_word_name); // 对搜索字符串进行分词
  for (int i = 0; i < words.size(); i++) {
    node *temp = root;
    for (int j = 0; j < words[i].length(); j++) {
      temp = temp->child[words[i][j]];
      if (temp == nullptr)
        break;
    }
    if (temp != nullptr && temp->firstOffset.count(fileName)) {
      return temp->firstOffset[fileName];
    }
  }
  return -1;
}

float trie::TimeBulding() const { return BuildingTime; }

float trie::SearchingTime() const { return TimeForCurrentSearch; }

int trie::WordCounts() const { return WordSCount; }
