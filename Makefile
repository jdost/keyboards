.PHONY: image kc60 flash-kc60 minivan flash-minivan hhkb flash-hhkb infinity flash-infinity
DOCKER_IMAGE_TAG=qmk_builder
KEYMAP_NAME=local
PAUSE=5
# ANSI color codes
HLT="\\e[32m"
RST="\\e[39m"
# ANSI control codes
CPL="\\033[1F"

.docker_image_id: Dockerfile docker-entrypoint.sh
	@echo -e "${HLT} >>${RST} Building container image"
	@docker build -t "${DOCKER_IMAGE_TAG}" .
	@docker images --quiet "${DOCKER_IMAGE_TAG}" > .docker_image_id
image: .docker_image_id

# KC60 keyboard rules...
kc60/firmware.hex: kc60/keymap.c kc60/config.h
	@echo -e "${HLT} >>${RST} Creating and populating building image for kc60"
	@docker rm "${DOCKER_IMAGE_TAG}__kc60" &> /dev/null || true
	@docker create -it --name "${DOCKER_IMAGE_TAG}__kc60" "${DOCKER_IMAGE_TAG}" make kc60:${KEYMAP_NAME} > /dev/null
	@docker cp kc60 "${DOCKER_IMAGE_TAG}__kc60":/src/qmk_firmware/keyboards/kc60/keymaps/${KEYMAP_NAME}/ &> /dev/null
	@pushd kc60 &> /dev/null \
		&& find . -type f -not -name "*.hex" \
		-exec docker cp {} "${DOCKER_IMAGE_TAG}__kc60":/src/qmk_firmware/keyboards/kc60/keymaps/${KEYMAP_NAME}/{} \; \
		&& popd &> /dev/null
	@echo -e "${HLT} >>${RST} Building the firmware image for kc60"
	@docker start -ia "${DOCKER_IMAGE_TAG}__kc60"
	@echo -e "${HLT} >>${RST} Retrieving the built image"
	@docker cp "${DOCKER_IMAGE_TAG}__kc60":/build/firmware.hex kc60/firmware.hex > /dev/null
	@docker rm "${DOCKER_IMAGE_TAG}__kc60" > /dev/null

kc60: image kc60/firmware.hex
flash-kc60: kc60
	@sudo echo -e "${HLT} >>${RST} Flashing firmware in ${PAUSE} seconds..."
	@for count in {${PAUSE}..1}; do \
		echo -e "${CPL}${HLT} >>${RST} Flashing firmware in $$count seconds..." ; \
		sleep 1 ; \
	done
	@echo -e "${CPL}${HLT} >>${RST} Flashing firmware..."
	@sudo dfu-programmer atmega32u4 erase --force
	@sudo dfu-programmer atmega32u4 flash kc60/firmware.hex
	@sudo dfu-programmer atmega32u4 reset
	@echo -e "${HLT} >>${RST} Finished"
# TheVan minivan44 rules...
minivan/firmware.hex: minivan/keymap.c minivan/config.h
	@echo -e "${HLT} >>${RST} Creating and populating building image for minivan"
	@docker rm "${DOCKER_IMAGE_TAG}__minivan" &> /dev/null || true
	@docker create -it --name "${DOCKER_IMAGE_TAG}__minivan" "${DOCKER_IMAGE_TAG}" make thevankeyboards/minivan:${KEYMAP_NAME} > /dev/null
	@docker cp minivan "${DOCKER_IMAGE_TAG}__minivan":/src/qmk_firmware/keyboards/thevankeyboards/minivan/keymaps/${KEYMAP_NAME}/ > /dev/null
	@pushd minivan &> /dev/null \
		&& find . -type f -not -name "*.hex" \
			-exec docker cp {} "${DOCKER_IMAGE_TAG}__minivan":/src/qmk_firmware/keyboards/thevankeyboards/minivan/keymaps/${KEYMAP_NAME}/{} \; \
		&& popd &> /dev/null
	@echo -e "${HLT} >>${RST} Building the firmware image for minivan"
	@docker start -ia "${DOCKER_IMAGE_TAG}__minivan"
	@echo -e "${HLT} >>${RST} Retrieving the built image"
	@docker cp "${DOCKER_IMAGE_TAG}__minivan":/build/firmware.hex minivan/firmware.hex > /dev/null
	@docker rm "${DOCKER_IMAGE_TAG}__minivan" > /dev/null

minivan: image minivan/firmware.hex
flash-minivan: minivan
	@sudo echo -e "${HLT} >>${RST} Flashing firmware in ${PAUSE} seconds..."
	@for count in {${PAUSE}..1}; do \
		echo -e "${CPL}${HLT} >>${RST} Flashing firmware in $$count seconds..." ; \
		sleep 1 ; \
	done
	@echo -e "${CPL}${HLT} >>${RST} Flashing firmware..."
	@# HHKB doesn't auto detect in flashing, so this looks up the device address after pause
	@#   We run these commands together to propagate the looked up address in a single
	@#   subshell
	@export ADDR=$$(lsusb | grep "atmega32u4" | awk '{ printf "%d,%d",$$2,$$4 }' | sed 's/[: ]//g'); \
		sudo dfu-programmer atmega32u4:$$ADDR erase --force; \
		sudo dfu-programmer atmega32u4:$$ADDR flash minivan/firmware.hex; \
		sudo dfu-programmer atmega32u4:$$ADDR reset
	@echo -e "${HLT} >>${RST} Finished"
# HHKB rules...
hhkb/firmware.hex: hhkb/keymap.c hhkb/config.h
	@echo -e "${HLT} >>${RST} Creating and populating building image for hhkb"
	@docker rm "${DOCKER_IMAGE_TAG}__hhkb" &> /dev/null || true
	@docker create -it --name "${DOCKER_IMAGE_TAG}__hhkb" "${DOCKER_IMAGE_TAG}" make hhkb:${KEYMAP_NAME} > /dev/null
	@docker cp hhkb "${DOCKER_IMAGE_TAG}__hhkb":/src/qmk_firmware/keyboards/hhkb/keymaps/${KEYMAP_NAME}/ > /dev/null
	@pushd hhkb &> /dev/null \
		&& find . -type f -not -name "*.hex" \
			-exec docker cp {} "${DOCKER_IMAGE_TAG}__hhkb":/src/qmk_firmware/keyboards/hhkb/keymaps/${KEYMAP_NAME}/{} \; \
		&& popd &> /dev/null
	@echo -e "${HLT} >>${RST} Building the firmware image for hhkb"
	@docker start -ia "${DOCKER_IMAGE_TAG}__hhkb"
	@echo -e "${HLT} >>${RST} Retrieving the built image"
	@docker cp "${DOCKER_IMAGE_TAG}__hhkb":/build/firmware.hex hhkb/firmware.hex > /dev/null
	@docker rm "${DOCKER_IMAGE_TAG}__hhkb" > /dev/null

hhkb: image hhkb/firmware.hex
flash-hhkb: hhkb
	@sudo echo -e "${HLT} >>${RST} Flashing firmware in ${PAUSE} seconds..."
	@for count in {${PAUSE}..1}; do \
		echo -e "${CPL}${HLT} >>${RST} Flashing firmware in $$count seconds..." ; \
		sleep 1 ; \
	done
	@echo -e "${CPL}${HLT} >>${RST} Flashing firmware..."
	@# HHKB doesn't auto detect in flashing, so this looks up the device address after pause
	@#   We run these commands together to propagate the looked up address in a single
	@#   subshell
	@export ADDR=$$(lsusb | grep "atmega32u4" | awk '{ printf "%d,%d",$$2,$$4 }' | sed 's/[: ]//g'); \
		sudo dfu-programmer atmega32u4:$$ADDR erase --force; \
		sudo dfu-programmer atmega32u4:$$ADDR flash hhkb/firmware.hex; \
		sudo dfu-programmer atmega32u4:$$ADDR reset
	@echo -e "${HLT} >>${RST} Finished"

# Infinity rules...
infinity/firmware.hex: infinity/keymap.c
	@echo -e "${HLT} >>${RST} Creating and populating building image for infinity"
	@docker rm "${DOCKER_IMAGE_TAG}__infinity" &> /dev/null || true
	@docker create -it --name "${DOCKER_IMAGE_TAG}__infinity" "${DOCKER_IMAGE_TAG}" make infinity60:${KEYMAP_NAME} > /dev/null
	@docker cp infinity "${DOCKER_IMAGE_TAG}__infinity":/src/qmk_firmware/keyboards/infinity60/keymaps/${KEYMAP_NAME}/ > /dev/null
	@pushd infinity &> /dev/null \
		&& find . -type f -not -name "*.hex" \
			-exec docker cp {} "${DOCKER_IMAGE_TAG}__infinity":/src/qmk_firmware/keyboards/infinity60/keymaps/${KEYMAP_NAME}/{} \; \
		&& popd &> /dev/null
	@echo -e "${HLT} >>${RST} Building the firmware image for infinity"
	@docker start -ia "${DOCKER_IMAGE_TAG}__infinity"
	@echo -e "${HLT} >>${RST} Retrieving the built image"
	@docker cp "${DOCKER_IMAGE_TAG}__infinity":/build/firmware.hex infinity/firmware.hex > /dev/null
	@docker rm "${DOCKER_IMAGE_TAG}__infinity" > /dev/null

infinity: image infinity/firmware.hex
flash-infinity: infinity
	@sudo echo -e "${HLT} >>${RST} Flashing firmware in ${PAUSE} seconds..."
	@for count in {${PAUSE}..1}; do \
		echo -e "${CPL}${HLT} >>${RST} Flashing firmware in $$count seconds..." ; \
		sleep 1 ; \
	done
	@echo -e "${CPL}${HLT} >>${RST} Flashing firmware..."
	@dfu-programmer atmega32u4 erase --force
	@dfu-programmer atmega32u4 flash infinity/firmware.hex
	@dfu-programmer atmega32u4 reset
	@echo -e "${HLT} >>${RST} Finished"
