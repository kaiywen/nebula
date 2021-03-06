/* Copyright (c) 2018 vesoft inc. All rights reserved.
 *
 * This source code is licensed under Apache 2.0 License,
 * attached with Common Clause Condition 1.0, found in the LICENSES directory.
 */

#include "meta/processors/MultiGetProcessor.h"

namespace nebula {
namespace meta {

void MultiGetProcessor::process(const cpp2::MultiGetReq& req) {
    CHECK_SEGMENT(req.get_segment());
    std::vector<std::string> keys;
    for (auto& key : req.get_keys()) {
        keys.emplace_back(MetaServiceUtils::assembleSegmentKey(req.get_segment(), key));
    }

    auto result = doMultiGet(std::move(keys));
    if (!result.ok()) {
        LOG(ERROR) << "MultiGet Failed " << result.status();
        resp_.set_code(cpp2::ErrorCode::E_STORE_FAILURE);
        onFinished();
        return;
    }
    resp_.set_code(cpp2::ErrorCode::SUCCEEDED);
    resp_.set_values(std::move(result.value()));
    onFinished();
}

}  // namespace meta
}  // namespace nebula
