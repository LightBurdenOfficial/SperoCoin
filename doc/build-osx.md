Mac OS X Build Instructions and Notes
====================================
The commands in this guide should be executed in a Terminal application.
The built-in one is located in `/Applications/Utilities/Terminal.app`.

Linux cross-compile
-----------
This guide describes how to build Sperocoin Core wallet from source under Ubuntu Linux. It is intended to serve as a simple guide for general compilation of non-deterministic binary files from the stable source code. For a more detailed guide, see the macOS Build Notes. A standard installation of Ubuntu Linux 18.04 LTS will be used as an environment for the build. We assume you are running as a user with sudo permissions. First add the necessary extra repository and update all packages:
```shell
sudo add-apt-repository ppa:bitcoin/bitcoin
sudo apt update
sudo apt upgrade
```

Now install the dependencies as described in the installation documentation:
```shell
sudo apt install build-essential libtool autotools-dev automake pkg-config libssl-dev libevent-dev bsdmainutils git libdb4.8-dev libdb4.8++-dev python3 libseccomp-dev curl -y
sudo apt install libboost-system-dev libboost-filesystem-dev libboost-chrono-dev libboost-program-options-dev libboost-test-dev libboost-thread-dev libboost-iostreams-dev libzmq3-dev libminiupnpc-dev -y
sudo apt install ca-certificates g++ git-core autoconf librsvg2-bin libtiff-tools faketime cmake imagemagick libcap-dev libz-dev libbz2-dev python python-dev python-setuptools fonts-tuffy p7zip-full sleuthkit -y
```

Optionally install the Qt dependencies if you want to build the Sperocoin GUI:
```shell
sudo apt install libqt5gui5 libqt5core5a libqt5dbus5 qttools5-dev qttools5-dev-tools libprotobuf-dev protobuf-compiler libqrencode-dev -y
```

Download the stable Sperocoin repository:
```shell
git clone --recursive https://github.com/DigitalCoin1/SperoCoin
cd SperoCoin
```

A copy of the macOS SDK is required during the build process. To download this, use a Google Chrome in a desktop environment to go to https://appleid.apple.com and create or sign in to your Apple account. Then go to https://developer.apple.com and open the <b>Chrome Developer Tools from the Menu -> More tools -> Developer tools</b>. Click on the Network tab, then go back to your main browser window and copy in the following URL:
```shell
https://developer.apple.com/services-account/download?path=/Developer_Tools/Xcode_7.3.1/Xcode_7.3.1.dmg
```

Cancel the download as soon as it begins and go back to your the Network tab in the developer tools. Right click on the network request at the bottom of the list labeled Xcode_7.3.1.dmg and select <b>Copy -> Copy as cURL (bash)</b>. Paste this long string of text into your Linux terminal, append `-o Xcode_7.3.1.dmg` at the end and then press enter to begin the download. Once it is complete, extract the required files from the disc image as follows:
```shell
contrib/macdeploy/extract-osx-sdk.sh
rm -rf 5.hfs MacOSX10.11.sdk.tar.gz Xcode_7.3.1.dmg
mkdir depends/SDKs
mv MacOSX10.11.sdk/ depends/SDKs/
```

And build:
```shell
make -C depends HOST=x86_64-apple-darwin11
./autogen.sh
./configure --prefix=`pwd`/depends/x86_64-apple-darwin11
make
```


`~/SperoCoin/src` now contains the compiled Sperocoin binaries, and `~/SperoCoin/src/qt` contains the Sperocoin GUI wallet.



macOS Native - Preparation
-----------
Install the OS X command line tools:

`xcode-select --install`

When the popup appears, click `Install`.

Then install [Homebrew](https://brew.sh).

Dependencies
----------------------

    brew install automake berkeley-db4 libtool boost miniupnpc openssl pkg-config protobuf python3 qt libevent

See [dependencies.md](dependencies.md) for a complete overview.

If you want to build the disk image with `make deploy` (.dmg / optional), you need RSVG

    brew install librsvg

If you want to build with ZeroMQ support
    
    brew install zeromq

NOTE: Building with Qt4 is still supported, however, could result in a broken UI. Building with Qt5 is recommended.

Berkeley DB
-----------
It is recommended to use Berkeley DB 4.8. If you have to build it yourself,
you can use [the installation script included in contrib/](/contrib/install_db4.sh)
like so

```shell
./contrib/install_db4.sh .
```

from the root of the repository.

**Note**: You only need Berkeley DB if the wallet is enabled (see the section *Disable-Wallet mode* below).

Build SperoCoin Core
------------------------

1. Clone the SperoCoin source code and cd into `sperocoin`

        git clone --recursive https://github.com/DigitalCoin1/SperoCoin.git
        cd sperocoin

2.  Build SperoCoin-core:

    Configure and build the headless SperoCoin binaries as well as the GUI (if Qt is found).

    You can disable the GUI build by passing `--without-gui` to configure.

        ./autogen.sh
        ./configure
        make

3.  It is recommended to build and run the unit tests:

        make check

4.  You can also create a .dmg that contains the .app bundle (optional):

        make deploy

5.  Installation into user directories (optional):

        make install

    or

        cd ~/sperocoin/src
        cp SperoCoind /usr/local/bin/
        cp SperoCoin-cli /usr/local/bin/

Running
-------

SperoCoin Core is now available at `./src/SperoCoind`

Before running, it's recommended you create an RPC configuration file.

    echo -e "rpcuser=sperocoinrpc\nrpcpassword=$(xxd -l 16 -p /dev/urandom)" > "/Users/${USER}/Library/Application Support/SperoCoin/SperoCoin.conf"

    chmod 600 "/Users/${USER}/Library/Application Support/SperoCoin/SperoCoin.conf"

The first time you run SperoCoind, it will start downloading the blockchain. This process could take several hours. 
Or you can go to website our https://sperocoin.org to find the official quick sync.

You can monitor the download process by looking at the debug.log file:

    tail -f $HOME/Library/Application\ Support/SperoCoin/debug.log

Other commands:
-------

    ./src/SperoCoind -daemon # Starts the SperoCoin daemon.
    ./src/SperoCoin-cli --help # Outputs a list of command-line options.
    ./src/SperoCoin-cli help # Outputs a list of RPC commands when the daemon is running.

Using Qt Creator as IDE
------------------------
You can use Qt Creator as an IDE, for SperoCoin development.
Download and install the community edition of [Qt Creator](https://www.qt.io/download/).
Uncheck everything except Qt Creator during the installation process.

1. Make sure you installed everything through Homebrew mentioned above
2. Do a proper ./configure --enable-debug
3. In Qt Creator do "New Project" -> Import Project -> Import Existing Project
4. Enter "SperoCoin-qt" as project name, enter src/qt as location
5. Leave the file selection as it is
6. Confirm the "summary page"
7. In the "Projects" tab select "Manage Kits..."
8. Select the default "Desktop" kit and select "Clang (x86 64bit in /usr/bin)" as compiler
9. Select LLDB as debugger (you might need to set the path to your installation)
10. Start debugging with Qt Creator

Notes
-----

* Tested on OS X 10.8 through 10.13 on 64-bit Intel processors only.

* Building with downloaded Qt binaries is not officially supported. See the notes in [#7714](https://github.com/bitcoin/bitcoin/issues/7714)
