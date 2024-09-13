#ifndef __KEY_H
#define __KEY_H

/**本程序只用了四个按键
如有需要
可自行去Key.c文件添加，例：

*/

#ifdef __cplusplus
extern "C" { 
#endif

void Button_Init(void);
void Single_Click(void)；//单击
void Double_Click(void)；//双击
void Long_Preass_Start(void)；//长按
void Button_Start(void)；

#ifdef __cplusplus
}
#endid

#endif 
