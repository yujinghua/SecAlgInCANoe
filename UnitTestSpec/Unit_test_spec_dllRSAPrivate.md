# Unit test specificatipn of dllRSAPrivateDecrypt & dllRSAPublicEncrypt

## 3 TG_dllRSAPrivateDecrypt
### 3.1 TC_dllRSAPrivateDecrypt_normal 
Purpose: To check whether the function works normally
Test setup: cipher text = "45ea2de117fb55ee22578b58a7251abcb725b6c9d75eea2a7080dbafe1195370120c45e9e70169d8e987c7ece01c6cf76e4b1be884dad7a1e050a5b7f7ed9485b12ff58386b6f02a2cccf6244c2d08828bffaa5d689f952c420bad6438e432934d72a3a6a3e50217dbcaee1eb1f08b167deca114a9fdeec9ff6e9dcbde647eed”; cipher text length = 128; priKeyFile = "C:\\correctpath\\rsa_prikey.pem";
Sub test cases 1: Normal operation

- input: /
- expected output: plain text = “Hello World!”; plain text length = 12;
- expected return: error code = 1 (operation succeeds)

### 3.2 TC_dllRSAPrivateDecrypt_priKeyFile 
Purpose: To check the function behaviors when various key files are input
Test setup: cipher text = "45ea2de117fb55ee22578b58a7251abcb725b6c9d75eea2a7080dbafe1195370120c45e9e70169d8e987c7ece01c6cf76e4b1be884dad7a1e050a5b7f7ed9485b12ff58386b6f02a2cccf6244c2d08828bffaa5d689f952c420bad6438e432934d72a3a6a3e50217dbcaee1eb1f08b167deca114a9fdeec9ff6e9dcbde647eed”; cipher text length = 128; 
Sub test cases 1: Correct private key

- input: priKeyFile = "C:\\correctpath\\rsa_prikey.pem";
- expected output: plain text = “Hello World!”; plain text length = 12;
- expected return: 1 (operation succeeds)

Sub test cases 2: Wrong private key file path

- input: priKeyFile = "C:\\wrongpath\\rsa_prikey.pem";
- expected output: /
- expected return: 0 (operation is abort)

Sub test cases 3: Wrong private key file

- input: priKeyFile = "C:\\correctpath\\rsa_prikey_wrong.pem";
- expected output: /
- expected return: 0 (operation is abort)

Sub test cases 4: null private key file path

- input: priKeyFile = "";
- expected output: /
- expected return: 0 (operation is abort)

### 3.3 TC_dllRSAPrivateDecrypt_priKeyFile_pw 
Purpose: To check the function behaviors when various key password values are input
Test setup: cipher text = "a38453093827a781da0c84af61d08b0f9426eb860165cdb444fb1b8628b367155d49fcddf751641c7e4e0d1987a433da50dbceb6288374d606fc9bea071e0ed2dc73f95fabdc5efd3ee3e21dd50060b571133ddd91291decc0e5750b4119b6086978559531dfbc8e2be33fc126c5519c2d306f48bf437e308518ee98c0590ab0”; cipher text length = 128; priKeyFile = "C:\\correctpath\\rsa_prikey_pw.pem"; 
Sub test cases 1: Correct private key password

- input: key password = "123456"; (correct password)
- expected output: plain text = “Hello World!”; plain text length = 12;
- expected return: 1 (operation succeeds)

Sub test cases 2: Wrong private key password

- input: key password = "123"; (wrong password)
- expected output:/
- expected return:  0 (operation is abort)

Sub test cases 3: Null private key password

- input: key password = ""; (wrong password)
- expected output:/
- expected return:  0 (operation is abort)


### 3.4 TC_dllRSAPrivateDecrypt_in_cipher 
Purpose: To check the function behaviors when various cryptotexts are input
Test setup: priKeyFile = "C:\\correctpath\\rsa_prikey.pem"; 
Sub test cases 1: Correct input ciphertext

- input: cipher text = "a38453093827a781da0c84af61d08b0f9426eb860165cdb444fb1b8628b367155d49fcddf751641c7e4e0d1987a433da50dbceb6288374d606fc9bea071e0ed2dc73f95fabdc5efd3ee3e21dd50060b571133ddd91291decc0e5750b4119b6086978559531dfbc8e2be33fc126c5519c2d306f48bf437e308518ee98c0590ab0”; cipher text length = 128;
- expected output: plain text = “Hello World!”; plain text length = 12;
- expected return: 1 (operation succeeds)

Sub test cases 2: Correct input ciphertext

- input: cipher text = "55ea2de117fb55ee22578b58a7251abcb725b6c9d75eea2a7080dbafe1195370120c45e9e70169d8e987c7ece01c6cf76e4b1be884dad7a1e050a5b7f7ed9485b12ff58386b6f02a2cccf6244c2d08828bffaa5d689f952c420bad6438e432934d72a3a6a3e50217dbcaee1eb1f08b167deca114a9fdeec9ff6e9dcbde647eed”; cipher text length = 128;
- expected output:/
- expected return: 0 (operation is abort)

Sub test cases 3: Null input ciphertext

- input: cipher text = "”; cipher text length = 0;
- expected output:/
- expected return: 0 (operation is abort)

### 3.5 TC_dllRSAPrivateDecrypt_in_cipherlen_wrong 
Purpose: To check the function behaviors when various cryptotext lengths are input
Test setup: priKeyFile = "C:\\correctpath\\rsa_prikey.pem"; cipher text = "a38453093827a781da0c84af61d08b0f9426eb860165cdb444fb1b8628b367155d49fcddf751641c7e4e0d1987a433da50dbceb6288374d606fc9bea071e0ed2dc73f95fabdc5efd3ee3e21dd50060b571133ddd91291decc0e5750b4119b6086978559531dfbc8e2be33fc126c5519c2d306f48bf437e308518ee98c0590ab0”;
Sub test cases 1: Correct input ciphertext length

- input:  cipher text length = 128;
- expected output: plain text = “Hello World!”; plain text length = 12;
- expected return: 1 (operation succeeds)

Sub test cases 2: Shorter input ciphertext length

- input:  cipher text length = 127;
- expected output: /
- expected return: 0 (operation is abort)

Sub test cases 3: longer input ciphertext length

- input:  cipher text length = 129;
- expected output: /
- expected return: 0 (operation is abort)

Sub test cases 4: Zero input ciphertext length

- input:  cipher text length = 0;
- expected output: /
- expected return: 0 (operation is abort)

## 4 TG_dllRSAPublicEncrypt
(Note: For unit tests of "dllRSAPublicEncrypt", "dllRSAPrivateDecrypt" is used to dectypt the output ciphertext to check whether the target interface works correctly. "dllRSAPrivateDecrypt" has been tested in unit test group 3.)
### 4.1 TC_dllRSAPublicEncrypt_normal 
Purpose: To check whether the function works normally
Test setup: pubKeyFile = "C:\\correctpath\\rsa_pubkey.pem"; plain text = “Hello World!”; plain text length = 12;
Sub test cases 1: Normal operation

- input: /
- pass conditions: The decrypted text matched the original plain text.


### 4.2 TC_dllRSAPublicEncrypt_pubKeyFile
Purpose: To check the function behaviors when various key files are input
Test setup:  plain text = “Hello World!”; plain text length = 12;
Sub test cases 1: Correct public key

- input: pubKeyFile = "C:\\correctpath\\rsa_pubkey.pem";
- pass conditions: The decrypted text matched the original plain text.

Sub test cases 2: Wrong public key file path

- input: pubKeyFile = "C:\\wrongpath\\rsa_pubkey.pem";
- expected return: 0 (operation is abort)

Sub test cases 3: Wrong public key file

- input: pubKeyFile = "C:\\correctpath\\rsa_pubkey_wrong.pem";
- expected return: 0 (operation is abort)

Sub test cases 4: Null public key file path

- input: pubKeyFile = "";
- expected return: 0 (operation is abort)


### 4.3 TC_dllRSAPublicEncrypt_in_plaintext 
Purpose: To check the function behaviors when various plaintext are input
Test setup: priKeyFile = "C:\\correctpath\\rsa_pubkey.pem"; 
Sub test cases 1: Plaintext length < 117 bytes

- input: plain text = “Hello World!”; plain text length = 12;
- pass conditions: The decrypted text matched the original plain text.

Sub test cases 2: Plaintext length = 117 bytes

- input: plain text = “0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef01234”; plain text length = 117;
- pass conditions: The decrypted text matched the original plain text.

Sub test cases 3: Plaintext length > 117 bytes

- input: plain text = “0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef012345”; plain text length = 118;
- expected return: 0 (operation is abort)

Sub test cases 4: Plaintext length > 117 bytes

- input: plain text = “”; plain text length = 0;
- pass conditions: The decrypted text matched the original plain text.

### 4.4 TC_dllRSAPublicEncrypt_in_plainlen\_wrong 
Purpose: To check the function behaviors when various plaintext lengths are input
Test setup: priKeyFile = "C:\\correctpath\\rsa_pubkey.pem"; 
Sub test cases 1: Correct plaintext length

- input: plain text = “Hello World!”; plain text length = 12;
- pass conditions: The decrypted text matched the original plain text.

Sub test cases 2: Shorter plaintext length

- input: plain text = “Hello World!”; plain text length = 11;
- pass conditions: The decrypted text matched the original plain text.

Sub test cases 3: Longer plaintext length

- input: plain text = “Hello World!1”; plain text length = 13;
- pass conditions: The decrypted text matched the original plain text.

Sub test cases 4: Zero plaintext length

- input: plain text = “”; plain text length = 0;
- pass conditions: The decrypted text matched the original plain text.
