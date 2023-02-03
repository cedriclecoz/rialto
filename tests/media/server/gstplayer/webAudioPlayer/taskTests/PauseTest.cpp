/*
 * If not stated otherwise in this file or this component's LICENSE file the
 * following copyright and licenses apply:
 *
 * Copyright 2023 Sky UK
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "tasks/webAudio/Pause.h"
#include "GstWebAudioPlayerClientMock.h"
#include "GstWebAudioPlayerPrivateMock.h"
#include <gtest/gtest.h>

using testing::Return;
using testing::StrictMock;

class WebAudioPauseTest : public testing::Test
{
protected:
    StrictMock<firebolt::rialto::server::GstWebAudioPlayerPrivateMock> m_gstPlayer;
    StrictMock<firebolt::rialto::server::GstWebAudioPlayerClientMock> m_gstPlayerClient;
};

TEST_F(WebAudioPauseTest, shouldPause)
{
    EXPECT_CALL(m_gstPlayer, changePipelineState(GST_STATE_PAUSED)).WillOnce(Return(true));
    firebolt::rialto::server::tasks::webaudio::Pause task{m_gstPlayer, &m_gstPlayerClient};
    task.execute();
}

TEST_F(WebAudioPauseTest, shouldFailToPause)
{
    EXPECT_CALL(m_gstPlayer, changePipelineState(GST_STATE_PAUSED)).WillOnce(Return(false));
    EXPECT_CALL(m_gstPlayerClient, notifyState(firebolt::rialto::WebAudioPlayerState::FAILURE));
    firebolt::rialto::server::tasks::webaudio::Pause task{m_gstPlayer, &m_gstPlayerClient};
    task.execute();
}