/*
 * DemoShm.h
 *
 *  Created on: 2015年5月4日
 *      Author: Administrator
 */

#ifndef DEMOSHM_H_
#define DEMOSHM_H_

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <sys/shm.h>

#include "shm_com.h"

class DemoShm {
public:
	DemoShm();
	virtual ~DemoShm();
	bool CreateShm(int id, int size);
	bool InsertOneRecord(void *oneRec);
	bool GetOneRecord(void **oneRec);

private:
	void *shared_memory;

};

#endif /* DEMOSHM_H_ */
