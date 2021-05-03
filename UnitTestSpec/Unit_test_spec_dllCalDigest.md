# Unit Test Specification of the Interface "dllCalDigest"

## TG_dllCalDigest

### 5.1 TC_dllCalDigest_invalid_digest_name
**Purpose:** To check the function behaviors when an invalid cipher name is input <br>
**Test setup:** source text = "Hello World!"; source text length = 16; <br>
**Sub test cases 1: Input an invalid cipher name**
* input: digest algorithm name = "md6”
* expected output: / 
* expected return: 0 (the function is abort)

**Sub test cases 2: Input a null cipher name**
* input: digest algorithm name = null
* expected output: null (the function is abort)
* expected return: 0 (the function is abort)

### 5.2.1 TC_dllCalDigest_md5_normal 
**Purpose:** To check whether the function works normally <br>
**Test setup:** digest algorithm name = "md5”; source text = "Hello World!"; source text length = 12; <br>
**Sub test cases 1: Normal operation**
* input: /
* expected output: digest text = “ed076287532e86365e841e92bfc50d8c”; digest text length = 16;
* expected return: 1 (operation succeeds)

### 5.2.2 TC_dllCalDigest_md5_in_plaintext 
**Purpose:** To check whether the function works normally with various input text values<br>
**Test setup:** digest algorithm name = "md5”; <br>
**Sub test cases 1: Calculte the digest with correct input text**
* input: source text = "Hello World!"; source text length = 12;
* expected output: digest text = “ed076287532e86365e841e92bfc50d8c”; digest text length = 16;
* expected return: 1 (operation succeeds)

**Sub test cases 2: Calculte the digest with null input text**
* input: source text = ""; source text length = 0;
* expected output: digest text = “d41d8cd98f00b204e9800998ecf8427e”; digest text length = 16;
* expected return: 1 (operation succeeds)

**Sub test cases 3: Calculte the digest with a large input text**
* input: source text = "0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef"; source text length = 160;
* expected output: digest text = “7379d6fb5fe1d30f7d5df7021943091e”; digest text length = 16;
* expected return: 1 (operation succeeds)

### 5.3.1 TC_dllCalDigest_sha1_normal 
**Purpose:** To check whether the function works normally <br>
**Test setup:** digest algorithm name = "sha1”; source text = "Hello World!"; source text length = 12; <br>
**Sub test cases 1: Normal operation**
* input: /
* expected output: digest text = “2ef7bde608ce5404e97d5f042f95f89f1c232871”; digest text length = 20;
* expected return: 1 (operation succeeds)

### 5.3.2 TC_dllCalDigest_sha1_in_plaintext 
**Purpose:** To check whether the function works normally with various input text values<br>
**Test setup:** digest algorithm name = "sha1”; <br>
**Sub test cases 1: Calculte the digest with correct input text**
* input: source text = "Hello World!"; source text length = 12;
* expected output: digest text = “2ef7bde608ce5404e97d5f042f95f89f1c232871”; digest text length = 20;
* expected return: 1 (operation succeeds)

**Sub test cases 2: Calculte the digest with null input text**
* input: source text = ""; source text length = 0;
* expected output: digest text = “da39a3ee5e6b4b0d3255bfef95601890afd80709”; digest text length = 20;
* expected return: 1 (operation succeeds)

**Sub test cases 3: Calculte the digest with a large input text**
* input: source text = "0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef"; source text length = 160;
* expected output: digest text = “dc13aa62da0074f1b0ead3830dc56e98c25bb52c”; digest text length = 20;
* expected return: 1 (operation succeeds)

### 5.4.1 TC_dllCalDigest_sha256_normal 
**Purpose:** To check whether the function works normally <br>
**Test setup:** digest algorithm name = "sha256”; source text = "Hello World!"; source text length = 12; <br>
**Sub test cases 1: Normal operation**
* input: /
* expected output: digest text = “7f83b1657ff1fc53b92dc18148a1d65dfc2d4b1fa3d677284addd200126d9069”; digest text length = 32;
* expected return: 1 (operation succeeds)

### 5.4.2 TC_dllCalDigest_sha256_in_plaintext 
**Purpose:** To check whether the function works normally with various input text values<br>
**Test setup:** digest algorithm name = "sha256”; <br>
**Sub test cases 1: Calculte the digest with correct input text**
* input: source text = "Hello World!"; source text length = 12;
* expected output: digest text = “7f83b1657ff1fc53b92dc18148a1d65dfc2d4b1fa3d677284addd200126d9069”; digest text length = 32;
* expected return: 1 (operation succeeds)

**Sub test cases 2: Calculte the digest with null input text**
* input: source text = ""; source text length = 0;
* expected output: digest text = “e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855”; digest text length = 32;
* expected return: 1 (operation succeeds)

**Sub test cases 3: Calculte the digest with a large input text**
* input: source text = "0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef"; source text length = 160;
* expected output: digest text = “c84e5648e5bd3dd9e37b57ecb80fc505e3324f53487e07532c9020e5b9e4e76d”; digest text length = 32;
* expected return: 1 (operation succeeds)

### 5.5.1 TC_dllCalDigest_sha512_normal 
**Purpose:** To check whether the function works normally <br>
**Test setup:** digest algorithm name = "sha512”; source text = "Hello World!"; source text length = 12; <br>
**Sub test cases 1: Normal operation**
* input: /
* expected output: digest text = “861844d6704e8573fec34d967e20bcfef3d424cf48be04e6dc08f2bd58c729743371015ead891cc3cf1c9d34b49264b510751b1ff9e537937bc46b5d6ff4ecc8”; digest text length = 64;
* expected return: 1 (operation succeeds)

### 5.5.2 TC_dllCalDigest_sha512_in_plaintext 
**Purpose:** To check whether the function works normally with various input text values<br>
**Test setup:** digest algorithm name = "sha512”; <br>
**Sub test cases 1: Calculte the digest with correct input text**
* input: source text = "Hello World!"; source text length = 12;
* expected output: digest text = “861844d6704e8573fec34d967e20bcfef3d424cf48be04e6dc08f2bd58c729743371015ead891cc3cf1c9d34b49264b510751b1ff9e537937bc46b5d6ff4ecc8”; digest text length = 64;
* expected return: 1 (operation succeeds)

**Sub test cases 2: Calculte the digest with null input text**
* input: source text = ""; source text length = 0;
* expected output: digest text = “cf83e1357eefb8bdf1542850d66d8007d620e4050b5715dc83f4a921d36ce9ce47d0d13c5d85f2b0ff8318d2877eec2f63b931bd47417a81a538327af927da3e”; digest text length = 64;
* expected return: 1 (operation succeeds)

**Sub test cases 3: Calculte the digest with a large input text**
* input: source text = "0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef"; source text length = 160;
* expected output: digest text = “be08ccaac1e41a76a605ce60a745b82d66614fd30722fbf741ae70a3353cfadd5f2b9046e4f11220da5fde19afbda6228c54d62bdc35eb0821d99eaff37097f0”; digest text length = 64;
* expected return: 1 (operation succeeds)

