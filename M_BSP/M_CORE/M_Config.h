/**
  ******************************************************************************
  * @file    RTE_Config.h
  * @author  Shan Lei ->>lurenjia.tech ->>https://github.com/sudashannon
  * @brief   RTE��������ͷ�ļ�������KEIL��ʽ��д��ΪRTE�������вü����á�
  * @version V1.0 2018/11/02 ��һ��
  ******************************************************************************
  */
#ifndef __RTE_CONFIG_H
#define __RTE_CONFIG_H
#ifdef __cplusplus  
extern "C" {  
#endif  
//-------- <<< Use Configuration Wizard in Context Menu >>> --------------------
//<s> RTE�汾��
//<i> ���嶨�������ĵ���
#define RTE_VERSION "3.3.0113"
//=======================
//<e> ��̬�ڴ����ģ��
//=======================
//<i> ʹ��RTE�Դ��Ķ�̬�ڴ��������ģ�飺�ޡ�
#define RTE_USE_MEMMANAGE             1
#if RTE_USE_MEMMANAGE == 1
	//<q> Ӳ�������Ƿ�֧��64λ
	//<i> ����STM32��32λMCU�����蹴ѡ���
	#define RTE_MEM_64BIT               0
	//<q> �Ƿ��Զ�������Ƭ
	//<i> ʹ��MEM�Դ�����Ƭ�����ܡ�
	#define RTE_MEM_AUTO_DEFRAG         1
	//<o> RTE�ڴ���С
	//<i> RTEʹ�õö�̬�ڴ��С
	//<i> Ĭ�ϴ�С: 32����λ��K��
	#define RTE_MEM_SIZE    		        (8U)
#endif
//</e>
//=======================
//<e> ��̬����ģ��
//=======================
//<i> ʹ��RTE�Դ��Ķ�̬�����������ģ�飺��̬�ڴ�ģ�顣
#define RTE_USE_VEC                   1
#if RTE_USE_VEC == 1
#if RTE_USE_MEMMANAGE == 0
#error "This module needs dynatic mem manage module's support!"
#endif
#endif
//</e>
//=======================
//<e> ˫������ģ��
//=======================
//<i> ʹ��RTE�Դ���˫������ģ�飬����ģ�飺��̬�ڴ�ģ�顣
#define RTE_USE_LL                    0
#if RTE_USE_LL == 1
#if RTE_USE_MEMMANAGE == 0
#error "This module needs dynatic mem manage module's support!"
#endif
#endif
//</e>
//=======================
//<h> ��׼C��ģ��
//=======================
//<i> ʹ��RTE�Դ����滻��׼C��ĺ���������ģ�飺�ޡ�
//<q> �ַ�������ģ��
//<i> �ṩһЩ�ַ�������ĺ���ʵ�֡�
#define RTE_USE_USTRING               1

//<q> ��׼���ģ��
//<i> �ṩprintf�������ʵ�֣���֧��%f��
#define RTE_USE_USTDOUT               1
//</h>
//=======================
//<e> KV���ݿ�ģ��
//=======================
//<i> ʹ��RTE�Դ���KV��ϵ���ݿ⣬����ģ�飺��׼�����
#define RTE_USE_KVDB                  1
	//<o>KVDB��С������λ��С
	//<i>��λ��K
	#define KVDB_ERASE_MIN_SIZE         (1024)
	//<q>���籣��
	#define KVDB_USE_PFS                0
	//<o>�û����û���������С
	#define KVDB_USER_SETTING_SIZE      1024
	//<o>KVDB��ַƫ��
	//<i>����FLASH�׵�ַ��Ϊʵ�ʵ�ַ����λ��K��
	#define KVDB_ADDR_OFFSET            60 * 1024 
	//<o>FLASH�׵�ַ
	#define KVDB_FLASH_BASE             0x08000000
	//<e>�Զ����£��������£�
	#define KVDB_USE_AUTO_UPDATE        0
	//<o>�̼��汾
	//<i>�����⵽��Ʒ�洢�İ汾�����趨�汾�Ų�һ�£����Զ�׷��Ĭ�ϻ������������������Ļ���������
	#define KVDB_FM_VER_NUM             0
	//</e>
//</e>
//=======================
//<e> ״̬��ģ��
//=======================
//<i> ʹ��RTE�Դ���״̬��ģ�ͣ�����ģ�飺VECģ�飬��̬�ڴ����
#define RTE_USE_SM                    1
#if RTE_USE_SM == 1
#if RTE_USE_VEC == 0 || RTE_USE_MEMMANAGE == 0
#error "This module needs vec and dynatic mem manage module's support!"
#endif
#endif
//</e>
//=======================
//<e> ���ζ���ģ��
//=======================
//<i> ʹ��RTE�Դ��Ļ��ζ�������Ϣ���У�����ģ�飺��̬�ڴ����
#define RTE_USE_RINGQUENE             1
#if RTE_USE_RINGQUENE == 1
#if RTE_USE_MEMMANAGE == 0
#error "This module needs dynatic mem manage module's support!"
#endif
#endif
//</e>
//=======================
//<e> SHELLģ��
//=======================
//<i> ��Ϣ����ģ�飬����ģ�飺���ζ���ģ�飬VECģ�飬��̬�ڴ����
#define RTE_USE_SHELL                 1
#if RTE_USE_SHELL == 1
#if RTE_USE_VEC == 0 || RTE_USE_MEMMANAGE == 0 || RTE_USE_RINGQUENE == 0
#error "This module needs vec and dynatic mem manage module's support!"
#endif
	//<o>���֧��ָ����Ŀ
	//<i>Ĭ�ϴ�С: 16
	#define SHELL_MAX_NUM    		        16
	//<o>����ָ�����֧�ֲ�����
	//<i>Ĭ�ϴ�С: 8
	#define SHELL_MAX_ARGS              8
	//<o>���ݻ����С
	//<i>Ĭ�ϴ�С: 32 [bytes] 
	#define SHELL_BUFSIZE    		        64
#endif
//</e>
//=======================
//<e> ʱ��Ƭ��ת����ģ��
//=======================
//<i> ��������ϵͳ�����µ�ʱ��Ƭ��ת���ȣ�����ģ�飺vecģ�飬��̬�ڴ�ģ�顣
#define RTE_USE_ROUNDROBIN            1
#if RTE_USE_ROUNDROBIN == 1
#if RTE_USE_VEC == 0 || RTE_USE_MEMMANAGE == 0
#error "This module needs vec and dynatic mem manage module's support!"
#endif
	// <q> ʵʱ����ϵͳ
	// <i> Ĭ����RTX5
	#ifndef RTE_USE_OS
	#define RTE_USE_OS          0
	#endif
	// <o> ��ת�������֧�ֵ�Timer��Ŀ 
	// <i> Ĭ�ϴ�С: 16
	#define ROUNDROBIN_MAX_NUM    		  16
	// <o> ��ת�������֧�ֵ�TimerGroup��Ŀ
	// <i> Ĭ�ϴ�С: 4
	#define ROUNDROBIN_MAX_GROUP_NUM    4
#endif
//</e>
//=======================
//<e> ��־ģ��
//=======================
//<i> ʹ��RTE�Դ�����־ģ���¼����������Ϣ����ѡ��¼λ�á�
#define RTE_USE_LOG                   1
//</e>
//=======================
//<e> ͼ����ģ��
//=======================
//<i> ʹ��RTE�Դ��Ļ����Ӿ�
#define RTE_USE_OPENMV                0
//</e>
//=======================
//<e> GUIģ��
//=======================
//<i> ʹ��RTE�Դ���GUI
#define RTE_USE_GUI                   0
#if RTE_USE_GUI == 1
#if RTE_USE_MEMMANAGE == 0
#error "This module needs dynatic mem manage module's support!"
#endif
#endif
//</e>
//=======================
//<e> ASSERT
//=======================
#define RTE_USE_ASSERT                   1
#if RTE_USE_ASSERT
#include <stdint.h>
extern void RTE_Assert(char *file, uint32_t line);
#define RTE_AssertParam(expr) {                                     \
																 if(!(expr))                        \
																 {                                  \
																		 RTE_Assert(__FILE__, __LINE__);\
																 }                                  \
															}
#else
#define RTE_AssertParam(expr) ((void)0)
#endif
//</e>
#ifdef __cplusplus  
}  
#endif  
#endif
