#include "stopwatch.h"
#include <QTimer>

Stopwatch::Stopwatch(QObject *parent) : QObject(parent)
{
    connect(&m_timer, SIGNAL(timeout()), this, SLOT(timeout()));
    this->m_best = 0;
}

// ***************************** slots ***********************************
void Stopwatch::start(){
    this->m_timer.start(10);
    this->m_watch.restart();
}

void Stopwatch::stop(){
    this->m_timer.stop();
    double elapsed = this->m_watch.elapsed();
    if (elapsed > this->m_best)
    {
        setBest(elapsed);
        emit bestChanged();
        this->timeout();
    }

}

void Stopwatch::reset(){
    m_watch.restart();


}
void Stopwatch::toggle(bool value){
    // value is true if it is slow, m_fastest true if it is fast
    // if value is true (slow) and m_fastest false then do nothing
    // if value is false (fast) and m_fastest true then do nothing
    // if value is false and m_fastest false then speed up
    // if value is true and m_fastest true then slow down
    if (value == m_fastest){
        if (value)
        {
            m_timer.setInterval(20);
        }else {
            m_timer.setInterval(10);
        }
        m_fastest = !value;
    }
}


void Stopwatch::timeout(){
    long long m_elapsed = m_watch.elapsed();
    long long seconds = m_elapsed/1000;
    double centiseconds = (m_elapsed % 1000);
    QString time = QString("%2.%1").arg(centiseconds, 2,'f', 0).arg(seconds);
    //setDisplay(QString::number(m_watch.elapsed()));
    setDisplay(time);
    emit displayChanged();
}


// ***************************** slots end *********************************
void Stopwatch::updateDisplay(bool reset){
    if (reset)
        setDisplay(QString::number(0));
}


double Stopwatch::best(){
    return m_best;
}
void Stopwatch::setBest(double value){
    m_best = value;
}
QString Stopwatch::display(){
    return m_display;
}
void Stopwatch::setDisplay(QString value){
    m_display = value;
}

