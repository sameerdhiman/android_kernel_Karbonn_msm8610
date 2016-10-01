/**********************************************
  *   PHICOMM kernel notifier module
  *   ZUO Chengbing<chengbing.zuo@phicomm.com.cn>
  *
 **********************************************/
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/phicomm_notifier.h>
#include <linux/workqueue.h>

static RAW_NOTIFIER_HEAD(bl);

int bl_notifier_chain_register(struct notifier_block *nb)
{
	return raw_notifier_chain_register(&bl, nb);
}
EXPORT_SYMBOL(bl_notifier_chain_register);

int bl_notifier_chain_unregister(struct notifier_block *nb)
{
	return raw_notifier_chain_unregister(&bl, nb);
}
EXPORT_SYMBOL(bl_notifier_chain_unregister);

int bl_notifier_call_chain(unsigned long val, void *v)
{
	return raw_notifier_call_chain(&bl, val, v);
}
EXPORT_SYMBOL(bl_notifier_call_chain);

static int __init phicomm_notifier_init(void)
{
	return 0;
}

static void __exit phicomm_notifer_exit(void)
{
}

module_init(phicomm_notifier_init);
module_exit(phicomm_notifer_exit);

MODULE_DESCRIPTION("Kernel Notifier Module");
MODULE_AUTHOR("ZUO Chengbing");
MODULE_LICENSE("GPL");
