#include "dialog.h"
#include "./ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    m_types.insert("Fish",2);
    m_types.insert("Cat",7);
    m_types.insert("Dog",5);
    m_types.insert("Mice",15);

    ui->cmbType->addItems(m_types.keys());
    ui->cmbType->setCurrentIndex(0);

}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_cmbType_currentIndexChanged(int index)
{
    Q_UNUSED(index);
    int m = m_types.value(ui->cmbType->currentText());
    ui->leMultiplier->setText(QString::number(m));
}


void Dialog::on_btnCalulate_clicked()
{
    bool ok = false;
    int v = ui->leValue->text().toInt(&ok);
    if(!ok) ui->leValue->setText("0");

    int m = ui->leMultiplier->text().toInt(&ok);
    if(!ok) ui->leMultiplier->setText("0");

    int r = v * m;
    ui->leResult->setText(QString::number(r));
}

