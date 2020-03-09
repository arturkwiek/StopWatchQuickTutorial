#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <QObject>
#include <QVariant>
#include <QTimer>
#include <QElapsedTimer>
#include <QtDebug>

class StopWatch: public QObject
{
    Q_OBJECT

    Q_PROPERTY(double best READ best WRITE setBest NOTIFY bestChanged)
    Q_PROPERTY(QString display READ display WRITE setDisplay NOTIFY displayChanged)

public:
    explicit StopWatch(QObject *parent = nullptr) {};

signals:
    void bestChanged();
    void displayChanged();

public slots:

    void start() {m_timer.start();}
    void stop() {m_timer.stop();}
    void reset() {m_timer.stop();m_timer.start();}
    void toogle(bool toogle) {m_fastest = toogle;}

private:
    QTimer m_timer;
    QElapsedTimer m_watch;
    QString m_display;
    double m_best;
    bool m_fastest;

    void timeout();
    void updateDisplay(bool reset = false);
    double best() {return m_best;}
    void  setBest(double value) {if(value != m_best) m_best = value; emit bestChanged();}
    QString display() {return m_display;}
    void setDisplay(QString value) {if(value != m_display) m_display = value; emit displayChanged();}



};

#endif // STOPWATCH_H
