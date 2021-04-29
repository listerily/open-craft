#ifndef GL_TYPE_ENUM_H
#define GL_TYPE_ENUM_H

namespace gl
{
    enum class TypeEnum : int
    {
        FLOAT, DOUBLE, INT, UNSIGNED_INT, UNSIGNED_BYTE, BYTE
    };

    int typeEnumToGLEnum(TypeEnum);
}

#endif //GL_TYPE_ENUM_H
