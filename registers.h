
#ifndef REGISTERS_H_
#define REGISTERS_H_

#ifdef __cplusplus
extern "C"
{
#endif

typedef struct{
	int address;
	int length;
} Register;

extern const Register STATUS0;
extern const Register STATUS1;
extern const Register MASK0;
extern const Register MASK1;

extern const Register CHECKSUM;


#ifdef __cplusplus
}
#endif

#endif /* REGISTERS_H_ */
