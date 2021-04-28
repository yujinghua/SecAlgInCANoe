/********** Included files ************/
#include <openssl/evp.h>

/********** The function realizes the algorithm ************/
int EVPHmac(char* hashAlgName, const unsigned char* msg, long mlen, unsigned char* val, long* vlen, unsigned char* aKey, long keyLen) {
	EVP_MD_CTX* mdctx = NULL;
	const EVP_MD* md = NULL;
	EVP_PKEY* pkey = NULL;
	unsigned char md_value[EVP_MAX_MD_SIZE];
	size_t md_len = 0;

	OpenSSL_add_all_digests();

	if (!(mdctx = EVP_MD_CTX_create())) {
		printf("EVP_MD_CTX_create failed, error \n");
		EVP_MD_CTX_free(mdctx); return 0;
	}

	if (!(md = EVP_get_digestbyname(hashAlgName))) {
		printf("EVP_get_digestbyname failed, error \n");
		EVP_MD_CTX_free(mdctx); return 0;
	}

	if (!(pkey = EVP_PKEY_new_mac_key(EVP_PKEY_HMAC, NULL, aKey, keyLen))) {
		printf("EVP_PKEY_new_mac_key failed, error \n");
		EVP_MD_CTX_free(mdctx); return 0;
	}

	if (1 != EVP_DigestSignInit(mdctx, NULL, md, NULL, pkey)) {
		printf("EVP_DigestSignInit failed, error \n");
		EVP_MD_CTX_free(mdctx); return 0;
	}

	/* Call update with the message */
	if (1 != EVP_DigestSignUpdate(mdctx, msg, mlen)) {
		printf("EVP_DigestSignUpdate failed, error \n");
		EVP_MD_CTX_free(mdctx); return 0;
	}

	if (1 != EVP_DigestSignFinal(mdctx, val, &md_len)) {
		printf("EVP_DigestSignFinal failed, error \n");
		EVP_MD_CTX_free(mdctx); return 0;
	}

	*vlen = md_len;
	//*val = md_value;

	EVP_MD_CTX_free(mdctx);
	return 1;

}

/********** The function interface ************/
uint32_t CAPLEXPORT CAPLPASCAL calHMAC(char* hashAlgName,
	unsigned char* msg, long mlen, 
	unsigned char* val, long* vlen, 
	unsigned char* aKey, long keyLen) {
	int ret;
	ret = EVPHmac(hashAlgName, msg, mlen, val, vlen, aKey, keyLen);

	return ret;
}

/********** The string for the export table ************/
{"dllCalHMAC",(CAPL_FARCALL)calHMAC,        "CryptoBasis", "This function will calculate HMAC of input messages. Return 1 if it is succeeded.", 'D', 7, {'C', 'B', 'L', 'B', 'L' - 128, 'B', 'L'},  "\001\001\000\001\000\001\000", {"hashAlgName", "msg", "mlen", "val", "vlen", "aKey", "keyLen"}},
	
