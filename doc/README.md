SperoCoin-Qt and SperoCoind
===========================

Setup
---------------------
SperoCoin-Qt is SperoCoin client with graphic interface. SperoCoind is the daemon for SperoCoin. They download and, by default, store the entire history of SperoCoin transactions; depending on the speed of your computer and network connection, the synchronization process can take anywhere from a few hours to a day or more.

To download SperoCoin-Qt/SperoCoind, visit [sperocoin.org](https://sperocoin.org).

Running
---------------------
The following are some helpful notes on how to run SperoCoin on your native platform.

### Unix

Unpack the files into a directory and run:

- `bin/sperocoin-qt` (GUI) or
- `bin/sperocoind` (headless)

### Windows

Unpack the files into a directory, and then run SperoCoin-Qt.exe.

### OS X

Drag SperoCoin-Qt to your applications folder, and then run SperoCoin-Qt.

### Need Help?

* See the documentation at the [SperoCoin Knowledge Base](https://sperocoin.org/community/support-tickets/knowledge-base)
for help and more information.
* Ask for help on the [SperoCoin Forum](https://sperocoin.org/community/).

Building
---------------------
The following are developer notes on how to build SperoCoin on your native platform. They are not complete guides, but include notes on the necessary libraries, compile flags, etc.

- [Dependencies](dependencies.md)
- [OS X Build Notes](build-osx.md)
- [Unix Build Notes](build-unix.md)
- [Windows Build Notes](build-windows.md)
- [OpenBSD Build Notes](build-openbsd.md)
- [Gitian Building Guide](gitian-building.md)

Development
---------------------
The SperoCoin repo's [root README](/README.md) contains relevant information on the development process and automated testing.

- [Developer Notes](developer-notes.md)
- [Release Notes](release-notes.md)
- [Release Process](release-process.md)
- [Translation Process](translation_process.md)
- [Translation Strings Policy](translation_strings_policy.md)
- [Travis CI](travis-ci.md)
- [Unauthenticated REST Interface](REST-interface.md)
- [Shared Libraries](shared-libraries.md)
- [BIPS](bips.md)
- [Dnsseed Policy](dnsseed-policy.md)
- [Benchmarking](benchmarking.md)

### Resources
* Discuss on the [SperoCoin](https://sperocoin.org/community/) forums.
* Discuss on twitter https://twitter.com/GetSperoCoin
* Discuss on facebook https://www.facebook.com/sperocoinx/
* Discuss on reddit https://www.reddit.com/r/SperoCoin/
* View videos on youtube https://www.youtube.com/SperoCoinOfficial

### Miscellaneous
- [Assets Attribution](assets-attribution.md)
- [Files](files.md)
- [Fuzz-testing](fuzzing.md)
- [Reduce Traffic](reduce-traffic.md)
- [Init Scripts (systemd/upstart/openrc)](init.md)
- [ZMQ](zmq.md)

License
---------------------
Distributed under the [MIT software license](/COPYING).
This product includes software developed by the OpenSSL Project for use in the [OpenSSL Toolkit](https://www.openssl.org/). This product includes
cryptographic software written by Eric Young ([eay@cryptsoft.com](mailto:eay@cryptsoft.com)), and UPnP software written by Thomas Bernard.
