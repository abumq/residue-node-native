﷽

# Residue Node.js Native Binding

[![Version](https://img.shields.io/npm/v/residue-native.svg)](https://www.npmjs.com/package/residue-native)
[![GitHub license](https://img.shields.io/badge/License-Apache%202.0-blue.svg)](https://github.com/amrayn/residue-node/blob/master/LICENSE)

[![Donate](https://amrayn.github.io/donate.png?v2)](https://amrayn.com/donate)

This module goes hand-in-hand with [residue-node](https://www.npmjs.com/package/residue). You must have [C++ library](https://github.com/amrayn/residue-cpp) already installed on the system.

## Requirements

 * Node 7+

## Install
First, you need to install libresidue binary (dynamic)

```
sh -c "$(curl -fsSL https://raw.githubusercontent.com/amrayn/residue-cpp/master/install.sh)"
```

Once dynamic library is available you can install the package, that will eventually build the native module.

```
npm install --save residue-native
```

## API
Please see [Native Binding](https://github.com/amrayn/residue-node/blob/master/README.md#native-binding) section for API and usage.

## License
```
Copyright 2017-present Amrayn Web Services
Copyright 2017-present @abumusamq

https://github.com/amrayn/
https://amrayn.com/
https://muflihun.com/

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
```
