#include "registers_def.h"

//Register Located in DSP Data Memory RAM
const Register AIGAIN = {0x4380, 4};
const Register AVGAIN = {0x4381, 4};
const Register BIGAIN = {0x4382, 4};
const Register BVGAIN = {0x4383, 4};
const Register CIGAIN = {0x4384, 4};
const Register CVGAIN = {0x4385, 4};
const Register NIGAIN = {0x4386, 4};
const Register DICOEFF = {0x4388, 4};
const Register APGAIN = {0x4389, 4};
const Register APWATTOS = {0x438A, 4};
const Register BPGAIN = {0x438B, 4};
const Register BPWATTOS = {0x438C, 4};
const Register CPGAIN = {0x438D, 4};
const Register CPWATTOS = {0x438E, 4};
const Register AIRMSOS = {0x438F, 4};
const Register AVRMSOS = {0x4390, 4};
const Register BIRMSOS = {0x4391, 4};
const Register BVRMSOS = {0x4392, 4};
const Register CIRMSOS = {0x4393, 4};
const Register CVRMSOS = {0x4394, 4};
const Register NIRMSOS = {0x4395, 4};
const Register HPGAIN = {0x4398, 4};
const Register ISUMVL = {0x4399, 4};
const Register VLEVEL = {0x439F, 4};
const Register AFWATTOS = {0x43A2, 4};
const Register BFWATTOS = {0x43A3, 4};
const Register CFWATTOS = {0x43A4, 4};
const Register AFVAROS = {0x43A5, 4};
const Register BFVAROS = {0x43A6, 4};
const Register CFVAROS = {0x43A7, 4};
const Register AFIRMSOS = {0x43A8, 4};
const Register BFIRMSOS = {0x43A9, 4};
const Register CFIRMSOS = {0x43AA, 4};
const Register AFVRMSOS = {0x43AB, 4};
const Register BFVRMSOS = {0x43AC, 4};
const Register CFVRMSOS = {0x43AD, 4};
const Register HXWATTOS = {0x43AE, 4};
const Register HYWATTOS = {0x43AF, 4};
const Register HZWATTOS = {0x43B0, 4};
const Register HXVAROS = {0x43B1, 4};
const Register HYVAROS = {0x43B2, 4};
const Register HZVAROS = {0x43B3, 4};
const Register HXIRMSOS = {0x43B4, 4};
const Register HYIRMSOS = {0x43B5, 4};
const Register HZIRMSOS = {0x43B6, 4};
const Register HXVRMSOS = {0x43B7, 4};
const Register HYVRMSOS = {0x43B8, 4};
const Register HZVRMSOS = {0x43B9, 4};
const Register AIRMS = {0x43C0, 4};
const Register AVRMS = {0x43C1, 4};
const Register BIRMS = {0x43C2, 4};
const Register BVRMS = {0x43C3, 4};
const Register CIRMS = {0x43C4, 4};
const Register CVRMS = {0x43C5, 4};
const Register NIRMS = {0x43C6, 4};
const Register ISUM = {0x43C7, 4};

//Internal DSP Memory RAM Registers
const Register Run = {0xE228, 2};

//Billable Registers
const Register AWATTHR = {0xE400, 4};
const Register BWATTHR = {0xE401, 4};
const Register CWATTHR = {0xE402, 4};
const Register AFWATTHR = {0xE403, 4};
const Register BFWATTHR = {0xE404, 4};
const Register CFWATTHR = {0xE405, 4};
const Register AFVARHR = {0xE409, 4};
const Register BFVARHR = {0xE40A, 4};
const Register CFVARHR = {0xE40B, 4};
const Register AVAHR = {0xE40C, 4};
const Register BVAHR = {0xE40D, 4};
const Register CVAHR = {0xE40E, 4};

//Configuration and Power Quality Registers
const Register IPEAK = {0xE500, 4};
const Register VPEAK = {0xE501, 4};
const Register STATUS0 = {0xE501, 4};
const Register STATUS1 = {0xE503, 4};
const Register AIMAV = {0xE504, 4};
const Register BIMAV = {0xE505, 4};
const Register CIMAV = {0xE506, 4};
const Register OILVL = {0xE507, 4};
const Register OVLVL = {0xE508, 4};
const Register SAGLVL = {0xE509, 4};
const Register MASK0 = {0xE50A, 4};
const Register MASK1 = {0xE50B, 4};
const Register IAMV = {0xE50C, 4};
const Register IBMV = {0xE50D, 4};
const Register ICMV = {0xE50E, 4};
const Register INMV = {0xE50F, 4};
const Register VAMV = {0xE510, 4};
const Register VBMV = {0xE511, 4};
const Register VCMV = {0xE512, 4};
const Register AWATTT = {0xE513, 4};
const Register BWATTT = {0xE514, 4};
const Register CWATTT = {0xE515, 4};
const Register AVA = {0xE519, 4};
const Register BVA = {0xE51A, 4};
const Register CVA = {0xE51B, 4};
const Register CHECKSUM = {0xE51F, 4};
const Register VNOM = {0xE520, 4};
const Register LAST_RWDATA32 = {0xE5FF, 4};
const Register PHSTATUS = {0xE600, 2};
const Register ANGLE0 = {0xE601, 2};
const Register ANGLE1 = {0xE602, 2};
const Register ANGLE2 = {0xE603, 2};
const Register PHNOLOAD = {0xE608, 2};
const Register LINECYC = {0xE60C, 2};
const Register ZXTOUT = {0xE60D, 2};
const Register COMPMODE = {0xE60E, 2};
const Register Gain = {0xE60F, 2};
const Register CFMODE = {0xE610, 2};
const Register CF1DEN = {0xE611, 2};
const Register CF2DEN = {0xE612, 2};
const Register CF3DEN = {0xE613, 2};
const Register APHCAL = {0xE614, 2};
const Register BPHCAL = {0xE615, 2};
const Register CPHCAL = {0xE616, 2};
const Register PHSIGN = {0xE617, 2};
const Register CONFIG = {0xE618, 2};
const Register MMODE = {0xE700, 1};
const Register ACCMODE = {0xE701, 1};
const Register LCYCMODE = {0xE702, 1};
const Register PEAKCYC = {0xE703, 1};
const Register SAGCYC = {0xE704, 1};
const Register CFCYC = {0xE705, 1};
const Register HSDC_CFG = {0xE706, 1};
const Register Version = {0xE707, 1};
const Register LAST_RWDATA8 = {0xE7FD, 1};
const Register FVRMS = {0xE880, 4};
const Register FIRMS = {0xE881, 4};
const Register FWATT = {0xE882, 4};
const Register FVAR = {0xE883, 4};
const Register FVA = {0xE884, 4};
const Register FPF = {0xE885, 4};
const Register VTHD = {0xE886, 4};
const Register ITHD = {0xE887, 4};
const Register HXVRMS = {0xE888, 4};
const Register HXIRMS = {0xE889, 4};
const Register HXWATT = {0xE88A, 4};
const Register HXVAR = {0xE88B, 4};
const Register HXVA = {0xE88C, 4};
const Register HXPF = {0xE88D, 4};
const Register HXVHD = {0xE88E, 4};
const Register HXIHD = {0xE88F, 4};
const Register HYVRMS = {0xE890, 4};
const Register HYIRMS = {0xE891, 4};
const Register HYWATT = {0xE892, 4};
const Register HYVAR = {0xE893, 4};
const Register HYVA = {0xE894, 4};
const Register HYPF = {0xE895, 4};
const Register HYVHD = {0xE896, 4};
const Register HYIHD = {0xE897, 4};
const Register HZVRMS = {0xE898, 4};
const Register HZIRMS = {0xE899, 4};
const Register HZWATT = {0xE89A, 4};
const Register HZVAR = {0xE89B, 4};
const Register HZVA = {0xE89C, 4};
const Register HZPF = {0xE89D, 4};
const Register HZVHD = {0xE89E, 4};
const Register HZIHD = {0xE89F, 4};
const Register HCONFIG = {0xE900, 2};
const Register APF = {0xE902, 2};
const Register BPF = {0xE903, 2};
const Register CPF = {0xE904, 2};
const Register APERIOD = {0xE905, 2};
const Register BPERIOD = {0xE906, 2};
const Register CPERIOD = {0xE907, 2};
const Register APNOLOAD = {0xE908, 2};
const Register VARNOLOAD = {0xE909, 2};
const Register VANOLOAD = {0xE90A, 2};
const Register LAST_ADD = {0xE9FE, 2};
const Register LAST_RWDATA16 = {0xE9FF, 2};
const Register CONFIG3 = {0xEA00, 1};
const Register LAST_OP = {0xEA01, 1};
const Register WTHR = {0xEA02, 1};
const Register VARTHR = {0xEA03, 1};
const Register VATHR = {0xEA04, 1};
const Register HX = {0xEA08, 1};
const Register HY = {0xEA09, 1};
const Register HZ = {0xEA0A, 1};
const Register LPOILVL = {0xEC00, 1};
const Register CONFIG2 = {0xEC01, 1};

//Returns the position of the right most bit set to HIGH
unsigned short BitPosition(int value)
{
	/*Works by checking if the value is odd and shifting the value to the right until odd number
	 *
	 */

	unsigned short count = 0;

	while(value % 2 == 0)
	{
		count++;
		value = value >> 1;
	}

	return count;
}
