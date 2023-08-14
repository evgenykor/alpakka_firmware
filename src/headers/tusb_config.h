// SPDX-License-Identifier: GPL-2.0-only
// Copyright (C) 2022, Input Labs Oy.

#pragma once

#define BOARD_DEVICE_RHPORT_NUM 0
#define BOARD_DEVICE_RHPORT_SPEED  OPT_MODE_FULL_SPEED

// #define CFG_TUSB_DEBUG 2
#define CFG_TUSB_RHPORT0_MODE (OPT_MODE_DEVICE | BOARD_DEVICE_RHPORT_SPEED)
#define CFG_TUSB_MEM_SECTION
#define CFG_TUSB_MEM_ALIGN __attribute__ ((aligned(4)))
#define CFG_TUD_ENDPOINT0_SIZE 64
#define CFG_TUD_VENDOR_RX_BUFSIZE 64
#define CFG_TUD_VENDOR_TX_BUFSIZE 64

#define CFG_TUD_HID 1
#define CFG_TUD_CDC 0
#define CFG_TUD_MSC 0
#define CFG_TUD_MIDI 0
#define CFG_TUD_VENDOR 1

#define ITF_HID 0
#define ITF_WEBUSB 1
#define ITF_XINPUT 2

#define ADDR_HID_IN 0x86
#define ADDR_WEBUSB_IN 0x84
#define ADDR_WEBUSB_OUT 0x04
#define ADDR_XINPUT_IN 0x81
#define ADDR_XINPUT_OUT 0x02

#define REPORT_KEYBOARD 1
#define REPORT_MOUSE 2
#define REPORT_GAMEPAD 3

#define STRING_VENDOR "Input Labs"
#define STRING_PRODUCT "Alpakka"
#define STRING_DEVICE_VERSION "1.0"
#define STRING_HID "HID"
#define STRING_WEBUSB "WEBUSB"
#define STRING_XINPUT "XINPUT_GENERIC_CONTROLLER"

#define MS_OS_VENDOR 0x17

#define USB_WIN_VENDOR  0x0170  // Input Labs.
#define USB_WIN_PRODUCT 0xAE29  // Alpakka (Xinput)

#define USB_UNIX_VENDOR  0x045E  // 360 controller vendor.
#define USB_UNIX_PRODUCT 0x028E  // 360 controller product.

#define USB_GENERIC_VENDOR  0x0170  // Input Labs.
#define USB_GENERIC_PRODUCT 0xAE17  // Alpakka (HID complilant gamepad)


#define DESCRIPTOR_DEVICE \
    0x12,    /* .bLength */\
    0x01,    /* .bDescriptorType */\
    0x0200,  /* .bcdUSB */\
    0x00,    /* .bDeviceClass */\
    0x00,    /* .bDeviceSubClass */\
    0x00,    /* .bDeviceProtocol */\
    0x40,    /* .bMaxPacketSize0 */\
    0x0000,  /* .idVendor */\
    0x0000,  /* .idProduct */\
    0x0114,  /* .bcdDevice */\
    0x01,    /* .iManufacturer */\
    0x02,    /* .iProduct */\
    0x03,    /* .iSerialNumber */\
    0x01     /* .bNumConfiguration */

#define DESCRIPTOR_CONFIGURATION(itfs) \
    0x09,        /* bLength */\
    0x02,        /* bDescriptorType: configuration */\
    0x00, 0x00,  /* wTotalLength */\
    itfs,        /* bNumInterfaces */\
    0x01,        /* bConfigurationValue */\
    0x00,        /* iConfiguration */\
    0x80,        /* bmAttributes */\
    0xFA         /* bMaxPower */

#define DESCRIPTOR_INTERFACE_HID(report_size) \
    TUD_HID_DESCRIPTOR( \
        ITF_HID,                /* Interface index */\
        ITF_HID + 4,            /* String index */\
        HID_ITF_PROTOCOL_NONE,  /* Boot protocol */\
        report_size,            /* Report descriptor length */\
        ADDR_HID_IN,            /* Interface address */\
        32,                     /* Endpoint buffer size */\
        1                       /* Interface interval (ms) */\
    )

#define DESCRIPTOR_INTERFACE_WEBUSB \
    TUD_VENDOR_DESCRIPTOR( \
        ITF_WEBUSB,       /* Interface index */\
        ITF_WEBUSB + 4,   /* String index */\
        ADDR_WEBUSB_OUT,  /* Address out */\
        ADDR_WEBUSB_IN,   /* Address in */\
        64                /* Size */\
    )

#define DESCRIPTOR_INTERFACE_XINPUT \
    0x09,        /* bLength */\
    0x04,        /* bDescriptorType: interface */\
    ITF_XINPUT,  /* bInterfaceNumber */\
    0x00,        /* bAlternateSetting */\
    0x02,        /* bNumEndpoints */\
    0xFF,        /* bInterfaceClass */\
    0x5D,        /* bInterfaceSubClass */\
    0x01,        /* bInterfaceProtocol */\
    0x00,        /* iInterface */\
    /* Undocumented */\
    0x10, 0x21, 0x10, 0x01, 0x01, 0x24, 0x81, 0x14, \
    0x03, 0x00, 0x03, 0x13, 0x02, 0x00, 0x03, 0x00, \
    /* Endpoints */\
    DESCRIPTOR_ENDPOINT_XINPUT_IN, \
    DESCRIPTOR_ENDPOINT_XINPUT_OUT

#define DESCRIPTOR_ENDPOINT_XINPUT_IN \
    0x07,            /* bLength */\
    0x05,            /* bDescriptorType: endpoint */\
    ADDR_XINPUT_IN,  /* bEndpointAddress */\
    0x03,            /* bmAttributes */\
    0x20, 0x00,      /* wMaxPacketSize */\
    0x04             /* bInterval */\

#define DESCRIPTOR_ENDPOINT_XINPUT_OUT \
    0x07,             /* bLength */\
    0x05,             /* bDescriptorType: endpoint */\
    ADDR_XINPUT_OUT,  /* bEndpointAddress */\
    0x03,             /* bmAttributes */\
    0x20, 0x00,       /* wMaxPacketSize */\
    0x08              /* bInterval */

#define MS_OS_DESCRIPTOR \
    0x12,                    /* Length */\
    0x03,                    /* Descriptor type: string */\
    'M' , 0x00, 'S' , 0x00,  /* Signature */\
    'F' , 0x00, 'T' , 0x00,  \
    '1' , 0x00, '0' , 0x00,  \
    '0' , 0x00,              \
    MS_OS_VENDOR,            /* Vendor code */\
    0x00                     /* Padding */

#define MS_OS_COMPATIDS \
    0x40, 0x00, 0x00, 0x00,  /* Length */\
    0x00, 0x01,              /* Version */\
    0x04, 0x00,              /* Descriptor type: Compatibility ID */\
    0x02, 0x00,              /* Sections */\
    0x00, 0x00, 0x00, 0x00,  /* Reserved */\
    0x00, 0x00,              /* Reserved */\
    ITF_WEBUSB,              /* Interface index */\
    0x01,                    /* Reserved */\
    'W' , 'I' , 'N' , 'U' ,  /* Compat ID */\
    'S' , 'B' , 0x00, 0x00,  \
    0x00, 0x00, 0x00, 0x00,  /* Sub-compat ID. */\
    0x00, 0x00, 0x00, 0x00,  \
    0x00, 0x00, 0x00, 0x00,  /* Reserved */\
    0x00, 0x00,              /* Reserved */\
    ITF_XINPUT,              /* Interface index */\
    0x01,                    /* Reserved */\
    'X' , 'U' , 'S' , 'B',   /* Compat ID */\
    '1' , '0' , 0x00, 0x00,  \
    0x00, 0x00, 0x00, 0x00,  /* Sub-compat ID. */\
    0x00, 0x00, 0x00, 0x00,  \
    0x00, 0x00, 0x00, 0x00,  /* Reserved */\
    0x00, 0x00               /* Reserved */

#define MS_OS_PROPERTIES \
    0x8E, 0x00, 0x00, 0x00,  /* Length */\
    0x00, 0x01,              /* Version */\
    0x05, 0x00,              /* Descriptor type: Extented property*/\
    0x01, 0x00,              /* Sections */\
    0x84, 0x00, 0x00, 0x00,  /* Section size */\
    0x01, 0x00, 0x00, 0x00,  /* Data type */\
    0x28, 0x00,              /* Property name size */\
    /* Property name */\
    'D', 0, 'e', 0, 'v', 0, 'i', 0, 'c', 0, 'e', 0, 'I', 0, 'n', 0, \
    't', 0, 'e', 0, 'r', 0, 'f', 0, 'a', 0, 'c', 0, 'e', 0, 'G', 0, \
    'U', 0, 'I', 0, 'D', 0,  0 , 0, \
    /* Data size */\
    0x4E, 0x00, 0x00, 0x00, \
    /* Data */\
    '{', 0, 'A', 0, '0', 0, '0', 0, '6', 0, 'C', 0, '7', 0, 'D', 0, \
    'A', 0, '-', 0, '8', 0, '8', 0, 'A', 0, '4', 0, '-', 0, '4', 0, \
    '7', 0, 'E', 0, 'E', 0, '-', 0, 'A', 0, '7', 0, '5', 0, '2', 0, \
    '-', 0, 'F', 0, 'B', 0, 'C', 0, '4', 0, '2', 0, '2', 0, '5', 0, \
    '8', 0, '6', 0, '6', 0, 'A', 0, '1', 0, '}', 0,  0 , 0
