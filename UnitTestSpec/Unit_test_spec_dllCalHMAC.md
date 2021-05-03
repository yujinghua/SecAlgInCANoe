# Unit Test Specification of the Interface "dllCalHMAC"

## TG_dllCalHMAC

### 6.1 TC_dllCalHMAC_invalid_digest_name
**Purpose:** To check the function behaviors when an invalid cipher name is input<br>
**Test setup:** key = "akey"; akeyLen = 4; source text = "Hello World!"; source text length = 16; <br>
**Sub test cases 1: Input an invalid cipher name**
* input: digest algorithm name = "md6”
* expected output: / 
* expected return: 0 (the function is abort)

**Sub test cases 2: Input a null cipher name**
* input: digest algorithm name = null
* expected output: null (the function is abort)
* expected return: 0 (the function is abort)

### 6.2.1 TC_dllCalHMAC_md5_normal 
**Purpose:** To check whether the function works normally<br>
**Test setup:** digest algorithm name = "md5”; key = "akey"; akeyLen = 4; source text = "Hello World!"; source text length = 12; <br>
**Sub test cases 1: Normal operation**
* input: /
* expected output: digest text = “e18ef6f39af8457c1e0c90c9e555e54e”; digest text length = 16;
* expected return: 1 (operation succeeds)

### 6.2.2 TC_dllCalHMAC_md5_akey 
**Purpose:** To check whether the function works normally with various key values<br>
**Test setup:** digest algorithm name = "md5”;  source text = "Hello World!"; source text length = 12; <br>
**Sub test cases 1: Calculte the HMAC value with a short key value**
* input: key = "akey"; akeyLen = 4;
* expected output: digest text = “e18ef6f39af8457c1e0c90c9e555e54e”; digest text length = 16;
* expected return: 1 (operation succeeds)

**Sub test cases 2: Calculte the HMAC value with a long key value**
* input: key = "0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef"; akeyLen = 160;
* expected output: digest text = “73e9edb010e88d157c43edd5081df7c5”; digest text length = 16;
* expected return: 1 (operation succeeds)

**Sub test cases 3: Calculte the HMAC value with a null key value**
* input: key = ""; akeyLen = 0;
* expected output: digest text = “72d422b3c98cc57b12d204a4eb935c4b”; digest text length = 16;
* expected return: 1 (operation succeeds)

### 6.2.3 TC_dllCalHMAC_md5_akeylen 
**Purpose:** To check whether the function works normally with various key length values<br>
**Test setup:** digest algorithm name = "md5”;  source text = "Hello World!"; source text length = 12; key = "akey"; <br>
**Sub test cases 1: Calculte the HMAC value with a correct key length**
* input:  akeyLen = 4;
* expected output: digest text = “e18ef6f39af8457c1e0c90c9e555e54e”; digest text length = 16;
* expected return: 1 (operation succeeds)

**Sub test cases 2: Calculte the HMAC value with a incorrect key length**
* input:  akeyLen = 3;
* expected output: digest text = “a0e5b555cdb90afdf7dd2a66ccb8c95b”; digest text length = 16;
* expected return: 1 (operation succeeds)

**Sub test cases 3: Calculte the HMAC value with a zero key length**
* input:  akeyLen = 0;
* expected output: digest text = “72d422b3c98cc57b12d204a4eb935c4b”; digest text length = 16;
* expected return: 1 (operation succeeds)

### 6.2.4 TC_dllCalHMAC_md5_in_plaintext 
**Purpose:** To check whether the function works normally with various input text values<br>
**Test setup:** digest algorithm name = "md5”;   key = "akey"; akeyLen = 4;<br>
**Sub test cases 1: Calculte the HMAC value of a short text**
* input: source text = "Hello World!"; source text length = 12;
* expected output: digest text = “e18ef6f39af8457c1e0c90c9e555e54e”; digest text length = 16;
* expected return: 1 (operation succeeds)

**Sub test cases 2: Calculte the HMAC value of a long text**
* input: source text = "0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef"; source text length = 160;
* expected output: digest text = “51ea71f71d7c82003ece18e4bdee5df1”; digest text length = 16;
* expected return: 1 (operation succeeds)

**Sub test cases 3: Calculte the HMAC value of null text**
* input: source text = ""; source text length = 0;
* expected output: digest text = “eaff3652fb057e9cff6ceed45c483c6c”; digest text length = 16;
* expected return: 1 (operation succeeds)


### 6.2.5 TC_dllCalHMAC_md5_in_plainlen_wrong 
**Purpose:** To check whether the function works normally with various input text length values<br>
**Test setup:** digest algorithm name = "md5”;   key = "akey"; akeyLen = 4; source text = "Hello World!";<br>
**Sub test cases 1: Calculte the HMAC value with a correct input text length**
* input:  source text length = 12;
* expected output: digest text = “e18ef6f39af8457c1e0c90c9e555e54e”; digest text length = 16;
* expected return: 1 (operation succeeds)

**Sub test cases 2: Calculte the HMAC value with a incorrect input text length**
* input:  source text length = 11;
* expected output: digest text = “18d87654d75c8aff82c98f37eefb7acf”; digest text length = 16;
* expected return: 1 (operation succeeds)

**Sub test cases 3: Calculte the HMAC value with a zero input text length**
* input:  source text length = 0;
* expected output: digest text = “eaff3652fb057e9cff6ceed45c483c6c”; digest text length = 16;
* expected return: 1 (operation succeeds)

### 6.3.1 TC_dllCalHMAC_sha1_normal 
**Purpose:** To check whether the function works normally<br>
**Test setup:** digest algorithm name = "sha1”; key = "akey"; akeyLen = 4; source text = "Hello World!"; source text length = 12; <br>
**Sub test cases 1: Normal operation**
* input: /
* expected output: digest text = “1ebdb9cf9220fa8c9df3f4847aa93df082beaf79”; digest text length = 20;
* expected return: 1 (operation succeeds)

### 6.3.2 TC_dllCalHMAC_sha1_akey 
**Purpose:** To check whether the function works normally with various key values<br>
**Test setup:** digest algorithm name = "sha1”;  source text = "Hello World!"; source text length = 12; <br>
**Sub test cases 1: Calculte the HMAC value with a short key value**
* input: key = "akey"; akeyLen = 4;
* expected output: digest text = “1ebdb9cf9220fa8c9df3f4847aa93df082beaf79”; digest text length = 20;
* expected return: 1 (operation succeeds)

**Sub test cases 2: Calculte the HMAC value with a long key value**
* input: key = "0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef"; akeyLen = 160;
* expected output: digest text = “d35d6f38719024683d78250c380ca99245ea2111”; digest text length = 20;
* expected return: 1 (operation succeeds)

**Sub test cases 3: Calculte the HMAC value with a null key value**
* input: key = ""; akeyLen = 0;
* expected output: digest text = “938ed40988f078b2281a6d2f058fa9bf2de578b9”; digest text length = 20;
* expected return: 1 (operation succeeds)

### 6.3.3 TC_dllCalHMAC_sha1_akeylen 
**Purpose:** To check whether the function works normally with various key length values<br>
**Test setup:** digest algorithm name = "sha1”;  source text = "Hello World!"; source text length = 12; key = "akey"; <br>
**Sub test cases 1: Calculte the HMAC value with a correct key length**
* input:  akeyLen = 4;
* expected output: digest text = “1ebdb9cf9220fa8c9df3f4847aa93df082beaf79”; digest text length = 20;
* expected return: 1 (operation succeeds)

**Sub test cases 2: Calculte the HMAC value with a incorrect key length**
* input:  akeyLen = 3;
* expected output: digest text = “30342008a8da1056b1ed5405780e03e668d468a9”; digest text length = 20;
* expected return: 1 (operation succeeds)

**Sub test cases 3: Calculte the HMAC value with a zero key length**
* input:  akeyLen = 0;
* expected output: digest text = “938ed40988f078b2281a6d2f058fa9bf2de578b9”; digest text length = 20;
* expected return: 1 (operation succeeds)

### 6.3.4 TC_dllCalHMAC_sha1_in_plaintext 
**Purpose:** To check whether the function works normally with various input text values<br>
**Test setup:** digest algorithm name = "sha1”;   key = "akey"; akeyLen = 4;<br>
**Sub test cases 1: Calculte the HMAC value of a short text**
* input: source text = "Hello World!"; source text length = 12;
* expected output: digest text = “1ebdb9cf9220fa8c9df3f4847aa93df082beaf79”; digest text length = 20;
* expected return: 1 (operation succeeds)

**Sub test cases 2: Calculte the HMAC value of a long text**
* input: source text = "0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef"; source text length = 160;
* expected output: digest text = “a9381f708b18fdf67b61ccfaec51c5cde82232fb”; digest text length = 20;
* expected return: 1 (operation succeeds)

**Sub test cases 3: Calculte the HMAC value of null text**
* input: source text = ""; source text length = 0;
* expected output: digest text = “c1324f8e9a47ee7f04f764bd2b077dbf85364d0e”; digest text length = 20;
* expected return: 1 (operation succeeds)


### 6.3.5 TC_dllCalHMAC_sha1_in_plainlen_wrong 
**Purpose:** To check whether the function works normally with various input text length values<br>
**Test setup:** digest algorithm name = "sha1”;   key = "akey"; akeyLen = 4; source text = "Hello World!";<br>
**Sub test cases 1: Calculte the HMAC value with a correct input text length**
* input:  source text length = 12;
* expected output: digest text = “1ebdb9cf9220fa8c9df3f4847aa93df082beaf79”; digest text length = 20;
* expected return: 1 (operation succeeds)

**Sub test cases 2: Calculte the HMAC value with a incorrect input text length**
* input:  source text length = 11;
* expected output: digest text = “e45780c3fd92618c4bb3c8b2f4936b9717279699”; digest text length = 20;
* expected return: 1 (operation succeeds)

**Sub test cases 3: Calculte the HMAC value with a zero input text length**
* input:  source text length = 0;
* expected output: digest text = “c1324f8e9a47ee7f04f764bd2b077dbf85364d0e”; digest text length = 20;
* expected return: 1 (operation succeeds)

### 6.4.1 TC_dllCalHMAC_sha256_normal 
**Purpose:** To check whether the function works normally<br>
**Test setup:** digest algorithm name = "sha256”; key = "akey"; akeyLen = 4; source text = "Hello World!"; source text length = 12; <br>
**Sub test cases 1: Normal operation**
* input: /
* expected output: digest text = “08bd1230b29e00a5e38bc327497e16e336a296f52011f3dcbc9ece39bbd19a65”; digest text length = 32;
* expected return: 1 (operation succeeds)

### 6.4.2 TC_dllCalHMAC_sha256_akey 
**Purpose:** To check whether the function works normally with various key values<br>
**Test setup:** digest algorithm name = "sha256”;  source text = "Hello World!"; source text length = 12; <br>
**Sub test cases 1: Calculte the HMAC value with a short key value**
* input: key = "akey"; akeyLen = 4;
* expected output: digest text = “08bd1230b29e00a5e38bc327497e16e336a296f52011f3dcbc9ece39bbd19a65”; digest text length = 32;
* expected return: 1 (operation succeeds)

**Sub test cases 2: Calculte the HMAC value with a long key value**
* input: key = "0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef"; akeyLen = 160;
* expected output: digest text = “a99007dc186b60cc67d8ed38eb1cd902ba9af53a6d1c88405abb0eb417a36a95”; digest text length = 32;
* expected return: 1 (operation succeeds)

**Sub test cases 3: Calculte the HMAC value with a null key value**
* input: key = ""; akeyLen = 0;
* expected output: digest text = “0366d43cf5215a646b90008490ca34b5994cc08f173c9e6cdccef82656896592”; digest text length = 32;
* expected return: 1 (operation succeeds)

### 6.4.3 TC_dllCalHMAC_sha256_akeylen 
**Purpose:** To check whether the function works normally with various key length values<br>
**Test setup:** digest algorithm name = "sha256”;  source text = "Hello World!"; source text length = 12; key = "akey"; <br>
**Sub test cases 1: Calculte the HMAC value with a correct key length**
* input:  akeyLen = 4;
* expected output: digest text = “08bd1230b29e00a5e38bc327497e16e336a296f52011f3dcbc9ece39bbd19a65”; digest text length = 32;
* expected return: 1 (operation succeeds)

**Sub test cases 2: Calculte the HMAC value with a incorrect key length**
* input:  akeyLen = 3;
* expected output: digest text = “22939d51b38ca7e1c9d6316ed8f20db0bd67e8ed7fe40b06ec078e79c8204374”; digest text length = 32;
* expected return: 1 (operation succeeds)

**Sub test cases 3: Calculte the HMAC value with a zero key length**
* input:  akeyLen = 0;
* expected output: digest text = “0366d43cf5215a646b90008490ca34b5994cc08f173c9e6cdccef82656896592”; digest text length = 32;
* expected return: 1 (operation succeeds)

### 6.4.4 TC_dllCalHMAC_sha256_in_plaintext 
**Purpose:** To check whether the function works normally with various input text values<br>
**Test setup:** digest algorithm name = "sha256”;   key = "akey"; akeyLen = 4;<br>
**Sub test cases 1: Calculte the HMAC value of a short text**
* input: source text = "Hello World!"; source text length = 12;
* expected output: digest text = “08bd1230b29e00a5e38bc327497e16e336a296f52011f3dcbc9ece39bbd19a65”; digest text length = 32;
* expected return: 1 (operation succeeds)

**Sub test cases 2: Calculte the HMAC value of a long text**
* input: source text = "0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef"; source text length = 160;
* expected output: digest text = “64a96e24aa8fdf3e6cfae93727729b30d21c135b9376a367a489e78a3d4a5b5f”; digest text length = 32;
* expected return: 1 (operation succeeds)

**Sub test cases 3: Calculte the HMAC value of null text**
* input: source text = ""; source text length = 0;
* expected output: digest text = “412f5ab81989c224095cb91a353a772266edc9655df612cacec72b0eedb3b9eb”; digest text length = 32;
* expected return: 1 (operation succeeds)


### 6.4.5 TC_dllCalHMAC_sha256_in_plainlen_wrong 
**Purpose:** To check whether the function works normally with various input text length values<br>
**Test setup:** digest algorithm name = "sha256”;   key = "akey"; akeyLen = 4; source text = "Hello World!";<br>
**Sub test cases 1: Calculte the HMAC value with a correct input text length**
* input:  source text length = 12;
* expected output: digest text = “08bd1230b29e00a5e38bc327497e16e336a296f52011f3dcbc9ece39bbd19a65”; digest text length = 32;
* expected return: 1 (operation succeeds)

**Sub test cases 2: Calculte the HMAC value with a incorrect input text length**
* input:  source text length = 11;
* expected output: digest text = “ee8186e679e6c575b3bbb529cd97035d362e5458608251f4ea4e230d0b8e24ed”; digest text length = 32;
* expected return: 1 (operation succeeds)

**Sub test cases 3: Calculte the HMAC value with a zero input text length**
* input:  source text length = 0;
* expected output: digest text = “412f5ab81989c224095cb91a353a772266edc9655df612cacec72b0eedb3b9eb”; digest text length = 32;
* expected return: 1 (operation succeeds)

### 6.5.1 TC_dllCalHMAC_sha512_normal 
**Purpose:** To check whether the function works normally<br>
**Test setup:** digest algorithm name = "sha512”; key = "akey"; akeyLen = 4; source text = "Hello World!"; source text length = 12; <br>
**Sub test cases 1: Normal operation**
* input: /
* expected output: digest text = “ebd36dd33ed836f21c4725ca55dbca927bbe7887a478b1531c55455ce6379064bf437316d3b49f45111fd042643904b2da712a70c4814a85cb3ecdd65f1c3467”; digest text length = 64;
* expected return: 1 (operation succeeds)

### 6.5.2 TC_dllCalHMAC_sha512_akey 
**Purpose:** To check whether the function works normally with various key values<br>
**Test setup:** digest algorithm name = "sha512”;  source text = "Hello World!"; source text length = 12; <br>
**Sub test cases 1: Calculte the HMAC value with a short key value**
* input: key = "akey"; akeyLen = 4;
* expected output: digest text = “ebd36dd33ed836f21c4725ca55dbca927bbe7887a478b1531c55455ce6379064bf437316d3b49f45111fd042643904b2da712a70c4814a85cb3ecdd65f1c3467”; digest text length = 64;
* expected return: 1 (operation succeeds)

**Sub test cases 2: Calculte the HMAC value with a long key value**
* input: key = "0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef"; akeyLen = 160;
* expected output: digest text = “bc01504b3f29c489b5838163cdc6d4da6cc9ae563c9f0b1bf5e15481e95b4c17dcfb5c4c927db7c6e1c1994d7ab2d05e11f8e90f1ee7b3258ad53cf01b7bd20e”; digest text length = 64;
* expected return: 1 (operation succeeds)

**Sub test cases 3: Calculte the HMAC value with a null key value**
* input: key = ""; akeyLen = 0;
* expected output: digest text = “4bfa8ef27b6cd15d399d7129390fcb179d24da60436001a7aa3ffa2fade1a8ef7f23d0a10616bdbcd8fa5f69c089addc953856df0ebcb1911cd4742825cb960f”; digest text length = 64;
* expected return: 1 (operation succeeds)

### 6.5.3 TC_dllCalHMAC_sha512_akeylen 
**Purpose:** To check whether the function works normally with various key length values<br>
**Test setup:** digest algorithm name = "sha512”;  source text = "Hello World!"; source text length = 12; key = "akey"; <br>
**Sub test cases 1: Calculte the HMAC value with a correct key length**
* input:  akeyLen = 4;
* expected output: digest text = “ebd36dd33ed836f21c4725ca55dbca927bbe7887a478b1531c55455ce6379064bf437316d3b49f45111fd042643904b2da712a70c4814a85cb3ecdd65f1c3467”; digest text length = 64;
* expected return: 1 (operation succeeds)

**Sub test cases 2: Calculte the HMAC value with a incorrect key length**
* input:  akeyLen = 3;
* expected output: digest text = “c47502665b32abbb7f125223f14f718c7ab4b1f65609ff15569d073bf153ab8577662fa7499793b02587ea202cb265e3f4d009c083cd6e55deee2637bf34133f”; digest text length = 64;
* expected return: 1 (operation succeeds)

**Sub test cases 3: Calculte the HMAC value with a zero key length**
* input:  akeyLen = 0;
* expected output: digest text = “4bfa8ef27b6cd15d399d7129390fcb179d24da60436001a7aa3ffa2fade1a8ef7f23d0a10616bdbcd8fa5f69c089addc953856df0ebcb1911cd4742825cb960f”; digest text length = 64;
* expected return: 1 (operation succeeds)

### 6.5.4 TC_dllCalHMAC_sha512_in_plaintext 
**Purpose:** To check whether the function works normally with various input text values<br>
**Test setup:** digest algorithm name = "sha512”;   key = "akey"; akeyLen = 4;<br>
**Sub test cases 1: Calculte the HMAC value of a short text**
* input: source text = "Hello World!"; source text length = 12;
* expected output: digest text = “ebd36dd33ed836f21c4725ca55dbca927bbe7887a478b1531c55455ce6379064bf437316d3b49f45111fd042643904b2da712a70c4814a85cb3ecdd65f1c3467”; digest text length = 64;
* expected return: 1 (operation succeeds)

**Sub test cases 2: Calculte the HMAC value of a long text**
* input: source text = "0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef"; source text length = 160;
* expected output: digest text = “7ad32e4e3c7d9d8604a7bd27898ea93b88395fb453d09e5139802bb9285b201065acbb412c36303584c22c68e0d2be0ec40d788efd724e6405f1b49d0337b193”; digest text length = 64;
* expected return: 1 (operation succeeds)

**Sub test cases 3: Calculte the HMAC value of null text**
* input: source text = ""; source text length = 0;
* expected output: digest text = “ec7e218662a8525f1d0a984dadec6b3cbc8d0f3ca779586904adbc5f7c484b6e9a74f51c8728dd9e9b55ef4798fd3c97fa054d6de2004d02ad31f723302425af”; digest text length = 64;
* expected return: 1 (operation succeeds)


### 6.5.5 TC_dllCalHMAC_sha512_in_plainlen_wrong 
**Purpose:** To check whether the function works normally with various input text length values<br>
**Test setup:** digest algorithm name = "sha512”;   key = "akey"; akeyLen = 4; source text = "Hello World!";<br>
**Sub test cases 1: Calculte the HMAC value with a correct input text length**
* input:  source text length = 12;
* expected output: digest text = “ebd36dd33ed836f21c4725ca55dbca927bbe7887a478b1531c55455ce6379064bf437316d3b49f45111fd042643904b2da712a70c4814a85cb3ecdd65f1c3467”; digest text length = 64;
* expected return: 1 (operation succeeds)

**Sub test cases 2: Calculte the HMAC value with a incorrect input text length**
* input:  source text length = 11;
* expected output: digest text = “3acd8f5681bcb5a4b7f356915490219161d87601333e803259e054c6a8141f15929da90a2b72fe8fe0b470b054fa238b7d4edd924696c6a8490fc79f956efb9c”; digest text length = 64;
* expected return: 1 (operation succeeds)

**Sub test cases 3: Calculte the HMAC value with a zero input text length**
* input:  source text length = 0;
* expected output: digest text = “ec7e218662a8525f1d0a984dadec6b3cbc8d0f3ca779586904adbc5f7c484b6e9a74f51c8728dd9e9b55ef4798fd3c97fa054d6de2004d02ad31f723302425af”; digest text length = 64;
* expected return: 1 (operation succeeds)

