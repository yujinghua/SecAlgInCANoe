/********** Included files ************/
#include "openssl/rsa.h"  
#include "openssl/pem.h" 

/********** The function realizes the algorithm ************/
int RSAPriDec(const unsigned char* ciphertext, long cipherLen, const char* priKeyFile, const char* priKeyFilePW, unsigned char* decryptedtext, long* dectextLen) {

	char tmp[256];

	RSA* rsa = NULL;
	BIO* bp = NULL;
	bp = BIO_new_file(priKeyFile, "rb");
	if (NULL == bp) {
		printf("RSAPrivateDecrypt bio file new error!\n");
		BIO_free(bp);
		RSA_free(rsa);
		return 0;
	}
	rsa = PEM_read_bio_RSAPrivateKey(bp, &rsa, NULL, (void*)priKeyFilePW);
	if (rsa == 0)
	{
		printf("RSAPrivateDecrypt failed to PEM_read_bio_RSAPrivateKey!\n");
		BIO_free(bp);
		RSA_free(rsa);
		return 0;
	}

	//RSA_private_decrypt() returns the size of the recovered plaintext.
	*dectextLen = RSA_private_decrypt(cipherLen, ciphertext, decryptedtext, rsa, RSA_PKCS1_PADDING);

	if (*dectextLen == -1) {
		printf("RSAPrivateDecrypt failed to RSA_private_decrypt!\n");
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
uint32_t CAPLEXPORT CAPLPASCAL RSAPrivateDecrypt(unsigned char* ciphertext, long cipherLen, char* priKeyFile, char* priKeyFilePW, unsigned char* decryptedtext, long* dectextLen) {
	int ret;
	ret = RSAPriDec(ciphertext, cipherLen, priKeyFile, priKeyFilePW, decryptedtext, dectextLen);
	return ret; 
}

/********** The string for the export table ************/
{"dllRSAPrivateDecrypt",(CAPL_FARCALL)RSAPrivateDecrypt,        "CryptoBasis", "This function will decrypt the input string with . Return 1 if it is succeeded.", 'D', 6, {'B', 'L', 'C', 'C', 'B', 'L' - 128},  "\001\000\001\001\001\000", {"ciphertext", "cipherLen", "priKeyFile", "priKeyFilePW", "decryptedtext", "dectextLen"}},
  
