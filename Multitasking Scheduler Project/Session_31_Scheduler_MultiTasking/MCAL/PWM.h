/**
 * @file    PWM.h
 * @brief   Timer0 fast PWM API.
 * @author  Marawan Azmy
 */

#ifndef PWM_H_
#define PWM_H_

void init_PWM(void);
void start_PWM(short value);	/* value: duty cycle, 0-255 */

#endif /* PWM_H_ */
