///////////////////////////////////////////////////////////////////////////////
//
// Copyright (c) 1997-2008 Morgan Stanley All rights reserved.
// See .../src/LICENSE for terms of distribution.
//
//
///////////////////////////////////////////////////////////////////////////////
#if HAVE_NEW
#include <new>
#else
#include <new.h>
#endif
#include <MSGUI/MSKeyPress.H>

typedef struct
{
    const char* _pTranslationString;
    const char* _pAPLString;
} APLKeyTranslationStruct;

static APLKeyTranslationStruct APLKeyTranslations[] = {
    { "<Key>KP_0", "0" },
    { "<Key>KP_1", "1" },
    { "<Key>KP_2", "2" },
    { "<Key>KP_3", "3" },
    { "<Key>KP_4", "4" },
    { "<Key>KP_5", "5" },
    { "<Key>KP_6", "6" },
    { "<Key>KP_7", "7" },
    { "<Key>KP_8", "8" },
    { "<Key>KP_9", "9" },
    { "<Key>KP_Decimal", "." },
    { "!Meta<Key>a", "�" },
    { "!Meta<Key>b", "�" },
    { "!Meta<Key>c", "�" },
    { "!Meta<Key>d", "�" },
    { "!Meta<Key>e", "�" },
    { "!Meta<Key>f", "_" },
    { "!Meta<Key>g", "�" },
    { "!Meta<Key>h", "�" },
    { "!Meta<Key>i", "�" },
    { "!Meta<Key>j", "�" },
    { "!Meta<Key>k", "'" },
    { "!Meta<Key>l", "�" },
    { "!Meta<Key>m", "|" },
    { "!Meta<Key>n", "�" },
    { "!Meta<Key>o", "�" },
    { "!Meta<Key>p", "*" },
    { "!Meta<Key>q", "?" },
    { "!Meta<Key>r", "�" },
    { "!Meta<Key>s", "�" },
    { "!Meta<Key>t", "~" },
    { "!Meta<Key>u", "�" },
    { "!Meta<Key>v", "�" },
    { "!Meta<Key>w", "�" },
    { "!Meta<Key>x", "�" },
    { "!Meta<Key>y", "�" },
    { "!Meta<Key>z", "�" },
    { "!Meta<Key>1", "�" },
    { "!Meta<Key>2", "�" },
    { "!Meta<Key>3", "<" },
    { "!Meta<Key>4", "�" },
    { "!Meta<Key>5", "=" },
    { "!Meta<Key>6", "�" },
    { "!Meta<Key>7", ">" },
    { "!Meta<Key>8", "�" },
    { "!Meta<Key>9", "�" },
    { "!Meta<Key>0", "^" },
    { "!Shift Meta<Key>exclam", "�" },
    { "!Shift Meta<Key>at", "�" },
    { "!Shift Meta<Key>numbersign", "�" },
    { "!Shift Meta<Key>dollar", "�" },
    { "!Shift Meta<Key>percent", "�" },
    { "!Shift Meta<Key>asciicircum", "�" },
    { "!Shift Meta<Key>ampersand", "�" },
    { "!Shift Meta<Key>asterisk", "�" },
    { "!Shift Meta<Key>parenleft", "�" },
    { "!Shift Meta<Key>parenright", "�" },
    { "!Shift Meta<Key>underscore", "!" },
    { "!Meta<Key>minus", "�" },
    { "!Meta<Key>equal", "�" },
    { "!Meta<Key>backslash", "�" },
    { "!Meta<Key>quoteleft", "�" },
    { "!Meta<Key>comma", "�" },
    { "!Meta<Key>bracketleft", "�" },
    { "!Meta<Key>bracketright", "�" },
    { "!Meta<Key>semicolon", "�" },
    { "!Meta<Key>apostrophe", "�" },
    { "!Meta<Key>period", "�" },
    { "!Meta<Key>slash", "�" },
    { "!Meta<Key>braceleft", "�" },
    { "!Meta<Key>at", "�" },
    { "!Meta<Key>numbersign", "�" },
    { "!Meta<Key>dollar", "�" },
    { "!Meta<Key>percent", "�" },
    { "!Meta<Key>asciicircum", "�" },
    { "!Meta<Key>ampersand", "�" },
    { "!Meta<Key>asterisk", "�" },
    { "!Meta<Key>parenleft", "�" },
    { "!Meta<Key>parenright", "�" },
    { "!Meta<Key>underscore", "!" },
    { "!Shift Meta <Key>plus", "�" },
    { "!Shift Meta <Key>bar", "�" },
    { "Shift Meta<Key>o", "�" },
    { "Shift Meta<Key>j", "�" },
    { "Shift Meta<Key>f", "�" },
    { "Shift Meta<Key>e", "�" },
    { "Shift Meta<Key>i", "�" },
    { "Shift Meta<Key>braceleft", "�" },
    { "Shift Meta<Key>braceright", "�" },
    { "Shift Meta<Key>s", "�" },
    { "Shift Meta<Key>g", "�" },
    { "Shift Meta<Key>h", "�" },
    { "Shift Meta<Key>l", "�" },
    { "Shift Meta<Key>colon", "�" },
    { "Shift Meta<Key>quotedbl", "�" },
    { "Shift Meta<Key>c", "�" },
    { "Shift Meta<Key>b", "�" },
    { "Shift Meta<Key>n", "�" },
    { "Shift Meta<Key>m", "�" },
    { "Shift Meta<Key>greater", "�" },
    { "Shift Meta<Key>p", "�" },
    { "Shift Meta<Key>y", "�" },
    { "Shift Meta<Key>z", "�" },
    { "Shift Meta<Key>q", "�" },
    { "Shift Meta<Key>x", "X" },
    { "Shift Meta<Key>v", "V" },
    { "Shift Meta<Key>slash", "?" },
    { 0, 0 }
};

MSKeyPress* _keyPressTable = 0;

// this class helps us clean up memory when
// the application exits.

class StaticInitClass {
public:
    StaticInitClass(void);
    ~StaticInitClass(void);
};

StaticInitClass::StaticInitClass(void) {}
StaticInitClass::~StaticInitClass(void)
{
    if (_keyPressTable != 0) {
        delete[](char*) _keyPressTable;
        _keyPressTable = 0;
    }
}

static StaticInitClass _staticInitClass;

static void initKeyPressTable(void)
{
    int n = sizeof(APLKeyTranslations) / sizeof(APLKeyTranslationStruct) - 1;
    _keyPressTable = (MSKeyPress*)new char[n * sizeof(MSKeyPress)];
    for (int i = 0; i < n; i++) {
        new (&_keyPressTable[i]) MSKeyPress(APLKeyTranslations[i]._pTranslationString);
    }
}

const char* aplKeyTranslationFunction(const XEvent* pEvent_)
{
    char buf[16];
    KeySym keysym;
    int len = XLookupString((XKeyEvent*)pEvent_, buf, 8, &keysym, NULL);
    buf[len] = '\0';

    if (_keyPressTable == 0)
        initKeyPressTable();
    int n = sizeof(APLKeyTranslations) / sizeof(APLKeyTranslationStruct) - 1;
    for (int i = 0; i < n; i++) {
        if (_keyPressTable[i].isMatch(keysym, pEvent_->xkey.state)) {
            return APLKeyTranslations[i]._pAPLString;
        }
    }
    return 0;
}
