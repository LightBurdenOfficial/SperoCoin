.. This file is licensed under the MIT License (MIT) available on
   http://opensource.org/licenses/MIT.

addmultisigaddress
==================

``addmultisigaddress nrequired ["key",...] ( "account" "address_type" )``

Add a nrequired-to-sign multisignature address to the wallet. Requires a new wallet backup.

Each key is a SperoCoin address or hex-encoded public key.

This functionality is only intended for use with non-watchonly addresses.

See `importaddress` for watchonly p2sh address support.

If 'account' is specified (DEPRECATED), assign address to that account.

Argument #1 - nrequired
~~~~~~~~~~~~~~~~~~~~~~~

**Type:** numeric, required

The number of required signatures out of the n keys or addresses.

Argument #2 - keys
~~~~~~~~~~~~~~~~~~

**Type:** string, required

A json array of SperoCoin addresses or hex-encoded public keys

::

     [
       "address"                  (string) SperoCoin address or hex-encoded public key
       ...,
     ]

Argument #3 - account
~~~~~~~~~~~~~~~~~~~~~

**Type:** string, optional

DEPRECATED. An account to assign the addresses to.

Argument #4 - address_type
~~~~~~~~~~~~~~~~~~~~~~~~~~

**Type:** string, optional

The address type to use. Options are "legacy", "p2sh-segwit", and "bech32". Default is set by -addresstype.

Result
~~~~~~

::

  {
    "address":"multisigaddress",    (string) The value of the new multisig address.
    "redeemScript":"script"         (string) The string value of the hex-encoded redemption script.
  }

Result (DEPRECATED. To see this result in v0.16 instead, please start SperoCoind with -deprecatedrpc=addmultisigaddress).
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. list-table::
   :header-rows: 1

   * - Name
     - Type
     - Description
   * - address
     - string
     - A SperoCoin address associated with the keys.

Examples
~~~~~~~~


.. highlight:: shell

Add a multisig address from 2 addresses::

  SperoCoin-cli addmultisigaddress 2 "[\"LEr4hnAefwYhBmGxcFP2Po1NPrUEIk8KM2\",\"Dc7BLTLqSyWSp6uEpQPbbcb7figA7xHjKQ\"]"

As json rpc call::

  curl --user myusername --data-binary '{"jsonrpc": "1.0", "id":"curltest", "method": "addmultisigaddress", "params": [2, "[\"LEr4hnAefwYhBmGxcFP2Po1NPrUEIk8KM2\",\"Dc7BLTLqSyWSp6uEpQPbbcb7figA7xHjKQ\"]"] }' -H 'content-type: text/plain;' http://127.0.0.1:9332/

