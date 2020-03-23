.PHONY: image kc60 flash-kc60 minivan flash-minivan hhkb flash-hhkb infinity flash-infinity
DOCKER_IMAGE_TAG=qmk_builder
KEYMAP_NAME=local
PAUSE=5

.docker_image_id: Dockerfile docker-entrypoint.sh
	@echo " >> Building container image"
	@docker build -t "${DOCKER_IMAGE_TAG}" .
	@docker images --quiet "${DOCKER_IMAGE_TAG}" > .docker_image_id
image: .docker_image_id

# KC60 keyboard rules...
kc60/firmware.hex: kc60/keymap.c kc60/config.h
	@echo " >> Creating and populating building image for kc60"
	@docker rm "${DOCKER_IMAGE_TAG}__kc60" &> /dev/null || true
	@docker create -it --name "${DOCKER_IMAGE_TAG}__kc60" "${DOCKER_IMAGE_TAG}" make kc60:${KEYMAP_NAME} > /dev/null
	@docker cp kc60 "${DOCKER_IMAGE_TAG}__kc60":/src/qmk_firmware/keyboards/kc60/keymaps/${KEYMAP_NAME}/ > /dev/null
	@pushd kc60 \
		&& find . -type f -not -name "*.hex" \
			-exec docker cp {} "${DOCKER_IMAGE_TAG}__kc60":/src/qmk_firmware/keyboards/kc60/keymaps/${KEYMAP_NAME}/{} \; \
		&& popd
	@docker start -ia "${DOCKER_IMAGE_TAG}__kc60"
	@docker cp "${DOCKER_IMAGE_TAG}__kc60":/build/firmware.hex kc60/firmware.hex > /dev/null
	@docker rm "${DOCKER_IMAGE_TAG}__kc60" > /dev/null

kc60: image kc60/firmware.hex
flash-kc60: kc60
	@sudo echo "Will flash firmware in ${PAUSE} seconds..."
	@sleep ${PAUSE}
	@sudo dfu-programmer atmega32u4 erase --force
	@sudo dfu-programmer atmega32u4 flash kc60/firmware.hex
	@sudo dfu-programmer atmega32u4 reset
# TheVan minivan44 rules...
minivan/firmware.hex: minivan/keymap.c
	@echo " >> Creating and populating building image for minivan"
	@docker rm "${DOCKER_IMAGE_TAG}__minivan" &> /dev/null || true
	@docker create -it --name "${DOCKER_IMAGE_TAG}__minivan" "${DOCKER_IMAGE_TAG}" make thevankeyboards/minivan:${KEYMAP_NAME} > /dev/null
	@docker cp minivan "${DOCKER_IMAGE_TAG}__minivan":/src/qmk_firmware/keyboards/thevankeyboards/minivan/keymaps/${KEYMAP_NAME}/ > /dev/null
	@pushd minivan \
		&& find . -type f -not -name "*.hex" \
			-exec docker cp {} "${DOCKER_IMAGE_TAG}__minivan":/src/qmk_firmware/keyboards/thevankeyboards/minivan/keymaps/${KEYMAP_NAME}/{} \; \
		&& popd
	@docker start -ia "${DOCKER_IMAGE_TAG}__minivan"
	@docker cp "${DOCKER_IMAGE_TAG}__minivan":/build/firmware.hex minivan/firmware.hex > /dev/null
	@docker rm "${DOCKER_IMAGE_TAG}__minivan" > /dev/null

minivan: image minivan/firmware.hex
flash-minivan: minivan
	@echo "Will flash firmware in ${PAUSE} seconds..."
	@sleep ${PAUSE}
	@dfu-programmer atmega32u4 erase --force
	@dfu-programmer atmega32u4 flash minivan/firmware.hex
	@dfu-programmer atmega32u4 reset
# HHKB rules...
hhkb/firmware.hex: hhkb/keymap.c
	@echo " >> Creating and populating building image for hhkb"
	@docker rm "${DOCKER_IMAGE_TAG}__hhkb" &> /dev/null || true
	@docker create -it --name "${DOCKER_IMAGE_TAG}__hhkb" "${DOCKER_IMAGE_TAG}" make hhkb:${KEYMAP_NAME} > /dev/null
	@docker cp hhkb "${DOCKER_IMAGE_TAG}__hhkb":/src/qmk_firmware/keyboards/hhkb/keymaps/${KEYMAP_NAME}/ > /dev/null
	@pushd hhkb \
		&& find . -type f -not -name "*.hex" \
			-exec docker cp {} "${DOCKER_IMAGE_TAG}__hhkb":/src/qmk_firmware/keyboards/hhkb/keymaps/${KEYMAP_NAME}/{} \; \
		&& popd
	@docker start -ia "${DOCKER_IMAGE_TAG}__hhkb"
	@docker cp "${DOCKER_IMAGE_TAG}__hhkb":/build/firmware.hex hhkb/firmware.hex > /dev/null
	@docker rm "${DOCKER_IMAGE_TAG}__hhkb" > /dev/null

hhkb: image hhkb/firmware.hex
flash-hhkb: hhkb
	@echo "Will flash firmware in ${PAUSE} seconds..."
	@sleep ${PAUSE}
	@dfu-programmer atmega32u4 erase --force
	@dfu-programmer atmega32u4 flash hhkb/firmware.hex
	@dfu-programmer atmega32u4 reset
# Infinity rules...
infinity/firmware.hex: infinity/keymap.c
	@echo " >> Creating and populating building image for infinity"
	@docker rm "${DOCKER_IMAGE_TAG}__infinity" &> /dev/null || true
	@docker create -it --name "${DOCKER_IMAGE_TAG}__infinity" "${DOCKER_IMAGE_TAG}" make infinity60:${KEYMAP_NAME} > /dev/null
	@docker cp infinity "${DOCKER_IMAGE_TAG}__infinity":/src/qmk_firmware/keyboards/infinity60/keymaps/${KEYMAP_NAME}/ > /dev/null
	@pushd infinity \
		&& find . -type f -not -name "*.hex" \
			-exec docker cp {} "${DOCKER_IMAGE_TAG}__infinity":/src/qmk_firmware/keyboards/infinity60/keymaps/${KEYMAP_NAME}/{} \; \
		&& popd
	@docker start -ia "${DOCKER_IMAGE_TAG}__infinity"
	@docker cp "${DOCKER_IMAGE_TAG}__infinity":/build/firmware.hex infinity/firmware.hex > /dev/null
	@docker rm "${DOCKER_IMAGE_TAG}__infinity" > /dev/null

infinity: image infinity/firmware.hex
flash-infinity: infinity
	@echo "Will flash firmware in ${PAUSE} seconds..."
	@sleep ${PAUSE}
	@dfu-programmer atmega32u4 erase --force
	@dfu-programmer atmega32u4 flash infinity/firmware.hex
	@dfu-programmer atmega32u4 reset
