# Security Algorithm Interface for Vector CANoe

This project can help you to call cryptographic functions from the OpenSSL library in the Vector CANoe environment. Please follow the [guideline](#Setup-development-environment) below to build your own CAPL dll, which is used in CANoe. 

Setup guideline in Chinese: [CANoe中调用OpenSSL库函数(CAPL DLL开发)](https://yujinghua.github.io/blog/openssl-capl-setup.html)

Codes of various interfaces are in the folder [InterfaceCode](https://github.com/yujinghua/SecAlgInCANoe/tree/main/InterfaceCode), including function definitaion and configiration for the CAPL export table. You can use them directly or take them as examples for further development.

## Setup development environment

### Use OpenSSL functions in a Visual Studio (VS) consloe app project

Create an individual VS consloe app can help you to debug the new algorithms without using CANoe.

#### S1: Install OpenSSL library
Option 1: Use the [Installation Package](http://slproweb.com/products/Win32OpenSSL.html)
Option 2: Follow the guideline from the [OpenSSL website](https://www.openssl.org/source/)

#### S2: Add the path of the library files to the project Property
![](https://github.com/yujinghua/SecAlgInCANoe/blob/main/image/Setup_1.png) <br>
Fig.1

#### S3: Add library names to the project Property
![](https://github.com/yujinghua/SecAlgInCANoe/blob/main/image/Setup_2.png) <br>
Fig. 2

#### S4: Include corresponding .h files in your .cpp

### Create a CAPL DLL

#### S1: Use the CAPL DLL project templates provided by CANoe to start
The template path could be C:\Users\Public\Documents\Vector\CANoe\Sample Configurations 13.0.118\Programming\CAPLdll\，which can be checked in CANoe -> File -> Sample Configuration -> programming -> CAPL DLL.

#### S2: Configure the name and path of the exported .dll file
![](https://github.com/yujinghua/SecAlgInCANoe/blob/main/image/Setup_3.png) <br>
Fig.3

#### S3: Add the path of the library files and the library names to the project Property 
See Fig.1 and Fig.2

#### S4: Program in capldll.cpp file (Don't foget to include the corresponding head files)

#### S5: Build the project and get the .dll file i the target folder

### Configure CANoe environment

#### Option 1: Add .dll files in .can 

```
includes{
    #pragma library("C:\Program Files (x86)\OpenSSL-Win32\libcrypto-1_1.dll")
    #pragma library("C:\Program Files (x86)\OpenSSL-Win32\libssl-1_1.dll")
    #pragma library("C:\your\dll\path\OpenSSL_CAPL.dll")
}
```
#### Option 2: Add .dll files in CANoe Configuration
![](https://github.com/yujinghua/SecAlgInCANoe/blob/main/image/Setup_4.png) <br>
Fig.4

### Create the first interface
An interface for "Add" function is presented as example to show how to create a new interface

#### S1: Define and realize the "Add" function
```
int32_t CAPLEXPORT CAPLPASCAL appAdd(int32_t x, int32_t y)
{
  int32_t z = x + y;
  return z;
}
```
#### S2: Configure the CAPL export table "CAPL_DLL_INFO4_table[]" in capldll.cpp
```
{"dllAdd", (CAPL_FARCALL)appAdd, "CAPL_DLL", "This function will add two values. The return value is the result",'L', 2, "LL", "", {"x","y"}},
```
Rules for configuring th CAPL export table are defined in CANoe help file called "Description of the CAPL Export Table". (Path: CAPL » CAPL DLL » Export Table)

