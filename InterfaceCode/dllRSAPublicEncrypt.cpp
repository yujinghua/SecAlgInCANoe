/********** Included files ************/
#include "openssl/rsa.h"  
#include "openssl/pem.h" 

/********** The function realizes the algorithm ************/
int RSAPubEnc(const unsigned char* plaintext, long plainLen, const char* pubKeyFile, unsigned char* ciphertext, long* cipherLen) {

	RSA* rsa = NULL;
	BIO* bp = BIO_new(BIO_s_file());
	BIO_read_filename(bp, pubKeyFile);
	if (NULL == bp) {
		printf("RSAPublicEncrypt bio file new error!\n");
		BIO_free(bp);
		RSA_free(rsa);
		return 0;
	}
	rsa = PEM_read_bio_RSA_PUBKEY(bp, NULL, NULL, NULL); //PKCS#8 - todo
	if (rsa == NULL) {
		printf("RSAPublicEncrypt failed to PEM_read_bio_RSAPublicKey!\n");
		BIO_free(bp);
		RSA_free(rsa);
		return 0;
	}

	//RSA_public_encrypt() returns the size of the encrypted data(i.e., RSA_size(rsa)).
	*cipherLen = RSA_public_encrypt(plainLen, plaintext, ciphertext, rsa, RSA_PKCS1_PADDING);
	if (*cipherLen == -1) {
		printf("RSAPublicEncrypt failed to RSA_public_encrypt!\n");
		BIO_free(bp);
		RSA_free(rsa);
		return 0;
	}

	// release memory
	BIO_free_all(bp);
	RSA_free(rsa);

	return 1;
}

/********** The function interface ************/
uint32_t CAPLEXPORT CAPLPASCAL RSAPublicEncrypt(unsigned char* plaintext, long plainLen, char* pubKeyFile, unsigned char* ciphertext, long* cipherLen) {

	// (?) use both Dbgview.exe and Dbgview64.exe for this dll
	//#include <Windows.h>
	char tmp[512]; 
	sprintf_s(tmp, "rsa debug info output %d \n", 1); OutputDebugStringA(tmp);
	
	int ret;
	ret = RSAPubEnc(plaintext, plainLen, pubKeyFile, ciphertext, cipherLen);
	return ret;
}

/********** The string for the export table ************/
{"dllRSAPublicEncrypt",(CAPL_FARCALL)RSAPublicEncrypt,        "CryptoBasis", "This function will encrypt the input string with a public key. Return 1 if it is succeeded.", 'D', 5, {'B', 'L', 'C', 'B', 'L' - 128},  "\001\000\001\001\000", {"plaintext", "plainLen", "pubKeyFile", "ciphertext", "cipherLen"}},
  
