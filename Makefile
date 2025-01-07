# Variables système
ifeq ($(OS),Windows_NT)
    # Windows (MinGW)
    OS_NAME = Windows
    CC = g++
    LD = g++
    RM = rd /s /q
    DEL = del /f /q
    MKDIR = mkdir
    EXT = .exe
else
    # Linux
    OS_NAME = Linux
    CC = g++
    LD = g++
    RM = rm -rf
    MKDIR = mkdir -p
    EXT =
endif

# Répertoires communs
BIN_DIR = bin
OBJ_DIR = obj
BASE_DIR = extern
INCLUDE_BASE = -I$(BASE_DIR)
LIB_BASE = -L$(BASE_DIR)

# Inclusions SDL et SFML
INCLUDE_DIR_SDL = $(INCLUDE_BASE)/SDL2/include $(INCLUDE_BASE)/SDL2/include/SDL2 $(INCLUDE_BASE)/SDL_image/include $(INCLUDE_BASE)/SDL_ttf/include
INCLUDE_DIR_SFML = $(INCLUDE_BASE)/SFML/include

# Bibliothèques SDL et SFML
LIBS_SDL = $(LIB_BASE)/SDL2/lib $(LIB_BASE)/SDL_image/lib $(LIB_BASE)/SDL_ttf/lib -lSDL2 -lSDL2_image -lSDL2_ttf
LIBS_SFML = $(LIB_BASE)/SFML/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-network -lsfml-audio

# Fichiers source
CORE = core/Object.cpp core/Ennemi.cpp core/Equipage.cpp core/Terrain.cpp core/Jeu.cpp core/Navigateur.cpp core/Shoot.cpp core/Menu.cpp

SRCS_TXT = $(CORE) txt/txtJeu.cpp txt/winTxt.cpp txt/main_txt.cpp
FINAL_TARGET_TXT = Revenges_Island_txt

SRCS_SDL = $(CORE) sdl2/sdlJeu.cpp sdl2/main_sdl.cpp
FINAL_TARGET_SDL = Revenges_Island_sdl

SRCS_SFML = $(CORE) sfml/jeuSfml.cpp sfml/mainSfml.cpp sfml/MenuSFML.cpp sfml/Animation.cpp sfml/Nav.cpp
FINAL_TARGET_SFML = Revenges_Island_sfml

# Compilation des fichiers
CPPFLAGS = -Wall -std=c++11 -DSFML_STATIC -ggdb
SRC_DIR = src
INCLUDE_DIR = -Isrc -Isrc/core -Isrc/sdl2 -Itxt -Isrc/sfml $(INCLUDE_DIR_SDL) $(INCLUDE_DIR_SFML)

# Cible par défaut
default: make_dir $(BIN_DIR)/$(FINAL_TARGET_TXT) $(BIN_DIR)/$(FINAL_TARGET_SDL) $(BIN_DIR)/$(FINAL_TARGET_SFML) copy_SDL_DLL

# Créer les répertoires si ils n'existent pas
make_dir:
ifeq ($(OS_NAME),Windows)
	@mkdir $(OBJ_DIR)\core $(OBJ_DIR)\txt $(OBJ_DIR)\sdl2 $(OBJ_DIR)\sfml
	@mkdir $(BIN_DIR)
else
	@mkdir -p $(OBJ_DIR)/core $(OBJ_DIR)/txt $(OBJ_DIR)/sdl2 $(OBJ_DIR)/sfml
	@mkdir -p $(BIN_DIR)
endif

# Lier les fichiers objets pour produire les exécutables
$(BIN_DIR)/$(FINAL_TARGET_TXT): $(SRCS_TXT:%.cpp=$(OBJ_DIR)/%.o)
	$(LD) $+ -o $@ $(LDFLAGS)

$(BIN_DIR)/$(FINAL_TARGET_SDL): $(SRCS_SDL:%.cpp=$(OBJ_DIR)/%.o)
	$(LD) $+ $(LDFLAGS) -o $@ $(LIBS_SDL)

$(BIN_DIR)/$(FINAL_TARGET_SFML): $(SRCS_SFML:%.cpp=$(OBJ_DIR)/%.o)
	$(LD) $+ -o $@ $(LDFLAGS) $(LIBS_SFML)

# Compilation des fichiers source en objets
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) -c $(CPPFLAGS) $(INCLUDE_DIR) $< -o $@

# Copier les DLL pour SDL sur Windows
copy_SDL_DLL:
ifeq ($(OS_NAME),Windows)
	@copy $(BASE_DIR)\SDL2\bin\*.dll $(BIN_DIR)
	@copy $(BASE_DIR)\SDL_image\bin\*.dll $(BIN_DIR)
	@copy $(BASE_DIR)\SDL_ttf\bin\*.dll $(BIN_DIR)
	@copy $(BASE_DIR)\SFML\bin\*.dll $(BIN_DIR)
endif

# Nettoyage des fichiers générés
clean:
ifeq ($(OS_NAME),Windows)
	@if exist $(BIN_DIR) $(DEL) $(BIN_DIR)\$(FINAL_TARGET_TXT)$(EXT)
	@if exist $(BIN_DIR) $(DEL) $(BIN_DIR)\$(FINAL_TARGET_SDL)$(EXT)
	@if exist $(BIN_DIR) $(DEL) $(BIN_DIR)\$(FINAL_TARGET_SFML)$(EXT)
	@if exist $(OBJ_DIR) $(RM) $(OBJ_DIR)
	@if exist $(BIN_DIR) $(RM) $(BIN_DIR)
else
	$(RM) $(BIN_DIR)/$(FINAL_TARGET_TXT) $(BIN_DIR)/$(FINAL_TARGET_SDL) $(BIN_DIR)/$(FINAL_TARGET_SFML)
	$(RM) $(OBJ_DIR) $(BIN_DIR)
endif
