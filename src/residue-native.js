
const util = require('util');
const residue_native = require('./build/Release/residue-native-binding');

const getSourceLocation = (splitChar) => (new Error).stack.split('\n')[5].replace(' at ', '').trim().split(splitChar);

const getSourceFile = () => getSourceLocation(':')[0];

const getSourceLine = () => parseInt(getSourceLocation(':')[1]);

const getSourceFunc = () => {
    const parts = getSourceLocation(' ');
    if (parts.length <= 1) {
        return 'anonymous';
    }
    return parts[0];
}

const Residue = function() {
    this.version = () => {
        return residue_native.version();
    }

    this.configure = (json) => {
        residue_native.configure(json);
    }

    this.connect = () => {
        residue_native.connect();
    }
};

const Logger = function(id) {
    this.id = id;

    this.info = (fmt, ...args) => {
        this._send_log_msg(residue_native.info, undefined, fmt, ...args);
    }

    this.error = (fmt, ...args) => {
        this._send_log_msg(residue_native.error, undefined, fmt, ...args);
    }

    this.debug = (fmt, ...args) => {
        this._send_log_msg(residue_native.debug, undefined, fmt, ...args);
    }

    this.warning = (fmt, ...args) => {
        this._send_log_msg(residue_native.warning, undefined, fmt, ...args);
    }

    this.trace = (fmt, ...args) => {
        this._send_log_msg(residue_native.trace, undefined, fmt, ...args);
    }

    this.verbose = (vlevel, fmt, ...args) => {
        this._send_log_msg(residue_native.verbose, vlevel, fmt, ...args);
    }

    // private
    this._send_log_msg = (fn, vlevel, fmt, ...args) => {
        const cpy = args;
        for (var idx = 0; idx < cpy.length; ++idx) {
            if (typeof cpy[idx] === 'object') {
                cpy[idx] = JSON.stringify(cpy[idx]);
            }
        }

        fn(this.id, getSourceFile(), getSourceLine(), getSourceFunc(), util.format(fmt, ...cpy), vlevel);
    }
};

exports.Residue = Residue;
exports.Logger = Logger;
