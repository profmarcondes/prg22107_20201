#ifndef FINDDIALOG_H
#define FINDDIALOG_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class FindDialog; }
QT_END_NAMESPACE

class FindDialog : public QDialog
{
        Q_OBJECT

    public:
        FindDialog(QWidget *parent = nullptr);
        ~FindDialog();

    private:
        Ui::FindDialog *ui;
};
#endif // FINDDIALOG_H
