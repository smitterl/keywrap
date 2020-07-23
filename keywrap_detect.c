#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <asm/cpacf.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Sebastian Mitterle");
MODULE_DESCRIPTION("Describes wrapping key support for s390x architecture.");

static cpacf_mask_t pckmo_functions;

static int __init keywrap_init(void)
{
	if(!cpacf_query(CPACF_PCKMO, &pckmo_functions))
		printk("PCKMO not supported");
	if(!cpacf_test_func(&pckmo_functions, CPACF_PCKMO_QUERY))
		printk("QUERY not supported");
	if(!cpacf_test_func(&pckmo_functions, CPACF_PCKMO_ENC_DES_KEY))
		printk("DES_KEY not supported");
	if(!cpacf_test_func(&pckmo_functions, CPACF_PCKMO_ENC_TDES_128_KEY))
		printk("TDES_128_KEY not supported");
	if(!cpacf_test_func(&pckmo_functions, CPACF_PCKMO_ENC_TDES_192_KEY))
		printk("TDES_192_KEY not supported");
	if(!cpacf_test_func(&pckmo_functions, CPACF_PCKMO_ENC_AES_128_KEY))
		printk("AES_128_KEY not supported");
	if(!cpacf_test_func(&pckmo_functions, CPACF_PCKMO_ENC_AES_192_KEY))
		printk("AES_192_KEY not supported");
	if(!cpacf_test_func(&pckmo_functions, CPACF_PCKMO_ENC_AES_256_KEY))
		printk("AES_256_KEY not supported");
	return 0;

}

static void __exit keywrap_exit(void)
{
	printk("Unloading module.");
}

module_init(keywrap_init);
module_exit(keywrap_exit);
