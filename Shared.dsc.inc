#
#  Copyright (c) 2011-2015, ARM Limited. All rights reserved.
#  Copyright (c) 2014, Linaro Limited. All rights reserved.
#  Copyright (c) 2015 - 2016, Intel Corporation. All rights reserved.
#  Copyright (c) 2018 - 2019, Bingxing Wang. All rights reserved.
#
#  This program and the accompanying materials
#  are licensed and made available under the terms and conditions of the BSD License
#  which accompanies this distribution.  The full text of the license may be found at
#  http://opensource.org/licenses/bsd-license.php
#
#  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
#  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.
#
#

[BuildOptions.common]
  *_GCC5_AARCH64_CC_FLAGS = -mfix-cortex-a53-835769 -mfix-cortex-a53-843419
  *_GCC5_AARCH64_DLINK_FLAGS = -mfix-cortex-a53-835769 -mfix-cortex-a53-843419
  # Use Clang 11+ actually, some fixes are builtin
  *_CLANG38_AARCH64_CC_FLAGS = -mfix-cortex-a53-835769 -D CLANG
  *_CLANG38_AARCH64_DLINK_FLAGS = -mfix-cortex-a53-835769
  *_*_*_CC_FLAGS = -D DISABLE_NEW_DEPRECATED_INTERFACES -D HAS_MEMCPY_INTRINSICS

[BuildOptions.common.EDKII.DXE_CORE,BuildOptions.common.EDKII.DXE_DRIVER,BuildOptions.common.EDKII.UEFI_DRIVER,BuildOptions.common.EDKII.UEFI_APPLICATION]
  *_*_*_DLINK_FLAGS = -z common-page-size=0x1000

[BuildOptions.common.EDKII.DXE_RUNTIME_DRIVER]
  *_*_ARM_DLINK_FLAGS = -z common-page-size=0x1000
  *_*_AARCH64_DLINK_FLAGS = -z common-page-size=0x10000

[PcdsFeatureFlag.common]
  gArmTokenSpaceGuid.PcdCpuDxeProduceDebugSupport|FALSE

  gEfiMdePkgTokenSpaceGuid.PcdComponentNameDisable|TRUE
  gEfiMdePkgTokenSpaceGuid.PcdDriverDiagnosticsDisable|TRUE
  gEfiMdePkgTokenSpaceGuid.PcdComponentName2Disable|TRUE
  gEfiMdePkgTokenSpaceGuid.PcdDriverDiagnostics2Disable|TRUE

  gEfiMdeModulePkgTokenSpaceGuid.PcdTurnOffUsbLegacySupport|TRUE
  gEfiMdeModulePkgTokenSpaceGuid.PcdConOutGopSupport|TRUE
  gEfiMdeModulePkgTokenSpaceGuid.PcdSupportUpdateCapsuleReset|TRUE

  gEmbeddedTokenSpaceGuid.PcdPrePiProduceMemoryTypeInformationHob|TRUE

  gEfiMdeModulePkgTokenSpaceGuid.PcdPciBusHotplugDeviceSupport|FALSE

  gLumia950XLPkgTokenSpaceGuid.PcdIsLkBuild|FALSE

  gQcomTokenSpaceGuid.PcdMmcHs200Caps|FALSE

[PcdsFixedAtBuild.common]
  gArmTokenSpaceGuid.PcdSystemMemoryBase|0x00000000         # Starting address
  gArmTokenSpaceGuid.PcdCpuVectorBaseAddress|0x00C40000
  gArmTokenSpaceGuid.PcdArmArchTimerFreqInHz|19200000
  gArmTokenSpaceGuid.PcdArmArchTimerSecIntrNum|18
  gArmTokenSpaceGuid.PcdArmArchTimerIntrNum|19
  gArmTokenSpaceGuid.PcdGicDistributorBase|0xf9000000
  gArmTokenSpaceGuid.PcdGicInterruptInterfaceBase|0xf9002000

  gEfiMdeModulePkgTokenSpaceGuid.PcdFirmwareVendor|L"LumiaWoA authors"
  gEfiMdeModulePkgTokenSpaceGuid.PcdFirmwareVersionString|L"2.23"
  gEfiMdeModulePkgTokenSpaceGuid.PcdFirmwareRevision|0x00024001
  gEfiMdeModulePkgTokenSpaceGuid.PcdAcpiDefaultOemId|"LMNL  "
  gEfiMdeModulePkgTokenSpaceGuid.PcdAcpiDefaultOemTableId|0x324B44454D4F4351
  gEfiMdeModulePkgTokenSpaceGuid.PcdAcpiDefaultOemRevision|0x00000001
  gEfiMdeModulePkgTokenSpaceGuid.PcdAcpiDefaultCreatorId|0x4D4F4351
  gEfiMdeModulePkgTokenSpaceGuid.PcdAcpiDefaultCreatorRevision|0x00000001
  gEfiMdePkgTokenSpaceGuid.PcdMaximumUnicodeStringLength|1000000
  gEfiMdePkgTokenSpaceGuid.PcdMaximumAsciiStringLength|1000000
  gEfiMdePkgTokenSpaceGuid.PcdMaximumLinkedListLength|1000000
  gEfiMdePkgTokenSpaceGuid.PcdSpinLockTimeout|10000000
  gEfiMdePkgTokenSpaceGuid.PcdDebugClearMemoryValue|0xAF
  gEfiMdePkgTokenSpaceGuid.PcdPerformanceLibraryPropertyMask|1
  gEfiMdePkgTokenSpaceGuid.PcdPostCodePropertyMask|0
  gEfiMdePkgTokenSpaceGuid.PcdUefiLibMaxPrintBufferSize|320
  gEfiMdePkgTokenSpaceGuid.PcdDebugPropertyMask|0x2f
  gEfiMdePkgTokenSpaceGuid.PcdDebugPrintErrorLevel|0x800fee0f
  gEfiMdePkgTokenSpaceGuid.PcdReportStatusCodePropertyMask|0x07
  gEfiMdeModulePkgTokenSpaceGuid.PcdResetOnMemoryTypeInformationChange|FALSE
  
  #
  # Make VariableRuntimeDxe work at emulated non-volatile variable mode.
  #
  gEfiMdeModulePkgTokenSpaceGuid.PcdEmuVariableNvModeEnable|TRUE

  gEmbeddedTokenSpaceGuid.PcdPrePiCpuIoSize|0
  gEmbeddedTokenSpaceGuid.PcdMemoryTypeEfiACPIReclaimMemory|0
  gEmbeddedTokenSpaceGuid.PcdMemoryTypeEfiACPIMemoryNVS|0
  gEmbeddedTokenSpaceGuid.PcdMemoryTypeEfiReservedMemoryType|0
!if $(SECURE_BOOT_ENABLE) == TRUE
  gEmbeddedTokenSpaceGuid.PcdMemoryTypeEfiRuntimeServicesData|600
  gEmbeddedTokenSpaceGuid.PcdMemoryTypeEfiRuntimeServicesCode|400
  gEmbeddedTokenSpaceGuid.PcdMemoryTypeEfiBootServicesCode|1500
!else
  gEmbeddedTokenSpaceGuid.PcdMemoryTypeEfiRuntimeServicesData|300
  gEmbeddedTokenSpaceGuid.PcdMemoryTypeEfiRuntimeServicesCode|150
  gEmbeddedTokenSpaceGuid.PcdMemoryTypeEfiBootServicesCode|1000
!endif
  gEmbeddedTokenSpaceGuid.PcdMemoryTypeEfiBootServicesData|800
  gEmbeddedTokenSpaceGuid.PcdMemoryTypeEfiLoaderCode|10
  gEmbeddedTokenSpaceGuid.PcdMemoryTypeEfiLoaderData|0
  gEmbeddedTokenSpaceGuid.PcdPrePiStackBase|0x00C00000
  gEmbeddedTokenSpaceGuid.PcdPrePiStackSize|0x00040000      # 256K stack
  gEmbeddedTokenSpaceGuid.PcdInterruptBaseAddress|0xf9000000
  gEmbeddedTokenSpaceGuid.PcdPrePiCpuIoSize|16

  # SoC Drivers GPIO TLMM
  gQcomTokenSpaceGuid.PcdGpioTlmmBaseAddress|0xFD510000
  gQcomTokenSpaceGuid.PcdGpioTlmmSummaryIrq|240
  gQcomTokenSpaceGuid.PcdGpioTlmmIoOffset|0x1004
  gQcomTokenSpaceGuid.PcdGpioTlmmIoElementSize|0x10
  gQcomTokenSpaceGuid.PcdGpioTlmmCtlOffset|0x1000
  gQcomTokenSpaceGuid.PcdGpioTlmmCtlElementSize|0x10
  gQcomTokenSpaceGuid.PcdGpioTlmmIntrCfgOffset|0x1008
  gQcomTokenSpaceGuid.PcdGpioTlmmIntrCfgElementSize|0x10
  gQcomTokenSpaceGuid.PcdGpioTlmmIntrStatusOffset|0x100c
  gQcomTokenSpaceGuid.PcdGpioTlmmIntrStatusElementSize|0x10
  gQcomTokenSpaceGuid.PcdGpioTlmmIntrTargetOffset|0x1008
  gQcomTokenSpaceGuid.PcdGpioTlmmIntrTargetElementSize|0x10
  gQcomTokenSpaceGuid.PcdGpioTlmmIntrEnableBit|0
  gQcomTokenSpaceGuid.PcdGpioTlmmIntrStatusBit|0
  gQcomTokenSpaceGuid.PcdGpioTlmmIntrAckHigh|FALSE
  gQcomTokenSpaceGuid.PcdGpioTlmmIntrTargetBit|5
  gQcomTokenSpaceGuid.PcdGpioTlmmIntrTargetKpssValue|4
  gQcomTokenSpaceGuid.PcdGpioTlmmIntrRawStatusBit|4
  gQcomTokenSpaceGuid.PcdGpioTlmmIntrPolarityBit|1
  gQcomTokenSpaceGuid.PcdGpioTlmmIntrDetectionBit|2
  gQcomTokenSpaceGuid.PcdGpioTlmmIntrDetectionWidth|2
  gQcomTokenSpaceGuid.PcdGpioTlmmInBit|0
  gQcomTokenSpaceGuid.PcdGpioTlmmOutBit|1
  gQcomTokenSpaceGuid.PcdGpioTlmmOeBit|9
  gQcomTokenSpaceGuid.PcdGpioTlmmMuxBit|2
  gQcomTokenSpaceGuid.PcdGpioTlmmDrvBit|6
  gQcomTokenSpaceGuid.PcdGpioTlmmPullBit|0
  gQcomTokenSpaceGuid.PcdGpioTlmmNumFunctions|12

  # SoC Drivers SPMI
  gQcomTokenSpaceGuid.PcdSpmiBaseAddress|0xFC4C0000

  # SoC Drivers MMC
  gQcomTokenSpaceGuid.PcdSdccMciHcMode|0x00000078
  gQcomTokenSpaceGuid.PcdSdccHcPwrctlStatusReg|0x000000DC
  gQcomTokenSpaceGuid.PcdSdccHcPwrctlMaskReg|0x000000E0
  gQcomTokenSpaceGuid.PcdSdccHcPwrctlClearReg|0x000000E4
  gQcomTokenSpaceGuid.PcdSdccHcPwrctlCtlReg|0x000000E8
  gQcomTokenSpaceGuid.PcdMmcSdhciDdrCfgVal|0x80040870 # DDR_CFG_DLY_VAL
  gQcomTokenSpaceGuid.PcdMmcSdc1HdrvPullCtlOffset|0x00002044
  gQcomTokenSpaceGuid.PcdMmcSdc2HdrvPullCtlOffset|0x00002048

  # SoC Drivers Misc
  gQcomTokenSpaceGuid.PcdGicSpiStart|32

  # SoC Drivers UARTDM
  gQcomTokenSpaceGuid.PcdUartDmClkRxTxBitRate|0xCC

  gLumia950XLPkgTokenSpaceGuid.PcdUefiMemPoolSize|0x7800000      
  gLumia950XLPkgTokenSpaceGuid.PcdPreAllocatedMemorySize|0x20000000  # Start here

  ## Default Terminal Type
  ## 0-PCANSI, 1-VT100, 2-VT00+, 3-UTF8, 4-TTYTERM
  gEfiMdePkgTokenSpaceGuid.PcdDefaultTerminalType|4 

  # Boot Manager
  gEfiMdeModulePkgTokenSpaceGuid.PcdBootManagerMenuFile|{ 0x21, 0xaa, 0x2c, 0x46, 0x14, 0x76, 0x03, 0x45, 0x83, 0x6e, 0x8a, 0xb6, 0xf4, 0x66, 0x23, 0x31 }
  gLumia950XLPkgTokenSpaceGuid.PcdBootSplashAppFile|{ 0x59, 0x67, 0xbe, 0x93, 0x1a, 0x7d, 0x69, 0x4d, 0x6d, 0x98, 0x30, 0xf9, 0xc9, 0x54, 0x8e, 0xd7 }
  gEfiMdePkgTokenSpaceGuid.PcdPlatformBootTimeOut|2

  # Enable Debug
  gLumia950XLPkgTokenSpaceGuid.PcdEnableScreenSerial|TRUE

  # SoC Drivers I2C
  gQcomTokenSpaceGuid.PcdGicSpiStart|32

  # Device Driver Synaptics 3202
  gLumia950XLPkgTokenSpaceGuid.SynapticsCtlrAddress|0x4b
  gLumia950XLPkgTokenSpaceGuid.SynapticsCtlrResetPin|38
  gLumia950XLPkgTokenSpaceGuid.SynapticsCtlrIntPin|77
  gLumia950XLPkgTokenSpaceGuid.SynapticsCtlrI2cDevice|1

  # RPM
  gQcomTokenSpaceGuid.PcdApcsAlias0IpcInterrupt|0xF900D008
  gQcomTokenSpaceGuid.PcdSmdIrq|200

  # SMEM
  gQcomTokenSpaceGuid.PcdMsmSharedBase|0x06A00000
  gQcomTokenSpaceGuid.PcdMsmSharedSize|0x00200000

  # USB
  gQcomTokenSpaceGuid.PcdUsb30Ee1Irq|163
  gQcomTokenSpaceGuid.PcdUsb30Base|0xF9200000
  gQcomTokenSpaceGuid.PcdUsb30ScratchBase|0xF92F8800
  gQcomTokenSpaceGuid.PcdUsb30QmpPhyBase|0xF9B38000
  gQcomTokenSpaceGuid.PcdUsb2PhyBase|0xF9B39000
  gQcomTokenSpaceGuid.PcdUsb2PhyPortPowerDownOffset|0x000000B4
  gQcomTokenSpaceGuid.PcdUsb2PhyPortUtmiCtrl2Offset|0x000000C4
  gQcomTokenSpaceGuid.PcdUsb2PhyPortTune1Offset|0x00000080
  gQcomTokenSpaceGuid.PcdUsb2PhyPortTune2Offset|0x00000084
  gQcomTokenSpaceGuid.PcdUsb2PhyPortTune3Offset|0x00000088
  gQcomTokenSpaceGuid.PcdUsb2PhyPortTune4Offset|0x0000008C
  gQcomTokenSpaceGuid.PcdUsb2GccPhyBcr|0xFC4004B8

  # Variable Services
  # Each Size of 0xA0000
  # gEfiMdeModulePkgTokenSpaceGuid.PcdFlashNvStorageVariableBase|0x80000000
  # gEfiMdeModulePkgTokenSpaceGuid.PcdFlashNvStorageVariableSize|0x000A0000
  # gEfiMdeModulePkgTokenSpaceGuid.PcdFlashNvStorageFtwSpareBase|0x800A0000
  # gEfiMdeModulePkgTokenSpaceGuid.PcdFlashNvStorageFtwSpareSize|0x000A0000
  # gEfiMdeModulePkgTokenSpaceGuid.PcdFlashNvStorageFtwWorkingBase|0x80140000 
  # gEfiMdeModulePkgTokenSpaceGuid.PcdFlashNvStorageFtwWorkingSize|0x000A0000
  # gLumia950XLPkgTokenSpaceGuid.PcdNvStorageVolatileStorageBase|0x801E0000

  # eMMC should have block size of 512 bytes. (Assert)
  # Allocate 640KB (less than provisioned) so 500 blocks
  # And times 3 for other regions
  # And it starts at the beginning of the logical partition of "uefi_vars"
  # Synchronize the change in LK when the size changes
  # gLumia950XLPkgTokenSpaceGuid.PcdNvStorageVariableBlockCount|3840
  # gLumia950XLPkgTokenSpaceGuid.PcdNvStorageVariableBlockSize|512
  # gLumia950XLPkgTokenSpaceGuid.PcdNvStorageVariableBlockLba|0
  # gLumia950XLPkgTokenSpaceGuid.PcdNvStorageScratchAddress|0x90000000

  # PCI Express
  gEfiMdeModulePkgTokenSpaceGuid.PcdSrIovSupport|FALSE
  gEfiMdeModulePkgTokenSpaceGuid.PcdAriSupport|FALSE
  gEfiMdeModulePkgTokenSpaceGuid.PcdMrIovSupport|FALSE
  gEfiMdePkgTokenSpaceGuid.PcdPciExpressBaseAddress|0xf8800000
  gArmTokenSpaceGuid.PcdPciBusMin|0x0
  gArmTokenSpaceGuid.PcdPciBusMax|0xff

  # Timer
  gQcomTokenSpaceGuid.PcdIntDebugTimerExp|41
  gQcomTokenSpaceGuid.PcdQTimerBase|0xF9021000

  # Parking
  gLumia950XLPkgTokenSpaceGuid.SecondaryCpuStackSize|0x2000
  gLumia950XLPkgTokenSpaceGuid.SecondaryCpuMpParkRegionBase|0x00300000
  gLumia950XLPkgTokenSpaceGuid.SecondaryCpuIgnoreCpuIdCheck|TRUE

!if $(SECURE_BOOT_ENABLE) == TRUE
  gEfiMdeModulePkgTokenSpaceGuid.PcdMaxAuthVariableSize|0x2800
  gEfiSecurityPkgTokenSpaceGuid.PcdUserPhysicalPresence|TRUE
!endif

[PcdsDynamicDefault.common]
  gEfiMdeModulePkgTokenSpaceGuid.PcdVideoHorizontalResolution|1080
  gEfiMdeModulePkgTokenSpaceGuid.PcdVideoVerticalResolution|1920
  gEfiMdeModulePkgTokenSpaceGuid.PcdSetupVideoHorizontalResolution|1080
  gEfiMdeModulePkgTokenSpaceGuid.PcdSetupVideoVerticalResolution|1920
  gEfiMdeModulePkgTokenSpaceGuid.PcdSetupConOutRow|160
  gEfiMdeModulePkgTokenSpaceGuid.PcdSetupConOutColumn|120

!include MdePkg/MdeLibs.dsc.inc
	  
[LibraryClasses.common]
  ArmLib|ArmPkg/Library/ArmLib/ArmBaseLib.inf
  ArmMmuLib|ArmPkg/Library/ArmMmuLib/ArmMmuBaseLib.inf
  ArmGenericTimerCounterLib|ArmPkg/Library/ArmGenericTimerPhyCounterLib/ArmGenericTimerPhyCounterLib.inf
  ArmDisassemblerLib|ArmPkg/Library/ArmDisassemblerLib/ArmDisassemblerLib.inf
  ArmGicLib|ArmPkg/Drivers/ArmGic/ArmGicLib.inf
  ArmSmcLib|ArmPkg/Library/ArmSmcLib/ArmSmcLib.inf
  ArmGicArchLib|ArmPkg/Library/ArmGicArchLib/ArmGicArchLib.inf
  TimerLib|ArmPkg/Library/ArmArchTimerLib/ArmArchTimerLib.inf
  BaseLib|MdePkg/Library/BaseLib/BaseLib.inf
  BaseMemoryLib|MdePkg/Library/BaseMemoryLib/BaseMemoryLib.inf
  BaseSynchronizationLib|MdePkg/Library/BaseSynchronizationLib/BaseSynchronizationLib.inf
  BootLogoLib|MdeModulePkg/Library/BootLogoLib/BootLogoLib.inf
  BmpSupportLib|MdeModulePkg/Library/BaseBmpSupportLib/BaseBmpSupportLib.inf
  CapsuleLib|MdeModulePkg/Library/DxeCapsuleLibNull/DxeCapsuleLibNull.inf
  CacheMaintenanceLib|ArmPkg/Library/ArmCacheMaintenanceLib/ArmCacheMaintenanceLib.inf
  CompilerIntrinsicsLib|ArmPkg/Library/CompilerIntrinsicsLib/CompilerIntrinsicsLib.inf
  NULL|ArmPkg/Library/CompilerIntrinsicsLib/CompilerIntrinsicsLib.inf
  NULL|MdePkg/Library/BaseStackCheckLib/BaseStackCheckLib.inf
  CpuExceptionHandlerLib|ArmPkg/Library/ArmExceptionLib/ArmExceptionLib.inf
  CpuLib|MdePkg/Library/BaseCpuLib/BaseCpuLib.inf
  CustomizedDisplayLib|MdeModulePkg/Library/CustomizedDisplayLib/CustomizedDisplayLib.inf
  DefaultExceptionHandlerLib|ArmPkg/Library/DefaultExceptionHandlerLib/DefaultExceptionHandlerLib.inf
  DebugAgentLib|MdeModulePkg/Library/DebugAgentLibNull/DebugAgentLibNull.inf
  DevicePathLib|MdePkg/Library/UefiDevicePathLib/UefiDevicePathLib.inf
  DebugLib|MdePkg/Library/BaseDebugLibSerialPort/BaseDebugLibSerialPort.inf
  DebugPrintErrorLevelLib|MdePkg/Library/BaseDebugPrintErrorLevelLib/BaseDebugPrintErrorLevelLib.inf
  DxeServicesLib|MdePkg/Library/DxeServicesLib/DxeServicesLib.inf
  DxeServicesTableLib|MdePkg/Library/DxeServicesTableLib/DxeServicesTableLib.inf
  ExtractGuidedSectionLib|EmbeddedPkg/Library/PrePiExtractGuidedSectionLib/PrePiExtractGuidedSectionLib.inf
  FileExplorerLib|MdeModulePkg/Library/FileExplorerLib/FileExplorerLib.inf
  FdtLib|EmbeddedPkg/Library/FdtLib/FdtLib.inf
  FrameBufferBltLib|MdeModulePkg/Library/FrameBufferBltLib/FrameBufferBltLib.inf
  HobLib|MdePkg/Library/DxeHobLib/DxeHobLib.inf
  HiiLib|MdeModulePkg/Library/UefiHiiLib/UefiHiiLib.inf
  IoLib|MdePkg/Library/BaseIoLibIntrinsic/BaseIoLibIntrinsic.inf
  LzmaDecompressLib|MdeModulePkg/Library/LzmaCustomDecompressLib/LzmaCustomDecompressLib.inf
  NetLib|NetworkPkg/Library/DxeNetLib/DxeNetLib.inf
  DpcLib|NetworkPkg/Library/DxeDpcLib/DxeDpcLib.inf
  UdpIoLib|NetworkPkg/Library/DxeUdpIoLib/DxeUdpIoLib.inf
  IpIoLib|NetworkPkg/Library/DxeIpIoLib/DxeIpIoLib.inf
  PcdLib|MdePkg/Library/DxePcdLib/DxePcdLib.inf
  PeCoffExtraActionLib|MdePkg/Library/BasePeCoffExtraActionLibNull/BasePeCoffExtraActionLibNull.inf
  PeCoffLib|MdePkg/Library/BasePeCoffLib/BasePeCoffLib.inf
  PeCoffGetEntryPointLib|MdePkg/Library/BasePeCoffGetEntryPointLib/BasePeCoffGetEntryPointLib.inf
  PerformanceLib|MdePkg/Library/BasePerformanceLibNull/BasePerformanceLibNull.inf
  PrePiLib|EmbeddedPkg/Library/PrePiLib/PrePiLib.inf
  PrePiHobListPointerLib|ArmPlatformPkg/Library/PrePiHobListPointerLib/PrePiHobListPointerLib.inf
  PrePiMemoryAllocationLib|EmbeddedPkg/Library/PrePiMemoryAllocationLib/PrePiMemoryAllocationLib.inf
  PrintLib|MdePkg/Library/BasePrintLib/BasePrintLib.inf
  OrderedCollectionLib|MdePkg/Library/BaseOrderedCollectionRedBlackTreeLib/BaseOrderedCollectionRedBlackTreeLib.inf
  SafeIntLib|MdePkg/Library/BaseSafeIntLib/BaseSafeIntLib.inf
  SortLib|MdeModulePkg/Library/UefiSortLib/UefiSortLib.inf
  SynchronizationLib|MdePkg/Library/BaseSynchronizationLib/BaseSynchronizationLib.inf
  UefiLib|MdePkg/Library/UefiLib/UefiLib.inf
  UefiDecompressLib|MdePkg/Library/BaseUefiDecompressLib/BaseUefiDecompressLib.inf
  UefiBootServicesTableLib|MdePkg/Library/UefiBootServicesTableLib/UefiBootServicesTableLib.inf
  UefiRuntimeLib|MdePkg/Library/UefiRuntimeLib/UefiRuntimeLib.inf
  UefiRuntimeServicesTableLib|MdePkg/Library/UefiRuntimeServicesTableLib/UefiRuntimeServicesTableLib.inf
  UefiDriverEntryPoint|MdePkg/Library/UefiDriverEntryPoint/UefiDriverEntryPoint.inf
  UefiApplicationEntryPoint|MdePkg/Library/UefiApplicationEntryPoint/UefiApplicationEntryPoint.inf
  UefiUsbLib|MdePkg/Library/UefiUsbLib/UefiUsbLib.inf
  UefiBootManagerLib|MdeModulePkg/Library/UefiBootManagerLib/UefiBootManagerLib.inf
  UefiHiiServicesLib|MdeModulePkg/Library/UefiHiiServicesLib/UefiHiiServicesLib.inf
  TpmMeasurementLib|MdeModulePkg/Library/TpmMeasurementLibNull/TpmMeasurementLibNull.inf
  VarCheckLib|MdeModulePkg/Library/VarCheckLib/VarCheckLib.inf
  VariablePolicyLib|MdeModulePkg/Library/VariablePolicyLib/VariablePolicyLib.inf
  VariablePolicyHelperLib|MdeModulePkg/Library/VariablePolicyHelperLib/VariablePolicyHelperLib.inf
  TimeBaseLib|EmbeddedPkg/Library/TimeBaseLib/TimeBaseLib.inf

!if $(SECURE_BOOT_ENABLE) == TRUE
  RngLib|MdePkg/Library/BaseRngLibTimerLib/BaseRngLibTimerLib.inf
  IntrinsicLib|CryptoPkg/Library/IntrinsicLib/IntrinsicLib.inf
  OpensslLib|CryptoPkg/Library/OpensslLib/OpensslLibCrypto.inf
  PlatformSecureLib|SecurityPkg/Library/PlatformSecureLibNull/PlatformSecureLibNull.inf
  AuthVariableLib|SecurityPkg/Library/AuthVariableLib/AuthVariableLib.inf
  SecureBootVariableLib|SecurityPkg/Library/SecureBootVariableLib/SecureBootVariableLib.inf
  SecureBootVariableProvisionLib|SecurityPkg/Library/SecureBootVariableProvisionLib/SecureBootVariableProvisionLib.inf
!else
  AuthVariableLib|MdeModulePkg/Library/AuthVariableLibNull/AuthVariableLibNull.inf
!endif

  # Platform Drivers
!if $(USE_SCREEN_FOR_SERIAL_OUTPUT) == 1
  SerialPortLib|Lumia950XLPkg/Library/FrameBufferSerialPortLib/FrameBufferSerialPortLib.inf
!else
  SerialPortLib|MdePkg/Library/BaseSerialPortLibNull/BaseSerialPortLibNull.inf
!endif
  
  MemoryInitPeiLib|Lumia950XLPkg/Library/MemoryInitPeiLib/PeiMemoryAllocationLib.inf
  PlatformPeiLib|Lumia950XLPkg/Library/PlatformPeiLib/PlatformPeiLib.inf
  PlatformBootManagerLib|Lumia950XLPkg/Library/PlatformBootManagerLib/PlatformBootManagerLib.inf

  # SoC Drivers
  InterruptsLib|Lumia950XLPkg/Library/InterruptsLib/InterruptsLib.inf
  MallocLib|Lumia950XLPkg/Library/MallocLib/MallocLib.inf
  KeypadDeviceHelperLib|Lumia950XLPkg/Library/KeypadDeviceHelperLib/KeypadDeviceHelperLib.inf
  KeypadDeviceImplLib|Lumia950XLPkg/Library/KeypadDeviceImplLib/KeypadDeviceImplLib.inf
  DloadUtilLib|Lumia950XLPkg/Library/DloadUtilLib/DloadUtilLib.inf
  QcomPlatformClockInitLib|Lumia950XLPkg/Library/QcomPlatformClockInitLib/QcomPlatformClockInitLib.inf
  QcomPlatformMmcLib|Lumia950XLPkg/Library/PlatformMmcLib/QcomPlatformMmcLib.inf
  QcomPlatformMmcClockOverrideLib|Lumia950XLPkg/Library/QcomPlatformMmcClockOverrideLib/QcomPlatformMmcClockOverrideLib.inf
  QcomTargetMmcSdhciLib|Lumia950XLPkg/Library/TargetMmcSdhciLib/QcomTargetMmcSdhciLib.inf
  LcmLib|Lumia950XLPkg/Library/LcmLib/LcmLib.inf
  MicroLibC|Lumia950XLPkg/Library/MicroLibC/MicroLibC.inf
  StrLib|Lumia950XLPkg/Library/StrLib/StrLib.inf
  QcomPlatformI2cQupLib|Lumia950XLPkg/Library/StaticQcomPlatformI2cQupLib/StaticQcomPlatformI2cQupLib.inf
  SmemLib|Lumia950XLPkg/Driver/SmemDxe/SmemImplLib.inf
  SmemPtableLib|Lumia950XLPkg/Driver/SmemPtableDxe/SmemPtableImplLib.inf
  PTableLib|Lumia950XLPkg/Library/PTableLib/PTableLib.inf
  SsbiLib|Lumia950XLPkg/Driver/SsbiDxe/SsbiImplLib.inf
  BoardLib|Lumia950XLPkg/Driver/BoardDxe/BoardImplLib.inf
  QcomTargetBoardLib|Lumia950XLPkg/Library/QcomTargetBoardLib/QcomTargetBoardLib.inf
  PlatformIdLib|Lumia950XLPkg/Library/PlatformIdLib/PlatformIdLib.inf
  QTimerLib|Lumia950XLPkg/Library/QTimerLib/QTimerLib.inf

  # RTC Private
  Pm8x41LibRtcPrivate|Lumia950XLPkg/Driver/Pm8x41Dxe/Pm8x41ImplLib.inf
  SpmiLib|Lumia950XLPkg/Driver/SpmiDxe/SpmiImplLib.inf
  Pm8x41Lib|Lumia950XLPkg/Driver/Pm8x41Dxe/Pm8x41ImplLib.inf

  # System Reset
  ArmHvcLib|ArmPkg/Library/ArmHvcLib/ArmHvcLib.inf
  EfiResetSystemLib|Lumia950XLPkg/Library/QcomPmicResetSystemLib/QcomPmicResetSystemLib.inf
  RuntimeSpmiLib|Lumia950XLPkg/Library/RuntimeSpmiLib/RuntimeSpmiLib.inf
  RuntimeSpmiMemoryConfiguratorLib|Lumia950XLPkg/Library/RuntimeSpmiMemoryConfiguratorLib/RuntimeSpmiMemoryConfiguratorLib.inf

  # PCI Express Dependencies
  QcomPlatformClock2Lib|Lumia950XLPkg/Library/QcomPlatformClock2Lib/QcomPlatformClock2Lib.inf

  # UI Llbrary and apps
  LittleVglLib|Lumia950XLPkg/Library/LittleVglLib/LittleVglLib.inf
  LodePngLib|Lumia950XLPkg/Library/LodePngLib/LodePngLib.inf

[LibraryClasses.common.SEC]
  HobLib|EmbeddedPkg/Library/PrePiHobLib/PrePiHobLib.inf
  MemoryAllocationLib|EmbeddedPkg/Library/PrePiMemoryAllocationLib/PrePiMemoryAllocationLib.inf
  PrePiMemoryAllocationLib|EmbeddedPkg/Library/PrePiMemoryAllocationLib/PrePiMemoryAllocationLib.inf
  PrePiHobListPointerLib|ArmPlatformPkg/Library/PrePiHobListPointerLib/PrePiHobListPointerLib.inf
  PcdLib|MdePkg/Library/BasePcdLibNull/BasePcdLibNull.inf
  # SoC Drivers
  GpioTlmmLib|Lumia950XLPkg/GPLDriver/GpioTlmmDxe/GpioTlmmImplLib.inf
  SpmiLib|Lumia950XLPkg/Driver/SpmiDxe/SpmiImplLib.inf
  Pm8x41Lib|Lumia950XLPkg/Driver/Pm8x41Dxe/Pm8x41ImplLib.inf
  ClockLib|Lumia950XLPkg/Driver/ClockDxe/ClockImplLib.inf
  SmemLib|Lumia950XLPkg/Driver/SmemDxe/SmemImplLib.inf
  SmemPtableLib|Lumia950XLPkg/Driver/SmemPtableDxe/SmemPtableImplLib.inf
  PTableLib|Lumia950XLPkg/Library/PTableLib/PTableLib.inf
  RpmLib|Lumia950XLPkg/Driver/SmdRpmDxe/RpmLib.inf
  SsbiLib|Lumia950XLPkg/Driver/SsbiDxe/SsbiImplLib.inf
  BoardLib|Lumia950XLPkg/Driver/BoardDxe/BoardImplLib.inf
  QcomTargetBoardLib|Lumia950XLPkg/Library/QcomTargetBoardLib/QcomTargetBoardLib.inf
  PlatformIdLib|Lumia950XLPkg/Library/PlatformIdLib/PlatformIdLib.inf

[LibraryClasses.common.DXE_CORE]
  HobLib|MdePkg/Library/DxeCoreHobLib/DxeCoreHobLib.inf
  MemoryAllocationLib|MdeModulePkg/Library/DxeCoreMemoryAllocationLib/DxeCoreMemoryAllocationLib.inf
  DxeCoreEntryPoint|MdePkg/Library/DxeCoreEntryPoint/DxeCoreEntryPoint.inf
  ReportStatusCodeLib|MdeModulePkg/Library/DxeReportStatusCodeLib/DxeReportStatusCodeLib.inf
  ExtractGuidedSectionLib|MdePkg/Library/DxeExtractGuidedSectionLib/DxeExtractGuidedSectionLib.inf
  UefiDecompressLib|MdePkg/Library/BaseUefiDecompressLib/BaseUefiDecompressLib.inf
  PerformanceLib|MdeModulePkg/Library/DxeCorePerformanceLib/DxeCorePerformanceLib.inf

[LibraryClasses.common.DXE_DRIVER]
  ReportStatusCodeLib|MdeModulePkg/Library/DxeReportStatusCodeLib/DxeReportStatusCodeLib.inf
  SecurityManagementLib|MdeModulePkg/Library/DxeSecurityManagementLib/DxeSecurityManagementLib.inf
  PerformanceLib|MdeModulePkg/Library/DxePerformanceLib/DxePerformanceLib.inf
  MemoryAllocationLib|MdePkg/Library/UefiMemoryAllocationLib/UefiMemoryAllocationLib.inf
  HiiLib|MdeModulePkg/Library/UefiHiiLib/UefiHiiLib.inf
  UefiHiiServicesLib|MdeModulePkg/Library/UefiHiiServicesLib/UefiHiiServicesLib.inf
  ExtractGuidedSectionLib|MdePkg/Library/DxeExtractGuidedSectionLib/DxeExtractGuidedSectionLib.inf

  # SoC Drivers
  GpioTlmmLib|Lumia950XLPkg/GPLDriver/GpioTlmmDxe/GpioTlmmLib.inf
  SpmiLib|Lumia950XLPkg/Driver/SpmiDxe/SpmiImplLib.inf
  Pm8x41Lib|Lumia950XLPkg/Driver/Pm8x41Dxe/Pm8x41ImplLib.inf
  ClockLib|Lumia950XLPkg/Driver/ClockDxe/ClockLib.inf
  I2cQupLib|Lumia950XLPkg/Driver/I2cQupDxe/I2cQupLib.inf
  SmemLib|Lumia950XLPkg/Driver/SmemDxe/SmemImplLib.inf
  SmemPtableLib|Lumia950XLPkg/Driver/SmemPtableDxe/SmemPtableImplLib.inf
  PTableLib|Lumia950XLPkg/Library/PTableLib/PTableLib.inf
  RpmLib|Lumia950XLPkg/Driver/SmdRpmDxe/RpmLib.inf
  SsbiLib|Lumia950XLPkg/Driver/SsbiDxe/SsbiImplLib.inf
  BoardLib|Lumia950XLPkg/Driver/BoardDxe/BoardImplLib.inf
  QcomTargetBoardLib|Lumia950XLPkg/Library/QcomTargetBoardLib/QcomTargetBoardLib.inf
  PlatformIdLib|Lumia950XLPkg/Library/PlatformIdLib/PlatformIdLib.inf
  QcomDxeTimerLib|Lumia950XLPkg/Library/QTimerLib/QcomQTimerDxeTimerLib.inf

!if $(SECURE_BOOT_ENABLE) == TRUE
  BaseCryptLib|CryptoPkg/Library/BaseCryptLib/BaseCryptLib.inf
!endif

[LibraryClasses.common.UEFI_APPLICATION]
  UefiDecompressLib|MdePkg/Library/BaseUefiDecompressLib/BaseUefiTianoCustomDecompressLib.inf
  PerformanceLib|MdeModulePkg/Library/DxePerformanceLib/DxePerformanceLib.inf
  MemoryAllocationLib|MdePkg/Library/UefiMemoryAllocationLib/UefiMemoryAllocationLib.inf
  HiiLib|MdeModulePkg/Library/UefiHiiLib/UefiHiiLib.inf
  ShellLib|ShellPkg/Library/UefiShellLib/UefiShellLib.inf
  FileHandleLib|MdePkg/Library/UefiFileHandleLib/UefiFileHandleLib.inf
  ReportStatusCodeLib|MdeModulePkg/Library/DxeReportStatusCodeLib/DxeReportStatusCodeLib.inf
  ExtractGuidedSectionLib|MdePkg/Library/DxeExtractGuidedSectionLib/DxeExtractGuidedSectionLib.inf
  # SoC Drivers
  GpioTlmmLib|Lumia950XLPkg/GPLDriver/GpioTlmmDxe/GpioTlmmLib.inf
  SpmiLib|Lumia950XLPkg/Driver/SpmiDxe/SpmiImplLib.inf
  Pm8x41Lib|Lumia950XLPkg/Driver/Pm8x41Dxe/Pm8x41ImplLib.inf
  ClockLib|Lumia950XLPkg/Driver/ClockDxe/ClockLib.inf
  SmemLib|Lumia950XLPkg/Driver/SmemDxe/SmemImplLib.inf
  SmemPtableLib|Lumia950XLPkg/Driver/SmemPtableDxe/SmemPtableImplLib.inf
  PTableLib|Lumia950XLPkg/Library/PTableLib/PTableLib.inf
  RpmLib|Lumia950XLPkg/Driver/SmdRpmDxe/RpmLib.inf
  SsbiLib|Lumia950XLPkg/Driver/SsbiDxe/SsbiImplLib.inf
  BoardLib|Lumia950XLPkg/Driver/BoardDxe/BoardImplLib.inf
  QcomTargetBoardLib|Lumia950XLPkg/Library/QcomTargetBoardLib/QcomTargetBoardLib.inf
  PlatformIdLib|Lumia950XLPkg/Library/PlatformIdLib/PlatformIdLib.inf

!if $(SECURE_BOOT_ENABLE) == TRUE
  BaseCryptLib|CryptoPkg/Library/BaseCryptLib/BaseCryptLib.inf
!endif

[LibraryClasses.common.UEFI_DRIVER]
  ReportStatusCodeLib|MdeModulePkg/Library/DxeReportStatusCodeLib/DxeReportStatusCodeLib.inf
  UefiDecompressLib|MdePkg/Library/BaseUefiDecompressLib/BaseUefiTianoCustomDecompressLib.inf
  ExtractGuidedSectionLib|MdePkg/Library/DxeExtractGuidedSectionLib/DxeExtractGuidedSectionLib.inf
  PerformanceLib|MdeModulePkg/Library/DxePerformanceLib/DxePerformanceLib.inf
  MemoryAllocationLib|MdePkg/Library/UefiMemoryAllocationLib/UefiMemoryAllocationLib.inf
  UefiScsiLib|MdePkg/Library/UefiScsiLib/UefiScsiLib.inf
  ExtractGuidedSectionLib|MdePkg/Library/DxeExtractGuidedSectionLib/DxeExtractGuidedSectionLib.inf
  # SoC Drivers
  GpioTlmmLib|Lumia950XLPkg/GPLDriver/GpioTlmmDxe/GpioTlmmLib.inf
  SpmiLib|Lumia950XLPkg/Driver/SpmiDxe/SpmiImplLib.inf
  Pm8x41Lib|Lumia950XLPkg/Driver/Pm8x41Dxe/Pm8x41ImplLib.inf
  ClockLib|Lumia950XLPkg/Driver/ClockDxe/ClockLib.inf
  SmemLib|Lumia950XLPkg/Driver/SmemDxe/SmemImplLib.inf
  SmemPtableLib|Lumia950XLPkg/Driver/SmemPtableDxe/SmemPtableImplLib.inf
  PTableLib|Lumia950XLPkg/Library/PTableLib/PTableLib.inf
  RpmLib|Lumia950XLPkg/Driver/SmdRpmDxe/RpmLib.inf
  SsbiLib|Lumia950XLPkg/Driver/SsbiDxe/SsbiImplLib.inf
  BoardLib|Lumia950XLPkg/Driver/BoardDxe/BoardImplLib.inf
  QcomTargetBoardLib|Lumia950XLPkg/Library/QcomTargetBoardLib/QcomTargetBoardLib.inf
  PlatformIdLib|Lumia950XLPkg/Library/PlatformIdLib/PlatformIdLib.inf

!if $(SECURE_BOOT_ENABLE) == TRUE
  BaseCryptLib|CryptoPkg/Library/BaseCryptLib/BaseCryptLib.inf
!endif

[LibraryClasses.common.DXE_RUNTIME_DRIVER]
  HobLib|MdePkg/Library/DxeHobLib/DxeHobLib.inf
  MemoryAllocationLib|MdePkg/Library/UefiMemoryAllocationLib/UefiMemoryAllocationLib.inf
  ReportStatusCodeLib|MdeModulePkg/Library/DxeReportStatusCodeLib/DxeReportStatusCodeLib.inf
  CapsuleLib|MdeModulePkg/Library/DxeCapsuleLibNull/DxeCapsuleLibNull.inf
  ArmSmcLib|ArmPkg/Library/ArmSmcLib/ArmSmcLib.inf
  ExtractGuidedSectionLib|MdePkg/Library/DxeExtractGuidedSectionLib/DxeExtractGuidedSectionLib.inf

  # System Reset
  ArmHvcLib|ArmPkg/Library/ArmHvcLib/ArmHvcLib.inf
  EfiResetSystemLib|Lumia950XLPkg/Library/QcomPmicResetSystemLib/QcomPmicResetSystemLib.inf

  VariablePolicyLib|MdeModulePkg/Library/VariablePolicyLib/VariablePolicyLibRuntimeDxe.inf

!if $(SECURE_BOOT_ENABLE) == TRUE
  BaseCryptLib|CryptoPkg/Library/BaseCryptLib/RuntimeCryptLib.inf
!endif

[Components.common]
  # PrePI
  Lumia950XLPkg/PrePi/PrePi.inf {
    <LibraryClasses>
    SerialPortLib|Lumia950XLPkg/Library/FrameBufferSerialPortLib/FrameBufferSerialPortLib.inf
  }

  # DXE
  MdeModulePkg/Core/Dxe/DxeMain.inf {
    <LibraryClasses>
    NULL|MdeModulePkg/Library/DxeCrc32GuidedSectionExtractLib/DxeCrc32GuidedSectionExtractLib.inf
    NULL|MdeModulePkg/Library/DxeCrc32GuidedSectionExtractLib/DxeCrc32GuidedSectionExtractLib.inf
    NULL|MdeModulePkg/Library/LzmaCustomDecompressLib/LzmaCustomDecompressLib.inf
  }

  # PCD Database
  MdeModulePkg/Universal/PCD/Dxe/Pcd.inf {
    <LibraryClasses>
    PcdLib|MdePkg/Library/BasePcdLibNull/BasePcdLibNull.inf
  }

  # Processor Core Services
  ArmPkg/Drivers/CpuDxe/CpuDxe.inf
  # Even though we switch to QTimer / armv7-timer
  # We are still building it
  ArmPkg/Drivers/TimerDxe/TimerDxe.inf
  ArmPkg/Drivers/ArmGic/ArmGicDxe.inf
  MdeModulePkg/Universal/WatchdogTimerDxe/WatchdogTimer.inf
  EmbeddedPkg/MetronomeDxe/MetronomeDxe.inf
  EmbeddedPkg/ResetRuntimeDxe/ResetRuntimeDxe.inf
  EmbeddedPkg/RealTimeClockRuntimeDxe/RealTimeClockRuntimeDxe.inf {
    <LibraryClasses>
	  RealTimeClockLib|Lumia950XLPkg/Library/VirtualRealTimeClockLib/VirtualRealTimeClockLib.inf
  }

  # SoC Drivers (Cross-referenced from EFIDroid)
  Lumia950XLPkg/Driver/BamDxe/BamDxe.inf
  Lumia950XLPkg/GPLDriver/GpioTlmmDxe/GpioTlmmDxe.inf
  Lumia950XLPkg/GPLDriver/GpioTlmmInterruptDxe/GpioTlmmInterruptDxe.inf
  Lumia950XLPkg/Driver/SpmiDxe/SpmiDxe.inf
  Lumia950XLPkg/Driver/Pm8x41Dxe/Pm8x41Dxe.inf
  Lumia950XLPkg/Driver/GenericKeypadDeviceDxe/GenericKeypadDeviceDxe.inf
  Lumia950XLPkg/Driver/KeypadDxe/KeypadDxe.inf
  Lumia950XLPkg/Driver/ClockDxe/ClockDxe.inf
  Lumia950XLPkg/Driver/SdhciMMCHSDxe/SdhciMMCHS.inf
  Lumia950XLPkg/Driver/I2cQupDxe/I2cQupDxe.inf
  Lumia950XLPkg/Driver/SmemDxe/SmemDxe.inf
  Lumia950XLPkg/Driver/SmemPtableDxe/SmemPtableDxe.inf
  Lumia950XLPkg/Driver/SmdRpmDxe/RpmDxe.inf
  Lumia950XLPkg/Driver/SsbiDxe/SsbiDxe.inf
  Lumia950XLPkg/Driver/BoardDxe/BoardDxe.inf
  Lumia950XLPkg/Driver/RuntimeMemoryConfigDxe/RuntimeMemoryConfigDxe.inf
  Lumia950XLPkg/Driver/PCIExpressConfiguratorDxe/PCIExpressConfiguratorDxe.inf
  Lumia950XLPkg/Driver/TimerDxe/TimerDxe.inf

  # PreLoader checker
  Lumia950XLPkg/Driver/PreLoaderDxe/PreLoaderDxe.inf

  # Device Drivers
  Lumia950XLPkg/Driver/SynapticsTouchDxe/SynapticsTouchDevice.inf
  Lumia950XLPkg/Driver/SynapticsTouchDxe/SynapticsTouchDxe.inf

  # Debug heartbeat
!if $(SEND_HEARTBEAT_TO_SERIAL) == 1
  Lumia950XLPkg/Driver/HeartbeatDxe/HeartbeatDxe.inf
!endif

  # Runtime Services
  MdeModulePkg/Core/RuntimeDxe/RuntimeDxe.inf
  MdeModulePkg/Universal/CapsuleRuntimeDxe/CapsuleRuntimeDxe.inf
  MdeModulePkg/Universal/MonotonicCounterRuntimeDxe/MonotonicCounterRuntimeDxe.inf
  
  # Fake Variable Services
  MdeModulePkg/Universal/Variable/RuntimeDxe/VariableRuntimeDxe.inf

  # Security Stub
  MdeModulePkg/Universal/SecurityStubDxe/SecurityStubDxe.inf {
    <LibraryClasses>
!if $(SECURE_BOOT_ENABLE) == TRUE
      NULL|SecurityPkg/Library/DxeImageVerificationLib/DxeImageVerificationLib.inf
!endif
  }

!if $(SECURE_BOOT_ENABLE) == TRUE
  SecurityPkg/VariableAuthenticated/SecureBootConfigDxe/SecureBootConfigDxe.inf
!endif

  # Graphics Driver
  Lumia950XLPkg/Driver/SimpleFbDxe/SimpleFbDxe.inf

  # Lattice UC120 Configuration
  Lumia950XLPkg/Driver/LiCE40SpiConfigDxe/LiCE40SpiConfigDxe.inf
  Lumia950XLPkg/GPLDriver/QupSpiDxe/QupSpiDxe.inf

  # BDS
  MdeModulePkg/Universal/PrintDxe/PrintDxe.inf
  MdeModulePkg/Universal/Console/ConPlatformDxe/ConPlatformDxe.inf
  MdeModulePkg/Universal/Console/ConSplitterDxe/ConSplitterDxe.inf
  MdeModulePkg/Universal/Console/GraphicsConsoleDxe/GraphicsConsoleDxe.inf
  MdeModulePkg/Universal/DevicePathDxe/DevicePathDxe.inf
  MdeModulePkg/Universal/HiiDatabaseDxe/HiiDatabaseDxe.inf
  MdeModulePkg/Universal/SmbiosDxe/SmbiosDxe.inf
  MdeModulePkg/Universal/DisplayEngineDxe/DisplayEngineDxe.inf
  MdeModulePkg/Universal/SetupBrowserDxe/SetupBrowserDxe.inf
  MdeModulePkg/Universal/DriverHealthManagerDxe/DriverHealthManagerDxe.inf
  MdeModulePkg/Universal/BdsDxe/BdsDxe.inf
  Lumia950XLPkg/Application/BdsMenuApp/BdsMenuApp.inf {
    <LibraryClasses>
      NULL|MdeModulePkg/Library/DeviceManagerUiLib/DeviceManagerUiLib.inf
      NULL|MdeModulePkg/Library/BootManagerUiLib/BootManagerUiLib.inf
      NULL|MdeModulePkg/Library/BootMaintenanceManagerUiLib/BootMaintenanceManagerUiLib.inf
  }
  Lumia950XLPkg/Driver/LogoDxe/LogoDxe.inf
  Lumia950XLPkg/Application/BootSplashApp/BootSplashApp.inf

  # Disk IO
  MdeModulePkg/Universal/Disk/DiskIoDxe/DiskIoDxe.inf
  MdeModulePkg/Universal/Disk/PartitionDxe/PartitionDxe.inf
  MdeModulePkg/Universal/Disk/UnicodeCollation/EnglishDxe/EnglishDxe.inf
  FatPkg/EnhancedFatDxe/Fat.inf
  MdeModulePkg/Bus/Scsi/ScsiBusDxe/ScsiBusDxe.inf
  MdeModulePkg/Bus/Scsi/ScsiDiskDxe/ScsiDiskDxe.inf

  # ACPI and SMBIOS
  # We use pre-built ACPI tables, so only core components are loaded
  Lumia950XLPkg/AcpiTables/Lumia950XLAcpiTables.inf
  Lumia950XLPkg/Driver/SmBiosTableDxe/SmBiosTableDxe.inf
  MdeModulePkg/Universal/Acpi/AcpiTableDxe/AcpiTableDxe.inf
  MdeModulePkg/Universal/Acpi/AcpiPlatformDxe/AcpiPlatformDxe.inf
  MdeModulePkg/Universal/Acpi/BootGraphicsResourceTableDxe/BootGraphicsResourceTableDxe.inf

  # Shell
  ShellPkg/Application/Shell/Shell.inf {
    <LibraryClasses>
      ShellCommandLib|ShellPkg/Library/UefiShellCommandLib/UefiShellCommandLib.inf
      NULL|ShellPkg/Library/UefiShellLevel2CommandsLib/UefiShellLevel2CommandsLib.inf
      NULL|ShellPkg/Library/UefiShellLevel1CommandsLib/UefiShellLevel1CommandsLib.inf
      NULL|ShellPkg/Library/UefiShellLevel3CommandsLib/UefiShellLevel3CommandsLib.inf
      NULL|ShellPkg/Library/UefiShellDriver1CommandsLib/UefiShellDriver1CommandsLib.inf
      NULL|ShellPkg/Library/UefiShellDebug1CommandsLib/UefiShellDebug1CommandsLib.inf
      NULL|ShellPkg/Library/UefiShellInstall1CommandsLib/UefiShellInstall1CommandsLib.inf
      NULL|ShellPkg/Library/UefiShellNetwork1CommandsLib/UefiShellNetwork1CommandsLib.inf
      HandleParsingLib|ShellPkg/Library/UefiHandleParsingLib/UefiHandleParsingLib.inf
      PrintLib|MdePkg/Library/BasePrintLib/BasePrintLib.inf
      BcfgCommandLib|ShellPkg/Library/UefiShellBcfgCommandLib/UefiShellBcfgCommandLib.inf

    <PcdsFixedAtBuild>
      gEfiMdePkgTokenSpaceGuid.PcdDebugPropertyMask|0xFF
      gEfiShellPkgTokenSpaceGuid.PcdShellLibAutoInitialize|FALSE
      gEfiMdePkgTokenSpaceGuid.PcdUefiLibMaxPrintBufferSize|8000
  }
