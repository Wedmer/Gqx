#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>

#include "GIdleHandler.h"

class QComboBox;

namespace Ui {
  class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();

protected:
  void closeEvent(QCloseEvent* event) Q_DECL_OVERRIDE Q_DECL_FINAL;

private:
  Ui::MainWindow *ui;
  QComboBox *combo_host_;
  GIdleHandler idle_handler_;

private slots:
  void on_actionHelpAbout_triggered();

private slots:
  void onIdle();

};

#endif // MAIN_WINDOW_H
