MAKEFLAGS += --no-print-directory -lpcre
CURRENT_DIR = $(shell pwd)

THREADS = 4
CMAKE = cmake
BUILD_DIR = build
SOURCE_DIR = src
LIB_DIR = src
LIB_NAME = s21_SmartCalc
CALC_LIB = CalculationRpn
OPERATIONS_LIB = OperationsForCalculation

PUURPLE = '\033[0;35m'
YELLOW = \033[1;33m
BLUE = '\033[1;36m'
GREEN='\033[0;32m'
LIGTH_GREEN='\033[1;32m'
RED='\033[0;31m'
NC=\033[0m

CODE_STYLE = google
UNAME := $(shell uname)

ifeq (UNAME, Darwin)
	LIB = ${LIB_NAME}.a
else
	LIB = lib${LIB_NAME}.a
endif

all: ${LIB} tests


${LIB}: assemble
	@echo
	@echo ${GREEN}"Saving${NC} ${YELLOW}${LIB}"${GREEN}" ...${NC}"
	@echo "${YELLOW}${LIB}"${LIGTH_GREEN}" was saved to "${BLUE}"${CURRENT_DIR}/${LIB}"${LIGTH_GREEN}"$!${NC}"
	@echo

configure:${BUILD_DIR}
	@echo
	@echo ${GREEN}"Configuration ${YELLOW}${LIB}"${GREEN}" ...${NC}"
	@${CMAKE} -S ${SOURCE_DIR} -B ${BUILD_DIR}
	@echo ${LIGTH_GREEN}Successfully configured "${YELLOW}${LIB}"${LIGTH_GREEN}"!${NC}"
	@echo

build_lib:
	@echo
	@echo ${GREEN}"Building ${YELLOW}${LIB}"${GREEN}"...${NC}"
	@${CMAKE} --build ${BUILD_DIR}
	@echo ${LIGTH_GREEN}Successfully built "${YELLOW}${LIB}"${LIGTH_GREEN}"!${NC}"
	@echo

assemble: configure build_lib
	



${BUILD_DIR}:
	@mkdir -p ${BUILD_DIR}


CALCULATION_TESTS = ${BUILD_DIR}/${CALC_LIB}/tests/simple_test
OPERATIONS_TESTS = ${BUILD_DIR}/${OPERATIONS_LIB}/tests/OperationTests

.PHONY: tests
tests: ${assemble}
	@echo
	@echo ${GREEN}"Testing ${YELLOW}${CALC_LIB}"${GREEN}" ...${NC}"
	@./${CALCULATION_TESTS}
	@echo ${LIGTH_GREEN}End!'${NC}'
	@echo

	@echo
	@echo ${GREEN}"Testing ${YELLOW}${OPERATIONS_LIB}"${GREEN}" ...${NC}"
	@./${OPERATIONS_TESTS}
	@echo ${LIGTH_GREEN}End!'${NC}'
	@echo



clean:
	@echo
	@echo ${GREEN}"Cleaning...${NC}"
	@rm -rf *${BUILD_DIR}
	@rm -fr *.log
	@rm -fr *.a
	@rm -fr *.h
	@echo ${LIGTH_GREEN}End!'${NC}'
	@echo



SOURCES_CPP = $(shell find ${LIB_DIR} -name '.ccls-cache' -type d -prune -o -type f -name '*.cpp' -print)
SOURCES_C = $(shell find ${LIB_DIR} -name '.ccls-cache' -type d -prune -o -type f -name '*.c' -print)
HEADERS = $(shell find ${LIB_DIR} -name '.ccls-cache' -type d -prune -o -type f -name '*.h' -print)

.PHONY: prepare
prepare:clean style_correct files_and_dir_counter string_counter
	@echo ===============['${YELLOW}'STATUS'${NC}']===============
	@git status
	@echo =======================================

.PHONY:status
stat: files_and_dir_counter string_counter

.PHONY: print_files
print_files:
	@echo ============['${YELLOW}'${LIB_NAME}'${NC}']=============
	@echo ${BLUE}"${HEADERS} ${SOURCES_CPP} ${SOURCES_C}'${NC}'"
	@echo ==========================================

.PHONY: style_check
style_check:
	@echo ${GREEN}"Check style...${NC}"
	@clang-format -style=${CODE_STYLE} -n ${SOURCES_CPP} ${HEADERS} ${SOURCES_C}
	@echo ${LIGTH_GREEN}End!'${NC}'
	@echo

.PHONY: style_correct
style_correct:
	@echo ${GREEN}"Correct style...${NC}"
	@clang-format -style=${CODE_STYLE} -i ${SOURCES_CPP} ${HEADERS} ${SOURCES_C}
	@echo ${LIGTH_GREEN}End!'${NC}'
	@echo

.PHONY: files_and_dir_counter
files_and_dir_counter:
	@echo "${YELLOW}"${LIB_NAME}"${NC}":
	@echo "	"Number of ${PUURPLE}files'${NC}':
	@echo 	"		"[${BLUE}${shell find  ${LIB_DIR} -type f -print | wc -l}'${NC}']
	@echo "	"Number of ${PUURPLE}directories'${NC}':
	@echo 	"		"[${BLUE}${shell find  ${LIB_DIR} -type d -print | wc -l}'${NC}']

.PHONY: string_counter
string_counter:
	@echo "${YELLOW}${LIB_NAME}${NC}:"
	@echo "	"Number of strings in ${PUURPLE}.c'${NC}' files:
	@echo 	"		"[${BLUE}${shell find ${LIB_DIR} -name '*.c' -type f -print0 | xargs -0 cat | wc -l}'${NC}']
	@echo "	"Number of strings in ${PUURPLE}.cpp'${NC}' files:
	@echo 	"		"[${BLUE}${shell find ${LIB_DIR} -name '*.cpp' -type f -print0 | xargs -0 cat | wc -l}'${NC}']
	@echo "	"Number of strings in ${PUURPLE}.h'${NC}' files:
	@echo 	"		"[${BLUE}${shell find ${LIB_DIR} -name '*.h' -type f -print0 | xargs -0 cat | wc -l}'${NC}']
