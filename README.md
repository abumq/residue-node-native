﷽

# Residue Node.js Native Binding

[![Version](https://img.shields.io/npm/v/residue-native.svg)](https://www.npmjs.com/package/residue-native)
[![GitHub license](https://img.shields.io/badge/License-Apache%202.0-blue.svg)](https://github.com/muflihun/residue-node/blob/master/LICENSE)
[![Donate](https://img.shields.io/badge/Donate-PayPal-green.svg)](https://www.paypal.me/MuflihunDotCom/25)

This module goes hand-in-hand with [residue-node](https://www.npmjs.com/package/residue). You must have [C++ library](https://github.com/muflihun/residue-cpp) already installed on the system.

## Install
```
npm install --save residue-native
```

## Sample
API is same as residue-node. The only difference is include `residue/lib/native` instead of `residue`

```
const residue = require('residue/lib/native');
const logger = residue.getLogger('sample-app');

console.log(`Library version: ${residue.version()}`);

const confFile = 'client.conf.json';
if (residue.loadConfiguration(confFile)) {
    residue.connect();
}

logger.info('simple log');

logger.info('array %s', [1, 2, 3]);

var person = { 'name': 'Adam', 'age': 960, }
logger.info('obj %s', person);

logger.info('null %s', null);

logger.info('undefined %s', undefined);
```

## License
```
Copyright 2017-present Muflihun Labs
Copyright 2017-present @abumusamq

https://github.com/muflihun/
https://muflihun.github.io/
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
