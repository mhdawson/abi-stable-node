# Node.js API (NAPI)
This repository is the home for ABI Stable Node API project (NAPI). The goal of this
project is to provide a stable Node API for native module developers. NAPI aims
to provide ABI compatibility guarantees across different Node versions and also
across different Node VMs – allowing NAPI enabled native modules to just work
across different versions and flavors of Node.js without recompilations.

It is introduced by this Node enhancemnet proposal:
[005-ABI-Stable-Module-API.md](https://github.com/nodejs/node-eps/blob/master/005-ABI-Stable-Module-API.md).

This project is in an early proof of concept stage. Check out our [roadmap](https://github.com/nodejs/abi-stable-node/issues/18)
for details on the remaining work.

Copies of the Node.js source with the changes for the ABI Stable Node API are
in branches in this repo.  Currently we have the following versions:

* api-prototype-0.10.40
* api-prototype-0.12.7
* api-prototype-6.2.0
* api-prototype-chakracore-7.x
* api-prototype-8.x
* api-prototype-chakracore-8.x

**API Design & Shape**

The current shape of the API can be found in header file 
[node_jsvmapi.h](https://github.com/nodejs/abi-stable-node/blob/api-prototype-6.2.0/src/node_jsvmapi.h)

**Branches**

This repository contains node sources from Node versions 0.10, 0.12, 6.2 and
Node-ChakraCore version 7.0, with addition of ABI stable Node APIs. The branches
are named according to the node versions that have been enabled with NAPI support. 

**NAPI enabled modules**

|Module|Converted By|Location|Performance Assesment|
|------|------------|--------|-----------|
|leveldown|[boingoing](https://github.com/boingoing) / [ianwjhalliday](https://github.com/ianwjhalliday)|  https://github.com/boingoing/leveldown/| [#55](https://github.com/nodejs/abi-stable-node/issues/55)|
|nanomsg|[sampsongao](https://github.com/sampsongao) | https://github.com/sampsongao/node-nanomsg | [#57](https://github.com/nodejs/abi-stable-node/issues/57)|
|canvas|[jasongin](https://github.com/jasongin) | https://github.com/jasongin/node-canvas | [#77](https://github.com/nodejs/abi-stable-node/issues/77)|
|node-sass|[boingoing](https://github.com/boingoing) | https://github.com/boingoing/node-sass | In progress|
|sqllite3|[sampsongao](https://github.com/sampsongao) / [mhdawson](https://github.com/mhdawson) | https://github.com/mhdawson/node-sqlite3 | In progress|
|iotivity|[gabrielschulhof](https://github.com/gabrielschulhof) | https://github.com/gabrielschulhof/iotivity-node/tree/abi-stable| In progress|


**Testing**

In addition to running the tests in the converted modules.  We have also 

* Converted version of the NAN examples that we always keep working
  [abi-stable-node-addon-examples](https://github.com/nodejs/abi-stable-node-addon-examples)

* Converted version of the [core addons tests](https://github.com/nodejs/abi-stable-node/tree/api-prototype-6.2.0/test/addons-abi) which can be run with ```make test addons-abi```

**How to get involved**
* Convert a native module to use [NAPI](https://github.com/nodejs/abi-stable-node/blob/api-prototype-6.2.0/src/node_jsvmapi.h) and report issues on conversion and performance;
* Port ABI stable APIs to your fork of Node and let us know if there are gaps;
* Review the [roadmap](https://github.com/nodejs/abi-stable-node/issues/18) and see how can you
can help accelerate this project.

Hangout link for weekly standup
https://plus.google.com/u/0/events/c0eevtrlajniu7h8cjrdk0f56c8?authkey=COH04YCalJS8Ug

# Project Participants
* [aruneshchandra](https://github.com/aruneshchandra) - Arunesh Chandra
* [boingoing](https://github.com/boingoing) - Taylor Woll
* [digitalinfinity](https://github.com/digitalinfinity) - Hitesh Kanwathirtha
* [gabrielschulhof](https://github.com/gabrielschulhof) - Gabriel Schulhof
* [ianwjhalliday](https://github.com/ianwjhalliday) - Ian Halliday
* [jasongin](https://github.com/jasongin) - Jason Ginchereau 
* [mhdawson](https://github.com/mhdawson) - Michael Dawson 
* [mykmelez](https://github.com/mykmelez) - Myk Melez
* [sampsongao](https://github.com/sampsongao) - Sampson Gao
