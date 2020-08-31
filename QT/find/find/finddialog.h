#ifndef FINDDIALOG_H
#define FINDDIALOG_H

#include <QWidget>

class FindDialog : public QWidget
{
        Q_OBJECT

    public:
        FindDialog(QWidget *parent = nullptr);
        ~FindDialog();
};
#endif // FINDDIALOG_H
