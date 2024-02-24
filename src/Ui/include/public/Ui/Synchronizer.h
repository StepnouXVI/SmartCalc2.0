#pragma once
#include <QLineEdit>
#include <QObject>
#include <list>
#include <memory>
namespace Ui
{
    class Synchronizer: public QObject
    {
        Q_OBJECT
    public:
        using QLineEditPtr = std::shared_ptr<QLineEdit>;

    private:
        static std::list<QLineEditPtr> _lines;
        static Synchronizer _instance;

    public:
        static void AddLine(QLineEditPtr line);
    public slots:
        static void SynchronizeLines(const QString &text);

        static QLineEditPtr GetNewLine();

    private:
        Synchronizer();
    };
}