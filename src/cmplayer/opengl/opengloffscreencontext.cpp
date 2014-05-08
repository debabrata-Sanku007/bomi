#include "opengloffscreencontext.hpp"

OpenGLOffscreenContext::OpenGLOffscreenContext()
{
}

auto OpenGLOffscreenContext::setFormat(const QSurfaceFormat &format) -> void
{
    m_gl.setFormat(format);
    m_surface.setFormat(format);
}

auto OpenGLOffscreenContext::setShareContext(QOpenGLContext *context) -> void
{
    m_gl.setShareContext(context);
}

auto OpenGLOffscreenContext::setThread(QThread *thread) -> void
{
    Q_ASSERT(m_gl.thread() == QThread::currentThread());
    m_gl.moveToThread(thread);
}

auto OpenGLOffscreenContext::create() -> bool
{
    m_surface.create();
    return m_gl.create();
}
