CXX ?= g++
CC ?= gcc
CXX_FLAGS ?= -std=c++20 -fdiagnostics-color=always -fno-omit-frame-pointer -fvar-tracking -fvar-tracking-assignments -g
QT_VER ?= 6.4.2
QT_PATH ?= C:/Qt/$(QT_VER)/mingw_64
QT_INC ?= $(QT_PATH)/include
INCLUDES ?= -isystem $(QT_INC) -isystem $(QT_INC)/QtGui -isystem $(QT_INC)/QtCore -isystem $(QT_INC)/QtWidgets -Iinclude
GUI_SRC_DIR ?= src\ppp3\graphics
GUI_BUILD_DIR = build\graphics
GUI_HDR_DIR ?= include\ppp3\graphics
LIBRARY_PATH ?= -L$(QT_PATH)\lib
QT_FLAGS ?= -DQT_CORE_LIB -DQT_GUI_LIB -DQT_WIDGETS_LIB
QT_LIBS ?= -lQt6Core -lQt6Widgets -lQt6Gui
TARGET_SRC ?= src\ppp3\examples\screenshot.cpp
TARGET_FILE = $(notdir $(TARGET_SRC))
TARGET_EXE ?= $(subst .cpp,.exe,$(TARGET_FILE))
TARGET_DIR ?= $(dir $(TARGET_SRC))
EXE_PATH ?= $(GUI_BUILD_DIR)\$(TARGET_EXE)

HEADERS = $(subst /,\,$(wildcard $(GUI_HDR_DIR)/*.h))
CXX_CMD = $(CXX) $(CXX_FLAGS) $(INCLUDES) -L$(QT_PATH)\lib
SRC_FILES = $(subst /,\,$(wildcard $(GUI_SRC_DIR)/*.cpp))
OBJS = $(patsubst $(GUI_SRC_DIR)\\%.cpp,$(GUI_BUILD_DIR)\\%.o,$(SRC_FILES))
MOCS = $(patsubst $(GUI_HDR_DIR)\\%.h,$(GUI_BUILD_DIR)\\%_moc.cpp,$(HEADERS))
TARGET_MOC = $(GUI_BUILD_DIR)\$(subst .cpp,_moc.cpp,$(TARGET_FILE))
MOC_OBJS = $(subst moc.cpp,moc.o,$(MOCS))
TARGET_DIR_CLEAN = $(patsubst "%",%,$(abspath $(TARGET_DIR)))
TARGET_SRC_CLEAN = $(patsubst "%",%,$(abspath $(TARGET_SRC)))
MAKEFLAGS = -j$(NUMBER_OF_PROCESSORS)

deploy: build
	@echo ============================
	@echo Deploying QT dependencies to $(GUI_BUILD_DIR)
	$(QT_PATH)\bin\windeployqt.exe $(EXE_PATH)

build: objs $(TARGET_MOC) clean_exe
	@echo ============================
	@echo Building target $(EXE_PATH) from src $(TARGET_SRC)
	@echo
	$(CXX_CMD) $(TARGET_MOC) -I$(abspath $(TARGET_DIR)) -o $(EXE_PATH) -static $(OBJS) $(MOC_OBJS) $(QT_LIBS) $(QT_FLAGS)

objs: $(MOC_OBJS) $(OBJS)
mocs: $(MOCS) $(TARGET_MOC)
moc_objs: $(MOC_OBJS)

$(MOC_OBJS): $(MOCS)
	@echo ============================
	@echo Building $@
	$(CXX_CMD) -c $(subst .o,.cpp,$@) -o $@ $(QT_FLAGS)

$(OBJS):
	@echo ============================
	@echo Building $@
	$(CXX_CMD) -c $(patsubst $(GUI_BUILD_DIR)\\%.o,$(GUI_SRC_DIR)\\%.cpp,$@) -o $@ $(QT_FLAGS)

$(TARGET_MOC): FORCE
	@echo ============================
	@echo Generating moc file $@
	@if exist $(TARGET_MOC) del /F /Q $(TARGET_MOC)
	$(QT_PATH)\bin\moc.exe -i "$(TARGET_SRC)" -o "$(TARGET_MOC)"
	@echo.>> "$(TARGET_MOC)"
	@sed -i "1i #include \"$(notdir $(TARGET_SRC))\"" $(TARGET_MOC)
	@del sed*

$(MOCS):
	@echo ============================
	@echo Generating moc file $@
	$(QT_PATH)\bin\moc.exe $(patsubst $(GUI_BUILD_DIR)\\%_moc.cpp,$(GUI_HDR_DIR)\\%.h,$@) -o $@

FORCE:

build_path:
	if not exist "$(GUI_BUILD_DIR)" mkdir "$(GUI_BUILD_DIR)"

clean_exe:
	@if exist $(GUI_BUILD_DIR)\*.exe del /F /Q /S $(GUI_BUILD_DIR)\*.exe

clean: clean_exe
	@if exist $(GUI_BUILD_DIR)\*_moc.cpp del /F /Q /S $(GUI_BUILD_DIR)\*_moc.cpp
	@if exist $(GUI_BUILD_DIR)\*.dll del /F /Q /S $(GUI_BUILD_DIR)\*.dll
	@if exist $(GUI_BUILD_DIR)\*.o del /F /Q /S $(GUI_BUILD_DIR)\*.o
	@if exist $(GUI_BUILD_DIR)\*.qm del /F /Q /S $(GUI_BUILD_DIR)\*.qm
