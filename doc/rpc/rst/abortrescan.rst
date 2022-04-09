.. This file is licensed under the MIT License (MIT) available on
   http://opensource.org/licenses/MIT.

abortrescan
===========

``abortrescan``

Stops current wallet rescan triggered by an RPC call, e.g. by an importprivkey call.

Examples
~~~~~~~~


.. highlight:: shell

Import a private key::

  SperoCoin-cli importprivkey "mykey"

Abort the running wallet rescan::

  SperoCoin-cli abortrescan

As a JSON-RPC call::

  curl --user myusername --data-binary '{"jsonrpc": "1.0", "id":"curltest", "method": "abortrescan", "params": [] }' -H 'content-type: text/plain;' http://127.0.0.1:55681/

