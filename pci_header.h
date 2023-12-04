#ifndef PCI_HEADER_H
#define PCI_HEADER_H

#include "global.h"

// Identifiers
typedef union _pci_header_id_t
{
    struct __pci_header_id_bit_t
    {
        u16 vendor_id;
        u16 device_id;
    } bit;
    u32 config;
} __attribute__((packed)) pci_header_id_t;

// Command
typedef union _pci_header_cmd_t
{
    struct _pci_header_cmd_bit_t
    {
        u16 iose : 1;
        u16 mse : 1;
        u16 bme : 1;
        u16 sce : 1;    // Not Supported
        u16 mvie : 1;   // Not Supported
        u16 vga : 1;    // Not Supported
        u16 pee : 1;
        u16 hardwired_0 : 1;
        u16 see : 1;
        u16 fbe : 1;    // Not Supported
        u16 id : 1;     // Interrupt Disable
        u16 rsvd : 5;
    } bit;
    u16 config;
} __attribute__((packed)) pci_header_cmd_t;

typedef union _pci_header_sts_t
{
    struct _pci_header_sts_bit_t
    {
        u16 rsvd : 3;
        u16 is : 1;     // Interrupt Status
        u16 cl : 1;     // Capabilities List
        u16 c66 : 1;    // 66 MHz Capable
        u16 rsvd : 1;
        u16 fbc : 1;    // Fast Back-to-Back Capable (FBC)
        u16 dpd : 1;    // Data Parity Error Detected (DPD)
        u16 devt : 2;   // DEVSEL# Timing (DEVT)
        u16 sta : 1;    // Signaled Target Abort
        u16 rta : 1;    // Received Target Abort
        u16 rma : 1;    // Received Master Abort
        u16 sse : 1;    // Signaled System Error
        u16 dpe : 1;    // Detected Parity Error
    } bit;
    u16 config;
} __attribute__((packed)) pci_header_sts_t;

typedef union _pci_header_rid_cc_t
{
    struct _pci_header_rid_cc_bit_t
    {
        u32 rid : 8;    // Revision ID
        u32 pi : 8;
        u32 scc : 8;
        u32 bcc : 8;
    } bit;
    u32 config;
} __attribute__((packed)) pci_header_rid_cc_t;

typedef union _pci_header_cls_t
{
    struct _pci_header_cls_bit_t
    {
        u8 cls;
    } bit;
    u8 config;
} __attribute__((packed)) pci_header_cls_t;

typedef union _pci_header_mlt_t
{
    struct _pci_header_mlt_bit_t
    {
        u8 mlt;
    } bit;
    u8 config;
} __attribute__((packed)) pci_header_mlt_t;

typedef union _pci_header_htype_t
{
    struct _pci_header_htype_bit_t
    {
        u8 hl : 7;      // Header Layout
        u8 mfd : 1;     // Multi-Function Device
    } bit;
    u8 config;
} __attribute__((packed)) pci_header_htype_t;

typedef union _pci_header_bist_t
{
    struct _pci_header_bist_bit_t
    {
        u8 cc : 4;
        u8 rsvd : 2;
        u8 sb : 1;
        u8 bc : 1;
    } bit;
    u8 config;
} __attribute__((packed)) pci_header_bist_t;

typedef union _pci_header_mlbar_t
{
    struct _pci_header_mlbar_bit_t
    {
        u32 rte : 1;    // Resource Type Indicator
        u32 tp : 2;     // Type
        u32 pf : 1;     // Prefetchable
        u32 rsvd : 10 ;
        u32 ba : 18;    // Base Address
    } bit;
    u32 config;
} pci_header_mlbar_t;

typedef union _pci_header_mubar_t
{
    struct _pci_header_mubar_bit_t
    {
        u32 ba;         // Base Address
    } bit;
    u32 config;
} pci_header_mubar_t;

typedef struct _pci_header_t
{
    pci_header_id_t id;
    pci_header_cmd_t cmd;
    pci_header_sts_t sts;
    pci_header_rid_cc_t rid_cc;
    pci_header_cls_t cls;
    pci_header_cls_t mlt;
    pci_header_htype_t htype;
} pci_header_t;

#endif // ~ PCI_HEADER_H