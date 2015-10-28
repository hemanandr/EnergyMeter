
#ifndef REGISTERS_DEF_H_
#define REGISTERS_DEF_H_

#ifdef __cplusplus
extern "C"
{
#endif

//Bit Position Definitions
#define	_0			0x00000001
#define	_1			0x00000002
#define	_2			0x00000004
#define	_3			0x00000008
#define	_4			0x00000010
#define	_5			0x00000020
#define	_6			0x00000040
#define	_7			0x00000080
#define	_8			0x00000100
#define	_9			0x00000200
#define	_10			0x00000400
#define	_11			0x00000800
#define	_12			0x00001000
#define	_13			0x00002000
#define	_14			0x00004000
#define	_15			0x00008000
#define	_16			0x00010000
#define	_17			0x00020000
#define	_18			0x00040000
#define	_19			0x00080000
#define	_20			0x00100000
#define	_21			0x00200000
#define	_22			0x00400000
#define	_23			0x00800000
#define	_24			0x01000000
#define	_25			0x02000000
#define	_26			0x04000000
#define	_27			0x08000000
#define	_28			0x10000000
#define	_29			0x20000000
#define	_30			0x40000000
#define	_31			0x80000000

//IPEAK Register
#define IPEAKVAL	0x00FFFFFFF
#define IPPHASEA	_24
#define IPPHASEB	_25
#define IPPHASEC	_26

//IPEAK Register
#define VPEAKVAL	0x00FFFFFFF
#define VPPHASEA	_24
#define VPPHASEB	_25
#define VPPHASEC	_26

//STATUS0 / MASK0 Bit Definitions
#define	AEHF		_0
#define	FAEHF		_1
#define	FREHF		_3
#define	VAEHF		_4
#define	LENERGY		_5
#define	REVAPA		_6
#define	REVAPB		_7
#define	REVAPC		_8
#define	REVPSUM1	_9
#define	REVFRPA		_10
#define	REVFRPB		_11
#define	REVFRPC		_12
#define	REVPSUM2	_13
#define	CF1			_14
#define	CF2			_15
#define	CF3			_16
#define	DREADY		_17
#define	REVPSUM3	_18
#define	HREADY		_19

//STATUS1 / MASK1 Bit Definitions
#define	NLOAD		_0
#define	FNLOAD		_1
#define	VANLOAD		_2
#define	ZXTOVA		_3
#define	ZXTOVB		_4
#define	ZXTOVC		_5
#define	ZXTOIA		_6
#define	ZXTOIB		_7
#define	ZXTOIC		_8
#define	ZXVA		_9
#define	ZXVB		_10
#define	ZXVC		_11
#define	ZXIA		_12
#define	ZXIB		_13
#define	ZXIC		_14
#define	RSTDONE		_15
#define	SAG			_16
#define	OI			_17
#define	OV			_18
#define	SEQERR		_19
#define	MISMTCH		_20
#define	PKI			_23
#define	PKV			_24
#define	CRC			_25

//PHSTATUS Bit Definitions
#define OIPHASEA	_3
#define OIPHASEB	_4
#define OIPHASEC	_5
#define OVPHASEA	_9
#define OVPHASEB	_10
#define OVPHASEC	_11
#define VSPHASEA	_12
#define VSPHASEB	_13
#define VSPHASEC	_14

//PHNOLOAD Bit Definitions
#define NLPHASEA	_0
#define NLPHASEB	_1
#define NLPHASEC	_2
#define FNLPHASEA	_3
#define FNLPHASEB	_4
#define FNLPHASEC	_5
#define VANLPHASEA	_6
#define VANLPHASEB	_7
#define VANLPHASEC	_8

//COMPMODE Bit Definitions
#define TERMSEL1A	_0
#define TERMSEL1B	_1
#define TERMSEL1C	_2
#define TERMSEL2A	_3
#define TERMSEL2B	_4
#define TERMSEL2C	_5
#define TERMSEL3A	_6
#define TERMSEL3B	_7
#define TERMSEL3C	_8
#define ANGLESEL	_9|_10
#define VNOMAEN		_11
#define VNOMBEN		_12
#define VNOMCEN		_13
#define SELFREQ		_14

//Gain Register Bit Definitions
#define PGA1		_0|_1|_2	//0x00000007	// 000:1; 001:2; 010:4; 011:8; 100:16;
#define PGA2		_3|_4|_5	//0x00000038
#define PGA3		_6|_7|_8	//0x000001C0

//CFMODE Bit Definitions
#define CF1SEL		_0|_1|_2
#define CF2SEL		_5|_4|_3
#define CF3SEL		_8|_7|_6
#define CF1DIS		_9
#define CF2DIS		_10
#define CF3DIS		_11
#define CF1LATCH	_12
#define CF2LATCH	_13
#define CF3LATCH	_14

//APHCAL, BPHCAL, CPHCAL Bit Definition
#define	PHCALVAL	0x01FF

//PHSIGN Bit Definitions
#define AWSIGN		_0
#define BWSIGN		_1
#define CWSIGN		_2
#define SUM1SIGN	_3
#define AFVARSIGN	_4
#define BFVARSIGN	_5
#define CFVARSIGN	_6
#define SUM2SIGN	_7
#define SUM3SIGN	_8

//CONFIG Bit Definitions
#define	INTEN		_0
#define	CF2DIS		_2
#define	SWAP		_3
#define	MOD1SHORT	_4
#define	MOD2SHORT	_5
#define	HSDCEN		_6
#define	SWRST		_7
#define	VTOIA		_8|_9
#define	VTOIB		_10|_11
#define	VTOIC		_12|_13

//MMODE Bit Definitions
#define	PEAKSELA	_2
#define	PEAKSELB	_3
#define	PEAKSELC	_4

//ACCMODE Bit Definitions
#define WATTACC		_0|_1
#define VARACC		_2|_3
#define CONSEL		_4|_5	//Table 50
#define REVAPSEL	_6

//LCYCMODE Bit Definitions
#define	LWATT		_0
#define	LVAR		_1
#define	LVA			_2
#define	ZXSELA		_3
#define	ZXSELB		_4
#define	ZXSELC		_5
#define	RSTREAD		_6
#define	PFMODE		_7

//HSDC_CFG Bit Definitions
#define	HCLK		_0
#define	HSIZE		_1
#define	HGAP		_2
#define	HXFER		_3|_4
#define	HSAPOL		_5

//CONFIG3 Bit Definitions
#define HPFEN		_0
#define LPFEL		_1
#define INSEL		_2
#define ININTEN		_3

//HCONFIG Bit Definitions
#define HRCFG		_0
#define HPHASE		_1|_2
#define HSTIME		_3|_4
#define HRATE		_5|_6|_7
#define ACTPHSEL	_8|_9

//LPOILVL Bit Definitions
#define	LPOIL		_0|_1|_2
#define	LPLINE		_3|_4|_5|_6|_7

//CONFIG2 Bit Definitions
#define EXTREFEN	_0
#define	I2C_LOCK	_1

//Register Structure Definition
typedef struct{
	int address;
	int length;
} Register;

//Register Located in DSP Data Memory RAM
extern const Register AIGAIN;
extern const Register AVGAIN;
extern const Register BIGAIN;
extern const Register BVGAIN;
extern const Register CIGAIN;
extern const Register CVGAIN;
extern const Register NIGAIN;
extern const Register DICOEFF;
extern const Register APGAIN;
extern const Register APWATTOS;
extern const Register BPGAIN;
extern const Register BPWATTOS;
extern const Register CPGAIN;
extern const Register CPWATTOS;
extern const Register AIRMSOS;
extern const Register AVRMSOS;
extern const Register BIRMSOS;
extern const Register BVRMSOS;
extern const Register CIRMSOS;
extern const Register CVRMSOS;
extern const Register NIRMSOS;
extern const Register HPGAIN;
extern const Register ISUMVL;
extern const Register VLEVEL;
extern const Register AFWATTOS;
extern const Register BFWATTOS;
extern const Register CFWATTOS;
extern const Register AFVAROS;
extern const Register BFVAROS;
extern const Register CFVAROS;
extern const Register AFIRMSOS;
extern const Register BFIRMSOS;
extern const Register CFIRMSOS;
extern const Register AFVRMSOS;
extern const Register BFVRMSOS;
extern const Register CFVRMSOS;
extern const Register HXWATTOS;
extern const Register HYWATTOS;
extern const Register HZWATTOS;
extern const Register HXVAROS;
extern const Register HYVAROS;
extern const Register HZVAROS;
extern const Register HXIRMSOS;
extern const Register HYIRMSOS;
extern const Register HZIRMSOS;
extern const Register HXVRMSOS;
extern const Register HYVRMSOS;
extern const Register HZVRMSOS;
extern const Register AIRMS;
extern const Register AVRMS;
extern const Register BIRMS;
extern const Register BVRMS;
extern const Register CIRMS;
extern const Register CVRMS;
extern const Register NIRMS;
extern const Register ISUM;

//Internal DSP Memory RAM Registers
extern const Register Run;

//Billable Registers
extern const Register AWATTHR;
extern const Register BWATTHR;
extern const Register CWATTHR;
extern const Register AFWATTHR;
extern const Register BFWATTHR;
extern const Register CFWATTHR;
extern const Register AFVARHR;
extern const Register BFVARHR;
extern const Register CFVARHR;
extern const Register AVAHR;
extern const Register BVAHR;
extern const Register CVAHR;

//Configuration and Power Quality Registers
extern const Register IPEAK;
extern const Register VPEAK;
extern const Register STATUS0;
extern const Register STATUS1;
extern const Register AIMAV;
extern const Register BIMAV;
extern const Register CIMAV;
extern const Register OILVL;
extern const Register OVLVL;
extern const Register SAGLVL;
extern const Register MASK0;
extern const Register MASK1;
extern const Register IAMV;
extern const Register IBMV;
extern const Register ICMV;
extern const Register INMV;
extern const Register VAMV;
extern const Register VBMV;
extern const Register VCMV;
extern const Register AWATTT;
extern const Register BWATTT;
extern const Register CWATTT;
extern const Register AVA;
extern const Register BVA;
extern const Register CVA;
extern const Register CHECKSUM;
extern const Register VNOM;
extern const Register LAST_RWDATA32;
extern const Register PHSTATUS;
extern const Register ANGLE0;
extern const Register ANGLE1;
extern const Register ANGLE2;
extern const Register PHNOLOAD;
extern const Register LINECYC;
extern const Register ZXTOUT;
extern const Register COMPMODE;
extern const Register Gain;
extern const Register CFMODE;
extern const Register CF1DEN;
extern const Register CF2DEN;
extern const Register CF3DEN;
extern const Register APHCAL;
extern const Register BPHCAL;
extern const Register CPHCAL;
extern const Register PHSIGN;
extern const Register CONFIG;
extern const Register MMODE;
extern const Register ACCMODE;
extern const Register LCYCMODE;
extern const Register PEAKCYC;
extern const Register SAGCYC;
extern const Register CFCYC;
extern const Register HSDC_CFG;
extern const Register Version;
extern const Register LAST_RWDATA8;
extern const Register FVRMS;
extern const Register FIRMS;
extern const Register FWATT;
extern const Register FVAR;
extern const Register FVA;
extern const Register FPF;
extern const Register VTHD;
extern const Register ITHD;
extern const Register HXVRMS;
extern const Register HXIRMS;
extern const Register HXWATT;
extern const Register HXVAR;
extern const Register HXVA;
extern const Register HXPF;
extern const Register HXVHD;
extern const Register HXIHD;
extern const Register HYVRMS;
extern const Register HYIRMS;
extern const Register HYWATT;
extern const Register HYVAR;
extern const Register HYVA;
extern const Register HYPF;
extern const Register HYVHD;
extern const Register HYIHD;
extern const Register HZVRMS;
extern const Register HZIRMS;
extern const Register HZWATT;
extern const Register HZVAR;
extern const Register HZVA;
extern const Register HZPF;
extern const Register HZVHD;
extern const Register HZIHD;
extern const Register HCONFIG;
extern const Register APF;
extern const Register BPF;
extern const Register CPF;
extern const Register APERIOD;
extern const Register BPERIOD;
extern const Register CPERIOD;
extern const Register APNOLOAD;
extern const Register VARNOLOAD;
extern const Register VANOLOAD;
extern const Register LAST_ADD;
extern const Register LAST_RWDATA16;
extern const Register CONFIG3;
extern const Register LAST_OP;
extern const Register WTHR;
extern const Register VARTHR;
extern const Register VATHR;
extern const Register HX;
extern const Register HY;
extern const Register HZ;
extern const Register LPOILVL;
extern const Register CONFIG2;

//Function Definitions
unsigned short BitPosition(int value);

#ifdef __cplusplus
}
#endif

#endif /* REGISTERS_DEF_H_ */
