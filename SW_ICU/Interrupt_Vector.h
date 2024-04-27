#ifndef   INTERRUPT_VECTOR_H_ 
#define   INTERRUPT_VECTOR_H_ 


#define  ISR(__vector_NUM )  void __vector_NUM(void)__attribute__((signal)) ;\
                             void __vector_NUM(void)

#define  INT_0_   __vector_1 
#define  INT_1_   __vector_2
#define  INT_2_   __vector_3

#define  TIMER0_OVF   __vector_11

#endif 