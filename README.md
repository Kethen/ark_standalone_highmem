### ark_standalone_highmem

Selected patches from Adrenaline to enable highmem layout on ARK standalone

#### Install

Follow the normal ARK installation steps, put `ark_standalone_highmem_kern.skprx` and `ark_standalone_highmem_user.suprx` in `ur0:/tai`, then add the following to the end of `ur0:/tai/config.txt`

```
*KERNEL
ur0:/tai/ark_standalone_highmem_kern.skprx
*ALL
ur0:/tai/ark_standalone_highmem_user.suprx
```
