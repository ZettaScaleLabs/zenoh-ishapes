
#pragma once
#ifndef _ISHAPESFORM_HPP
#define _ISHAPESFORM_HPP

/** @file */

#include <QtWidgets/QtWidgets>

#if  (ISHAPES_WIDE_FORMAT == 1)
#   include <ui_iShapesForm.h>
#else
#   include <ui_iShapesForm-small.h>
#endif

#include <WriterQosDialog.hpp>
#include <ReaderQosDialog.hpp>
#include <FilterDialog.hpp>

#include <ShapesWidget.hpp>
#include <Circle.hpp>

#ifdef TESTBUILD
    #include <QtTest/QtTest>
#endif

#include "zenoh.hxx"

#define CN 9

/**
 * @addtogroup demos_iShapes
 */
/** @{*/

namespace demo { namespace ishapes {
class ShapesDialog : public QDialog
{
    Q_OBJECT
public:
    enum { CIRCLE = 0, SQUARE = 1, TRIANGLE = 2 };

    enum
    {
        BLUE    = 0,
        RED     = 1,
        GREEN   = 2,
        ORANGE  = 3,
        YELLOW  = 4,
        MAGENTA = 5,
        CYAN    = 6,
        GRAY    = 7,
        BLACK   = 8
    };

public:
    ShapesDialog();

    virtual ~ShapesDialog();
    void setConfiguration(zenoh::Config config);

    bool eventFilter(QObject* object, QEvent* event)
    {
        QString objname(object->objectName());
        QEvent ev = (QEvent)event->type();
        if(event->type() == QEvent::MouseButtonPress && object->objectName() == QString("renderFrame"))
        {
            if(!shapesWidget->paused())
            {
                shapesWidget->paused(true);
                mainWidget.PausedLabel->setVisible(true);
            }
            else
            {
                shapesWidget->paused(false);
                mainWidget.PausedLabel->setVisible(false);
            }
        }
        return QObject::eventFilter(object,event);
    }
public slots:
    virtual void onPublishButtonClicked();
    virtual void onSubscribeButtonClicked();
    virtual void onReaderQosButtonClicked();
    virtual void onWriterQosButtonClicked();
    virtual void onFilterButtonClicked();

private:
    ShapesDialog(const ShapesDialog& orig);

//Tests
private slots:
#ifdef TESTBUILD
    //Publisher or Subscriber with default QoS
    void CreatePublisher();
    void CreateSubscriber();
    //Publisher or Subscriber with mismatching QoS
    void CreatePublisherMMQos();
    void CreateSubscriberMMQos();
    //Comparison tests
    void logShape();
    void logDDSShape();
#endif

private:
    QTimer            timer;
    Ui::ShapesDialog  mainWidget;
    ShapesWidget*     shapesWidget;
    ReaderQosDialog   readerQos_;
    WriterQosDialog   writerQos_;
    FilterDialog*     filterDialog_;


    //Config config;
    std::shared_ptr<zenoh::Session> session;
    //zenoh::Publisher pub;
    //auto pub;
    std::vector<std::string>   filterParams_;
    const char *confStr;
};
}
}

/** @}*/

#endif	/* _ISHAPESFORM_HPP */
