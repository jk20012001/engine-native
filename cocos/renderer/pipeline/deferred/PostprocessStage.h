/****************************************************************************
 Copyright (c) 2020-2021 Huawei Technologies Co., Ltd.

 http://www.cocos.com

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated engine source code (the "Software"), a limited,
 worldwide, royalty-free, non-assignable, revocable and non-exclusive license
 to use Cocos Creator solely to develop games on your target platforms. You shall
 not use Cocos Creator software for developing other software or tools that's
 used for developing games. You are not granted to publish, distribute,
 sublicense, and/or sell copies of Cocos Creator.

 The software or tools in this License Agreement are licensed, not sold.
 Xiamen Yaji Software Co., Ltd. reserves all rights not expressly granted to you.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
****************************************************************************/

#pragma once

#include "../RenderStage.h"
#include "frame-graph/Handle.h"

namespace cc {
namespace pipeline {

class UIPhase;

class CC_DLL PostprocessStage : public RenderStage {
public:
    PostprocessStage();
    ~PostprocessStage() override = default;

    static const RenderStageInfo &getInitializeInfo();
    bool initialize(const RenderStageInfo &info) override;
    void activate(RenderPipeline *pipeline, RenderFlow *flow) override;
    void destroy() override;
    void render(scene::Camera *camera) override;

    gfx::DescriptorSet *getGlobalSet() { return _globalSet; }
    UIPhase *getUIPhase() { return _uiPhase; }

private:
    gfx::Rect _renderArea;
    UIPhase * _uiPhase = nullptr;
    uint      _phaseID = 0;

    static RenderStageInfo initInfo;

    gfx::DescriptorSetLayout *_globalSetlayout = nullptr;
    gfx::DescriptorSet       *_globalSet = nullptr;

    framegraph::StringHandle _fgStrHandlePostOut;
};
} // namespace pipeline
} // namespace cc
