#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    // Otras funciones...

    void guardarDatosNeurona();  // Declaración de la función guardarDatosNeurona

    void on_Mostrar_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
