cmake_minimum_required(VERSION 3.17)
project(open-craft)

set(CMAKE_CXX_STANDARD 14)

add_executable(${PROJECT_NAME}
        src/glad.c src/main.cpp src/gl/shader/ShaderProgram.cpp src/gl/shader/ShaderProgram.h src/gl/shader/Shader.cpp src/gl/shader/Shader.h src/gl/GLCpp.cpp src/gl/GLCpp.h src/gl/object/VertexArrayObject.cpp src/gl/object/VertexArrayObject.h src/gl/object/BufferObject.cpp src/gl/object/BufferObject.h src/stb-image/stb_image.cpp include/stb_image.h src/gl/texture/Texture.cpp src/gl/texture/Texture.h src/gl/TypeEnum.h src/gl/TypeEnum.cpp src/gl/shader/uniform/UniformParameters.cpp src/gl/shader/uniform/UniformParameters.h src/open-craft/MainApplication.cpp src/open-craft/MainApplication.h src/gl/extra/geometry/Geometry.cpp src/gl/extra/geometry/Geometry.h src/gl/extra/geometry/data/Vertex.cpp src/gl/extra/geometry/data/Vertex.h src/gl/extra/geometry/Triangle.cpp src/gl/extra/geometry/Triangle.h src/gl/extra/factory/VertexArrayFactory.cpp src/gl/extra/factory/VertexArrayFactory.h src/gl/extra/wrapper/GraphicsProgram.cpp src/gl/extra/wrapper/GraphicsProgram.h src/gl/extra/geometry/data/extra/CommonExtra.cpp src/gl/extra/geometry/data/extra/CommonExtra.h src/gl/extra/geometry/data/extra/TextureExtra.cpp src/gl/extra/geometry/data/extra/TextureExtra.h src/gl/extra/geometry/data/extra/VertexExtra.cpp src/gl/extra/geometry/data/extra/VertexExtra.h src/gl/extra/geometry/data/VertexDataRef.cpp src/gl/extra/geometry/data/VertexDataRef.h src/gl/extra/geometry/factory/TriangleFactory.cpp src/gl/extra/geometry/factory/TriangleFactory.h src/gl/extra/wrapper/VertexArrayWithBuffer.cpp src/gl/extra/wrapper/VertexArrayWithBuffer.h src/open-craft/world/World.cpp src/open-craft/world/World.h src/open-craft/world/Chunk.cpp src/open-craft/world/Chunk.h src/open-craft/entity/Entity.cpp src/open-craft/entity/Entity.h src/open-craft/entity/mob/player/Player.cpp src/open-craft/entity/mob/player/Player.h src/open-craft/world/blocksource/WorldBlockSource.cpp src/open-craft/world/blocksource/WorldBlockSource.h src/open-craft/world/blocksource/ChunkBlockSource.cpp src/open-craft/world/blocksource/ChunkBlockSource.h src/open-craft/world/blocksource/IBlockSource.cpp src/open-craft/world/blocksource/IBlockSource.h src/open-craft/item/Item.cpp src/open-craft/item/Item.h src/open-craft/util/ItemInstance.cpp src/open-craft/util/ItemInstance.h src/open-craft/util/Vec3.cpp src/open-craft/util/Vec3.h src/open-craft/util/Vec2.cpp src/open-craft/util/Vec2.h src/open-craft/block/Block.cpp src/open-craft/block/Block.h src/open-craft/renderer/render-layer/RenderLayer.cpp src/open-craft/renderer/render-layer/RenderLayer.h src/open-craft/renderer/tessellate/BlockTessellation.cpp src/open-craft/renderer/tessellate/BlockTessellation.h src/open-craft/world/generator/WorldGenerator.cpp src/open-craft/world/generator/WorldGenerator.h src/open-craft/database/WorldDataBase.cpp src/open-craft/database/WorldDataBase.h src/open-craft/database/ChunkDataBase.cpp src/open-craft/database/ChunkDataBase.h src/open-craft/database/io/DBManager.cpp src/open-craft/database/io/DBManager.h src/open-craft/database/io/DBReader.cpp src/open-craft/database/io/DBReader.h src/open-craft/database/io/DBWriter.cpp src/open-craft/database/io/DBWriter.h src/open-craft/database/io/DataBase.cpp src/open-craft/database/io/DataBase.h src/open-craft/renderer/tessellate/BlockTessellationCache.cpp src/open-craft/renderer/tessellate/BlockTessellationCache.h src/open-craft/entity/mob/Mob.cpp src/open-craft/entity/mob/Mob.h src/open-craft/client/OpenCraftGame.cpp src/open-craft/client/OpenCraftGame.h src/open-craft/renderer/RenderEngine.cpp src/open-craft/renderer/RenderEngine.h src/open-craft/renderer/render-layer/world/WorldRenderLayer.cpp src/open-craft/renderer/render-layer/world/WorldRenderLayer.h src/open-craft/renderer/texture/TextureManager.cpp src/open-craft/renderer/texture/TextureManager.h src/open-craft/renderer/tessellation-model/TessellationModel.cpp src/open-craft/renderer/tessellation-model/TessellationModel.h src/open-craft/renderer/tessellation-model/TessellationModelManager.cpp src/open-craft/renderer/tessellation-model/TessellationModelManager.h src/open-craft/renderer/tessellation-model/TessellationModelPart.cpp src/open-craft/renderer/tessellation-model/TessellationModelPart.h src/open-craft/block/BlockManager.cpp src/open-craft/block/BlockManager.h src/open-craft/item/ItemManager.cpp src/open-craft/item/ItemManager.h src/open-craft/block/impl/StoneBlock.cpp src/open-craft/block/impl/StoneBlock.h src/open-craft/block/impl/AirBlock.cpp src/open-craft/block/impl/AirBlock.h src/open-craft/util/AABB.cpp src/open-craft/util/AABB.h src/open-craft/app/GameThreadHandler.cpp src/open-craft/app/GameThreadHandler.h src/open-craft/app/KeyHandler.cpp src/open-craft/app/KeyHandler.h src/open-craft/app/MouseHandler.cpp src/open-craft/app/MouseHandler.h)

target_include_directories(${PROJECT_NAME}
        PRIVATE
        ${CMAKE_SYSTEM_INCLUDE_PATH}
        ${PROJECT_SOURCE_DIR}/include
        ${PROJECT_SOURCE_DIR}/src
        ${PROJECT_SOURCE_DIR}/src/open-craft)

target_link_directories(${PROJECT_NAME}
        PRIVATE
        ${CMAKE_SYSTEM_LIBRARY_PATH})

target_link_libraries(${PROJECT_NAME}
        PRIVATE
        GL
        glfw
        pthread
        dl
        jsoncpp)

target_compile_definitions(
        ${PROJECT_NAME}
        PRIVATE
)
