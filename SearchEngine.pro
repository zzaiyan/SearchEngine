QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    home.cpp

HEADERS += \
    cppjieba/DictTrie.hpp \
    cppjieba/FullSegment.hpp \
    cppjieba/HMMModel.hpp \
    cppjieba/HMMSegment.hpp \
    cppjieba/Jieba.hpp \
    cppjieba/KeywordExtractor.hpp \
    cppjieba/MPSegment.hpp \
    cppjieba/MixSegment.hpp \
    cppjieba/PosTagger.hpp \
    cppjieba/PreFilter.hpp \
    cppjieba/QuerySegment.hpp \
    cppjieba/SegmentBase.hpp \
    cppjieba/SegmentTagged.hpp \
    cppjieba/TextRankExtractor.hpp \
    cppjieba/Trie.hpp \
    cppjieba/Unicode.hpp \
    home.h \
    limonp/ArgvContext.hpp \
    limonp/BlockingQueue.hpp \
    limonp/BoundedBlockingQueue.hpp \
    limonp/BoundedQueue.hpp \
    limonp/Closure.hpp \
    limonp/Colors.hpp \
    limonp/Condition.hpp \
    limonp/Config.hpp \
    limonp/FileLock.hpp \
    limonp/ForcePublic.hpp \
    limonp/LocalVector.hpp \
    limonp/Logging.hpp \
    limonp/Md5.hpp \
    limonp/MutexLock.hpp \
    limonp/NonCopyable.hpp \
    limonp/StdExtension.hpp \
    limonp/StringUtil.hpp \
    limonp/Thread.hpp \
    limonp/ThreadPool.hpp \
    processer.hpp

FORMS += \
    home.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    dict/README.md \
    dict/hmm_model.utf8 \
    dict/idf.utf8 \
    dict/jieba.dict.utf8 \
    dict/pos_dict/char_state_tab.utf8 \
    dict/pos_dict/prob_emit.utf8 \
    dict/pos_dict/prob_start.utf8 \
    dict/pos_dict/prob_trans.utf8 \
    dict/stop_words.utf8 \
    dict/user.dict.utf8
