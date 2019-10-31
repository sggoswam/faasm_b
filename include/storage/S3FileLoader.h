#pragma once

#include <aws/S3Wrapper.h>
#include <util/config.h>

#include "FileLoader.h"

namespace storage {
    class S3FileLoader: public FileLoader {
    public:
        S3FileLoader();

        std::vector<uint8_t> loadFunctionWasm(const message::Message &msg) override;

        std::vector<uint8_t> loadSharedObjectWasm(const std::string &path) override;

        std::vector<uint8_t> loadFunctionObjectFile(const message::Message &msg) override;

        std::vector<uint8_t> loadSharedObjectObjectFile(const std::string &path) override;

        std::vector<uint8_t> loadSharedFile(const std::string &path) override {
            throw std::runtime_error("Not implemented for S3 function loader");
        }

        void uploadFunction(message::Message &msg) override;

        void uploadPythonFunction(message::Message &msg) override;

        void uploadFunctionObjectFile(const message::Message &msg, const std::vector<uint8_t> &objBytes) override;

        void uploadSharedObjectObjectFile(const std::string &path, const std::vector<uint8_t> &objBytes) override;

        void uploadSharedFile(const std::string &path, const std::vector<uint8_t> &fileBytes) override {
            throw std::runtime_error("Not implemented for S3 function loader");
        }
    private:
        util::SystemConfig &conf;
        awswrapper::S3Wrapper &s3;

        std::vector<uint8_t> loadFileBytes(const std::string &path);
    };
};