/********** Included files ************/
#include <openssl/evp.h>

/********** The function realizes the algorithm ************/
int EVPDigest(char* digestname, unsigned char* in, unsigned char* out, long* poutlen)
{

	unsigned int inlen, poutlenTmp;

	inlen = strlen((char*)in);
	EVP_MD_CTX* ctx = EVP_MD_CTX_new();
	const EVP_MD* md = NULL;

	/* initialize the context */
	EVP_MD_CTX_init(ctx);

	/* use "openssl dgst -h" to check the supported name */
	md = EVP_get_digestbyname(digestname);
	if (NULL == md) {
		fprintf(stderr, "OpenSSL_Digest: Digest for %s is NULL\n", digestname);
		goto err;
	}
	
	if (!EVP_DigestInit(ctx, md)) {
		fprintf(stderr, "OpenSSL_Cipher: EVP_DigestInit faileds\n");
		goto err;
	}

	if (!EVP_DigestUpdate(ctx, in, inlen)) {
		fprintf(stderr, "OpenSSL_Cipher: EVP_DigestUpdate failed\n");
		goto err;
	}

	/* Export the calculation result*/
	if (!EVP_DigestFinal(ctx, out, &poutlenTmp)) {
		fprintf(stderr, "OpenSSL_Cipher: EVP_DigestFinal failed\n");
		goto err;
	}
	*poutlen = (long)poutlenTmp;
	return 1;

err:
	
	EVP_MD_CTX_free(ctx);
	return 0;
}

/********** The function interface ************/
uint32_t CAPLEXPORT CAPLPASCAL calDigest(char* digestname, unsigned char* in, unsigned char* out, long* poutlen)
{
	int ret;
	ret = EVPDigest(digestname, in, out, poutlen);
	
	return ret;
}

/********** The string for the export table ************/
{"dllCalDigest",      (CAPL_FARCALL)calDigest,        "CryptoBasis", "This function will calculate the HASH value of the provided string. Return 1 if the calculation is succeeded.", 'D', 4, {'C', 'B', 'B', 'L'-128}, "\001\001\001\000", {"digestname", "in", "out", "poutlen"}},
  
