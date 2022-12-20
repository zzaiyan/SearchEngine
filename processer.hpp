#ifndef PROCESSER_HPP
#define PROCESSER_HPP

#include <QDebug>
#include <QString>
#include <cstring>
#include <string>
#include <vector>
#include "cppjieba/Jieba.hpp"
using cppjieba::Jieba;
using std::string;
using std::vector;

const char* const DICT = "../SearchEngine/dict/jieba.dict.utf8";
const char* const HMM = "../SearchEngine/dict/hmm_model.utf8";
const char* const USER_DICT = "../SearchEngine/dict/user.dict.utf8";
const char* const IDF = "../SearchEngine/dict/idf.utf8";
const char* const STOP_WORD = "../SearchEngine/dict/stop_words.utf8";

class Processer {
 public:
  Processer() {
    jieba = new cppjieba::Jieba(DICT, HMM, USER_DICT, IDF, STOP_WORD);
  }

  ~Processer() { delete jieba; }

  vector<string> cut(const string& s) {
    vector<string> words;
    //    qDebug() << s.data();
    jieba->Cut(s, words, true);
    //    qDebug() << limonp::Join(words.begin(), words.end(), "/").data();
    return words;
  }

 private:
  Jieba* jieba;
};

#endif  // PROCESSER_HPP
