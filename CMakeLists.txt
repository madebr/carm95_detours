
cmake_minimum_required(VERSION 3.15)
project(carm95hooks C CXX)

include(TestBigEndian)

test_big_endian(IS_BIG_ENDIAN)

include(FetchContent)
FetchContent_Declare(
  Detours
  GIT_REPOSITORY https://github.com/microsoft/detours.git
  GIT_TAG        734ac64899c44933151c1335f6ef54a590219221
)
FetchContent_Populate(Detours)
file(GLOB DETOURS_SOURCES "${detours_SOURCE_DIR}/src/*.cpp")
list(REMOVE_ITEM DETOURS_SOURCES
    "${detours_SOURCE_DIR}/src/uimports.cpp"
)
file(GLOB DETOURS_HEADERS "${detours_SOURCE_DIR}/src/*.h")
add_library(detours STATIC ${DETOURS_SOURCES} ${DETOURS_HEADERS})
target_include_directories(detours INTERFACE "$<BUILD_INTERFACE:${detours_SOURCE_DIR}/src>")
set_target_properties(detours
    PROPERTIES
        MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>"
)
if(MINGW)
    target_compile_options(detours PRIVATE -w)
endif()
add_library(Detours::Detours ALIAS detours)

add_library(carm95hooks SHARED
    hookmain.cpp
    include/carm95_hooks.h
    carm95_hooks.cpp
    dummy.c
    harness_trace.c
    DETHRACE/source/common/brucetrk.c
    DETHRACE/source/common/brucetrk.h
    DETHRACE/source/common/car.c
    DETHRACE/source/common/car.h
    DETHRACE/source/common/controls.c
    DETHRACE/source/common/controls.h
    DETHRACE/source/common/crush.c
    DETHRACE/source/common/crush.h
    DETHRACE/source/common/cutscene.c
    DETHRACE/source/common/cutscene.h
    DETHRACE/source/common/demo.c
    DETHRACE/source/common/demo.h
    DETHRACE/source/common/depth.c
    DETHRACE/source/common/depth.h
    DETHRACE/source/common/displays.c
    DETHRACE/source/common/displays.h
    DETHRACE/source/common/drfile.c
    DETHRACE/source/common/drfile.h
    DETHRACE/source/common/drmem.c
    DETHRACE/source/common/drmem.h
    DETHRACE/source/common/errors.c
    DETHRACE/source/common/errors.h
    DETHRACE/source/common/finteray.c
    DETHRACE/source/common/finteray.h
    DETHRACE/source/common/flicplay.c
    DETHRACE/source/common/flicplay.h
    DETHRACE/source/common/globvars.c
    DETHRACE/source/common/globvars.h
    DETHRACE/source/common/globvrbm.c
    DETHRACE/source/common/globvrbm.h
    DETHRACE/source/common/globvrkm.c
    DETHRACE/source/common/globvrkm.h
    DETHRACE/source/common/globvrme.c
    DETHRACE/source/common/globvrme.h
    DETHRACE/source/common/globvrpb.c
    DETHRACE/source/common/globvrpb.h
    DETHRACE/source/common/grafdata.c
    DETHRACE/source/common/grafdata.h
    DETHRACE/source/common/graphics.c
    DETHRACE/source/common/graphics.h
    DETHRACE/source/common/init.c
    DETHRACE/source/common/init.h
    DETHRACE/source/common/input.c
    DETHRACE/source/common/input.h
    DETHRACE/source/common/intrface.c
    DETHRACE/source/common/intrface.h
    DETHRACE/source/common/loading.c
    DETHRACE/source/common/loading.h
    DETHRACE/source/common/loadsave.c
    DETHRACE/source/common/loadsave.h
    DETHRACE/source/common/main.c
    DETHRACE/source/common/main.h
    DETHRACE/source/common/mainloop.c
    DETHRACE/source/common/mainloop.h
    DETHRACE/source/common/mainmenu.c
    DETHRACE/source/common/mainmenu.h
    DETHRACE/source/common/netgame.c
    DETHRACE/source/common/netgame.h
    DETHRACE/source/common/network.c
    DETHRACE/source/common/network.h
    DETHRACE/source/common/newgame.c
    DETHRACE/source/common/newgame.h
    DETHRACE/source/common/oil.c
    DETHRACE/source/common/oil.h
    DETHRACE/source/common/oppocar.c
    DETHRACE/source/common/oppocar.h
    DETHRACE/source/common/opponent.c
    DETHRACE/source/common/opponent.h
    DETHRACE/source/common/oppoproc.c
    DETHRACE/source/common/oppoproc.h
    DETHRACE/source/common/options.c
    DETHRACE/source/common/options.h
    DETHRACE/source/common/pedestrn.c
    DETHRACE/source/common/pedestrn.h
    DETHRACE/source/common/piping.c
    DETHRACE/source/common/piping.h
    DETHRACE/source/common/powerup.c
    DETHRACE/source/common/powerup.h
    DETHRACE/source/common/pratcam.c
    DETHRACE/source/common/pratcam.h
    DETHRACE/source/common/racestrt.c
    DETHRACE/source/common/racestrt.h
    DETHRACE/source/common/racesumm.c
    DETHRACE/source/common/racesumm.h
    DETHRACE/source/common/raycast.c
    DETHRACE/source/common/raycast.h
    DETHRACE/source/common/replay.c
    DETHRACE/source/common/replay.h
    DETHRACE/source/common/skidmark.c
    DETHRACE/source/common/skidmark.h
    DETHRACE/source/common/sound.c
    DETHRACE/source/common/sound.h
    DETHRACE/source/common/spark.c
    DETHRACE/source/common/spark.h
    DETHRACE/source/common/structur.c
    DETHRACE/source/common/structur.h
    DETHRACE/source/common/trig.c
    DETHRACE/source/common/trig.h
    DETHRACE/source/common/utility.c
    DETHRACE/source/common/utility.h
    DETHRACE/source/common/world.c
    DETHRACE/source/common/world.h
    DETHRACE/source/pc-dos/dosnet.c
    DETHRACE/source/pc-dos/dosnet.h
    DETHRACE/source/pc-dos/dossys.c
    DETHRACE/source/pc-dos/dossys.h
    BRSRC13/CORE/FW/mem.c
    BRSRC13/CORE/FW/mem.h
    BRSRC13/CORE/V1DB/regsupt.c
    BRSRC13/CORE/V1DB/regsupt.h
    BRSRC13/CORE/V1DB/modsupt.c
    BRSRC13/CORE/V1DB/modsupt.h
    BRSRC13/CORE/V1DB/actsupt.c
    BRSRC13/CORE/V1DB/actsupt.h
    BRSRC13/CORE/V1DB/prepmatl.c
    BRSRC13/CORE/V1DB/prepmatl.h
    BRSRC13/CORE/V1DB/prepmesh.c
    BRSRC13/CORE/V1DB/prepmesh.h
    BRSRC13/CORE/FW/diag.c
    BRSRC13/CORE/FW/diag.h
    BRSRC13/CORE/V1DB/render.c
    BRSRC13/CORE/V1DB/render.h
    BRSRC13/CORE/MATH/matrix34.c
    BRSRC13/CORE/MATH/matrix34.h
    BRSRC13/CORE/MATH/transfrm.c
    BRSRC13/CORE/MATH/transfrm.h
    BRSRC13/CORE/MATH/vector.c
    BRSRC13/CORE/MATH/vector.h
    BRSRC13/CORE/MATH/angles.c
    BRSRC13/CORE/MATH/angles.h
    BRSRC13/CORE/MATH/matrix4.c
    BRSRC13/CORE/MATH/matrix4.h
    BRSRC13/CORE/V1DB/v1dbfile.c
    BRSRC13/CORE/V1DB/v1dbfile.h
    BRSRC13/CORE/PIXELMAP/pixelmap.c
    BRSRC13/CORE/PIXELMAP/pixelmap.h
    BRSRC13/CORE/PIXELMAP/fontptrs.c
    BRSRC13/CORE/PIXELMAP/fontptrs.h
    BRSRC13/CORE/PIXELMAP/pmdsptch.c
    BRSRC13/CORE/PIXELMAP/pmdsptch.h
    BRSRC13/CORE/FW/fwsetup.c
    BRSRC13/CORE/FW/fwsetup.h
    BRSRC13/CORE/FW/resreg.c
    BRSRC13/CORE/FW/resreg.h
    BRSRC13/CORE/V1DB/matsupt.c
    BRSRC13/CORE/V1DB/matsupt.h
    BRSRC13/CORE/V1DB/dbsetup.c
    BRSRC13/CORE/V1DB/dbsetup.h
    BRSRC13/CORE/V1DB/enables.c
    BRSRC13/CORE/V1DB/enables.h
    BRSRC13/CORE/V1DB/preptab.c
    BRSRC13/CORE/V1DB/preptab.h
    BRSRC13/CORE/FW/resource.c
    BRSRC13/CORE/FW/resource.h
    BRSRC13/CORE/PIXELMAP/pmfile.c
    BRSRC13/CORE/PIXELMAP/pmfile.h
    BRSRC13/CORE/FW/bswap.c
    BRSRC13/CORE/FW/bswap.h
    BRSRC13/CORE/MATH/matrix23.c
    BRSRC13/CORE/MATH/matrix23.h
    BRSRC13/CORE/FW/brqsort.c
    BRSRC13/CORE/FW/brqsort.h
    BRSRC13/CORE/V1DB/prepmap.c
    BRSRC13/CORE/V1DB/prepmap.h
    BRSRC13/CORE/FW/devsetup.c
    BRSRC13/CORE/FW/devsetup.h
    BRSRC13/CORE/DOSIO/readmse.c
    BRSRC13/CORE/DOSIO/readmse.h
    BRSRC13/CORE/STD/stdlib.c
    BRSRC13/CORE/STD/stdlib.h
    BRSRC13/CORE/FW/register.c
    BRSRC13/CORE/FW/register.h
    BRSRC13/CORE/FW/pattern.c
    BRSRC13/CORE/FW/pattern.h
    BRSRC13/CORE/FW/brlists.c
    BRSRC13/CORE/FW/brlists.h
    BRSRC13/CORE/FW/scratch.c
    BRSRC13/CORE/FW/scratch.h
    BRSRC13/CORE/MATH/plane.c
    BRSRC13/CORE/MATH/plane.h
    BRSRC13/CORE/STD/math.c
    BRSRC13/CORE/STD/math.h
    BRSRC13/CORE/FW/printf.c
    BRSRC13/CORE/FW/printf.h
    BRSRC13/CORE/V1DB/otable.c
    BRSRC13/CORE/V1DB/otable.h
    BRSRC13/CORE/V1DB/modrend.c
    BRSRC13/CORE/V1DB/modrend.h
    BRSRC13/CORE/MATH/quat.c
    BRSRC13/CORE/MATH/quat.h
    BRSRC13/CORE/FW/genfile.c
    BRSRC13/CORE/FW/genfile.h
    BRSRC13/CORE/FW/datafile.c
    BRSRC13/CORE/FW/datafile.h
    BRSRC13/CORE/FW/file.c
    BRSRC13/CORE/FW/file.h
    BRSRC13/CORE/PIXELMAP/pmmem.c
    BRSRC13/CORE/PIXELMAP/pmmem.h
    BRSRC13/CORE/PIXELMAP/gencopy.c
    BRSRC13/CORE/PIXELMAP/gencopy.h
    BRSRC13/CORE/FW/image.c
    BRSRC13/CORE/FW/image.h
    BRSRC13/CORE/FW/object.c
    BRSRC13/CORE/FW/object.h
    BRSRC13/CORE/FW/devlist.c
    BRSRC13/CORE/FW/devlist.h
    BRSRC13/CORE/FW/error.c
    BRSRC13/CORE/FW/error.h
    BRSRC13/CORE/FW/lexer.c
    BRSRC13/CORE/FW/lexer.h
    BRSRC13/CORE/FW/objectc.c
    BRSRC13/CORE/FW/objectc.h
    BRSRC13/CORE/FW/tokenval.c
    BRSRC13/CORE/FW/tokenval.h
    BRSRC13/CORE/FW/token.c
    BRSRC13/CORE/FW/token.h
    BRSRC13/CORE/STD/brexcept.c
    BRSRC13/CORE/STD/brexcept.h
    BRSRC13/CORE/STD/stddiag.c
    BRSRC13/CORE/STD/stddiag.h
    BRSRC13/CORE/STD/stdfile.c
    BRSRC13/CORE/STD/stdfile.h
    BRSRC13/CORE/STD/stdmem.c
    BRSRC13/CORE/STD/stdmem.h
    BRSRC13/CORE/FW/sys_conf.c
    BRSRC13/CORE/FW/sys_conf.h
    BRSRC13/CORE/V1DB/def_mdl.c
    BRSRC13/CORE/V1DB/def_mdl.h
    BRSRC13/CORE/V1DB/def_mat.c
    BRSRC13/CORE/V1DB/def_mat.h
    BRSRC13/CORE/V1DB/def_otab.c
    BRSRC13/CORE/V1DB/def_otab.h
    BRSRC13/CORE/FW/brbegin.c
    BRSRC13/CORE/FW/brbegin.h
    BRSRC13/CORE/HOST/hstsetup.c
    BRSRC13/CORE/HOST/hstsetup.h
    BRSRC13/CORE/DOSIO/eventq.c
    BRSRC13/CORE/DOSIO/eventq.h
    BRSRC13/CORE/STD/logwrite.c
    BRSRC13/CORE/STD/logwrite.h
    BRSRC13/CORE/V1DB/custsupt.c
    BRSRC13/CORE/V1DB/custsupt.h
    BRSRC13/CORE/PIXELMAP/pmgen.c
    BRSRC13/CORE/PIXELMAP/pmgen.h
    BRSRC13/CORE/PIXELMAP/pmsetup.c
    BRSRC13/CORE/PIXELMAP/pmsetup.h
    BRSRC13/CORE/PIXELMAP/genclip.c
    BRSRC13/CORE/PIXELMAP/genclip.h
    BRSRC13/CORE/HOST/himage.c
    BRSRC13/CORE/HOST/himage.h
    BRSRC13/CORE/FW/loader.c
    BRSRC13/CORE/FW/loader.h
    BRSRC13/CORE/HOST/hostcfg.c
    BRSRC13/CORE/HOST/hostcfg.h
    BRSRC13/CORE/FW/assocarr.c
    BRSRC13/CORE/FW/assocarr.h
    BRSRC13/CORE/FW/brbhook.c
    BRSRC13/CORE/FW/brbhook.h
    BRSRC13/CORE/HOST/hook.c
    BRSRC13/CORE/HOST/hook.h
    BRSRC13/CORE/HOST/memmgmt.c
    BRSRC13/CORE/HOST/memmgmt.h
    BRSRC13/CORE/PIXELMAP/pmnull.c
    BRSRC13/CORE/PIXELMAP/pmnull.h

    S3/s3sound.c
)
target_compile_definitions(carm95hooks PRIVATE
    PLUGIN_NAME="carm95hooks"
    BR_ENDIAN_BIG=$<BOOL:${IS_BIG_ENDIAN}>
)
target_compile_options(carm95hooks
    PRIVATE
        -Wall
)
if(CMAKE_C_COMPILER_ID MATCHES "MSVC")
    target_compile_definitions(carm95hooks
        PRIVATE
            WIN32_LEAN_AND_MEAN
            _CRT_SECURE_NO_WARNINGS
    )
    target_compile_options(carm95hooks
        PRIVATE
            -wd4820  # x' bytes padded
            -wd4255  # no function prototype given: converting '()' to '(void)'
            -wd4101  # unreferenced local variable
            -wd4774  # 'printf' : format string expected in argument 1 is not a string literal
            -wd5247  # section '.CRT$XCZ' is reserved for C++ dynamic initialization
            -wd5045  # Compiler will insert Spectre mitigation for memory load if /Qspectre switch specified
            -wd4242  # function': conversion from 'xxx' to 'yyy', possible loss of data
            -wd4244  # function': conversion from 'xxx' to 'yyy', possible loss of data
    )
endif()
target_include_directories(carm95hooks PRIVATE
   ${CMAKE_CURRENT_SOURCE_DIR}/BRSRC13
   ${CMAKE_CURRENT_SOURCE_DIR}/DETHRACE/source
   ${CMAKE_CURRENT_SOURCE_DIR}/include
   ${CMAKE_CURRENT_SOURCE_DIR}/include/harness
   ${CMAKE_CURRENT_SOURCE_DIR}/include/brender
)
target_link_libraries(carm95hooks PRIVATE
    Detours::Detours
)
set_target_properties(carm95hooks
    PROPERTIES
        PREFIX ""
        OUTPUT_NAME carm95hooks
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/plugins"
        MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>"
)
if(MSVC)
    target_sources(carm95hooks PRIVATE hook_msvc.def)
elseif(MINGW)
    target_sources(carm95hooks PRIVATE hook_mingw.def)
endif()

add_executable(carm95_injector injector.cpp)
target_compile_definitions(carm95_injector PRIVATE
    TARGET="carm95_injector"
    VICTIM="CARM95.EXE"

)
target_link_libraries(carm95_injector PRIVATE
    Detours::Detours
)
set_target_properties(carm95_injector
    PROPERTIES
        CXX_STANDARD 17
        MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>"
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}"
)

set(CARM95_LOCATION "" CACHE FILEPATH "Path of CARM95.EXE (+game data)")
if(CARM95_LOCATION)
    add_custom_target(copy_hooks
        COMMENT "Copying carm95 hooks to \"${CARM95_LOCATION}\""
        COMMAND "${CMAKE_COMMAND}" -E make_directory "${CARM95_LOCATION}/plugins"
        COMMAND "${CMAKE_COMMAND}" -E copy "$<TARGET_FILE:carm95hooks>" "${CARM95_LOCATION}/plugins/$<TARGET_FILE_NAME:carm95hooks>"
        COMMAND "${CMAKE_COMMAND}" -E copy "$<TARGET_FILE:carm95_injector>" "${CARM95_LOCATION}/$<TARGET_FILE_NAME:carm95_injector>"
    )
endif()
