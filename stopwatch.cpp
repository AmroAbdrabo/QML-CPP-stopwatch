#include "stopwatch.h"
#include <QTimer>
#include <QDebug>

Stopwatch::Stopwatch(QObject *parent) : QObject(parent)
{
    connect(&m_timer, SIGNAL(timeout()), this, SLOT(timeout()));
    this->m_best = 0;
    this->last_elapsed = 0;
    this->stoppedClicked = false;
}

// ***************************** slots ***********************************
void Stopwatch::start(){
    this->m_timer.start(10);
    this->m_watch.restart();
}

void Stopwatch::stop(){
    this->m_timer.stop();

    double elapsed = this->m_watch.elapsed() + last_elapsed;
    last_elapsed = elapsed;
    qDebug() << last_elapsed;

    //this->m_watch.restart();

    //if (elapsed > this->m_best)
    //{
     //   setBest(elapsed);
     //   emit bestChanged();
     //   this->timeout();
    //}
    stoppedClicked = true;


}

void Stopwatch::reset(){
    m_watch.restart();
    last_elapsed = 0;
    updateDisplay(true);
    emit displayChanged();


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
    //qDebug() << last_elapsed;
    long long m_elapsed;
    if (stoppedClicked)
    {
        m_watch.restart();
        m_elapsed = m_watch.elapsed() + last_elapsed;
        stoppedClicked = false;
    }
    else {
        m_elapsed = m_watch.elapsed()+last_elapsed;
    }
    long long hours = (m_elapsed/1000)/3600;
    long long minutes = ((m_elapsed/1000)/60)%60;
    long long seconds =  (m_elapsed/1000)%60;
    long long centiseconds = (m_elapsed % 1000)/10;
    QString time = QString("%4:%3:%2.%1").arg(centiseconds).arg(seconds).arg(minutes).arg(hours);
    //setDisplay(QString::number(m_watch.elapsed()));
    setDisplay(time);
    emit displayChanged();
}


// ***************************** slots end *********************************
void Stopwatch::updateDisplay(bool reset){
    if (reset)
        setDisplay("0:0:0.00");
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

