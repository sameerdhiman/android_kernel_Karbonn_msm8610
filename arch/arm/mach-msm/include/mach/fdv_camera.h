#ifndef FDV_CAMERA_H
#define FDV_CAMERA_H
#include <asm/types.h>


/*define device_name*/
//#define DEV_CAMERA		"Camera"

/*definition:
	e:	0x0  1  1  0  0000
	bits:0-15:devices id
	bits:16-19:reserved
	bits:20-23:manuf id
	bits:24-27: DEV id

	ex: LCD DEV id is 0, NAND DEV id is 1
	ex: TP DEV id is 2, P/L DEV id is 3*/
         
/*define manuf_name and id*/
/*camera*/
#define MANUF_S5K4E1	 	"SAMSUNG"
#define MANUF_S5K4E1_ID		0x04100000

/*bits:16-19:module id*/
#define MANUF_S5K4E1_NSM_185A	 		"S5k4e1_nsm_185a"
#define MANUF_S5K4E1_NSM_185A_ID		0x04110000

#define MANUF_S5K4E1_NSM_325A	 		"S5k4e1_nsm_325a"
#define MANUF_S5K4E1_NSM_325A_ID		0x04120000

#define MANUF_OV5640		"Ov5640"
#define MANUF_OV5640_ID   	0x04200000

#define MANUF_OV5648		"OmniVision"
#define MANUF_OV5648_ID   	0x06c00000

#define MANUF_GC0339		"GALAXYCORE"
#define MANUF_GC0339_ID		0x04300000

#define MANUF_GC0339_SYX_58A		"Gc0339_syx_58a"
#define MANUF_GC0339_SYX_58A_ID		0x04300000

#define MANUF_OV7692            "Ov7692"
#define MANUF_OV7692_ID         0x04400000

#define MANUF_OV8825			"Ov8825"
#define MANUF_OV8825_ID         0x04500000

#define MANUF_OV2675			"Ov2675"
#define MANUF_OV2675_ID         0x04600000

#define MANUF_GC2035			"Gc2035"
#define MANUF_GC2035_ID         0x04700000

#define MANUF_GC2035_TONGJU_I855W			"Gc2035"
#define MANUF_GC2035_TONGJU_I855W_ID         0x04710000

#define MANUF_OV5647_SYX_58A			"Ov5647_syx_58a"
#define MANUF_OV5647_SYX_58A_ID         0x04800000

#define MANUF_IMX111			"IMX111"
#define MANUF_IMX111_ID         0x04900000


#define MANUF_GC2235			"GALAXYCORE"
#define MANUF_GC2235_ID         0x04a00000

#define MANUF_IMX111_ST_30681			"IMX111_ST_30681"
#define MANUF_IMX111_ST_30681_ID         0x04910000

#define MANUF_HI351             "HI351"
#define MANUF_HI351_ID          0x04b00000
#endif
