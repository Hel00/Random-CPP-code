#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_listWidget_activated(const QModelIndex &index);

    void on_itemList_activated(const QModelIndex &index);

    void on_itemFilter_textChanged();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
