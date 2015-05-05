/*
 * shm_com.h
 *
 *  Created on: 2015年5月4日
 *      Author: Administrator
 */

#ifndef SHM_COM_H_
#define SHM_COM_H_

#define TEXT_SZ 2048

struct shared_use_st
{
	int writtten_by_you;
	char some_text[TEXT_SZ];
};

struct cust_info_st
{
	char cust_no[11];
	char cust_name[20];
	char sex[2];
	int  age;
};

#endif /* SHM_COM_H_ */
