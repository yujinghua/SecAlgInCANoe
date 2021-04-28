# Help file of interfaces in the CAPL DLL 

## Interface List
* [dllSymmetryEncrypt](#dllSymmetryEncrypt)
* [dllSymmetryDecrypt](#dllSymmetryDecrypt)
* [dllRSAPublicEncrypt](#dllRSAPublicEncrypt)
* [dllRSAPrivateDecrypt](#dllRSAPrivateDecrypt)
* [dllCalDigest](#dllCalDigest)
* [dllCalHMAC](#dllCalHMAC)

### dllSymmetryEncrypt

**Definition**
Item|Content
----|------- 
Class | CryptoBasis 
Function Name| dllSymmetryEncrypt
Syntax|dword dllSymmetryEncrypt (char[] ciphername, byte[] aKey, byte[] iVec, byte[] in, long inlen, byte[] out, long& poutlen)
Description|This function encrypts the string by the specified symmetry encryption algorithm.
Parameters| - ciphername: the name of the encryption algorithm. (see [OpenSSL Supported Algorithms](#OpenSSL-Supported-Algorithms)) <br> - aKey: symmetry envryption key <br> - iVec: iv value <br> - in: input plain text <br> - inlen: length of the plain text <br> - out: output cipher text <br> - poutlen: length of the cipher text
Return Values| Return 1 if no error occurs. |

**Example Codes**
 ```
  char ciphername[32] = "aes-128-cbc";
  byte plaintext[64];
  byte ciphertext[64];
  byte decryptedtext[64];
  byte akey[64];
  byte iv[16];
  long plainlen, cipherlen, decryptedlen;
 
  int len, i;
  char plaintextStr[133]; //64*2+5
  char ciphertextStr[133];
  char decryptedtextStr[133];
  char akeyStr[133]; //64*2+5
  char ivStr[37]; //16*2+5
  char tmpC[3];
  
 // clear the byte array before a new round start
  for(i = 0; i < elCount(plaintext); i++){plaintext[i] = 0;} 
  for(i = 0; i < elCount(ciphertext); i++){ciphertext[i] = 0;} 
  for(i = 0; i < elCount(decryptedtext); i++){decryptedtext[i] = 0;} 
  //for(i = 0; i < 64; i++){akey[i] = 0x00;} //clean akey
  //for(i = 0; i < 16; i++){iv[i] = 0x00;} //clean iv
  for(i = 0; i < elCount(plaintextStr); i++){plaintextStr[i] = 0;}
  for(i = 0; i < elCount(ciphertextStr); i++){ciphertextStr[i] = 0;}
  for(i = 0; i < elCount(decryptedtextStr); i++){decryptedtextStr[i] = 0;}
 
  //set the key
  for(i = 0; i < elcount(akey); i++){
    //akey[i] = random(256);
    //akey[i] = i;
    akey[i] = 'k';
    snprintf(tmpC, elcount(tmpC), "%02x", akey[i]);
    strncat(akeyStr, tmpC, (64*2+1));
  }
  write("akey = %s", akeyStr);
 
  //set the iv
  for(i = 0; i < elcount(iv); i++){
    //iv[i] = i;
    iv[i] = 'i';
    snprintf(tmpC, elcount(tmpC), "%02x", iv[i]);
    strncat(ivStr, tmpC, (16*2+1));
  }
  write("iv = %s", ivStr);
 
  //get plain text from sysvar
  sysGetVariableString( sysvar::Sender::TxText, plaintextStr, elcount(plaintextStr) ); 
  len = strlen(plaintextStr);
  plainlen = len;
  write("plainlen = %d", plainlen);
  write("plaintext = %s", plaintextStr);
  for(i = 0; i < len; i++){
    plaintext[i] = plaintextStr[i];
    //write("%x", plaintext[i]);
  }
 
  // encrypt plaintext
  dllSymmetryEncrypt(ciphername, akey, iv, plaintext, plainlen, ciphertext, cipherlen);
  write("cipherlen = %d", cipherlen);
  //print cipher text in hex
  for(i = 0; i < cipherlen; i++){ //
    //write("%d %x %c", i, ciphertext[i], ciphertext[i]);
    snprintf(tmpC, elcount(tmpC), "%02x", ciphertext[i]);
    strncat(ciphertextStr, tmpC, (cipherlen * 2 + 1)); //elcount(ciphertextStr)
  }
  write("%s", ciphertextStr);
 
  // decrypt ciphertext
  dllSymmetryDecrypt(ciphername, akey, iv, ciphertext, cipherlen, decryptedtext, decryptedlen);
  write("decryptedlen = %d", decryptedlen);
  //print decrypted test
  for(i = 0; i < decryptedlen; i++){
    decryptedtextStr[i] = decryptedtext[i];
    //write("%d %x %c", i, decryptedtext[i], decryptedtext[i]);
    //snprintf(tmpC, elcount(tmpC), "%02x", decryptedtext[i]);
    //strncat(decryptedtextStr, tmpC, (decryptedlen + 1));
  }
  write("decryptedtextStr = %s", decryptedtextStr);
 ```

### dllSymmetryDecrypt
**Definition**
Item|Content
----|------- 
Class | CryptoBasis
Function Name| dllSymmetryDecrypt
Syntax|dword dllSymmetryDecrypt (char[] ciphername, byte[] aKey, byte[] iVec, byte[] in, long inlen, byte[] out, long& poutlen)
Description|This function decrypts the string by the specified symmetry encryption algorithm.
Parameters| - ciphername: the name of the decryption algorithm. (see [OpenSSL Supported Algorithms](#OpenSSL-Supported-Algorithms)) <br> - aKey: symmetry envryption key <br> - iVec: iv value <br> - in: input cipher text <br> - inlen: length of the input cipher text <br> - out: output decrypted text <br> - poutlen: length of the output decrypted text 
Return Values| Return 1 if no error occurs. 

**Example Codes**
See dllSymmetryEncrypt- > Example Codes

### dllRSAPublicEncrypt
**Definition**
Item|Content
----|------- 
Class | CryptoBasis
Function Name | dllRSAPublicEncrypt
Syntax|dword dllRSAPublicEncrypt(byte plaintext[], long plainLen, char pubKeyFile[], byte ciphertext[], long* cipherLen)
Description|This function encrypts the input plaintext into the ciphertext by the RSA public key.
Parameters | - plaintext: input plaintext <br> - plainLen: length of the input plaintext <br> - pubKeyFile: path of the public key file(*.pem) <br> - ciphertext: the output cipher text <br> - cipherLen: the length of the output cipher text 
Return Values | Return 1 if no error occurs. 

**Example Codes**
```
byte plaintext[245];
  byte ciphertext[260];
  byte decryptedtext[245];
  char pubKeyFile[256] = "C:\\rsa_pubkey_pw.pem";
  char priKeyFile[256] = "C:\\rsa_prikey_pw.pem";
  char priKeyPW[256] = "1234";
  long plainlen, cipherlen, decryptedlen;
  
  char plaintextStr[495]; //plaintext[]length * 2 + 5
  char ciphertextStr[517];
  char decryptedtextStr[495];
  
  int i;
  int len;
  char tmpC[3];
  
  for(i = 0; i < elCount(plaintext); i++){plaintext[i] = 0;} // clear the byte array before a new round start
  for(i = 0; i < elCount(ciphertext); i++){ciphertext[i] = 0;} // clear the byte array before a new round start
  for(i = 0; i < elCount(decryptedtext); i++){decryptedtext[i] = 0;} // clear the byte array before a new round start
  for(i = 0; i < elCount(plaintextStr); i++){plaintextStr[i] = 0;}
  for(i = 0; i < elCount(ciphertextStr); i++){ciphertextStr[i] = 0;}
  for(i = 0; i < elCount(decryptedtextStr); i++){decryptedtextStr[i] = 0;}
  
  //get plain text
  sysGetVariableString( sysvar::Sender::TxText, plaintextStr, elcount(plaintextStr) ); // get string from sysvar 
  plainlen = strlen(plaintextStr);
  write("plainlen = %d", plainlen);
  write("plaintext = %s", plaintextStr);
  for(i = 0; i < plainlen; i++){
    plaintext[i] = plaintextStr[i];
    //write("%x", plaintext[i]);
  }
  
  // encrypt plaintext
  dllRSAPublicEncrypt(plaintext, plainlen, pubKeyFile, ciphertext, cipherlen);
  write("cipherlen = %d", cipherlen);
  //print cipher text in hex
  write("cipher text = ");
 for(i = 0; i < cipherlen; i++){ //
    //write("%d %x %c", i, ciphertext[i], ciphertext[i]);
    snprintf(tmpC, elcount(tmpC), "%02x", ciphertext[i]);
    strncat(ciphertextStr, tmpC, (cipherlen * 2 + 1)); //elcount(ciphertextStr)
  }
  write("%s", ciphertextStr);
  
 // decrypt ciphertext
  dllRSAPrivateDecrypt(ciphertext, cipherlen, priKeyFile, priKeyPW, decryptedtext, decryptedlen);
  write("decryptedlen = %d", decryptedlen);
  //print decrypted test
  for(i = 0; i < decryptedlen; i++){
    decryptedtextStr[i] = decryptedtext[i];
    //write("%d %x %c", i, decryptedtext[i], decryptedtext[i]);
    //snprintf(tmpC, elcount(tmpC), "%02x", decryptedtext[i]);
    //strncat(decryptedtextStr, tmpC, (decryptedlen + 1));
  }
  write("decrypted text = %s", decryptedtextStr);
```

### dllRSAPrivateDecrypt
**Definition**
Item|Content
----|------- 
Class | CryptoBasis 
Function Name | dllRSAPrivateDecrypt
Syntax|dword dllRSAPrivateDecrypt(byte ciphertext[], long cipherLen, char priKeyFile[], char priKeyFilePW[], byte decryptedtext[], long* dectextLen)
Description|This function decrypts the input ciphertext by the RSA private key.
Parameters| - ciphertext: input ciphertext <br> - cipherLen: length of the input ciphertext <br> - pubKeyFile: path of the public key file(*.pem) <br> - priKeyFilePW: password of the private key file  <br> - decryptedtext: the output decrypted text <br> - dectextLen: the length of the output decrypted text 
Return Values | Return 1 if no error occurs. 

**Example Codes**
See dllRSAPublicEncrypt -> Example Codes
Return Values| Return 1 if no error occurs. 

### dllCalDigest
**Definition**
Item|Content
----|------- 
Class | CryptoBasis 
Function Name | dllCalDigest
Syntax|dword dllCalDigest (char digestname[],  byte in[], byte out[], long& poutlen)
Description|This function calculates the hash value of the provided string
Parameters| - digestname: the name of the digest algorithm. (see [OpenSSL Supported Algorithms](#OpenSSL-Supported-Algorithms)) <br> - in: source data <br> - out: hash value of the source data <br> - poutlen: length of the hash value
Return Values| Return 1 if no error occurs. 

**Example Codes**
```
  int len, i;
  char scrStr[64];
  char mdStr[128];
  char tmpC[3];
  byte scrText[64];
  byte mdText[128];
  long poutlen;
 
 // clear the byte array before a new round start
  for(i = 0; i < elCount(scrText); i++){scrText[i] = 0;}
  for(i = 0; i < elCount(mdStr); i++){mdStr[i] = 0;}
  for(i = 0; i < elCount(mdText); i++){mdText[i] = 0;}
 
  // get source text from sysvar
  sysGetVariableString( sysvar::Sender::TxText, scrStr, elcount(scrStr) ); 
  len = strlen(scrStr);
  write("scrlen = %d", len);
  //write("%s", scrStr);
  for(i = 0; i < len; i++){
    scrText[i] = scrStr[i];
    //write("%x", scrText[i]);
  }
 
  //claculate digest
  dllCalDigest("md5", scrText, mdText, poutlen);
 
  //print output text
  for(i = 0; i < poutlen; i++){
    snprintf(tmpC, elcount(tmpC), "%02x", mdText[i]);
    strncat(mdStr, tmpC, (poutlen * 2 + 1));
  }
  write("%s", mdStr);
  write("poutlen = %d", poutlen);
```

### dllCalHMAC
**Definition**
Item|Content
----|------- 
Class | CryptoBasis 
Function Name | dllCalHMAC 
Syntax|dword dllCalHMAC(char hashAlgName[], byte msg[], long mlen, byte val[], long* vlen, byte aKey[], long keyLen)
Description|This function calculates the HMAC of the input data.
Parameters| - hashAlgName: input hash algorithm name (see [OpenSSL Supported Algorithms](#OpenSSL-Supported-Algorithms)) <br> - msg: input message <br> - mlen: length of the input message) <br> - val: output calculated value <br> - vlen: output length of the calculared value <br> - aKey: input key of the calculation <br> - keyLen: key length 
Return Values| Return 1 if no error occurs. 

**Example Codes**
```
int len, i;
  char scrStr[64];
  char hmacStr[128];
  char tmpC[3];
  byte scrText[64];
  byte hmacText[128];
  long hmacLen;
  byte akey[64];
  long keyLen = 8;
  akey[0] = 'p';
  akey[1] = 'a';
  akey[2] = 's';
  akey[3] = 's';
  akey[4] = 'w';
  akey[5] = 'o';
  akey[6] = 'r';
  akey[7] = 'd';
  
  for(i = 0; i < elCount(scrText); i++){scrText[i] = 0;} // clear the byte array before a new round start
  for(i = 0; i < elCount(hmacStr); i++){hmacStr[i] = 0;}
  for(i = 0; i < elCount(hmacText); i++){hmacText[i] = 0;}
  
  // get source text
  sysGetVariableString( sysvar::Sender::TxText, scrStr, elcount(scrStr) ); // get string from sysvar
  len = strlen(scrStr);
  write("scrlen = %d", len);
  //write("%s", scrStr);
  for(i = 0; i < len; i++){
    scrText[i] = scrStr[i];
    //write("%x", scrText[i]);
  }
  
  //claculate digest
  dllCalHMAC("sha1", scrText, len, hmacText, hmacLen, akey, keyLen);
  
  //print output text
  for(i = 0; i < hmacLen; i++){
    snprintf(tmpC, elcount(tmpC), "%02x", hmacText[i]);
    strncat(hmacStr, tmpC, (hmacLen * 2 + 1));
  }
  write("%s", hmacStr);
  write("hmacLen = %d", hmacLen);
}

// key = "password"; scrSrc = "hello" 
```

## OpenSSL Supported Algorithms

Use command "help" in the OpenSSL shell to check the supported algorithms in the used version.

For example, in the OpenSSL 1.1.1h version, when excuting "help", it outputs as follows, which shows the supported algorithms.

```
Standard commands
asn1parse         ca                certhash          ciphers           
crl               crl2pkcs7         dgst              dh                
dhparam           dsa               dsaparam          ec                
ecparam           enc               errstr            gendh             
gendsa            genpkey           genrsa            nseq              
ocsp              passwd            pkcs12            pkcs7             
pkcs8             pkey              pkeyparam         pkeyutl           
prime             rand              req               rsa               
rsautl            s_client          s_server          s_time            
sess_id           smime             speed             spkac             
ts                verify            version           x509  

Message Digest commands (see the `dgst' command for more details)
gost-mac          md4               md5               md_gost94         
ripemd160         sha1              sha224            sha256            
sha384            sha512            streebog256       streebog512       
whirlpool  

Cipher commands (see the `enc' command for more details)
aes-128-cbc       aes-128-ecb       aes-192-cbc       aes-192-ecb       
aes-256-cbc       aes-256-ecb       base64            bf                
bf-cbc            bf-cfb            bf-ecb            bf-ofb            
camellia-128-cbc  camellia-128-ecb  camellia-192-cbc  camellia-192-ecb  
camellia-256-cbc  camellia-256-ecb  cast              cast-cbc          
cast5-cbc         cast5-cfb         cast5-ecb         cast5-ofb         
chacha            des               des-cbc           des-cfb           
des-ecb           des-ede           des-ede-cbc       des-ede-cfb       
des-ede-ofb       des-ede3          des-ede3-cbc      des-ede3-cfb      
des-ede3-ofb      des-ofb           des3              desx              
rc2               rc2-40-cbc        rc2-64-cbc        rc2-cbc           
rc2-cfb           rc2-ecb           rc2-ofb           rc4               
rc4-40   

```
