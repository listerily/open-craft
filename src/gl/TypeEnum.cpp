#include "TypeEnum.h"

#include <glad/glad.h>

namespace gl
{
    int typeEnumToGLEnum(TypeEnum type)
    {
        switch (type)
        {
            case TypeEnum::FLOAT:
                return GL_FLOAT;
            case TypeEnum::DOUBLE:
                return GL_DOUBLE;
            case TypeEnum::INT:
                return GL_INT;
            case TypeEnum::UNSIGNED_INT:
                return GL_UNSIGNED_INT;
            case TypeEnum::UNSIGNED_BYTE:
                return GL_UNSIGNED_BYTE;
            case TypeEnum::BYTE:
                return GL_BYTE;
        }
        return -1;
    }
}