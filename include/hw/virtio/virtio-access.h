/*
 * Virtio Accessor Support: In case your target can change endian.
 *
 * Copyright IBM, Corp. 2013
 *
 * Authors:
 *  Rusty Russell   <rusty@au.ibm.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 */
#ifndef _QEMU_VIRTIO_ACCESS_H
#define _QEMU_VIRTIO_ACCESS_H
#include "hw/virtio/virtio.h"

static inline uint16_t virtio_lduw_phys(AddressSpace *as, hwaddr pa,
                                        struct VirtIODevice *vdev)
{
    if (vdev->needs_byteswap) {
        return bswap16(lduw_phys(as, pa));
    }
    return lduw_phys(as, pa);
}

static inline uint32_t virtio_ldl_phys(AddressSpace *as, hwaddr pa,
                                       struct VirtIODevice *vdev)
{
    if (vdev->needs_byteswap) {
        return bswap32(ldl_phys(as, pa));
    }
    return ldl_phys(as, pa);
}

static inline uint64_t virtio_ldq_phys(AddressSpace *as, hwaddr pa,
                                       struct VirtIODevice *vdev)
{
    if (vdev->needs_byteswap) {
        return bswap64(ldq_phys(as, pa));
    }
    return ldq_phys(as, pa);
}

static inline void virtio_stw_phys(AddressSpace *as, hwaddr pa, uint16_t value,
                                   struct VirtIODevice *vdev)
{
    if (vdev->needs_byteswap) {
        stw_phys(as, pa, bswap16(value));
    } else {
        stw_phys(as, pa, value);
    }
}

static inline void virtio_stl_phys(AddressSpace *as, hwaddr pa, uint32_t value,
                                   struct VirtIODevice *vdev)
{
    if (vdev->needs_byteswap) {
        stl_phys(as, pa, bswap32(value));
    } else {
        stl_phys(as, pa, value);
    }
}

static inline void virtio_stw_p(void *ptr, uint16_t v,
                                struct VirtIODevice *vdev)
{
    if (vdev->needs_byteswap) {
        stw_p(ptr, bswap16(v));
    } else {
        stw_p(ptr, v);
    }
}

static inline void virtio_stl_p(void *ptr, uint32_t v,
                                struct VirtIODevice *vdev)
{
    if (vdev->needs_byteswap) {
        stl_p(ptr, bswap32(v));
    } else {
        stl_p(ptr, v);
    }
}

static inline void virtio_stq_p(void *ptr, uint64_t v,
                                struct VirtIODevice *vdev)
{
    if (vdev->needs_byteswap) {
        stq_p(ptr, bswap64(v));
    } else {
        stq_p(ptr, v);
    }
}

static inline int virtio_lduw_p(const void *ptr, struct VirtIODevice *vdev)
{
    if (vdev->needs_byteswap) {
        return bswap16(lduw_p(ptr));
    } else {
        return lduw_p(ptr);
    }
}

static inline int virtio_ldl_p(const void *ptr, struct VirtIODevice *vdev)
{
    if (vdev->needs_byteswap) {
        return bswap32(ldl_p(ptr));
    } else {
        return ldl_p(ptr);
    }
}

static inline uint64_t virtio_ldq_p(const void *ptr, struct VirtIODevice *vdev)
{
    if (vdev->needs_byteswap) {
        return bswap64(ldq_p(ptr));
    } else {
        return ldq_p(ptr);
    }
}

static inline uint32_t virtio_tswap32(uint32_t s, struct VirtIODevice *vdev)
{
    if (vdev->needs_byteswap) {
        return bswap32(tswap32(s));
    } else {
        return tswap32(s);
    }
}

static inline void virtio_tswap32s(uint32_t *s, struct VirtIODevice *vdev)
{
    tswap32s(s);
    if (vdev->needs_byteswap) {
        *s = bswap32(*s);
    }
}
#endif /* _QEMU_VIRTIO_ACCESS_H */
