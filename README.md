# A simple permission validation library  

This is a library for software rights verification.  
We have categorized the overall functionality into an online version, an offline version and a front-end activated version.  

## Online version  

We build the connection between the device and the server via the Ntrip protocol, through the heartbeat function set on the server side, we can ensure that only one device is connected to the server in real time.  

## Offline version  

We obtain the MAC address of the device from the user in advance, and encrypt the MAC address and expiration time and store them in the license file. When the program is running, by judging whether the system time and expiration time as well as the MAC address are the same as the pre-set MAC address, it is guaranteed that only one device can run the encrypted software.

## Frontend version  

This version is for those who use the docker image. Since the MAC address in the image may change, we only need to activate the software the first time we use it to get permanent access thereafter.

## Notes  

The rights to this project are vested in [鸣谷导航](https://www.navmg.com/#/home)

![My Image](image/鸣谷.png)  

Due to security reasons, we have not open sourced all the features, if you are interested in this project, you can contact me by email at my email address: <zzzz_zyp@whu.edu.cn>
