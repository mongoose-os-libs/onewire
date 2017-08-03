/*
 * Copyright (c) 2014-2017 Cesanta Software Limited
 * All rights reserved
 */

#ifndef CS_MOS_LIBS_ONEWIRE_SRC_MGOS_ONEWIRE_H_
#define CS_MOS_LIBS_ONEWIRE_SRC_MGOS_ONEWIRE_H_

#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

struct mgos_onewire;

uint8_t mgos_onewire_crc8(const uint8_t *rom, int len);
bool mgos_onewire_reset(struct mgos_onewire *ow);
void mgos_onewire_target_setup(struct mgos_onewire *ow,
                               const uint8_t family_code);
bool mgos_onewire_next(struct mgos_onewire *ow, uint8_t *rom, int mode);
void mgos_onewire_select(struct mgos_onewire *ow, const uint8_t *rom);
void mgos_onewire_skip(struct mgos_onewire *ow);
void mgos_onewire_search_clean(struct mgos_onewire *ow);
bool mgos_onewire_read_bit(struct mgos_onewire *ow);
uint8_t mgos_onewire_read(struct mgos_onewire *ow);
void mgos_onewire_read_bytes(struct mgos_onewire *ow, uint8_t *buf, int len);
void mgos_onewire_write_bit(struct mgos_onewire *ow, int bit);
void mgos_onewire_write(struct mgos_onewire *ow, const uint8_t data);
void mgos_onewire_write_bytes(struct mgos_onewire *ow, const uint8_t *buf,
                              int len);
struct mgos_onewire *mgos_onewire_create(int pin);
void mgos_onewire_close(struct mgos_onewire *ow);

bool mgos_onewire_init(void);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* CS_MOS_LIBS_ONEWIRE_SRC_MGOS_ONEWIRE_H_ */
