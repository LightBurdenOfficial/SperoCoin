.. This file is licensed under the MIT License (MIT) available on
   http://opensource.org/licenses/MIT.

getsperosendinfo
===============

``getsperosendinfo``

Returns an object containing sperosend-related information.

Result
~~~~~~

::

  {
    "enabled": true,             (boolean) If sperosend is enabled
    "servicenodes": 2,           (int) Currently connected service nodes
    "anontxinprogress": true,    (boolean) If sperosend tx is in progress
  }

Examples
~~~~~~~~


.. highlight:: shell

::

  SperoCoin-cli getsperosendinfo

::

  curl --user myusername --data-binary '{"jsonrpc": "1.0", "id":"curltest", "method": "getsperosendinfo", "params": [] }' -H 'content-type: text/plain;' http://127.0.0.1:55681/

