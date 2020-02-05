#ifndef AplusRulePrintItemHEADER
#define AplusRulePrintItemHEADER

///////////////////////////////////////////////////////////////////////////////
//
// Copyright (c) 1997-2008 Morgan Stanley All rights reserved.
// See .../src/LICENSE for terms of distribution.
//
//
///////////////////////////////////////////////////////////////////////////////

#include <AplusGUI/Macros.H>
#include <MSGUI/MSPrintItem.H>
#include <MSGUI/MSWidgetView.H>
#include <MSTypes/MSTime.H>
#include <a/k.h>

class AplusRulePrintItem : public MSWidgetView, public MSRulePrintItem {
public:
    AplusRulePrintItem(MSWidget*);
    AplusRulePrintItem(const AplusRulePrintItem&);
    ~AplusRulePrintItem(void);

    virtual void addSenderNotify(MSEventSender*);
    virtual void receiveEvent(MSEvent&);

    static MSBoolean verifyData(V, ::A);

    virtual const MSSymbol& widgetType(void) const;
    static const MSSymbol& symbol(void);

    inline int topPixel(void) const;
    inline void topPixel(int);
    inline int bottomPixel(void) const;
    inline void bottomPixel(int);

    STANDARD_WIDGET_METHODS_H
};

inline int AplusRulePrintItem::topPixel(void) const { return MSPrintItem::topPixel(); }
inline void AplusRulePrintItem::topPixel(int i_) { MSPrintItem::topPixel(i_); }
inline int AplusRulePrintItem::bottomPixel(void) const { return MSPrintItem::bottomPixel(); }
inline void AplusRulePrintItem::bottomPixel(int i_) { MSPrintItem::bottomPixel(i_); }

#endif //AplusRulePrintItemHEADER
