// Copyright (c) 2020 by Robert Bosch GmbH. All rights reserved.
//
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
#ifndef IOX_POSH_POPO_WAITSET_CONDITION_VARIABLE_DATA_HPP
#define IOX_POSH_POPO_WAITSET_CONDITION_VARIABLE_DATA_HPP

#include "iceoryx_posh/iceoryx_posh_types.hpp"
#include "iceoryx_posh/mepoo/memory_info.hpp"
#include "iceoryx_utils/posix_wrapper/semaphore.hpp"

#include <atomic>

namespace iox
{
namespace popo
{
struct ConditionVariableData
{
    ConditionVariableData(const mepoo::MemoryInfo& memoryInfo = mepoo::MemoryInfo()) noexcept
        : m_memoryInfo(memoryInfo)
    {
    }

    mepoo::MemoryInfo m_memoryInfo;
    posix::Semaphore m_semaphore = std::move(posix::Semaphore::create(0u)
                                                 .on_error([] {
                                                     /// @todo add errorhandler call here
                                                 })
                                                 .get_value());
};

} // namespace popo
} // namespace iox

#endif // IOX_POSH_POPO_WAITSET_CONDITION_VARIABLE_DATA_HPP
