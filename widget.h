#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>
#include "mytransmission.h"
#include "eventsys.h"
#include "QKeyEvent"
#include "QMouseEvent"
#include "qfile.h"
#include "QDir"
#include "QDateTime"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
protected:
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

private:
    Ui::Widget *ui;
    void Enable_button(bool enable);
    ScanfSerialPort();
    QTimer *timer;
    QTimer *timer1;
    QTimer *KeyTimer;
    myTransmission *transmission;
    uint8_t key_Flag;
    void create_file(QString filePath,QString fileName);
    QString logfileDir;
    int8_t angle_speed = 0;
    int8_t line_speed  = 0;

private slots:
   void Onclean_battery_low_vol_error_Click();
   void Onclean_battery_over_vol_error_Click();
   void Onclean_motor_over_curr_error_Click();
   void Onclean_motor_over_temp_error_Click();
   void Onclean_motot1_commu_error_Click();
   void Onclean_motot2_commu_error_Click();
   void Onclean_motot3_commu_error_Click();
   void Onclean_motot4_commu_error_Click();
   void onCtr_source_switch_currentIndexChanged(int index);
   void onKey_Mouse_Ctrl_Mode_Enable_Click();
   void OnStartOrStopButton_Click();

   void OnlinespeedAdd1Click();
   void OnlinespeedAdd10Click();
   void OnanglespeedAdd1Click();
   void OnanglespeedAdd10Click();

   void OnlinespeedSub1Click();
   void OnlinespeedSub10Click();
   void OnanglespeedSub1Click();
   void OnanglespeedSub10Click();

   void LineEditChangeLineSpeed();
   void LineEditChangeAngleSpeed();


   void SetLineSpeed(int value);
   void SetAngleSpeed(int value);

   void Dispaly_FeedBack();
   void KeyChangeCtrlVal();


};

#endif // WIDGET_H
