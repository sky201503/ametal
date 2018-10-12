/*******************************************************************************
*                                 AMetal
*                       ----------------------------
*                       innovating embedded platform
*
* Copyright (c) 2001-2018 Guangzhou ZHIYUAN Electronics Co., Ltd.
* All rights reserved.
*
* Contact information:
* web site:    http://www.zlg.cn/
*******************************************************************************/

/**
 * \file
 * \brief �����嵥4.13
 *
 * \note ��������Ҫ�õ�miniport��չ��
 *
 * \internal
 * \par Modification history
 * - 1.00 18-09-12  adw, first implementation
 * \endinternal
 */

#include "ametal.h"
#include "am_delay.h"
#include "digitron0.h"
int am_main (void)
{
    int i = 0;                     // ���������0

    digitron_init();
    while(1) {
        digitron_disp_num(0, i);   // com0��ʾi
        am_mdelay(1000);           // ��ʱ1s
        i = (i + 1) % 10;          // �������+1��������ʮ��һ
    }
}


/* end of file */
