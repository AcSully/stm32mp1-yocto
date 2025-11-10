# 正点原子STM32MP157 Yocto一键编译

## Key Features



- Touch panel Support
- ATK-7 RGB 7 inches
- uboot YT8511 support
- kernel Ethernet motorcomm phy support
- ALIENTEK OV5640 support
- GPU support
- st-image-core/st-image-weston support
- ST demo support
  - netdata
  - camera
  - video
  - GPU
  - Image Classification
  - Object Detection
- Splash uboot
- Distro features
  - alsa
  - argp
  - ext2
  - ext4
  - largefile
  - ipv4
  - ipv6
  - ...

## Build

```
git clone --recurse-submodules http://192.168.156.155:3000/niuke/stm32mp1-yocto.git
cd stm32mp1-yocto

DISTRO=openstlinux-weston MACHINE=stm32mp1-develop source layers/meta-st-develop/scripts/envsetup.sh build-stm32mp1-custom
bitbake st-image-weston
```



## 异常处理

```
ERROR: User namespaces are not usable by BitBake, possibly due to AppArmor.
See https://discourse.ubuntu.com/t/ubuntu-24-04-lts-noble-numbat-release-notes/39890#unprivileged-user-namespace-restrictions for more information.

解决方案
echo 0 | sudo tee /proc/sys/kernel/apparmor_restrict_unprivileged_userns
```

```
NOTE: Executing Tasks ERROR: PermissionError: [Errno 1] Operation not permitted
 
During handling of the above exception, another exception occurred:
 
Traceback (most recent call last):  File "..../layers/openembedded-core/bitbake/bin/bitbake-worker", line 278, in child    bb.utils.disable_network(uid, gid)  File "..../layers/openembedded-core/bitbake/lib/bb/utils.py", line 1696, in disable_network    with open("/proc/self/uid_map", "w") as f: PermissionError: [Errno 1] Operation not permitted

On Ubuntu 24.04, in combination with the apparmor package, the Ubuntu kernel now restricts the use of unprivileged user namespaces. This affects all programs on the system that are unprivileged and unconfined. You can disable this restriction by running
sudo apparmor_parser -R /etc/apparmor.d/unprivileged_userns
```
![f7887f741c213517a6f642a3d4a264c2](https://github.com/user-attachments/assets/623de8eb-21a4-49f0-a29a-490c2a44616b)


