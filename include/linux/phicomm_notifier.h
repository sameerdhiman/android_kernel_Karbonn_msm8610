/**********************************************
  *	PHICOMM kernel notifier module
  *   ZUO Chengbing<chengbing.zuo@phicomm.com.cn>
  *
 **********************************************/
#ifndef _PHICOMM_NOTIFIER_HEAD_
#define	_PHICOMM_NOTIFIER_HEAD_

#include <linux/notifier.h>
#include <linux/wakelock.h>

enum {
	BL_OFF = 0,
	BL_ON = 1,
};

int bl_notifier_chain_register(struct notifier_block *nb);
int bl_notifier_chain_unregister(struct notifier_block *nb);
int bl_notifier_call_chain(unsigned long val, void *v);

#endif
