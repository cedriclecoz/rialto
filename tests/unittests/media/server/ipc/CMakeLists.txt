#
# If not stated otherwise in this file or this component's LICENSE file the
# following copyright and licenses apply:
#
# Copyright 2022 Sky UK
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

set( CMAKE_INCLUDE_CURRENT_DIR ON )

add_gtests (
        RialtoServerIpcUnitTests

        # AckSender unittests
        ackSender/AckSenderTestsFixture.cpp
        ackSender/AckSenderTests.cpp

        # ApplicationManagementServer unittests
        applicationManagementServer/ApplicationManagementServerTestsFixture.cpp
        applicationManagementServer/ApplicationManagementServerTests.cpp

        # ServerManagerModuleService unittests
        serverManagerModuleService/ServerManagerModuleServiceTestsFixture.cpp
        serverManagerModuleService/ServerManagerModuleServiceTests.cpp

        # SessionManagementServer unittests
        sessionManagementServer/SessionManagementServerTestsFixture.cpp
        sessionManagementServer/SessionManagementServerTests.cpp

        # MediaPipelineModuleService unittests
        mediaPipelineModuleService/MediaPipelineModuleServiceTestsFixture.cpp
        mediaPipelineModuleService/MediaPipelineModuleServiceTests.cpp

        # ControlModuleService unittests
        controlModuleService/ControlModuleServiceTestsFixture.cpp
        controlModuleService/ControlModuleServiceTests.cpp

        # ControlClient unittests
        controlClient/ControlClientTestsFixture.cpp
        controlClient/ControlClientTests.cpp

        # MediaKeysModuleService unittests
        mediaKeysModuleService/MediaKeysModuleServiceTestsFixture.cpp
        mediaKeysModuleService/MediaKeysModuleServiceTests.cpp

        # MediaKeysModuleService unittests
        mediaKeysCapabilitiesModuleService/MediaKeysCapabilitiesModuleServiceTestsFixture.cpp
        mediaKeysCapabilitiesModuleService/MediaKeysCapabilitiesModuleServiceTests.cpp

        # MediaPipelineCapabilitiesModuleService unittests
        mediaPipelineCapabilitiesModule/MediaPipelineCapabilitiesModuleServiceTestsFixture.cpp
        mediaPipelineCapabilitiesModule/MediaPipelineCapabilitiesModuleServiceTests.cpp

        # WebAudioPlayerModuleService unittests
        webAudioPlayerModuleService/WebAudioPlayerModuleServiceTestsFixture.cpp
        webAudioPlayerModuleService/WebAudioPlayerModuleServiceTests.cpp
        )

target_include_directories(
        RialtoServerIpcUnitTests

        PRIVATE
        $<TARGET_PROPERTY:RialtoServerIpc,INCLUDE_DIRECTORIES>
        $<TARGET_PROPERTY:RialtoPlayerPublic,INTERFACE_INCLUDE_DIRECTORIES>
        $<TARGET_PROPERTY:RialtoServerCommon,INTERFACE_INCLUDE_DIRECTORIES>
        $<TARGET_PROPERTY:RialtoIpcServer,INTERFACE_INCLUDE_DIRECTORIES>
        $<TARGET_PROPERTY:RialtoServerService,INTERFACE_INCLUDE_DIRECTORIES>
        $<TARGET_PROPERTY:RialtoLogging,INTERFACE_INCLUDE_DIRECTORIES>
        $<TARGET_PROPERTY:RialtoServerMocks,INTERFACE_INCLUDE_DIRECTORIES>
        $<TARGET_PROPERTY:RialtoIpcMocks,INTERFACE_INCLUDE_DIRECTORIES>
        $<TARGET_PROPERTY:RialtoWrappers,INTERFACE_INCLUDE_DIRECTORIES>
        $<TARGET_PROPERTY:RialtoWrappersMocks,INTERFACE_INCLUDE_DIRECTORIES>
        $<TARGET_PROPERTY:RialtoTestCommonProtoUtils,INTERFACE_INCLUDE_DIRECTORIES>
        $<TARGET_PROPERTY:ExternalLibraryMocks,INTERFACE_INCLUDE_DIRECTORIES>
        $<TARGET_PROPERTY:RialtoCommonMisc,INTERFACE_INCLUDE_DIRECTORIES>

        stubs
        )

target_link_libraries(
        RialtoServerIpcUnitTests

        # # Link application source
        RialtoServerIpc
        RialtoIpcClient
        RialtoIpcCommon
        RialtoCommonMisc
        RialtoProtobuf
        )

set_target_properties(
        RialtoServerIpcUnitTests
        PROPERTIES COMPILE_FLAGS "-Wno-write-strings"
        )
