.. This file is licensed under the MIT License (MIT) available on
   http://opensource.org/licenses/MIT.

getnewstealthaddress
====================

``getnewstealthaddress ( "label")``

Returns a new SperoCoin stealth address for receiving payments anonymously.

Argument #1 - label
~~~~~~~~~~~~~~~~~~~

**Type:** string, optional, default=""

An optional label

Result
~~~~~~

::

  {
    "Label": "str",          (string) Stealth address label.
    "Address": "str",        (string) New SperoCoin Stealth address.
  }

Examples
~~~~~~~~


.. highlight:: shell

::

  SperoCoin-cli getnewstealthaddress mystealthaddress

::

  curl --user myusername --data-binary '{"jsonrpc": "1.0", "id":"curltest", "method": "getnewstealthaddress", "params": [mystealthaddress] }' -H 'content-type: text/plain;' http://127.0.0.1:55681/

