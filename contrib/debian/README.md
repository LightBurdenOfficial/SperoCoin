
Debian
====================
This directory contains files used to package SperoCoind/SperoCoin-qt
for Debian-based Linux systems. If you compile SperoCoind/SperoCoin-qt yourself, there are some useful files here.

## SperoCoin: URI support ##


SperoCoin-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install SperoCoin-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your SperoCoin-qt binary to `/usr/bin`
and the `../../share/pixmaps/sperocoin128.png` to `/usr/share/pixmaps`

SperoCoin-qt.protocol (KDE)

