#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(){

        map<string, string> mp;

        mp.insert(make_pair("abc", "ABC"));

        if (mp["123"] == "123") {
                mp["123"] = "123";
        }

        cout << mp["123"] << endl; // 返回的是一个默认的值 ""

        return 0;
}

// see also : http://blog.csdn.net/starlee/article/details/2256054

/*
<1003 linux16 [enip] :/home/enip/fangxing/t>g++ -g cpp_map_array_assign.cpp
<1004 linux16 [enip] :/home/enip/fangxing/t>gdb a.out
GNU gdb (GDB) SUSE (7.0-0.4.16)
Copyright (C) 2009 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.  Type "show copying"
and "show warranty" for details.
This GDB was configured as "x86_64-suse-linux".
For bug reporting instructions, please see:
<http://www.gnu.org/software/gdb/bugs/>...
Reading symbols from /home/enip/fangxing/t/a.out...done.
(gdb) l
1       #include <iostream>
2       #include <map>
3       #include <string>
4
5       using namespace std;
6
7       int main(){
8
9               map<string, string> mp;
10
(gdb) b main
Breakpoint 1 at 0x4010ac: file cpp_map_array_assign.cpp, line 9.
(gdb) r
Starting program: /home/enip/fangxing/t/a.out
Missing separate debuginfo for /lib64/ld-linux-x86-64.so.2
Try: zypper install -C "debuginfo(build-id)=17c088070352d83e7afc43d83756b00899fd37f0"
Missing separate debuginfo for /usr/lib64/libstdc++.so.6
Try: zypper install -C "debuginfo(build-id)=e907b88d15f5e1312d1ae0c7c61f8da92745738b"
Missing separate debuginfo for /lib64/libm.so.6
Try: zypper install -C "debuginfo(build-id)=365e4d2c812908177265c8223f222a1665fe1035"
Missing separate debuginfo for /lib64/libgcc_s.so.1
Try: zypper install -C "debuginfo(build-id)=3f06bcfc74f9b01780d68e89b8dce403bef9b2e3"
Missing separate debuginfo for /lib64/libc.so.6
Try: zypper install -C "debuginfo(build-id)=a41ac0b0b7cd60bd57473303c2c3de08856d2e06"

Breakpoint 1, main () at cpp_map_array_assign.cpp:9
9               map<string, string> mp;
(gdb) n
11              mp.insert(make_pair("abc", "ABC"));
(gdb) n
13              if (mp["123"] == "123") {
(gdb) p mp
$1 = std::map with 2 elements = {
  ["123"] = "",
  ["abc"] = "ABC"
}
(gdb)
*/
