/* Copyright (c) 2020 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "bat/ads/internal/privacy/tokens/token_generator.h"

#include "base/check.h"

namespace ads {
namespace privacy {

TokenGenerator::TokenGenerator() = default;

TokenGenerator::~TokenGenerator() = default;

std::vector<cbr::Token> TokenGenerator::Generate(const int count) const {
  std::vector<cbr::Token> tokens;

  for (int i = 0; i < count; i++) {
    cbr::Token token;
    DCHECK(token.has_value());
    tokens.push_back(token);
  }

  return tokens;
}

}  // namespace privacy
}  // namespace ads
