.. This file is licensed under the MIT License (MIT) available on
   http://opensource.org/licenses/MIT.

listaddressgroupings
====================

``listaddressgroupings``

Lists groups of addresses which have had their common ownership
made public by common use as inputs or as the resulting change
in past transactions

Result
~~~~~~

::

  [
    [
      [
        "address",            (string) The SperoCoin address
        amount,                 (numeric) The amount in SPERO
        "account"             (string, optional) DEPRECATED. The account
      ]
      ,...
    ]
    ,...
  ]

Examples
~~~~~~~~


.. highlight:: shell

::

  SperoCoin-cli listaddressgroupings

::

  curl --user myusername --data-binary '{"jsonrpc": "1.0", "id":"curltest", "method": "listaddressgroupings", "params": [] }' -H 'content-type: text/plain;' http://127.0.0.1:55681/

