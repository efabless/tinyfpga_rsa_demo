#include "rsa/rsa.h"
#include "uart/uart.h"
#include "string/string.h"

extern uint32_t sram;

#define reg_leds (*(volatile uint32_t*)0x03000000)
#define reg_uart_clkdiv (*(volatile uint32_t*)0x02000004)


void main()
{
	//reg_uart_clkdiv = 139;
	reg_uart_clkdiv = 278;
	print("\n");
	print("HELLO WORLD\n");
	char int_print_buffer[20];
	unsigned int cyc_start, cyc_end, cycles;

	struct public_key_class pub[1];
	struct private_key_class priv[1];

//	priv->modulus = 728226539;
//	priv->exponent = 461835209;
//	pub->modulus = 728226539;
//	pub->exponent = 257;

	print("Generating keys..\n");
	__asm__ volatile ("rdcycle %0" : "=r"(cyc_start));
	rsa_gen_keys(pub, priv);
	__asm__ volatile ("rdcycle %0" : "=r"(cyc_end));
	cycles = cyc_end - cyc_start;
	inttochar(cycles, int_print_buffer);
	print("Keygen time:\t");
	print(int_print_buffer);
	print("\n");


	print("Public(exp, mod): ");
	inttochar(priv->exponent, int_print_buffer);
	print(int_print_buffer);
	print(", ");
	inttochar(priv->modulus, int_print_buffer);
	print(int_print_buffer);
	print("\n");

	print("Private(exp, mod): ");
	inttochar(pub->exponent, int_print_buffer);
	print(int_print_buffer);
	print(", ");
	inttochar(pub->modulus, int_print_buffer);
	print(int_print_buffer);
	print("\n");


	char message[] = "123abcd";

	print("Original:\n");
	print("\t");
	print(message);
	print("\n");


	long long *encrypted;
	__asm__ volatile ("rdcycle %0" : "=r"(cyc_start));
	if (rsa_encrypt(message, sizeof(message), pub, encrypted) == -1) {
		print("Encryption unkown error\n");
		return;
	}
	__asm__ volatile ("rdcycle %0" : "=r"(cyc_end));
	cycles = cyc_end - cyc_start;
	inttochar(cycles, int_print_buffer);
	print("Encrypting time:\t");
	print(int_print_buffer);
	print("\n");


	char* decrypted;
	__asm__ volatile ("rdcycle %0" : "=r"(cyc_start));
	if (rsa_decrypt(encrypted, 8*sizeof(message), priv, decrypted) == -1) {
		print("Unkown decryption error\n");
		return;
	}
	__asm__ volatile ("rdcycle %0" : "=r"(cyc_end));
	cycles = cyc_end - cyc_start;
	inttochar(cycles, int_print_buffer);
	print("Decrypting time:\t");
	print(int_print_buffer);
	print("\n");

	print("Decrypted:\n");
	print("\t");
	print(decrypted);
	print("\n");
}
