#
# If not stated otherwise in this file or this component's LICENSE file the
# following copyright and licenses apply:
#
# Copyright 2023 Sky UK
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

add_gtests (
        RialtoServerComponentTests

        # gtest code
        sessionServerStateChange/SessionServerStateChangeTest.cpp
        mediaPipeline/MediaPipelineTestFixture.cpp
        mediaPipeline/MediaPipelineTest.cpp
        mediaKeys/MediaKeysTest.cpp
        )

target_include_directories(
        RialtoServerComponentTests

        PRIVATE
        $<TARGET_PROPERTY:RialtoCommon,INTERFACE_INCLUDE_DIRECTORIES>
        $<TARGET_PROPERTY:RialtoServerComponentTestsFixtures,INTERFACE_INCLUDE_DIRECTORIES>
)

target_link_libraries(
        RialtoServerComponentTests
        RialtoCommon
        RialtoServerComponentTestsFixtures
)

if ( COVERAGE_ENABLED )
    target_link_libraries(
        RialtoServerComponentTests

        gcov
        )
endif()