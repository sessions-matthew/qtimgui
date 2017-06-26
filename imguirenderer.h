#pragma once

#include <QOpenGLExtraFunctions>
#include <imgui.h>
#include "imguiwidget.h"

namespace QtImGui {

class ImGuiRenderer : QOpenGLExtraFunctions {
public:
    ImGuiRenderer(ImGuiWidget *w) : widget(w) {}

    void initialize();

    void renderDrawList(ImDrawData *draw_data);
    void newFrame();

    void onMousePressedChange(QMouseEvent *event);
    void onWheel(QWheelEvent *event);
    void onKeyPressRelease(QKeyEvent *event);

private:
    bool createFontsTexture();
    bool createDeviceObjects();

    ImGuiWidget *widget;
    double       g_Time = 0.0f;
    bool         g_MousePressed[3] = { false, false, false };
    float        g_MouseWheel = 0.0f;
    GLuint       g_FontTexture = 0;
    int          g_ShaderHandle = 0, g_VertHandle = 0, g_FragHandle = 0;
    int          g_AttribLocationTex = 0, g_AttribLocationProjMtx = 0;
    int          g_AttribLocationPosition = 0, g_AttribLocationUV = 0, g_AttribLocationColor = 0;
    unsigned int g_VboHandle = 0, g_VaoHandle = 0, g_ElementsHandle = 0;
};

}
