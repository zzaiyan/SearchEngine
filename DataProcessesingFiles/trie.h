#ifndef TRIE_h
#define TRIE_h
#include "processer.hpp"
#include <QHash>
#include <QString>
#include <cmath>
#include <fstream>
#include <list>
#include <map>
#include <set>
#include <sstream>
#include <string>
#define Ump unordered_map

using namespace std;
struct node {
  list<QString> v;
  int count = 0;
  Ump<QString, int> firstOffset; // 在对应文章里第一次出现的位置（下标）
  Ump<QString, int> freq;
  Ump<char, node *> child;
};

class trie {
private:
  node *root;
  float TimeForCurrentSearch{0.0};
  float BuildingTime{0.0};
  int WordSCount{0};

  //  QHash<QString, int> qhash;

  struct SortUnit {
    QString name;
    int times;   // 种类数
    int cnt = 0; // 次数
    int len = 0;

    auto mark() const { // 种类数平方 * 次数 / 长度
      return 1.0 * times * times * cnt / len;
    }

    bool operator<(const SortUnit &b) const { return mark() > b.mark(); }
  };

public:
  Processer pro;
  //  QHash<QString, set<string>> textWordSet;
  QHash<QString, int> textLen;
  QHash<QString, double> textRank;

  trie();
  node *getNode(string word);
  void insert(string word_name, QString file_name, int offset);
  bool build_trie(QString path);
  list<QString> search(string requied_word_name);
  list<QString> newSearch(string requied_word_name);
  int getOffset(string requied_word_name, QString fileName);
  // bool search_bool(string requied_word_name);
  float TimeBulding() const;
  float SearchingTime() const;
  int WordCounts() const;
};
#endif // !TRIE_h
