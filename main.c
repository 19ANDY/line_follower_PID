/**
 * \file
 *
 * \brief Empty user application template
 *
 */

/**
 * \mainpage User Application template doxygen documentation
 *
 * \par Empty user application template
 *
 * Bare minimum empty user application template
 *
 * \par Content
 *
 * -# Include the ASF header files (through asf.h)
 * -# "Insert system clock initialization code here" comment
 * -# Minimal main function that starts with a call to board_init()
 * -# "Insert application code here" comment
 *
 */

/*
 * Include header files for all drivers that have been imported from
 * Atmel Software Framework (ASF).
 */
/*
 * Support and FAQ: visit <a href="http://www.atmel.com/design-support/">Atmel Support</a>
 */
 #include<avr/io.h>
 #include<util/delay.h>
 #include<compat/deprecated.h>
 void timer()
 {
	 TCCR1A|= (1<<COM1A1)|(1<<COM1B1)|(1<<WGM11);
	 TCCR1B|= (1<<WGM12)|(1<<WGM13)|(1<<CS10);
	 ICR1 = 50000;
	 OCR1A = 50000;
	 OCR1B = 50000;
 }
 void frnt()
 {
	 OCR1A=50200;
	 OCR1B=48000;
	 cbi(PORTD,2);
	 sbi(PORTD,3);
	 cbi(PORTD,6);
	 sbi(PORTD,7);
 }
 void ryt()
 {

	 OCR1A=40000;
	 OCR1B=50000;
	 cbi(PORTD,3);
	 cbi(PORTD,2);
	 sbi(PORTD,7);
	 cbi(PORTD,6);
 }
 void bck()
 {
	 OCR1A=25000;
	 OCR1B=25000;
	 cbi(PORTD,2);
	 sbi(PORTD,3);
	 sbi(PORTD,7);
	 cbi(PORTD,6);
 }
 void lft()
 {
	 
	 OCR1A=40000;
	 OCR1B=50000;
	 cbi(PORTD,2);
	 cbi(PORTD,3);
	 cbi(PORTD,7);
	 sbi(PORTD,6);
 }
 void srp_ryt()
 {

	 OCR1A=40000;
	 OCR1B=50000;
	 cbi(PORTD,2);
	 sbi(PORTD,3);
	 cbi(PORTD,7);
	 sbi(PORTD,6);
 }
 void conf()
 {
	 OCR1A=50200;
	 OCR1B=48000;

	 cbi(PORTD,2);
	 sbi(PORTD,3);
	 sbi(PORTD,6);
	 cbi(PORTD,7);
 }
 void srp_lft()
 {
	 OCR1A=40000;
	 OCR1B=39000;
	 sbi(PORTD,2);
	 cbi(PORTD,3);
	 cbi(PORTD,6);
	 sbi(PORTD,7);
 }
 void stp()
 {
	 OCR1A=19000;
	 OCR1B=19000;
	 sbi(PORTD,2);
	 cbi(PORTD,3);
	 sbi(PORTD,6);
	 cbi(PORTD,7);
	 
 }
 
 
 
 void main()
 {
	 timer();
	 DDRA=0x00;
	 //PORTA=0xff;
	 DDRD=0xff;
	 while(1)
	 {
		 
		 if((bit_is_clear(PINA,1))&&(bit_is_clear(PINA,2))&&(bit_is_set(PINA,3))&&(bit_is_clear(PINA,4))&&(bit_is_clear(PINA,5)))
		 {
			 frnt();
			 
			 _delay_ms(30);
		 }
		 
		 
		 if((bit_is_clear(PINA,1))&&(bit_is_set(PINA,2))&&(bit_is_set(PINA,3))&&(bit_is_clear(PINA,4))&&(bit_is_clear(PINA,5))||(bit_is_clear(PINA,1))&&(bit_is_set(PINA,2))&&(bit_is_clear(PINA,3))&&(bit_is_clear(PINA,4))&&(bit_is_clear(PINA,5)))
		 {
			 lft();
			 _delay_ms(30);
		 }
		 if((bit_is_clear(PINA,1))&&(bit_is_clear(PINA,2))&&(bit_is_set(PINA,3))&&(bit_is_set(PINA,4))&&(bit_is_clear(PINA,5))||(bit_is_clear(PINA,1))&&(bit_is_clear(PINA,2))&&(bit_is_clear(PINA,3))&&(bit_is_set(PINA,4))&&(bit_is_clear(PINA,5)))
		 {
			 
			 ryt();
			 _delay_ms(30);
		 }
		 
		 
		 if((bit_is_set(PINA,1))&&(bit_is_set(PINA,2))&&(bit_is_set(PINA,3))&&(bit_is_set(PINA,4))&&(bit_is_clear(PINA,5))||(bit_is_set(PINA,1))&&(bit_is_set(PINA,2))&&(bit_is_set(PINA,3))&&(bit_is_clear(PINA,4))&&(bit_is_clear(PINA,5))||(bit_is_set(PINA,1))&&(bit_is_set(PINA,2))&&(bit_is_clear(PINA,3))&&(bit_is_clear(PINA,4))&&(bit_is_clear(PINA,5))||(bit_is_set(PINA,1))&&(bit_is_clear(PINA,2))&&(bit_is_clear(PINA,3))&&(bit_is_clear(PINA,4))&&(bit_is_clear(PINA,5)))
		 {
			 srp_ryt();
			 _delay_ms(50);
		 }
		 
		 if((bit_is_clear(PINA,1))&&(bit_is_clear(PINA,2))&&(bit_is_set(PINA,3))&&(bit_is_set(PINA,4))&&(bit_is_set(PINA,5))||(bit_is_clear(PINA,1))&&(bit_is_clear(PINA,2))&&(bit_is_clear(PINA,3))&&(bit_is_set(PINA,4))&&(bit_is_set(PINA,5))||(bit_is_clear(PINA,1))&&(bit_is_clear(PINA,2))&&(bit_is_clear(PINA,3))&&(bit_is_clear(PINA,4))&&(bit_is_set(PINA,5))||(bit_is_clear(PINA,1))&&(bit_is_set(PINA,2))&&(bit_is_set(PINA,3))&&(bit_is_set(PINA,4))&&(bit_is_set(PINA,5)))
		 {
			 srp_lft();
			 _delay_ms(30);
		 }
		 if ((bit_is_set(PINA,1))&&(bit_is_set(PINA,2))&&(bit_is_set(PINA,3))&&(bit_is_set(PINA,4))&&(bit_is_set(PINA,5)))
		 {
			 conf();
			 _delay_ms(50);
		 }
		 else
		 {
			 stp();
		 }
		 
		 
		 
		 
	 }}
