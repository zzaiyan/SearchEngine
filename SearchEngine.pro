QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    DataProcessesingFiles/trie.cpp \
    QtAwesome/QtAwesome.cpp \
    QtAwesome/QtAwesomeAnim.cpp \
    main.cpp \
    layout.cpp

HEADERS += \
    DataProcessesingFiles/trie.h \
    QtAwesome/QtAwesome.h \
    QtAwesome/QtAwesomeAnim.h \
    codes/trie \
    layout.h \
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
    layout.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Images.qrc \
    Images.qrc \
    QtAwesome/QtAwesome.qrc \
    QtAwesome/QtAwesome.qrc \
    StyleResource.qrc

SUBDIRS += \
    QtAwesome/QtAwesome.pro \
    QtAwesome/QtAwesome.pro

DISTFILES += \
    DataSet/舔狗日记1.txt \
    DataSet/舔狗日记2.txt \
    DataSet/舔狗日记3.txt \
    DataSet/舔狗日记4.txt \
    DataSet/舔狗日记5.txt \
    DataSet/英文短文0.txt \
    DataSet/英文短文1.txt \
    DataSet/英文短文2.txt \
    DataSet/英文短文3.txt \
    Images/Mainlogo.ico \
    Images/Mainlogo2RM.ico \
    Images/Newproject.png \
    Images/Save.png \
    Images/Save2.jpeg \
    Images/Save3.png \
    Images/aboutIcon.png \
    Images/copyIcon.png \
    Images/edit.png \
    Images/home.png \
    Images/open.png \
    Images/pasteIcon.png \
    Images/quitIcon.png \
    Images/redoIcon.png \
    Images/undoIcon.png \
    Project Reference/100795628_897330624066995_8068757898521477120_n.png \
    Project Reference/2 - Copy.png \
    Project Reference/2.JPG \
    Project Reference/2.png \
    Project Reference/3 - Copy - Copy.png \
    Project Reference/3 - Copy.png \
    Project Reference/3.png \
    Project Reference/Example Second Window .png \
    Project Reference/FindLy.exe \
    Project Reference/activity (1).jpeg \
    Project Reference/activity (2).jpeg \
    Project Reference/data-structure-project.pdf \
    QtAwesome/QtAwesome.pri \
    QtAwesome/fonts/fontawesome-4.7.0.ttf \
    README.md \
    Style/qss.qss \
    csdn/csdn.exe \
    csdn/csdn.py \
    csdn/run.bat \
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

#include(QtAwesome/QtAwesome.pri)
RC_ICONS = Images/Mainlogo2RM.ico
