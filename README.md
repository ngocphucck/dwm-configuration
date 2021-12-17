dwm - dynamic window manager
============================
DWM is a dynamic, keyboard-driven, tiling window manager developed by [*Suckless*](https://suckless.org/). It's is an extremely fast, small, and dynamic window manager for X.

This repository includes some patchings to build a beautiful wm. My source code is based on [siduck's github](https://github.com/siduck/chadwm) <3. 

Installation
------------
I assume you have been already installed *Ubuntu* and are using *Gnome*. To install this repository, firstly you need to install a few dependencies:
```shell
$ sudo apt-get install build-essential libx11-dev libxinerama-dev sharutils suckless-tools libxft-dev stterm
```
After that, you need to download the source from our repository :
```shell
$ cd /usr/local/src
$ sudo git clone https://github.com/ngocphucck/dwm-configuration.git
$ cd ..
$ chown -R `id -u`:`id -g` dwm-configuration
```
Next, you need to build the project:
```shell
$ cd dwm-configuration/
$ sudo make clean install
```
Finally, you need to excute some action to get some entries in screen login.
```shell
$ sudo apt-get install dwm
$ sudo cp /usr/share/xsessions/dwm.desktop{,.bak}
$ sudo apt-get purge dwm
$ sudo mv /usr/share/xsessions/dwm.desktop{.bak,}
```

You have to add the following code to *.xsessionrc* to have a colorful bar :smile: :
```shell
path/to/bar.sh &
```

Screenshot
-------------
![](assets/screenshot1.png)
