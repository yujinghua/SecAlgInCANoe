# Security Algorithm Interface for Vector CANoe

This project can help you to call cryptographic functions from the OpenSSL library in the Vector CANoe environment. Please follow the guideline to build your own CAPL dll, which is used in CANoe.

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

#### S2: Config the name and path of the exported .dll file
![](https://github.com/yujinghua/SecAlgInCANoe/blob/main/image/Setup_3.png)

#### S3: Add the path of the library files and the library names to the project Property 
See Fig.1 and Fig.2

#### S4: Program in capldll.cpp file (Don't foget to include the corresponding head files)

#### S5: Build the project and get the .dll file i the target folder

### Config CANoe environment

#### Option 1: Add .dll files in .can 

```
includes{
    #pragma library("C:\Program Files (x86)\OpenSSL-Win32\libcrypto-1_1.dll")
    #pragma library("C:\Program Files (x86)\OpenSSL-Win32\libssl-1_1.dll")
    #pragma library("C:\your\dll\path\OpenSSL_CAPL.dll")
}
```
#### Option 2: Add .dll files in CANoe Configuration
![](https://github.com/yujinghua/SecAlgInCANoe/blob/main/image/Setup_4.png)

## Create the first interface



