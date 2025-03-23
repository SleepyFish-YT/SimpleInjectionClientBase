# Created by SleepyFish on 19-3-2025 for the SimpleInjectionClientBase project

cmake_minimum_required(VERSION 3.28)
project(SimpleClientBase)

find_package(JNI REQUIRED)
find_package(OpenGL REQUIRED)

set(CMAKE_CXX_STANDARD 20)

add_library(SimpleClientBase SHARED

        # asset files (read /assets/README.txt)
        assets/fonts/sfuibold.h
        assets/fonts/sfuiregular.h

        # imgui classes
        libraries/imgui/imconfig.h
        libraries/imgui/imgui.cpp
        libraries/imgui/imgui.h
        libraries/imgui/imgui_draw.cpp
        libraries/imgui/imgui_impl_opengl2.cpp
        libraries/imgui/imgui_impl_opengl2.h
        libraries/imgui/imgui_impl_win32.cpp
        libraries/imgui/imgui_impl_win32.h
        libraries/imgui/imgui_internal.h
        libraries/imgui/imgui_tables.cpp
        libraries/imgui/imgui_widgets.cpp
        libraries/imgui/imstb_rectpack.h
        libraries/imgui/imstb_textedit.h
        libraries/imgui/imstb_truetype.h

        # jni classes
        libraries/jni/jawt.h
        libraries/jni/jawt_md.h
        libraries/jni/jdwpTransport.h
        libraries/jni/jni.h
        libraries/jni/jni_md.h
        libraries/jni/jvmti.h
        libraries/jni/jvmticmlr.h
        libraries/jni/classfile_constants.h

        # minhook classes
        libraries/minhook/hde/hde32.cpp
        libraries/minhook/hde/hde32.h
        libraries/minhook/hde/hde64.cpp
        libraries/minhook/hde/hde64.h
        libraries/minhook/hde/pstdint.h
        libraries/minhook/hde/table32.h
        libraries/minhook/hde/table64.h
        libraries/minhook/buffer.cpp
        libraries/minhook/buffer.h
        libraries/minhook/hook.cpp
        libraries/minhook/minhook.h
        libraries/minhook/trampoline.cpp
        libraries/minhook/trampoline.h

        # main dll classes
        dllMain.cpp
        source/me/sleepyfish/Client.h
        source/me/sleepyfish/ClientMain.h

        # module manager classes
        source/me/sleepyfish/simpleClientBase/module/Module.h
        source/me/sleepyfish/simpleClientBase/module/Manager.h
        source/me/sleepyfish/simpleClientBase/module/setting/Setting.h
        source/me/sleepyfish/simpleClientBase/module/setting/impl/BoolSetting.h
        source/me/sleepyfish/simpleClientBase/module/setting/impl/ValueSetting.h
        source/me/sleepyfish/simpleClientBase/module/setting/impl/ColorSetting.h
        source/me/sleepyfish/simpleClientBase/module/impl/Auto_Clicker.h
        source/me/sleepyfish/simpleClientBase/module/impl/Auto_Clicker.cpp
        source/me/sleepyfish/simpleClientBase/module/impl/Text_Gui.h
        source/me/sleepyfish/simpleClientBase/module/impl/Text_Gui.cpp
        source/me/sleepyfish/simpleClientBase/module/impl/Player_Esp.h
        source/me/sleepyfish/simpleClientBase/module/impl/Player_Esp.cpp
        source/me/sleepyfish/simpleClientBase/module/impl/Module_Client.h
        source/me/sleepyfish/simpleClientBase/module/impl/Module_Client.cpp

        # java classes
        source/me/sleepyfish/simpleClientBase/utils/Java.h
        source/me/sleepyfish/simpleClientBase/utils/Mapper.h
        source/me/sleepyfish/simpleClientBase/utils/unit/Vec3.h
        source/me/sleepyfish/simpleClientBase/utils/unit/Matrix.h
        source/me/sleepyfish/simpleClientBase/utils/RenderUtils.h
        source/me/sleepyfish/simpleClientBase/utils/unit/Vec4.h
        source/me/sleepyfish/simpleClientBase/utils/unit/Vec2.h

        # util classes
        source/me/sleepyfish/simpleClientBase/utils/Utils.h
        source/me/sleepyfish/simpleClientBase/utils/ClickUtils.h
        source/me/sleepyfish/simpleClientBase/utils/ClientUtils.h
        source/me/sleepyfish/simpleClientBase/utils/Console.h
        source/me/sleepyfish/simpleClientBase/utils/MinecraftUtils.h

        # sdkm classes
        source/me/sleepyfish/simpleClientBase/sdkm/SdkmClass.h
        source/me/sleepyfish/simpleClientBase/sdkm/impl/Minecraft.h
        source/me/sleepyfish/simpleClientBase/sdkm/impl/Minecraft.cpp
        source/me/sleepyfish/simpleClientBase/sdkm/impl/entity/Entity.h
        source/me/sleepyfish/simpleClientBase/sdkm/impl/entity/Entity.cpp
        source/me/sleepyfish/simpleClientBase/sdkm/impl/entity/EntityLivingBase.h
        source/me/sleepyfish/simpleClientBase/sdkm/impl/entity/EntityLivingBase.cpp
        source/me/sleepyfish/simpleClientBase/sdkm/impl/entity/EntityPlayer.h
        source/me/sleepyfish/simpleClientBase/sdkm/impl/entity/EntityPlayer.cpp
        source/me/sleepyfish/simpleClientBase/sdkm/impl/item/Item.h
        source/me/sleepyfish/simpleClientBase/sdkm/impl/item/Item.cpp
        source/me/sleepyfish/simpleClientBase/sdkm/impl/item/ItemStack.h
        source/me/sleepyfish/simpleClientBase/sdkm/impl/item/ItemStack.cpp
        source/me/sleepyfish/simpleClientBase/sdkm/impl/entity/EntityPlayerSP.cpp
        source/me/sleepyfish/simpleClientBase/sdkm/impl/entity/EntityPlayerSP.h
        source/me/sleepyfish/simpleClientBase/sdkm/impl/util/MovingObjectPosition.h
        source/me/sleepyfish/simpleClientBase/sdkm/impl/util/MovingObjectPosition.cpp
        source/me/sleepyfish/simpleClientBase/sdkm/impl/world/World.cpp
        source/me/sleepyfish/simpleClientBase/sdkm/impl/world/World.h
        source/me/sleepyfish/simpleClientBase/sdkm/impl/world/WorldClient.cpp
        source/me/sleepyfish/simpleClientBase/sdkm/impl/world/WorldClient.h
        source/me/sleepyfish/simpleClientBase/sdkm/impl/util/CTimer.h
        source/me/sleepyfish/simpleClientBase/sdkm/impl/util/CTimer.cpp
        source/me/sleepyfish/simpleClientBase/sdkm/impl/render/RenderManager.cpp
        source/me/sleepyfish/simpleClientBase/sdkm/impl/render/RenderManager.h
        source/me/sleepyfish/simpleClientBase/sdkm/impl/render/ActiveRenderInfo.cpp
        source/me/sleepyfish/simpleClientBase/sdkm/impl/render/ActiveRenderInfo.h
        source/me/sleepyfish/simpleClientBase/sdkm/java/FloatBuffer.cpp
        source/me/sleepyfish/simpleClientBase/sdkm/java/FloatBuffer.h
        source/me/sleepyfish/simpleClientBase/sdkm/java/JavaList.cpp
        source/me/sleepyfish/simpleClientBase/sdkm/java/JavaList.h

        # interface classes
        source/me/sleepyfish/simpleClientBase/interface/Interface.cpp
        source/me/sleepyfish/simpleClientBase/interface/Interface.h
        source/me/sleepyfish/simpleClientBase/interface/hook/SwapBuffers.h
        source/me/sleepyfish/simpleClientBase/interface/hook/Keypress.h

)

# leave winm in its there so you can call and use the windows api properly
# additional libraries can be added here
target_link_libraries(SimpleClientBase PRIVATE
        winmm
        ${JNI_LIBRARIES}
        opengl32
)