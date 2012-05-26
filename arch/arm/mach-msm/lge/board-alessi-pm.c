/* arch/arm/mach-msm/lge/board-alessi-pm.c
 * Copyright (C) 2010 LGE, Inc.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include <linux/platform_device.h>
#include <linux/pm.h>
#include <linux/gpio.h>
#include <mach/board.h>
#include <mach/board_lge.h>
#include "board-alessi.h"

// ALESSI DISABLE
//int lcd_bl_power_state=0;
// ALESSI DISABLE
int alessi_pwrsink_suspend_noirq(struct device *dev)
{
	printk(KERN_INFO"%s: configure gpio for suspend\n", __func__);
// ALESSI DISABLE
#if 0
	camera_power_mutex_lock();

	if(camera_power_state == CAM_POWER_ON)
	{
		camera_power_mutex_unlock();
		return 0;
	}
#endif 
// ALESSI DISABLE
	gpio_tlmm_config(GPIO_CFG(GPIO_LCD_BL_EN, 0, GPIO_CFG_INPUT, GPIO_CFG_PULL_DOWN, GPIO_CFG_2MA), GPIO_CFG_ENABLE);

	gpio_tlmm_config(GPIO_CFG(GPIO_BL_I2C_SCL, 0, GPIO_CFG_INPUT, GPIO_CFG_NO_PULL, GPIO_CFG_2MA), GPIO_CFG_ENABLE);

	gpio_tlmm_config(GPIO_CFG(GPIO_BL_I2C_SDA, 0, GPIO_CFG_INPUT, GPIO_CFG_NO_PULL, GPIO_CFG_2MA), GPIO_CFG_ENABLE);

//	gpio_tlmm_config(GPIO_CFG(GPIO_LCD_VSYNC_O, 0, GPIO_CFG_INPUT, GPIO_CFG_PULL_DOWN, GPIO_CFG_2MA), GPIO_CFG_ENABLE);

	gpio_tlmm_config(GPIO_CFG(GPIO_LCD_MAKER_LOW, 0, GPIO_CFG_OUTPUT, GPIO_CFG_PULL_DOWN, GPIO_CFG_2MA), GPIO_CFG_ENABLE);
	/* gpio_direction_output(GPIO_LCD_MAKER_LOW, 0); */

	gpio_tlmm_config(GPIO_CFG(GPIO_LCD_RESET_N, 0, GPIO_CFG_OUTPUT, GPIO_CFG_PULL_DOWN, GPIO_CFG_2MA), GPIO_CFG_ENABLE);
	/* gpio_direction_output(GPIO_LCD_RESET_N, 0); */

// ALESSI DISABLE
#if 0
	lcd_bl_power_state = BL_POWER_SUSPEND;
	camera_power_mutex_unlock();
#endif 
// ALESSI DISABLE
	return 0;
}

int alessi_pwrsink_resume_noirq(struct device *dev)
{
	printk(KERN_INFO"%s: configure gpio for resume\n", __func__);
// ALESSI DISABLE
#if 0
	camera_power_mutex_lock();

	if(camera_power_state == CAM_POWER_ON || lcd_bl_power_state == BL_POWER_RESUME)
	{
		camera_power_mutex_unlock();
		return 0;
	}
#endif 
// ALESSI DISABLE
	gpio_tlmm_config(GPIO_CFG(GPIO_LCD_BL_EN, 0, GPIO_CFG_OUTPUT, GPIO_CFG_NO_PULL, GPIO_CFG_2MA), GPIO_CFG_ENABLE);
	gpio_direction_output(GPIO_LCD_BL_EN, 1);

	gpio_tlmm_config(GPIO_CFG(GPIO_BL_I2C_SCL, 0, GPIO_CFG_OUTPUT, GPIO_CFG_NO_PULL, GPIO_CFG_2MA), GPIO_CFG_ENABLE);
	gpio_direction_output(GPIO_BL_I2C_SCL, 1);

	gpio_tlmm_config(GPIO_CFG(GPIO_BL_I2C_SDA, 0, GPIO_CFG_OUTPUT, GPIO_CFG_NO_PULL, GPIO_CFG_2MA), GPIO_CFG_ENABLE);
	gpio_direction_output(GPIO_BL_I2C_SDA, 1);

//	gpio_tlmm_config(GPIO_CFG(GPIO_LCD_VSYNC_O, 0, GPIO_CFG_INPUT, GPIO_CFG_PULL_DOWN, GPIO_CFG_2MA), GPIO_CFG_ENABLE);

	gpio_tlmm_config(GPIO_CFG(GPIO_LCD_MAKER_LOW, 0, GPIO_CFG_INPUT, GPIO_CFG_PULL_UP, GPIO_CFG_2MA), GPIO_CFG_ENABLE);

	gpio_tlmm_config(GPIO_CFG(GPIO_LCD_RESET_N, 0, GPIO_CFG_OUTPUT, GPIO_CFG_PULL_DOWN, GPIO_CFG_2MA), GPIO_CFG_ENABLE);
	/* gpio_direction_output(GPIO_LCD_RESET_N, 0); */

// ALESSI DISABLE
#if 0
	lcd_bl_power_state = BL_POWER_RESUME;

	camera_power_mutex_unlock();
#endif 
// ALESSI DISABLE

	return 0;
}

// ALESSI DISABLE
#if 0
void thunderg_pwrsink_resume()
{
	gpio_tlmm_config(GPIO_CFG(GPIO_LCD_BL_EN, 0, GPIO_CFG_OUTPUT, GPIO_CFG_NO_PULL, GPIO_CFG_2MA), GPIO_CFG_ENABLE);
	gpio_direction_output(GPIO_LCD_BL_EN, 1);

	gpio_tlmm_config(GPIO_CFG(GPIO_BL_I2C_SCL, 0, GPIO_CFG_OUTPUT, GPIO_CFG_NO_PULL, GPIO_CFG_2MA), GPIO_CFG_ENABLE);
	gpio_direction_output(GPIO_BL_I2C_SCL, 1);

	gpio_tlmm_config(GPIO_CFG(GPIO_BL_I2C_SDA, 0, GPIO_CFG_OUTPUT, GPIO_CFG_NO_PULL, GPIO_CFG_2MA), GPIO_CFG_ENABLE);
	gpio_direction_output(GPIO_BL_I2C_SDA, 1);

//	gpio_tlmm_config(GPIO_CFG(GPIO_LCD_VSYNC_O, 0, GPIO_CFG_INPUT, GPIO_CFG_PULL_DOWN, GPIO_CFG_2MA), GPIO_CFG_ENABLE);

	gpio_tlmm_config(GPIO_CFG(GPIO_LCD_MAKER_LOW, 0, GPIO_CFG_INPUT, GPIO_CFG_PULL_UP, GPIO_CFG_2MA), GPIO_CFG_ENABLE);

	gpio_tlmm_config(GPIO_CFG(GPIO_LCD_RESET_N, 0, GPIO_CFG_OUTPUT, GPIO_CFG_NO_PULL, GPIO_CFG_2MA), GPIO_CFG_ENABLE);
	gpio_direction_output(GPIO_LCD_RESET_N, 0);

	lcd_bl_power_state = BL_POWER_RESUME;
}
#endif 
// ALESSI DISABLE
static struct dev_pm_ops alessi_pwrsink_data = {
	.suspend_noirq = alessi_pwrsink_suspend_noirq,
	.resume_noirq = alessi_pwrsink_resume_noirq,
};

static struct platform_device alessi_pwrsink_device = {
	.name = "lge-pwrsink",
	.id = -1,
	.dev = {
		.platform_data = &alessi_pwrsink_data,
	},
};

void __init lge_add_pm_devices(void)
{
// ALESSI DISABLE
//	lcd_bl_power_state = BL_POWER_RESUME;
// ALESSI DISABLE	
	platform_device_register(&alessi_pwrsink_device);
}
