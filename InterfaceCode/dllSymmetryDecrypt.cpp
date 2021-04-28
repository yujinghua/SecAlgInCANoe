/********** Included files ************/
#include "openssl/evp.h"

/********** The function realizes the algorithm ************/
int EVPSymmetryDecrypt(const char* ciphername,
	const unsigned char* aKey, const unsigned char* iVec,
	const unsigned char* in, long inlen,
	unsigned char* out, long* poutlen)
{
	int tmplen = 0;
	int inlentmp;
	int poutlenTmp;

	if (inlen == 0) {
		return 101;
	}
	inlentmp = inlen;

	const EVP_CIPHER* cipher = NULL;
	EVP_CIPHER_CTX* ctx = EVP_CIPHER_CTX_new();

	EVP_CIPHER_CTX_init(ctx);

	cipher = EVP_get_cipherbyname(ciphername);
	if (NULL == cipher) {
		fprintf(stderr, "OpenSSL_Cipher: Cipher for %s is NULL. \n", ciphername);
		EVP_CIPHER_CTX_cleanup(ctx);
		return 100;
	}


	if (!EVP_DecryptInit_ex(ctx, cipher, NULL, aKey, iVec)) {
		fprintf(stderr, "OpenSSL_Cipher: EVP_DecryptInit_ex failed. \n");
		EVP_CIPHER_CTX_cleanup(ctx);
		return 0;
	}

	if (!EVP_DecryptUpdate(ctx, out, &poutlenTmp, in, inlentmp)) {
		fprintf(stderr, "OpenSSL_Cipher: EVP_DecryptUpdate failed. \n");
		EVP_CIPHER_CTX_cleanup(ctx);
		return 0;
	}

	if (!EVP_DecryptFinal_ex(ctx, out + poutlenTmp, &tmplen)) {
		fprintf(stderr, "OpenSSL_Cipher: EVP_DecryptFinal_ex failed. \n");
		EVP_CIPHER_CTX_cleanup(ctx);
		return 0;
	}
	
	poutlenTmp += tmplen;
	*poutlen = poutlenTmp;

	EVP_CIPHER_CTX_cleanup(ctx);
	return 1;

}

/********** The function interface ************/
uint32_t CAPLEXPORT CAPLPASCAL symmetryDecrypt(char* ciphername,
	unsigned char* aKey, unsigned char* iVec,
	unsigned char* in, long inlen,
	unsigned char* out, long* poutlen) 
{
	int ret;
	ret = EVPSymmetryDecrypt(ciphername, aKey, iVec, in, inlen, out, poutlen);
	return ret;
}

/********** The string for the export table ************/
{"dllSymmetryDecrypt",(CAPL_FARCALL)symmetryDecrypt,        "CryptoBasis", "This function will decrypt the input string. Return 1 if it is succeeded.", 'D', 7, {'C', 'B', 'B', 'B', 'L', 'B', 'L' - 128},  "\001\001\001\001\000\001\000", {"ciphername", "aKey", "iVec", "in", "inlen", "out", "poutlen"}},
  
