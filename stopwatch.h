#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <QElapsedTimer>
#include <QTimer>


class Stopwatch : public QObject
{
    Q_OBJECT
public:
    explicit Stopwatch(QObject *parent = nullptr);
signals:
    void bestChanged();
    void displayChanged();
public slots:

    void start();
    void stop();
    void reset();
    void toggle(bool value);
private:
    QTimer m_timer;
    QElapsedTimer m_watch;
    QString m_display;
    double m_best;
    bool m_fastest;

    void timeout();
    void updateDisplay(bool reset = false);
    double best();
    void setBest(double value);
    QString display();
    void setDisplay(QString value);
};
#endif // STOPWATCH_H
