//
//  residue-native
//  Residue Node Native Binding
//
//  Part of Residue Node.js client for Residue logging server
//
//  Copyright (C) 2017-present Muflihun Labs
//  Copyright (C) 2017-present @abumusamq
//
//  https://muflihun.com/
//  https://muflihun.github.io/residue/
//  https://github.com/muflihun/residue-node-native/
//
//  See https://github.com/muflihun/residue-node-native/blob/master/LICENSE
//  for licensing information
//

#include <nan.h>
#include <residue/residue.h>

using v8::FunctionTemplate;
using v8::Isolate;
using v8::String;
using Nan::To;
using Nan::GetFunction;
using Nan::New;
using Nan::Set;

NAN_METHOD(Version)
{
    info.GetReturnValue().Set(String::NewFromUtf8(Isolate::GetCurrent(), Residue::version().c_str()));
}

NAN_METHOD(RegisterLogger)
{
    const std::string loggerId = *Nan::Utf8String(info[0]);
    
    if (!el::Logger::isValidId(loggerId)) {
        return Nan::ThrowError(Nan::Error("Invalid logger ID. Allowed characters are alpha-numeric, hyphen, underscore or dot"));
    }
    el::Loggers::getLogger(loggerId, true);
}

NAN_METHOD(Configure)
{
    const std::string json = *Nan::Utf8String(info[0]);

    Residue::loadConfigurationFromJson(json);
}

NAN_METHOD(LoadConnection)
{
    const std::string json = *Nan::Utf8String(info[0]);

    Residue::loadConnectionFromJson(json);
}

NAN_METHOD(Connect)
{
    Residue::reconnect();
}

NAN_METHOD(Disconnect)
{
    Residue::disconnect();
}

NAN_METHOD(IsConnected)
{
    Residue::connected();
}

NAN_METHOD(WriteLog) {
    const std::string loggerId = *Nan::Utf8String(info[0]);
    const std::string file = *Nan::Utf8String(info[1]);
    const std::string func = *Nan::Utf8String(info[3]);
    const std::string msg = *Nan::Utf8String(info[4]);
    std::string level = "128";
    std::string line = "0";
    std::string vlevel = "0";
    
    if (info[5]->IsNumber()) {
        level = *Nan::Utf8String(info[5]);
    }
    if (info[2]->IsNumber()) {
        line = *Nan::Utf8String(info[2]);
    }
    if (info[6]->IsNumber()) {
        vlevel = *Nan::Utf8String(info[6]);
    }

    el::base::type::LineNumber lineNumb = stoi(line);
    el::Level lvl = static_cast<el::Level>(stoi(level));
    el::base::type::VerboseLevel vl = stoi(vlevel);
    
    el::base::Writer(lvl,
                     file.c_str(),
                     lineNumb, func.c_str(),
                     el::base::DispatchAction::NormalLog, vl)
    .construct(1, loggerId.c_str()) << msg;
}

NAN_MODULE_INIT(InitAll)
{
    #define DEFINE_FN(name, callback) Set(target, New<String>(#name).ToLocalChecked(), \
        GetFunction(New<FunctionTemplate>(callback)).ToLocalChecked())

    DEFINE_FN(version, Version);
    DEFINE_FN(configure, Configure);
    DEFINE_FN(load_connection, LoadConnection);
    DEFINE_FN(connect, Connect);
    DEFINE_FN(disconnect, Disconnect);
    DEFINE_FN(is_connected, IsConnected);
    DEFINE_FN(write_log, WriteLog);
    DEFINE_FN(register_logger, RegisterLogger);
    #undef DEFINE_FN
}


NODE_MODULE(residue_native, InitAll)
