const residue = require('residue-native');

const instance = new residue.Residue();

console.log(`Library version: ${instance.version()}`);

instance.configure('{"url":"residue-server:8777","application_id":"com.muflihun.residue.sampleapp","rsa_key_size":2048,"utc_time":false,"time_offset":0,"dispatch_delay":1,"main_thread_id":"MainThread","client_id":"muflihun00102030","client_private_key":"keys/muflihun00102030.pem"}');
instance.connect();

const logger = new residue.Logger("sample-app");

logger.info("blah");

function a_fn()
{
    logger.debug('a debug log in func %s', 'with string fmt');
    logger.verbose(5, 'a verbose log in func, verbose level: %d', 5);
}

logger.debug('a debug log %s', 'with string fmt');

a_fn();
