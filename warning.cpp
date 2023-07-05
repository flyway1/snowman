#include "warning.h"
#include "picture.h"

warning::warning()
{
    m_warn.load(W_PATH);
    m_warn = m_warn.scaled(100, 100, Qt::KeepAspectRatio, Qt::SmoothTransformation);
}
