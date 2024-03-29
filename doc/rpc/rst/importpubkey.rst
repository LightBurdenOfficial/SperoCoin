.. This file is licensed under the MIT License (MIT) available on
   http://opensource.org/licenses/MIT.

importpubkey
============

``importpubkey "pubkey" ( "label" rescan )``

Adds a public key (in hex) that can be watched as if it were in your wallet but cannot be used to spend. Requires a new wallet backup.

Argument #1 - pubkey
~~~~~~~~~~~~~~~~~~~~

**Type:** string, required

The hex-encoded public key

Argument #2 - label
~~~~~~~~~~~~~~~~~~~

**Type:** string, optional, default=""

An optional label

Argument #3 - rescan
~~~~~~~~~~~~~~~~~~~~

**Type:** boolean, optional, default=true

Rescan the wallet for transactions

Examples
~~~~~~~~


.. highlight:: shell

Import a public key with rescan::

  SperoCoin-cli importpubkey "mypubkey"

Import using a label without rescan::

  SperoCoin-cli importpubkey "mypubkey" "testing" false

As a JSON-RPC call::

  curl --user myusername --data-binary '{"jsonrpc": "1.0", "id":"curltest", "method": "importpubkey", "params": ["mypubkey", "testing", false] }' -H 'content-type: text/plain;' http://127.0.0.1:55681/

