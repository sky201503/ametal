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
 * \brief ֹͣģʽ���̣�ͨ��������ӿ�ʵ��
 *
 * - ʵ������
 *   1. MCU ����ֹͣģʽʱ�� J-Link ���ԶϿ���
 *   2. ���� KEY/RES ������ MCU��������� wake_up������������С�
 *
 * \par Դ����
 * \snippet demo_zmf159_drv_stopmode_wake_up.c src_zmf159_drv_stopmode_wake_up
 *
 * \internal
 * \par Modification History
 * - 1.00 17-04-15  nwt, first implementation
 * \endinternal
 */

/**
 * \addtogroup demo_if_zmf159_drv_stopmode_wake_up
 * \copydoc demo_zmf159_drv_stopmode_wake_up.c
 */

/** [src_zmf159_drv_stopmode_wake_up] */
#include <demo_zmf159_core_entries.h>
#include "ametal.h"
#include "am_board.h"
#include "am_led.h"
#include "am_delay.h"
#include "am_gpio.h"
#include "am_vdebug.h"
#include "zmf159_pin.h"
#include "am_zmf159_pwr.h"
#include "am_zmf159_inst_init.h"

/**
 * \brief �����жϷ�����
 */
static void gpio_isr (void *p_arg)
{
    ;
}

/**
 * \brief �������
 */
void demo_zmf159_drv_stopmode_wake_up_entry (void)
{
    uint32_t i = 0;

    AM_DBG_INFO("low power test!\r\n");

    am_zmf159_pwr_inst_init();

    /* �������� */
    am_zmf159_wake_up_cfg(AM_ZMF159_PWR_MODE_STOP, gpio_isr, (void *)0);

    for (i = 0; i < 5; i++) {
        am_mdelay(1000);
    }

    /* ����ͣ��ģʽ */
    am_zmf159_pwr_mode_into(AM_ZMF159_PWR_MODE_STOP);

    AM_DBG_INFO("wake_up!\r\n");

    while (1) {

        /* ָʾ��ָʾʱ���Ƿ�ָ����� */
        am_led_on(LED0);
        am_mdelay(500);
        am_led_off(LED0);
        am_mdelay(500);

    }
}
/** [src_zmf159_drv_stopmode_wake_up] */

/* end of file */