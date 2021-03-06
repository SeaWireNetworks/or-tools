// Copyright 2010-2014 Google
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "util/time_limit.h"

#include "base/join.h"

DEFINE_bool(time_limit_use_usertime, false,
            "If true, rely on the user time in the TimeLimit class. This is "
            "only recommended for benchmarking on a non-isolated environment.");

namespace operations_research {
// static constants.
const double TimeLimit::kSafetyBufferSeconds = 1e-4;
const int TimeLimit::kHistorySize = 100;

std::string TimeLimit::DebugString() const {
  std::string buffer =
      StrCat("Time left: ", GetTimeLeft(), "\nDeterministic time left: ",
             GetDeterministicTimeLeft(), "\nElapsed time: ", GetElapsedTime(),
             "\nElapsed deterministic time: ", GetElapsedDeterministicTime());
#ifndef NDEBUG
  for (const auto& counter : deterministic_counters_) {
    const std::string& counter_name = counter.first;
    const double counter_value = counter.second;
    StrAppend(&buffer, "\n", counter_name, ": ", counter_value);
  }
#endif
  return buffer;
}
}  // namespace operations_research
